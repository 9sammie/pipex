/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:20:26 by maballet          #+#    #+#             */
/*   Updated: 2025/02/03 17:47:11 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char		*ft_strnjoin(char const *line, char const *buffer, size_t n);
size_t		ft_strlen_gnl(const char *s);
void		*ft_memchr_gnl(const void *s, int c, size_t n);
void		ft_bzero_gnl(void *s, size_t n);
char		*ft_putbuf(char *line, char *buffer);
void		*ft_memmove_gnl(void *dest, const void *src, size_t n);
char		*ft_free_line(char *line);

#endif