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

void	is_what(const char *input, t_note *notepad)
{
	char	s;

	s = (char)input[notepad->index];
	if (s == 'd' || s == 'i')
		notepad->nchr += ft_putnbr(va_arg(notepad->argz, int));
	else if (s == 'u')
		notepad->nchr += ft_putnbr(va_arg(notepad->argz, unsigned long));
	else if (s == 's')
		notepad->nchr += ft_putstr(va_arg(notepad->argz, char *));
	else if (s == 'c')
		notepad->nchr += ft_putchr(va_arg(notepad->argz, size_t));
	else if (s == 'x' || s == 'X')
		notepad->nchr += ft_puthex(va_arg(notepad->argz, unsigned int), s);
	else if (s == 'p')
		notepad->nchr += ft_putaddr(va_arg(notepad->argz, void *));
	else if (s == '%')
		notepad->nchr += ft_putchr('%');
}

int	ft_printf(const char *input, ...)
{
	t_note	notepad;

	notepad.index = 0;
	notepad.nchr = 0;
	va_start(notepad.argz, (char *)input);
	while (input[notepad.index])
	{
		if (input[notepad.index] != '%')
			notepad.nchr += ft_putchr(input[notepad.index]);
		else if (input[notepad.index] == '%')
		{
			notepad.index++;
			is_what(input, &notepad);
		}
		notepad.index++;
	}
	va_end(notepad.argz);
	return (notepad.nchr);
}
