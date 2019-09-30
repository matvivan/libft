/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:07:20 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/26 20:53:24 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_addnew(char **arr, size_t size, char *elem)
{
	char	**new;
	size_t	i;

	i = 0;
	new = (char **)malloc((size + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	if (arr)
	{
		while (i < size)
		{
			new[i] = ft_strsub(arr[i], 0, ft_strlen(arr[i]));
			i++;
		}
		free(arr);
	}
	new[i] = elem;
	return (new);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		len;
	int		size;

	new = NULL;
	size = 0;
	if (s)
	{
		len = 0;
		while (*s != '\0')
		{
			if (*s != c)
			{
				if (ft_strchr(s, c))
					len = ft_strchr(s, c) - s;
				else
					len = ft_strchr(s, '\0') - s;
				new = ft_addnew(new, size++, ft_strsub(s, 0, len));
				s += --len;
			}
			s++;
		}
	}
	new = ft_addnew(new, size, NULL);
	return (new);
}
