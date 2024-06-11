# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchapard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 15:50:00 by lchapard          #+#    #+#              #
#    Updated: 2023/11/27 16:52:19 by lchapard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = get_next_line.c get_next_line_utils.c
HEADERS = get_next_line.h
OBJS = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $@ $^

%.o : %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
