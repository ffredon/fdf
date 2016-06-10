/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:53:10 by fredon            #+#    #+#             */
/*   Updated: 2016/03/16 16:09:26 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

t_list	*ft_next_zoom(t_list *lst, int max)
{
	t_list	*prev;

	prev = lst->first;
	while (prev->next != lst)
		prev = prev->next;
	lst->xr = prev->xr + max;
	lst->yr = prev->yr + max;
	return (lst);
}

t_list	*ft_botzoom(t_list *lst, int max)
{
	t_list	*up;

	up = lst->first;
	while (up->y != lst->y - 1)
		up = up->next;
	lst->xr = 0;
	lst->yr = up->yr + max;
	up = lst->first;
	while (up != lst)
	{
		up->xr = up->xr + max;
		up = up->next;
	}
	return (lst);
}

t_list	*ft_makeit(t_list *lst, int max)
{
	while (1)
	{
		if ((!lst->x) && lst->y)
			lst = ft_botzoom(lst, max);
		else if (lst->x)
			lst = ft_next_zoom(lst, max);
		if (lst->next)
			lst = lst->next;
		else
			return (lst->first);
	}
}

t_list	*ft_zoom(t_list *lst)
{
	int		max;

	max = 0;
	lst = lst->first;
	while (1)
	{
		if (lst->x > max)
			max = lst->x;
		if (lst->y > max)
			max = lst->y;
		if (lst->next)
			lst = lst->next;
		else
			break ;
	}
	if (max == 0)
		return (lst);
	max = 400 / max;
	return (ft_makeit(lst->first, max));
}
