#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*pointer;

	i = 0;
	pointer = (unsigned char *)s;
	while (i < n)
	{
		pointer[i] = 0;
		i++;
	}
}
