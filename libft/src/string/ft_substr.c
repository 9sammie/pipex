/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:42:39 by maballet          #+#    #+#             */
/*   Updated: 2024/11/26 16:43:42 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*dup;
	size_t		slen;

	i = 0;
	slen = ft_strlen(s);
	if (slen <= start)
	{
		len = 0;
	}
	else if (slen <= len + start)
	{
		len = slen - start;
	}
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == 0)
		return (NULL);
	while (i < len && start + i < slen)
	{
		dup[i] = s[i + start];
		i++;
	}
	dup[i] = '\0';
	return ((char *)dup);
}
