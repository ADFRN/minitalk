# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afournie <afournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 17:14:16 by afournie          #+#    #+#              #
#    Updated: 2026/01/21 11:23:12 by afournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += -s

NAME_SERVER = server
NAME_CLIENT = client
CC          = cc
CFLAGS      = -Wall -Werror -Wextra -g3

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
INC         = -I includes -I $(LIBFT_DIR)

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)


all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(LIBFT) $(OBJS_SERVER)
	@$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) -o $(NAME_SERVER)
	@echo "✓ Server compiled"

$(NAME_CLIENT): $(LIBFT) $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) -o $(NAME_CLIENT)
	@echo "✓ Client compiled"

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME_SERVER)
	@rm -f $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
