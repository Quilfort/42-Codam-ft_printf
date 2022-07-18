#include "libft.h"

int	ft_putstr_fd(char *str, int fd)
{
	int	len;

	if (!str)
		return (write(fd, "(null)", 6));
	len = ft_strlen(str);
	return (write(fd, str, len));
}
