#include "../include/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	size;

	size = ft_strlen(s);
	if (start > size)
		return (ft_strdup(""));
	if (len > size - start)
		len = size - start;
	subs = malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	ft_strlcpy(subs, s + start, len + 1);
	return (subs);
}
