#include "libft.h"

static int	length(long n)
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

int	ft_putnbr_fd(int n, int fd)
{
	int	number;
	int	temp;

	number = n;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 0 && n <= 9)
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
