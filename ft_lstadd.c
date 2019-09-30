/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:45:52 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/25 15:20:15 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd(t_list **alst, t_list *new)
{
	if (new)
	{
		if (*alst)
			new->next = *alst;
		*alst = new;
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
	t_list	*second;

	first = ft_lstnew("one1", 5);
	second = ft_lstnew("two", 4);
	alst = &first;
	ft_lstadd(alst, second);
	print(*alst);
	ft_lstdel(alst, ft_bzero);
	ft_lstadd(alst, second);
	print(*alst);
	return (0);
}

#endif
