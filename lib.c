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

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (s)
		while (s[++i] != 0)
			write(1, &s[i], 1);
}

void	ft_putchr(char c)
{
	write(1, &c, 1);
}
