#include "../include/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = (unsigned int)ft_strlen(s);
	while (i--)
		f(i, &s[i]);
}
