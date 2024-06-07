# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 20:26:25 by adbouras          #+#    #+#              #
#    Updated: 2024/06/06 13:04:57 by adbouras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN	= \033[1;92m
YELLOW	= \033[0;93m
RED		= \033[1;91m
RESET	= \033[0;39m

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = client

B_NAME = client_bonus

SERVER = server

B_SERVER = server_bonus

N_SRC = client.c

B_N_SRC = ./bonus/client_bonus.c

S_SRC = server.c

B_S_SRC = ./bonus/server_bonus.c

HDR = minitalk.h

B_HDR = ./bonus/minitalk_bonus.h

LIBFT = libft/libft.a

FT_PRINTF = ft_printf/libftprintf.a

N_OBJ = $(N_SRC:.c=.o)

B_N_OBJ = $(B_N_SRC:.c=.o)

S_OBJ = $(S_SRC:.c=.o)

B_S_OBJ = $(B_S_SRC:.c=.o)

all: $(NAME) $(SERVER)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(N_OBJ) $(S_OBJ) $(HDR) 
	@echo "$(YELLOW)[Compiling Libraries]$(RESET)\n"
	@make -C libft
	@make -C ft_printf
	@echo "$(GREEN)[Libraries Compiled]$(RESET)\n"
	@echo "$(YELLOW)[Compiling Minitalk]$(RESET)\n"
	@$(CC) $(CFLAGS) $(N_OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME) && $(CC) $(CFLAGS) $(S_OBJ) $(LIBFT) $(FT_PRINTF) -o $(SERVER)
	@echo "$(GREEN)[Minitalk Compiled]$(RESET)\n"

$(B_NAME): $(B_N_OBJ) $(B_S_OBJ) $(B_HDR)
	@echo "$(YELLOW)[Compiling Libraries]$(RESET)\n"
	@make -C libft
	@make -C ft_printf
	@echo "$(GREEN)[Libraries Compiled]$(RESET)\n"
	@echo "$(YELLOW)[Compiling Bonus]$(RESET)\n"
	@$(CC) $(CFLAGS) $(B_N_OBJ) $(LIBFT) $(FT_PRINTF) -o $(B_NAME) && $(CC) $(CFLAGS) $(B_S_OBJ) $(LIBFT) $(FT_PRINTF) -o $(B_SERVER)
	@echo "$(GREEN)[Bonus Compiled]$(RESET)\n"

bonus: $(B_NAME) $(B_SERVER)

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@rm -f $(N_OBJ) $(S_OBJ) $(B_S_OBJ) $(B_N_OBJ)
	@echo "$(RED)[Objects Cleaned]$(RESET)\n"

fclean: clean
	@make fclean -C libft
	@make fclean -C ft_printf
	@rm -f $(NAME) $(SERVER) $(B_SERVER) $(B_NAME)
	@echo "$(RED)[EXEs Cleaned]$(RESET)\n"

re: fclean all

.PHONY: all bonus clean fclean re