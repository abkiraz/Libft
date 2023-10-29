#include "../include/libft.h"

size_t	ft_strlen(const char *str)
{
	const char	*begin;

	begin = str;
	while (*begin)
	{
		begin++;
	}
	return (begin - str);
}
