#include "printf.h"

void	ft_putnbr(int n)
{
	char	pchr;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
			ft_putnbr(n);
		}
		else if (n < 10)
		{
			pchr = n + 48;
			write(1, &pchr, 1);
		}
		else
		{
			ft_putnbr(n / 10);
			pchr = (n % 10) + 48;
			write(1, &pchr, 1);
		}
	}
}

void	ft_puthex(unsigned long long hex, char type)
{
	if (hex < 16)
	{
		if (hex >= 10)
		{
			if (type == 'x')
				ft_putchr(hex + 87);
			else
				ft_putchr(hex + 55); 
		}
		else
			ft_putchr(hex + 48);
	}
	else
	{
		ft_puthex(hex / 16, type);
		ft_puthex(hex % 16, type);
	}
} 

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (s)
		while (s[++i] != 0)
			write(1, &s[i], 1);
}

void	ft_putaddr(void *ptr)
{
	uintptr_t	ptraddr;

	ptraddr = (uintptr_t)ptr;
	ft_putstr("0x");
	ft_puthex(ptraddr, 'x');
}

void	ft_putchr(char c)
{
	write(1, &c, 1);
}