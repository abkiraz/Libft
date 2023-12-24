#include "../include/libft.h"

static int	wordcount(const char *s, char c)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			wc++;
		while (s[i] != c && s[i])
			i++;
	}
	return (wc);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		size;
	int		i;
	int		j;

	size = wordcount(s, c);
	str = malloc(sizeof(char *) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (*s == c)
			s++;
		j = 0;
		while (s[j] != c && s[j])
			j++;
		str[i++] = ft_substr(s, 0, j);
		s += j;
	}
	str[i] = 0;
	return (str);
}
