/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:10:25 by maballet          #+#    #+#             */
/*   Updated: 2024/11/26 16:43:34 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l;
	size_t	n;

	i = 0;
	l = 0;
	n = ft_strlen((char *)little);
	if (little[i] == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		while (big[i + l] == little[l] && l < n && i + l < len)
			l++;
		if (l == n)
			return ((char *)&big[i]);
		else
			l = 0;
		i++;
	}
	return (0);
}
