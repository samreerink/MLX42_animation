# **************************************************************************** #
#                                                                              #
#                                                        ::::::::              #
#    Makefile                                          :+:    :+:              #
#                                                     +:+                      #
#    By: sreerink <sreerink@student.codam.nl>        +#+                       #
#                                                   +#+                        #
#    Created: 2024/11/26 17:14:08 by sreerink      #+#    #+#                  #
#    Updated: 2024/11/26 17:21:54 by sreerink      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME= 		MLX42_animation.a

HEADER=		MLX42_animation.h

RM= 		rm -f

FLAGS= 		-Wall -Werror -Wextra

SRC_DIR=	src

OBJ_DIR=	obj

SRCS=		$(addprefix $(SRC_DIR)/, init_animation.c free_animation.c \
			image.c update_animation.c)

all:		$(NAME)

OBJECT= 	$(SRCS:.c=.o)

$(NAME): 	$(OBJECT)
			ar rcs $@ $^

%.o:		%.c $(HEADER)
			$(CC) -c $(FLAGS) -o $@ $<

clean:
			$(RM) $(OBJECT)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:	all clean fclean re
