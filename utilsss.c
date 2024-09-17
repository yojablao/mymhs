#include "minishell.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if(!str)
	{
		printf("wazbi\n");
		return 0;
	}
	i = 0;
	while (str[i])
		i++;
	return (i);
}
size_t ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ls;
	size_t	ld;
	size_t	l;
	size_t	i;

	if (!size)
		return (ft_strlen(src));
	ld = ft_strlen(dst);
	ls = ft_strlen(src);
	l = ld;
	i = 0;
	if (size < ld)
		return (size + ls);
	if (size <= ld)
		return (ls + size);
	while (l < (size -1) && src[i] != '\0')
		dst[l++] = src[i++];
	dst[l] = '\0';
	if (ld < size)
		return (ld + ls);
	else
		return (size + ls);
}
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src [i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if(!str1 || !str2)
		return(-1);
	while (i < n && (str2[i] || str1[i]))
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
