#include "../include/libft.h"

void	*ft_memchr(const void *dst, int c, size_t n)
{
	unsigned char	c1;
	unsigned char	*str;

	c1 = (unsigned char)c;
	str = (unsigned char *)dst;
	while (n-- > 0)
	{
		if (*str == c1)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
