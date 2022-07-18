#include "ft_printf.h"

static int	length(unsigned int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_unsigned_putnbr(unsigned int n, int fd)
{
	unsigned int	number;
	unsigned int	temp;

	number = n;
	if (n >= 0 && n <= 9)
	{
		temp = n + '0';
		ft_putchar_fd(temp, fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	return (length(number));
}
