#include <stdlib.h>

static int	lenstr(const char *str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	res = malloc((lenstr(s1) + lenstr(s2) + 2) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = ' ';
	i = 0;
	while (s2[i] != 0)
	{
		res[lenstr(s1) + i + 1] = s2[i];
		i++;
	}
	res[lenstr(s1) + lenstr(s2) + 1] = 0;
	return (res);
}

static int	lenstr(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}