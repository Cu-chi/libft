/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:08:21 by equentin          #+#    #+#             */
/*   Updated: 2025/11/07 13:47:31 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	size_t			count;
	size_t			i;
	char			*sub;

	s_len = 0;
	while (s[s_len++])
		;
	if (start >= s_len)
		return (ft_calloc(1, sizeof(char)));
	count = 0;
	while (s[start + count] && count++ < len);
	sub = (char *)malloc(sizeof(char) * (count + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && count--)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*s = "search the substring and dup";
	char		*sub;

	sub = ft_substr(s, 110, 9);
	printf("RESULT : %s (ptr = %p)", sub, &sub);
	free(sub);
}
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	size;
	char	*join;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	size = (s1_len + s2_len + 1);
	join = (char *)malloc(sizeof(char) * size);
	if (join == NULL)
		return (NULL);
	ft_strlcpy(join, s1, size);
	ft_strlcat(join, s2, size);
	return (join);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*s1 = "hello";
	const char	*s2 = "world";
	char		*join;

	join = ft_strjoin(s1, s2);
	printf("RESULT : %s\n", join);
	free(join);
}
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	s1_len;
	size_t	i;
	char	*trim;

	s1_len = ft_strlen(s1);
	start = 0;
	while (start < s1_len && ft_strchr(set, s1[start]) != NULL)
		start++;
	end = s1_len;
	while (start < end && ft_strchr(set, s1[end]) != NULL)
		end--;
	end++;
	trim = (char *)malloc(sizeof(char) * (end - start + 1));
	if (trim == NULL)
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		trim[i] = s1[start + i];
		i++;
	}
	trim[i] = '\0';
	return (trim);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*s1 = "	,a,b , cc,    	";
	const char	*s2 = "\t ,";
	char		*trim;

	trim = ft_strtrim(s1, s2);
	printf("RESULT : %s\n", trim);
	free(trim);
}
*/

static size_t	ft_split_nb_strs(char const *s, char c)
{
	size_t	nb_strs;
	char	in_str;

	nb_strs = 0;
	in_str = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (in_str == 0)
				nb_strs++;
			in_str = 1;
		}
		else
			in_str = 0;
		s++;
	}
	return (nb_strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	nb_strs;
	size_t	i;
	size_t	start;
	size_t	end;

	nb_strs = ft_split_nb_strs(s, c);
	strs = (char **)malloc(sizeof(char *) * (nb_strs + 1));
	if (strs == NULL)
		return (NULL);
	start = 0;
	i = 0;
	while (i < nb_strs)
	{
		while (s[start++] == c)
			;
		end = start;
		while (s[end++] != c)
			;
		strs[i] = ft_substr(s, start - 1, end - start);
		if (strs[i] == NULL)
			return (NULL);
		start = end;
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*s1 = "A, B,B,B E D DD Q     ";
	char		s2;
	char		**s;
	int			i;

	s2 = ' ';
	i = 0;
	s = ft_split(s1, s2);
	while (s[i] != NULL)
	{
		printf("%s %p\n", s[i], s[i]);
		i++;
	}
		printf("%s %p\n", s[i], s[i]);
}
*/
