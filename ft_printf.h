#ifndef FT_PRINTF_H
# define	FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int					ft_printf(const char *format, ...);
int					ft_unsigned_putnbr(unsigned int n, int fd);
unsigned long long	ft_putnbr_base_lower(unsigned long long n);
unsigned long long	ft_putnbr_base_upper(unsigned long long n);

#endif