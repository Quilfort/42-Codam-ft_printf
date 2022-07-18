#include "ft_printf.h"

static unsigned long long	length(unsigned long long n)
{
	unsigned int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

unsigned long long	ft_putnbr_base_lower(unsigned long long n)
{
	char	*rep;

	rep = "0123456789abcdef";
	if (n > 15)
	{
		ft_putnbr_base_lower(n / 16);
		ft_putnbr_base_lower(n % 16);
	}
	else
	{
		ft_putchar_fd(rep[n % 16], 1);
	}
	return (length(n));
}

unsigned long long	ft_putnbr_base_upper(unsigned long long n)
{
	char	*rep;

	rep = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_putnbr_base_upper(n / 16);
		ft_putnbr_base_upper(n % 16);
	}
	else
	{
		ft_putchar_fd(rep[n % 16], 1);
	}
	return (length(n));
}
