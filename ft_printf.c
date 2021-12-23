/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdion <bdion@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:34:58 by bdion             #+#    #+#             */
/*   Updated: 2021/12/23 13:58:26 by bdion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

s_type	ft_note(void)
{
	s_type	i;
	
	i.index = 0;
	i.nchr = 0;
	return (i);
}

void	is_what(const char *input, s_type *note)
{
	char	s;

	s = (char)input[note->index];
	if (s == 'd' || s == 'i')
		note->nchr += ft_putnbr(va_arg(note->argz, size_t));
	else if (s == 'u')
		note->nchr += ft_putnbr(va_arg(note->argz, unsigned int));
	else if (s == 's')
		note->nchr += ft_putstr(va_arg(note->argz, char *));
	else if (s == 'c')
		note->nchr += ft_putchr(va_arg(note->argz, size_t));
	else if (s == 'x' || s == 'X')
		note->nchr += ft_puthex(va_arg(note->argz, size_t), s);
	else if (s == 'p')
		note->nchr += ft_putaddr(va_arg(note->argz, void *));
	else if (s == '%')
		note->nchr += ft_putchr('%');
}

int	ft_printf(const char *input, ...)
{
	s_type	note;

	note = ft_note();
	va_start(note.argz, (char *)input);
	while (input[note.index])
	{
		if (input[note.index] != '%')
			note.nchr += write(1, &input[note.index], 1); 
		else if (input[note.index] == '%')
		{
			note.index++;
			is_what(input, &note);
		}
		note.index++;
	}
	va_end(note.argz);
	return (note.nchr);
}

#include <stdio.h>
int	main(void)
{
	void		*ptr;
	int	s;

	puts("-----------------");		
	s = ft_printf("d|%d|\n", 42);
	ft_printf("nchr:%d\n", s);
	s = printf("d|%d|\n", 42);
 	ft_printf("nchr:%d\n", s);
	puts("-----------------");		
	s = ft_printf("u|%u|\n", 42);
	ft_printf("nchr:%d\n", s);
	s = printf("u|%u|\n", 42);
	ft_printf("nchr:%d\n", s);
	puts("-----------------");		
	s = ft_printf("s|%s|\n", "MyLap");
	ft_printf("nchr:%d\n", s);
	s = printf("s|%s|\n", "MyLap");
	ft_printf("nchr:%d\n", s);
	puts("-----------------");		
	s = ft_printf("c|%c|%%\n", '$');
	ft_printf("nchr:%d\n", s);
	s = printf("c|%c|%%\n", '$');
	ft_printf("nchr:%d\n", s);
	puts("-----------------");		
	s = ft_printf("x|%x|%X|\n", 0x8F4F4F, 0xabcde113);
	ft_printf("nchr:%d\n", s);
	s = printf("x|%x|%X|\n", 0x8F4F4F, 0xabcde113);
	ft_printf("nchr:%d\n", s);
	puts("-----------------");
	s = ft_printf("p|%p|\n", &ptr);
	ft_printf("nchr:%d\n", s);
	s = printf("p|%p|\n", &ptr);
	ft_printf("nchr:%d\n", s);
	return (0);
}
