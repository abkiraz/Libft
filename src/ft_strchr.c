#include "../include/libft.h"

char	*ft_strchr(const char *s1, int c)
{
	char	*str;
	char	c1;

	c1 = (unsigned char)c;
	str = (char *)s1;
	while (*str != c1 && *str)
		str++;
	if (*str == c1)
		return (str);
	return (0);
}
