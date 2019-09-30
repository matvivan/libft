/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:45:21 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/25 16:31:36 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
	}
}

#ifdef TEST

static void	print(t_list *lst)
{
	if (lst)
	{
		ft_putnbr(lst->content_size);
		ft_putendl(lst->content);
		if (lst->next)
			print(lst->next);
	}
}

static int	main(void)
{
	t_list	**alst;
	t_list	*first;
	t_list	*next;

	first = ft_lstnew("EWRREW", 7);
	first->next = ft_lstnew("qweqwe", 6);
	next = first->next;
	alst = &first;
	print(*alst);
	ft_lstdelone(alst, ft_bzero);
	print(next);
	return (0);
}

#endif
