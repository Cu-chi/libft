/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:08:21 by equentin          #+#    #+#             */
/*   Updated: 2025/11/06 11:21:54 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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