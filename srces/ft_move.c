/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:12:32 by fredon            #+#    #+#             */
/*   Updated: 2016/03/15 09:03:31 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	ft_left(t_graph *graph)
{
	t_list	*lst;

	lst = graph->lst->first;
	while (1)
	{
		lst->xr = lst->xr - 10;
		if (lst->next)
			lst = lst->next;
		else
			break ;
	}
	ft_erase(graph);
}

void	ft_right(t_graph *graph)
{
	t_list	*lst;

	lst = graph->lst->first;
	while (1)
	{
		lst->xr = lst->xr + 10;
		if (lst->next)
			lst = lst->next;
		else
			break ;
	}
	ft_erase(graph);
}

void	ft_up(t_graph *graph)
{
	t_list *lst;

	lst = graph->lst->first;
	while (1)
	{
		lst->yr = lst->yr - 10;
		if (lst->next)
			lst = lst->next;
		else
			break ;
	}
	ft_erase(graph);
}

void	ft_down(t_graph *graph)
{
	t_list	*lst;

	lst = graph->lst->first;
	while (1)
	{
		lst->yr = lst->yr + 10;
		if (lst->next)
			lst = lst->next;
		else
			break ;
	}
	ft_erase(graph);
}
