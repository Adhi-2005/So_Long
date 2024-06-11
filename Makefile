# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 18:10:21 by adshafee          #+#    #+#              #
#    Updated: 2024/04/15 19:06:42 by adshafee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := so_long
CC        := cc
CFLAGS    := -Wall -Wextra -Werror 

SRCS        :=      get_next_line/get_next_line.c \
                          get_next_line/get_next_line_utils.c \
                          libftprintf/ft_functions.c \
                          libftprintf/ft_hexa_pointers.c \
                          libftprintf/ft_printf.c \
                          map_utils.c \
                          map_utils2.c \
                          map_utils3.c \
                          so_long.c \
						  display_contents.c \
						  external_utils.c \
						  controls.c \
						  dfs.c \
                          utils.c
                          
OBJS := $(SRCS:.c=.o)

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

RM		    := rm -f

UNAME		:=	$(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME): ${OBJS}

			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
endif

all:		${NAME}

ifeq ($(UNAME), Darwin)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
endif

ifeq ($(UNAME), Darwin)
fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a
endif

re:			fclean all

.PHONY:		all clean fclean re