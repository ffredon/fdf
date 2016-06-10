/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 08:24:33 by fredon            #+#    #+#             */
/*   Updated: 2016/03/16 16:12:31 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int		ft_abs(int nb)
{
	if (nb == -2147483648)
		exit(0);
	if (nb >= 0)
		return (nb);
	return (-nb);
}

int		ft_moreof(int x, int y)
{
	if (ft_abs(x) >= ft_abs(y))
	{
		if (y)
			return ((x / ft_abs(y)));
		return (x);
	}
	if (x > 0)
		return (1);
	return (-1);
}

int		ft_pos(int x, int i)
{
	if (i > 0)
		x = x + 1;
	else
		x = x - 1;
	return (x);
}

void	ft_line(t_list *lst, t_list *nxt, t_graph *g, int x)
{
	int		y;
	int		i;
	int		j;
	int		c;

	y = lst->yr - lst->value;
	i = ft_moreof((nxt->xr + nxt->value) - x, ((nxt->yr - nxt->value) - y));
	j = ft_moreof((nxt->yr - nxt->value) - y, ((nxt->xr + nxt->value) - x));
	while (x != (nxt->xr + nxt->value) || y != (nxt->yr - nxt->value))
	{
		c = 0;
		while (c < ft_abs(i) && x != (nxt->xr + nxt->value) && (c = c + 1))
		{
			g->color = ft_colr(g, lst, nxt);
			ft_memcpy(&g->data[((x = ft_pos(x, i)) * 4) + (y * g->size)], \
					&g->color, (size_t)(sizeof(int)));
		}
		c = 0;
		while (c < ft_abs(j) && y != (nxt->yr - nxt->value) && (c = c + 1))
		{
			g->color = ft_colr(g, lst, nxt);
			ft_memcpy(&g->data[(x * 4) + ((y = ft_pos(y, j)) * g->size)], \
				&g->color, (size_t)(sizeof(int)));
		}
	}
}

void	ft_draw(t_list *lst, t_graph *graph)
{
	t_list	*next;
	int		x;

	x = lst->xr + lst->value;
	lst->step = 0;
	if (lst->next && lst->next->x)
		next = lst->next;
	else if (!lst->next)
		return ;
	if (lst->next->x)
		ft_line(lst, next, graph, x);
	next = lst->next;
	while (next->next && next->x != lst->x)
		next = next->next;
	if (next->x != lst->x)
		return ;
	lst->step = 0;
	ft_line(lst, next, graph, x);
}
