/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:19:30 by maballet          #+#    #+#             */
/*   Updated: 2025/03/03 15:27:16 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "projets/get_next_line.h"

char	*ft_free_line(char *line)
{
	if (line)
		free (line);
	return (NULL);
}

char	*ft_putbuf(char *line, char *buffer)
{
	size_t	n;
	char	*join;

	n = 0;
	while (buffer[n] != '\n' && buffer[n])
		n++;
	join = ft_strnjoin(line, buffer, n + (buffer[n] == '\n'));
	if (!join)
		return (ft_free_line(line));
	if (buffer[n] == '\n')
	{
		ft_memmove_gnl(buffer, buffer + n + 1,
			ft_strlen_gnl(buffer + n + 1) + 1);
	}
	else
	{
		ft_bzero_gnl(buffer, BUFFER_SIZE);
	}
	free(line);
	return (join);
}

char	*get_next_line(int fd)
{
	ssize_t		bytes_read;
	char		*line;
	static char	buffer[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (buffer[0] != '\0')
		{
			line = ft_putbuf(line, buffer);
			if (!line)
				return (NULL);
			if (line && ft_memchr_gnl(line, '\n', ft_strlen_gnl(line)))
				return (line);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			return (line);
		if (bytes_read == -1)
			return (ft_free_line(line));
		buffer[bytes_read] = '\0';
	}
	return (line);
}
