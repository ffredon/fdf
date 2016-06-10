/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 09:15:15 by fredon            #+#    #+#             */
/*   Updated: 2016/03/17 13:58:03 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int		ft_key_funct(int keycode, t_graph *graph)
{
	if (keycode == 0)
		ft_blue(graph);
	if (keycode == 1)
		ft_green(graph);
	if (keycode == 2)
		ft_red(graph);
	if (keycode == 3)
		ft_white(graph);
	if (keycode == 4)
		ft_nocolor(graph);
	if (keycode == 123)
		ft_left(graph);
	if (keycode == 124)
		ft_right(graph);
	if (keycode == 125)
		ft_down(graph);
	if (keycode == 126)
		ft_up(graph);
	if (keycode == 53)
		exit(0);
	return (0);
}

void	ft_print(t_graph *graph, t_list *lst)
{
	while (1)
	{
		lst->step = 0;
		graph->color = ft_colr(graph, lst, lst);
		ft_memcpy(&graph->data[((lst->xr + lst->value) * 4) + \
	((lst->yr - lst->value) * graph->size)], \
	&graph->color, (size_t)(sizeof(int)));
		ft_draw(lst, graph);
		if (lst->next)
			lst = lst->next;
		else
			break ;
	}
	mlx_put_image_to_window(graph->mlx, graph->win, graph->img, 0, 0);
}

int		ft_expose_funct(t_graph *graph)
{
	ft_print(graph, graph->lst);
	return (1);
}

int		main(int argc, char **argv)
{
	t_graph	*graph;
	int		fd;
	t_list	*lst;

	if (((graph = (t_graph*)malloc(sizeof(t_graph))) == NULL) ||
		((lst = (t_list*)malloc(sizeof(t_list))) == NULL) ||
		((fd = open(argv[1], O_RDONLY)) == -1) || (argc != 2) ||
		((lst = ft_zoom(ft_makelst(lst, fd, argv[1]))) == NULL) ||
		(close(fd) == -1))
		return (-1);
	graph->lst = lst;
	if (!graph->lst->first->next)
		return (-1);
	graph->nope = 0;
	graph = ft_minmax(graph, graph->lst->first);
	graph->mlx = mlx_init();
	graph->win = mlx_new_window(graph->mlx, 800, 800, "fdf");
	graph->img = mlx_new_image(graph->mlx, 800, 800);
	graph->data = mlx_get_data_addr(graph->img, &(graph->color),\
					&(graph->size), &(graph->endian));
	graph->set = 0;
	mlx_key_hook(graph->win, ft_key_funct, graph);
	mlx_expose_hook(graph->win, ft_expose_funct, graph);
	mlx_loop(graph->mlx);
	return (0);
}

void	ft_erase(t_graph *graph)
{
	ft_bzero(graph->data, 800 * 800 * 4);
	ft_expose_funct(graph);
}
