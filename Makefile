# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 10:20:58 by nfukuma           #+#    #+#              #
#    Updated: 2022/07/19 00:03:11 by nfukuma          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_printf.c ft_input_utils.c ft_put_c_s.c ft_put_d_i.c \
					ft_put_u.c ft_put_x.c ft_put_o.c ft_put_p.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
CPPFLAGS		+= -I./libft/
RM				= rm -f

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				make -C ./libft
				cp libft/libft.a $(NAME)
				ar rcs $@ $^

clean:
				make clean -C ./libft
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				make fclean -C ./libft
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:

.PHONY:			all clean fclean re
