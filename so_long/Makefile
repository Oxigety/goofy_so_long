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

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
XFLAGS = -L ./minilibx-linux -lmlx -lXext -lX11 

MDIR = ./minilibx-linux
PRINTDIR = ./ft_printf
GNLDIR = ./get_next_line
SRCS = ./src/events.c ./src/is_valid.c ./src/map_checks.c ./src/print_window.c ./src/set_map.c ./src/solong_utils.c
PRSRC = ./ft_printf/ft_print_adress.c ./ft_printf/ft_print_base.c ./ft_printf/ft_print_char.c ./ft_printf/ft_print_int.c \
./ft_printf/ft_print_pointer.c ./ft_printf/ft_print_string.c ./ft_printf/ft_write_nb.c
GNLSRC = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
HEADERS = ./include/map.h

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(PRSRC) $(GNLSRC)
	$(MAKE)	-C $(PRINTDIR)
	$(MAKE) -C $(MDIR)
	$(MAKE) -C $(GNLDIR)
	$(CC) $^ $(XFLAGS) $(CFLAGS) $(PRINTDIR)/printf.a $(MDIR)/libmlx.a $(GNLDIR)/gnl.a -o $(NAME)

%.o:%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	cd $(MDIR) && make clean
	cd $(PRINTDIR) && make clean	
	cd $(GNLDIR) && make clean
	rm -rf $(OBJS)

fclean : clean
	cd $(MDIR) && make clean
	cd $(PRINTDIR) && make fclean
	cd $(GNLDIR) && make fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re