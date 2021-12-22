#include "printf.h"

s_type	ft_note(void)
{
	s_type	i;
	
	i.index = 0;
	i.bytes = 0;
	return (i);
}

void	is_what(const char *input, s_type *note)
{
	char	s;

	s = (char)input[note->index];
	if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(note->argz, int));
	else if (s == 'u')
		ft_putnbr(va_arg(note->argz, unsigned int));
	else if (s == 's')
		ft_putstr(va_arg(note->argz, char *));
}

int	ft_printf(const char *input, ...)
{
	s_type	note;

	note = ft_note();
	va_start(note.argz, (char *)input);
	while (input[note.index])
	{
		if (input[note.index] != '%')
			note.bytes += write(1, &input[note.index], 1); 
		else if (input[note.index] == '%')
		{
			note.index++;
			is_what(input, &note);
		}
		note.index++;
	}
	va_end(note.argz);
	return (note.bytes);
}

int	main(void)
{
	void		*ptr;
	int		x;
	char		buff[256];
	
	puts("-----------------");		
	ft_printf("d|%d|\n", 42);
	printf("d|%d|\n", 42);
	puts("-----------------");		
	ft_printf("u|%u|\n", 42);
	printf("u|%u|\n", 42);
	puts("-----------------");		
	ft_printf("d|%s|\n", "MyLap");
	printf("d|%s|\n", "MyLap");
	puts("-----------------");		
	ft_printf("u|%u|\n", 42);
	printf("u|%u|\n", 42);

return (0);
}
