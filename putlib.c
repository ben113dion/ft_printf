/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdion <bdion@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:26:03 by bdion             #+#    #+#             */
/*   Updated: 2022/01/24 13:50:25 by bdion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putunsnbr(unsigned int n)
{
	size_t	nchr;

	nchr = 0;
	if (n < 0)
	{
		nchr += ft_putchr('-');
		n = -n;
		nchr += ft_putnbr(n);
	}
	else if (n < 10)
		nchr += ft_putchr(n + 48);
	else
	{
		nchr += ft_putnbr(n / 10);
		nchr += ft_putchr((n % 10) + 48);
	}
	return (nchr);
}

size_t	ft_putnbr(long n)
{
	size_t	nchr;

	nchr = 0;
	if (n == -2147483648)
		nchr += ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			nchr += ft_putchr('-');
			n = -n;
			nchr += ft_putnbr(n);
		}
		else if (n < 10)
			nchr += ft_putchr(n + 48);
		else
		{
			nchr += ft_putnbr(n / 10);
			nchr += ft_putchr((n % 10) + 48);
		}
	}
	return (nchr);
}

size_t	ft_puthex(unsigned long long hex, size_t type)
{
	size_t	nchr;

	nchr = 0;
	if (hex < 16)
	{
		if (hex >= 10)
		{
			if (type == 'x')
				nchr += ft_putchr(hex + 87);
			else
				nchr += ft_putchr(hex + 55);
		}
		else
			nchr += ft_putchr(hex + 48);
	}
	else
	{
		nchr += ft_puthex(hex / 16, type);
		nchr += ft_puthex(hex % 16, type);
	}
	return (nchr);
}

size_t	ft_putstr(char *s)
{
	size_t	nchr;

	if (!s)
		return (ft_putstr("(null)"));
	nchr = -1;
	if (s)
		while (s[++nchr] != 0)
			write(1, &s[nchr], 1);
	return (nchr);
}

size_t	ft_putaddr(void *ptr)
{
	uintptr_t	ptraddr;
	size_t		nchr;

	nchr = 0;
	ptraddr = (uintptr_t)ptr;
	nchr += ft_putstr("0x");
	nchr += ft_puthex(ptraddr, 'x');
	return (nchr);
}
