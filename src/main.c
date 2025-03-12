/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:18:39 by maballet          #+#    #+#             */
/*   Updated: 2025/03/11 15:44:17 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

void	close_everything(t_data *data)
{
	if (data->fd_in)
		close(data->fd_in);
	if (data->fd_out)
		close(data->fd_out);
	if (data->fd_pipe[0])
		close(data->fd_pipe[0]);
	if (data->fd_pipe[1])
		close(data->fd_pipe[1]);
}

void	data_init(t_data *data)
{
	data->cmd_1 = NULL;
	data->cmd_2 = NULL;
	data->path_1 = NULL;
	data->path_2 = NULL;
	data->fd_in = 0;
	data->fd_out = 0;
	data->pid1 = 0;
	data->pid2 = 0;
	data->status = 0;
}

void	write_pipe(t_data *data, char **envp)
{
	data->pid1 = fork();
	if (data->pid1 == -1)
	{
		perror("Error: fork failed");
		exit(EXIT_FAILURE);
	}
	if (data->pid1 == 0)
	{
		dup2(data->fd_in, STDIN_FILENO);
		dup2(data->fd_pipe[1], STDOUT_FILENO);
		close_everything(data);
		execve(data->path_1, data->cmd_1, envp);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}

void	read_pipe(t_data *data, char **envp)
{
	data->pid2 = fork();
	if (data->pid2 == -1)
	{
		perror("Error: fork failed");
		exit(EXIT_FAILURE);
	}
	if (data->pid2 == 0)
	{
		dup2(data->fd_pipe[0], STDIN_FILENO);
		dup2(data->fd_out, STDOUT_FILENO);
		close_everything(data);
		execve(data->path_2, data->cmd_2, envp);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	data_init(&data);
	if (argc != 5)
		return (1);
	data.fd_in = open(argv[1], O_RDONLY);
	data.fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data.fd_in == -1)
		perror("no such file or directory: argv[1]");
	if (data.fd_out == -1 || pipe(data.fd_pipe) == -1)
	{
		perror("Error opening file or pipe");
		return (1);
	}
	cmd_path_init(&data, argv, envp);
	write_pipe(&data, envp);
	read_pipe(&data, envp);
	close_everything(&data);
	waitpid(data.pid1, &data.status, 0);
	waitpid(data.pid2, &data.status, 0);
	free(data.path_1);
	free(data.path_2);
	free_array(data.cmd_1);
	free_array(data.cmd_2);
	return (0);
}
