/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdion <bdion@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:26:03 by bdion             #+#    #+#             */
/*   Updated: 2021/12/23 14:02:35 by bdion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//change write fr putstr or putchr
size_t	ft_putnbr(int n)
{
	size_t	pchr;
	size_t	nchr;

	nchr = 0;
	if (n == -2147483648)
		nchr += write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			nchr += write(1, "-", 1);
			n = -n;
			nchr += ft_putnbr(n);
		}
		else if (n < 10)
		{
			pchr = n + 48;
			nchr += write(1, &pchr, 1);
		}
		else
		{
			nchr += ft_putnbr(n / 10);
			pchr = (n % 10) + 48;
			nchr += write(1, &pchr, 1);
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

size_t	ft_putchr(size_t c)
{
	return(write(1, &c, 1));
}
