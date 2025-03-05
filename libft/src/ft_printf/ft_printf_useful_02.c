/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_useful_02.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maballet <maballet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:39:34 by maballet          #+#    #+#             */
/*   Updated: 2025/02/03 17:50:48 by maballet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "projets/ft_printf.h"

int	ft_putstr_printf(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		len += write(1, "(null)", 6);
		return (len);
	}
	write(1, s, ft_strlen_printf(s));
	return (ft_strlen_printf(s));
}

int	ft_putnbr_printf(int n)
{
	long	num;
	int		len;

	num = n;
	len = 0;
	if (num < 0)
	{
		len += write(1, "-", 1);
		num = -num;
	}
	if (num > 9)
		len += ft_putnbr_printf(num / 10);
	len += ft_putchar_printf((num % 10) + '0');
	return (len);
}

int	ft_putnbrbase(unsigned long n, char *base, unsigned long baselen)
{
	int		len;

	len = 0;
	if (n >= baselen)
		len += ft_putnbrbase(n / baselen, base, baselen);
	len += ft_putchar_printf(base[n % baselen]);
	return (len);
}

int	ft_putptr(void *ptr)
{
	int				len;

	len = 0;
	if (!ptr)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	len += write(1, "0x", 2);
	len += ft_putnbrbase((unsigned long)ptr, "0123456789abcdef", 16);
	return (len);
}

int	ft_putchar_printf(char c)
{
	write(1, &c, 1);
	return (1);
}
