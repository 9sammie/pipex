/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:40:25 by maballet          #+#    #+#             */
/*   Updated: 2025/03/06 18:47:28 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

static char	*find_path_env(char **envp)
{
	char	*path_env;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (envp[i] == NULL)
		return (NULL);
	path_env = envp[i] + 5;
	return (path_env);
}

static char	*find_full_path(char **paths, char *cmd, int i)
{
	char	*tmp;
	char	*full_path;

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
		return (full_path);
	free(full_path);
	return (NULL);
}

char	*find_executable(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;
	char	*full_path;
	int		i;

	if (cmd == NULL || envp == NULL)
		return (NULL);
	path_env = find_path_env(envp);
	paths = ft_split(path_env, ':');
	if (paths == NULL)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = find_full_path(paths, cmd, i);
		if (full_path != NULL)
		{
			free_array(paths);
			return (full_path);
		}
		i++;
	}
	perror("Command not found");
	free_array(paths);
	return (NULL);
}

void	cmd_path_init(t_data *data, char **argv, char **envp)
{
	data->cmd_1 = ft_split(argv[2], ' ');
	data->cmd_2 = ft_split(argv[3], ' ');
	if (data->cmd_1 == NULL || data->cmd_2 == NULL)
	{
		perror("ft_split failed");
		exit(EXIT_FAILURE);
	}
	data->path_1 = find_executable(data->cmd_1[0], envp);
	data->path_2 = find_executable(data->cmd_2[0], envp);
	if (data->path_1 == NULL || data->path_2 == NULL)
	{
		perror("command not found");
		exit (EXIT_FAILURE);
	}
}