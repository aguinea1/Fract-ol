# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguinea <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 02:52:41 by aguinea           #+#    #+#              #
#    Updated: 2025/02/08 12:29:06 by aguinea          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
BONUS = $(NAME)_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g  -fsanitize=address
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lX11 -lXext -lm

SRC_DIR = mandatory/src
OBJ_DIR = mandatory/obj
LIBFT_DIR = mandatory/libft
INCLUDE_DIR = mandatory/include
SRC_BONUS_DIR = bonus/src
OBJ_BONUS_DIR = bonus/obj
MLX_DIR = mlx

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/fractol_utils.c \
       $(SRC_DIR)/init_minilibx.c	\
	   $(SRC_DIR)/draw_fractal.c	\
	   $(SRC_DIR)/key_and_mouse.c	\
	   $(SRC_DIR)/mandelbrot.c		\
	   $(SRC_DIR)/julia.c			\
	   $(SRC_DIR)/colors.c			\
	   $(SRC_DIR)/burning_ships.c

SRCS_BONUS = $(SRC_BONUS_DIR)/main.c \
			 $(SRC_BONUS_DIR)/fractol_utils.c \
			 $(SRC_BONUS_DIR)/init_minilibx.c	\
			 $(SRC_BONUS_DIR)/draw_fractal.c	\
			 $(SRC_BONUS_DIR)/key_and_mouse.c	\
			 $(SRC_BONUS_DIR)/mandelbrot.c		\
			 $(SRC_BONUS_DIR)/julia.c			\
			 $(SRC_BONUS_DIR)/colors.c			\
			 $(SRC_BONUS_DIR)/burning_ships.c


OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_BONUS_DIR)/%.o)
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a
MLX1 = $(MLX_DIR)/libmlx_Linux.a
HEADER = $(INCLUDE_DIR)/fractol.h $(MLX_DIR)/mlx.h

all: $(LIBFT) $(MLX) $(OBJ_DIR) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

$(MLX1):
	@make -C $(MLX_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) Makefile | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(MLX_DIR) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(MLX) Makefile
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)
	@echo "Executable created: $(NAME)"
	
bonus: $(LIBFT) $(MLX) $(OBJ_BONUS_DIR) $(OBJS_BONUS) Makefile
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)_bonus
	@echo "Executable created: $(NAME)_bonus"

$(OBJ_BONUS_DIR):
	@mkdir -p $(OBJ_BONUS_DIR)

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c $(HEADER) Makefile | $(OBJ_BONUS_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(MLX_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@echo "Object files removed"

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@echo "Executable removed"

re: fclean all

.PHONY: all clean fclean re
