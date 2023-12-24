#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;
	char	*str;

	str = (char *)haystack;
	n_len = ft_strlen(needle);
	i = 0;
	if (n_len == 0 || haystack == needle)
		return (str);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] && needle[j] 
			&& haystack[i + j] == needle[j] && (i + j) < len)
			j++;
		if (j == n_len)
			return (str + i);
		i++;
	}
	return (0);
}
