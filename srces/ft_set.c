/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:07:30 by fredon            #+#    #+#             */
/*   Updated: 2016/03/17 14:01:04 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	ft_blue(t_graph *graph)
{
	graph->set = 1;
	graph->nope = 0;
	ft_erase(graph);
}

void	ft_red(t_graph *graph)
{
	graph->set = 5;
	graph->nope = 0;
	ft_erase(graph);
}

void	ft_green(t_graph *graph)
{
	graph->set = 3;
	graph->nope = 0;
	ft_erase(graph);
}

void	ft_white(t_graph *graph)
{
	graph->set = 0;
	graph->nope = 0;
	ft_erase(graph);
}

void	ft_nocolor(t_graph *graph)
{
	graph->nope = 1;
	ft_erase(graph);
}
