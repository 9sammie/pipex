/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:36:01 by maballet          #+#    #+#             */
/*   Updated: 2024/11/26 16:39:19 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	const size_t	a = size * nmemb;
	void			*array;

	if (nmemb == 0 || size == 0 || a / nmemb != size)
		return (malloc(0));
	array = malloc(size * nmemb);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, size * nmemb);
	return (array);
}
