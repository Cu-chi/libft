/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:08:21 by equentin          #+#    #+#             */
/*   Updated: 2025/11/06 15:32:54 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	size_t			count;
	char			*sub;

	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		return (malloc(0));
	count = 0;
	while (s[count] && count < len)
		count++;
	sub = (char *)malloc(sizeof(char) * (count + 1));
	if (sub == NULL)
		return (NULL);
	count = 0;
	while (s[start] && len--)
		sub[count++] = s[start++];
	sub[count] = '\0';
	return (sub);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*s = "search the substring and dup";
	char		*sub;
	char		*or_sub;

	sub = ft_substr(s, 11, 9);
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

static size_t	ft_strtrim_count_size(char const *s1, char const *set)
{
	size_t	i;
	size_t	fsize;
	char	beginning;

	beginning = 1;
	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == NULL)
		{
			fsize++;
			if (beginning == 1)
				beginning = 0;
		}
		i++;
	}
	while (ft_strchr(set, s1[i--]) != NULL) // --i plutot
		fsize--;
	return (fsize);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	fsize;
	size_t	i;
	char	*trim;
	char	beginning;
	int		last_index;

	fsize = ft_strtrim_count_size(s1, set);
	trim = (char *)malloc(sizeof(char) * (fsize + 1));
	if (trim == NULL)
		return (NULL);
	i = 0;
	beginning = 1;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == NULL)
			last_index = i;
			beginning = 0;
		i++;
	}
	i = 0;
	while (ft_strchr(set, s1[i]) != NULL)
		i++;
	
	return (trim);
}

#include <stdio.h>

int	main(void)
{
	const char	*s1 = "			trim 	this 	string			";
	const char	*s2 = "\t ";
	char		*trim;

	trim = ft_strtrim(s1, s2);
	printf("RESULT : %s\n", trim);
	free(trim);
}
