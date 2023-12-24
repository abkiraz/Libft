#include "../include/libft.h"

void	*ft_memset(void *str, int value, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (0 < len--)
	{
		*ptr = value;
		ptr++;
	}
	return (str);
}
