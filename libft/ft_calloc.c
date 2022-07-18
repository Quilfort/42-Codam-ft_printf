#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	pointer = malloc(count * size);
	if (pointer == NULL)
	{
		return (pointer);
	}
	ft_bzero(pointer, size * count);
	return (pointer);
}
