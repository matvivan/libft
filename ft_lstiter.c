/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:19:20 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/25 16:10:21 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst)
	{
		if (lst->next)
			ft_lstiter(lst->next, f);
		f(lst);
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

static void	change(t_list *elem)
{
	elem->content_size -= 1;
}

static int	main(void)
{
	t_list	**alst;
	t_list	*first;
	t_list	*second;

	first = ft_lstnew("one", 4);
	second = ft_lstnew("two", 4);
	alst = &second;
	ft_lstadd(alst, first);
	print(*alst);
	ft_lstiter(*alst, change);
	print(*alst);
	return (0);
}

#endif
