#include "printf.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*pointer;

	i = 0;
	pointer = (unsigned char *)b;
	while (i < len)
	{
		*pointer = (unsigned char)c;
		i++;
		pointer++;
	}
	return (b);
}
