/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdion <bdion@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:35:35 by bdion             #+#    #+#             */
/*   Updated: 2021/12/21 23:56:07 by bdion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# include <ctype.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# define PRINTF_H

typedef	struct	s_type
{
	int	index;
	int	bytes;
	va_list	argz;
}	s_type;

int	ft_printf(const char *format, ...);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_putchr(char c);

#endif 
