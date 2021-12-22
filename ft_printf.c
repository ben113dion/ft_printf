/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdion <bdion@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:34:58 by bdion             #+#    #+#             */
/*   Updated: 2021/12/22 02:01:24 by bdion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

s_type	ft_note(void)
{
	s_type	i;
	
	i.index = 0;
	return (i);
}

void	is_what(const char *input, s_type *note)
{
	char	s;

	s = (char)input[note->index];
	if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(note->argz, size_t));
	else if (s == 'u')
		ft_putnbr(va_arg(note->argz, unsigned int));
	else if (s == 's')
		ft_putstr(va_arg(note->argz, char *));
	else if (s == 'c')
		ft_putchr(va_arg(note->argz, size_t));
	else if (s == 'x' || s == 'X')
		ft_puthex(va_arg(note->argz, size_t), s);
	else if (s == 'p')
		ft_putaddr(va_arg(note->argz, void *));
	else if (s == '%')
		ft_putchr('%');
}

int	ft_printf(const char *input, ...)
{
	s_type	note;

	note = ft_note();
	va_start(note.argz, (char *)input);
	while (input[note.index])
	{
		if (input[note.index] != '%')
			write(1, &input[note.index], 1); 
		else if (input[note.index] == '%')
		{
			note.index++;
			is_what(input, &note);
		}
		note.index++;
	}
	va_end(note.argz);
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	void		*ptr;

	puts("-----------------");		
	ft_printf("d|%d|\n", 42);
	printf("d|%d|\n", 42);
	puts("-----------------");		
	ft_printf("u|%u|\n", 42);
	printf("u|%u|\n", 42);
	puts("-----------------");		
	ft_printf("s|%s|\n", "MyLap");
	printf("s|%s|\n", "MyLap");
	puts("-----------------");		
	ft_printf("c|%c|%%\n", '$');
	printf("c|%c|%%\n", '$');
	puts("-----------------");		
	ft_printf("x|%x|%X|\n", 0x8F4F4F, 0xabcde113);
	printf("x|%x|%X|\n", 0x8F4F4F, 0xabcde113);
	puts("-----------------");
	ft_printf("p|%p|\n", &ptr);
	printf("p|%p|\n", &ptr);
	return (0);
}*/
