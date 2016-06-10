# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fredon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/07 08:56:09 by fredon            #+#    #+#              #
#    Updated: 2016/03/17 12:32:05 by fredon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

SRCS	=	srces/ft_makelst.c \
			srces/ft_getvalue.c \
			srces/ft_zoom.c \
			srces/ft_draw.c \
			srces/ft_colr.c \
			srces/ft_set.c \
			srces/ft_move.c \
			srces/main.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

LIBFT	=	libft.a

LIBDIR	=	libft

CFLAGS	=	-Wall -Wextra -Werror

CGRAPH	=	-lmlx -framework OpenGL -framework AppKit

RM		=	rm -f

.PHONY	:	re clean fclean all

all		:	$(NAME)

$(NAME)	:	lib $(OBJS)
		@($(CC) $(CFLAGS) $(CGRAPH) -o $(NAME) $(OBJS) $(LIBDIR)/$(LIBFT))

%.o		:	%.c
		$(CC) $(CFLAGS) -o $@ -c $^ -I includes/

lib		:
		make -C $(LIBDIR)

libcl	:
		make -C $(LIBDIR) clean

libfcl	:
		make -C $(LIBDIR) fclean

clean	:	libcl
		$(RM) $(OBJS)

fclean	:	libfcl
		$(RM) $(OBJS)
		$(RM) $(NAME)

re		:	fclean all
