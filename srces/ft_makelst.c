/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 08:55:30 by fredon            #+#    #+#             */
/*   Updated: 2016/03/16 14:58:29 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

t_list		*ft_lstnext(t_list *lst, char *line)
{
	t_list	*next;

	if ((next = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	next->x = lst->x + 1;
	next->y = lst->y;
	next->first = lst->first;
	next->next = NULL;
	next->value = ft_getvalue(line);
	lst->next = next;
	return (next);
}

t_list		*ft_lstbot(t_list *lst, char *line)
{
	t_list	*next;
	t_list	*up;

	up = lst->first;
	while (up->y != lst->y)
		up = up->next;
	if ((next = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	next->x = 0;
	next->y = lst->y + 1;
	next->first = lst->first;
	next->next = NULL;
	next->value = ft_getvalue(line);
	lst->next = next;
	return (next);
}

t_list		*ft_include(t_list *lst, char *line)
{
	int		x;

	x = 0;
	while (line)
	{
		while (lst->next)
			lst = lst->next;
		if (lst == lst->first && x == 0)
			lst->value = ft_getvalue(line);
		else if (x == 0)
			lst = ft_lstbot(lst, line);
		else
			lst = ft_lstnext(lst, line);
		line = ft_pass(line);
		x = 1;
	}
	return (lst);
}

t_list		*ft_initlist(t_list *lst)
{
	lst->x = 0;
	lst->y = 0;
	lst->xr = 0;
	lst->yr = 0;
	lst->value = 0;
	lst->next = NULL;
	lst->first = lst;
	return (lst);
}

t_list		*ft_makelst(t_list *lst, int fd, char *line)
{
	lst = ft_initlist(lst);
	while (get_next_line(fd, &line))
		lst = ft_include(lst, line);
	return (lst->first);
}
