/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equentin <equentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:16:17 by equentin          #+#    #+#             */
/*   Updated: 2025/11/10 17:27:30 by equentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		ft_lstdelone(current, del);
		current = next;
	}
	*lst = NULL;
}
/*
static void	test(void *a)
{
	printf("contenu %s\n", (char *)a);
	//free(a);
}

int	main(void)
{
	t_list	*nl;
	char	*a;
	char	*b;
	char	*c;
	char	*d;

	nl = ft_lstnew("test");
	ft_lstadd_front(&nl, ft_lstnew("new"));
	ft_lstadd_front(&nl, ft_lstnew("new2"));
	ft_lstadd_front(&nl, ft_lstnew("new3"));
	ft_lstclear(&nl, &test);
	return (0);
}
*/
