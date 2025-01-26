# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilmahjou <ilmahjou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/26 16:17:47 by ilmahjou          #+#    #+#              #
#    Updated: 2025/01/26 16:17:48 by ilmahjou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = so_long
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = mlx/libmlx.a -L/usr/lib/X11 -lXext -lX11
INCLUDES = -I/usr/include -Imlx -Ilibft
LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a
SRCDIR = mandatory/
SRC = so_long.c \
      mandatory/parsing.c \
      mandatory/movements.c \
      mandatory/miscellaneous.c \
      mandatory/miscellaneous_bk.c \
      mandatory/mappings.c \
      mandatory/mapping2.c \
      mandatory/components.c \
      mandatory/free.c \
      mandatory/backtracking.c \
      mandatory/backtracking_utils.c

OBJ_DIR = obj
OBJECTS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LIBFT) $(MLX_FLAGS)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

$(OBJ_DIR)/%.o: $(SRCDIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
