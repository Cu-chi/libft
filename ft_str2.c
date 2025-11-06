/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:13:57 by equentin          #+#    #+#             */
/*   Updated: 2025/11/06 10:16:12 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_lenght;

	little_lenght = 0;
	while (little[little_lenght])
		little_lenght++;
	if (little_lenght == 0)
		return ((char *)big);
	i = 0;
	while (i <= len && big[i])
	{
		j = 0;
		while (big[i] == little[j] && i <= len)
		{
			if (big[i] == '\0')
				return ((char *)(big + i - j));
			j++;
			i++;
		}
		i -= j;
		i++;
	}
	return (NULL);
}

/*
#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	const char	*big = "h";
	const char	*little = "h";

	printf("%s\n", ft_strnstr(big, little, 1));
	printf("%s", strnstr(big, little, 1));
	return (0);
}
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/*
#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	const char	*big = "helloo";
	const char	*little = "hello";

	printf("%d\n", ft_strncmp(big, little, 5));
	printf("%d", strncmp(big, little, 5));
	return (0);
}
*/

char	*ft_strdup(const char *s)
{
	size_t	lenght;
	size_t	i;
	char	*d;

	lenght = 0;
	while (s[lenght])
		lenght++;
	d = (char *)malloc(sizeof(char) * (lenght + 1));
	if (d == NULL)
		return (NULL);
	i = 0;
	while (i < lenght)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*s = "helloo";
	char		*d1;
	char		*d2;

	d1 = ft_strdup(s);
	d2 = strdup(s);
	printf("%s\n", d1);
	printf("%s", d2);
	free(d1);
	free(d2);
	return (0);
}
*/