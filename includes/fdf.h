/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 13:18:31 by fredon            #+#    #+#             */
/*   Updated: 2016/03/17 14:01:19 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_list
{
	int				x;
	int				y;
	int				xr;
	int				yr;
	int				value;
	int				step;
	struct s_list	*next;
	struct s_list	*first;
}					t_list;

typedef struct		s_graph
{
	void			*mlx;
	void			*win;
	t_list			*lst;
	void			*img;
	char			*data;
	int				size;
	int				endian;
	int				color;
	int				set;
	int				max;
	int				min;
	int				diff;
	int				nope;
}					t_graph;

t_list				*ft_makelst(t_list *lst, int fd, char *line);
int					ft_getvalue(char *line);
char				*ft_pass(char *line);
t_list				*ft_zoom(t_list *lst);
void				ft_draw(t_list *lst, t_graph *graph);
int					ft_colr(t_graph *graph, t_list *lst, t_list *next);
int					ft_abs(int x);
void				ft_blue(t_graph *graph);
void				ft_red(t_graph *graph);
void				ft_green(t_graph *graph);
void				ft_white(t_graph *graph);
void				ft_nocolor(t_graph *graph);
void				ft_erase(t_graph *graph);
void				ft_up(t_graph *graph);
void				ft_down(t_graph *graph);
void				ft_left(t_graph *graph);
void				ft_right(t_graph *graph);
t_graph				*ft_minmax(t_graph *graph, t_list *lst);

#endif
