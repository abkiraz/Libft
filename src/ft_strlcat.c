#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	j = ft_strlen(dst);
	srclen = ft_strlen(src);
	dstlen = j;
	if (dstlen >= size)
		return (srclen + size);
	while (j < size - 1 && src[i])
	{
		dst[j] = src[i];
		j++ ;
		i++;
	}
	dst[j] = 0;
	return (dstlen + srclen);
}
