#include "ft_printf.h"

static void	ft_flags(const char *format, int *i, int *j, va_list *arguments)
{
	if (format[*(i)] == 'c')
		*(j) = *(j) + ft_putchar_fd(va_arg(*(arguments), int), 1);
	else if (format[*(i)] == 's')
		*(j) = *(j) + ft_putstr_fd(va_arg(*(arguments), char *), 1);
	else if (format[*(i)] == 'p')
	{
		write(1, "0x", 2);
		*(j) = *(j) + 2 + ft_putnbr_base_lower(va_arg(*(arguments), \
		unsigned long long));
	}
	else if (format[*(i)] == 'd' || format[*(i)] == 'i')
		*(j) = *(j) + ft_putnbr_fd(va_arg(*(arguments), int), 1);
	else if (format[*(i)] == 'u')
		*(j) = *(j) + ft_unsigned_putnbr(va_arg(*(arguments), int), 1);
	else if (format[*(i)] == 'x')
		*(j) = *(j) + ft_putnbr_base_lower(va_arg(*(arguments), unsigned int));
	else if (format[*(i)] == 'X')
		*(j) = *(j) + ft_putnbr_base_upper(va_arg(*(arguments), unsigned int));
	if (format[*(i)] == '%')
	{
		write(1, "%", 1);
		*(j) = *(j) + 1;
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	va_list	arguments;

	va_start(arguments, format);
	i = 0;
	j = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
			j++;
		}
		if (format[i] == '%')
		{
			i++;
			ft_flags(format, &i, &j, &arguments);
		}
		i++;
	}
	va_end(arguments);
	return (j);
}
