/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 09:20:38 by fredon            #+#    #+#             */
/*   Updated: 2016/03/17 14:01:06 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int		ft_color(t_graph *graph, int ret)
{
	int		i;
	int		j;
	int		tmp;
	int		t;

	i = ret;
	j = 0;
	while (graph->set == 0 && j < 3)
	{
		t = 0;
		tmp = 16;
		while (t < j)
		{
			tmp = tmp * 256;
			t++;
		}
		i = i + ret * tmp;
		j++;
	}
	while (j < graph->set)
	{
		i = i * 16;
		j++;
	}
	return (i);
}

t_graph	*ft_minmax(t_graph *graph, t_list *lst)
{
	graph->min = lst->value;
	graph->max = lst->value;
	while (1)
	{
		if (lst->value <= graph->min)
			graph->min = lst->value;
		if (lst->value >= graph->max)
			graph->max = lst->value;
		if (lst->next)
			lst = lst->next;
		else
			break ;
	}
	graph->diff = graph->max - graph->min;
	return (graph);
}

int		ft_diff(int j, int i, t_graph *graph)
{
	int		diff;

	diff = graph->diff;
	if (diff == 0)
		diff = 1;
	if (graph->min < 0)
	{
		j = j - graph->min;
		i = i - graph->min;
		j = (j * 15) / diff;
		i = i * 15 / diff;
		return (j - i);
	}
	j = graph->min + (j * 15) / diff;
	i = graph->min + (i * 15) / diff;
	return (j - i);
}

int		ft_value(int i, t_graph *graph)
{
	int		diff;

	diff = graph->diff;
	if (diff == 0)
		return (15);
	if (graph->min < 0)
		return ((i - graph->min) * 15 / diff);
	i = graph->min + (i * 15) / diff;
	return (i);
}

int		ft_colr(t_graph *graph, t_list *lst, t_list *next)
{
	int		stepmax;
	int		ret;
	int		diff;

	if (graph->nope == 1)
		return (0x00FFFFFF);
	stepmax = ft_abs((lst->xr + lst->value) - (next->xr + next->value)) + \
			ft_abs((lst->yr - lst->value) - (next->yr - next->value));
	if (!stepmax)
		stepmax = 1;
	diff = ft_diff(next->value, lst->value, graph);
	ret = (lst->step * (diff) / stepmax) + ft_value(lst->value, graph);
	lst->step++;
	return (ft_color(graph, ret));
}
