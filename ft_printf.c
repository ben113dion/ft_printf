/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdion <bdion@student.42quebec.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 20:34:58 by bdion             #+#    #+#             */
/*   Updated: 2021/12/23 15:31:47 by bdion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_note	ft_note(void)
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
		note->nchr += ft_putnbr(va_arg(note->argz, int));
	else if (s == 'u')
		note->nchr += ft_putnbr(va_arg(note->argz, unsigned int));
	else if (s == 's')
		note->nchr += ft_putstr(va_arg(note->argz, char *));
	else if (s == 'c')
		note->nchr += ft_putchr(va_arg(note->argz, size_t));
	else if (s == 'x' || s == 'X')
		note->nchr += ft_puthex(va_arg(note->argz, unsigned int), s);
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
			note.nchr += ft_putchr(input[note.index]);
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
