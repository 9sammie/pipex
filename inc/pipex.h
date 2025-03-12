/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:05:34 by maballet          #+#    #+#             */
/*   Updated: 2025/03/11 15:44:32 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/inc/libft.h"

typedef struct s_data
{
	char	**cmd_1;
	char	**cmd_2;
	char	*path_1;
	char	*path_2;
	int		fd_in;
	int		fd_out;
	int		fd_pipe[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;
}				t_data;

int		main(int argc, char **argv, char **envp);
void	free_array(char **array);
void	cmd_path_init(t_data *data, char **argv, char **envp);
char	*find_executable(char *cmd, char **envp);

#endif