#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	len;

	len = (unsigned int)ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = 0;
	while (len--)
		str[len] = f(len, s[len]);
	return (str);
}
