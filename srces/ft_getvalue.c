/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 09:18:51 by fredon            #+#    #+#             */
/*   Updated: 2016/03/15 09:02:14 by fredon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

char	*ft_pass(char *line)
{
	while (*line && *line != ' ')
		line++;
	while (*line && *line == ' ')
		line++;
	if (!*line)
		return (NULL);
	return (line);
}

int		ft_atoi(char *str)
{
	long int	i;
	int			c;
	int			sign;

	i = 0;
	c = 0;
	sign = 1;
	if ((str[c] == '-' && (sign = -1)) || str[c] == '+')
		c++;
	while (str[c] <= '9' && str[c] >= '0')
	{
		i = i * 10;
		i = i + str[c] - 48;
		c++;
	}
	i = sign * i;
	if ((str[c] && str[c] != ' ') || i > 2147483647 || i < -2147483648)
	{
		write(2, "Wrong map, you should have valid numbers here\n", 46);
		exit(0);
	}
	return ((int)i);
}

int		ft_getvalue(char *line)
{
	int		len;

	len = 0;
	while (line[len] && line[len] != ' ')
		len++;
	if (len >= 12 || len == 0)
	{
		write(2, "Wrong map, you should have valid numbers here\n", 46);
		exit(0);
	}
	return (ft_atoi(line));
}
