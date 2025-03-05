/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:18:39 by maballet          #+#    #+#             */
/*   Updated: 2025/03/04 17:47:43 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*find_executable(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;
	char	*full_path;
	char	*tmp;
	int		i;

	i = 0;
	if (cmd == NULL || envp == NULL)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break;
		i++;
	}
	if (envp[i] == NULL)
		return (NULL);
	path_env = envp[i] + 5;
	paths = ft_split(path_env, ':');
	if (paths == NULL)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (tmp == NULL)
		{
			free(tmp);
			perror("Error finding executable");
			exit(EXIT_FAILURE);
		}
		full_path = ft_strjoin(tmp, cmd);
		if (full_path == NULL)
		{
			free(full_path);
			free(tmp);
			perror("Error finding executable");
			exit(EXIT_FAILURE);
		}
		free (tmp);
		if (access(full_path, F_OK) == 0)
		{
			free_array(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	perror("Command not found");
	free_array(paths);
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	char	**cmd_1;
	char	**cmd_2;
	char	*path_1;
	char	*path_2;
	int		fd_in;
	int		fd_out;
	int 	fd_pipe[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (1);
	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_in == -1 || fd_out == -1 || pipe(fd_pipe) == -1)
	{
		perror("Error opening files or pipe");
		return (1);
	}
	cmd_1 = ft_split(argv[2], ' ');
	cmd_2 = ft_split(argv[3], ' ');
	if (cmd_1 == NULL || cmd_2 == NULL)
	{
		perror("ft_split failed");
		exit(EXIT_FAILURE);
	}
	path_1 = find_executable(cmd_1[0], envp);
	path_2 = find_executable(cmd_2[0], envp);
	if (path_1 == NULL || path_2 == NULL)
	{
		perror("command not found");
		exit (EXIT_FAILURE);
	}
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_pipe[1], STDOUT_FILENO);
		close(fd_in);
		close(fd_out);
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		(execve(path_1, cmd_1, envp));
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd_pipe[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_in);
		close(fd_out);
		close(fd_pipe[0]);
		close(fd_pipe[1]);
		execve(path_2, cmd_2, envp);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	close(fd_in);
	close(fd_out);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	free(path_1);
	free(path_2);
	free_array(cmd_1);
	free_array(cmd_2);
	return (0);
}
