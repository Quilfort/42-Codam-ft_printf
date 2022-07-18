#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*pointer;

	pointer = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (pointer[i] == (unsigned char)c)
		{
			return ((char *)&pointer[i]);
		}
		i++;
	}
	return (NULL);
}
