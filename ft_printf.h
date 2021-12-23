/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdion <bdion@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:35:35 by bdion             #+#    #+#             */
/*   Updated: 2021/12/23 14:53:53 by bdion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# define FT_PRINTF_H

typedef	struct	s_type
{
	size_t	index;
	size_t	nchr;
	va_list	argz;
}	s_type;

int	ft_printf(const char *input, ...);
size_t	ft_puthex(unsigned long long hex, size_t type);
size_t	ft_putaddr(void *ptr);
size_t	ft_putnbr(long n);
size_t	ft_putstr(char *s);
size_t	ft_putchr(size_t c);

#endif 
