/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 10:09:56 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/25 17:44:22 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst)
	{
		if ((*alst)->next)
			ft_lstdel(&((*alst)->next), del);
		ft_lstdelone(alst, del);
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

	first = ft_lstnew("BEGIN", 6);
	first->next = ft_lstnew("END", 4);
	alst = &first;
	next = first->next;
	print(*alst);
	ft_lstdel(alst, ft_bzero);
	print(first);
	return (0);
}

#endif
