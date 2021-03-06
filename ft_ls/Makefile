# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/21 18:23:32 by malexand          #+#    #+#              #
#    Updated: 2017/01/20 23:26:00 by skyzie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = ft_ls

export DEBUG = no
CC = clang
OS := $(shell uname -s)
MAKEFLAGS += --silent

ifeq ($(DEBUG), yes)
	CFLAGS = -Wall -Werror -Wextra -g -ggdb -fsanitize=address -v
else
	CFLAGS = -Wall -Werror -Wextra
endif

# Link lib : "-L FOLDER -lXXX" where XXX = libXXX.a

ifeq ($(OS), Linux)
	LFLAGS = -L./libft -lft
else
	LFLAGS = -L./libft -lft
endif

OUT_DIR = objs
SRC_DIR = srcs
INC_DIR = incs

SDIR =		./srcs/
SRCS =		$(shell ls $(SRC_DIR))
SRCC =		$(addprefix $(SDIR),$(SRCS))

INCLUDE = -I $(INC_DIR)

ODIR =		./objs/
OBJS =		$(SRCS:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))

all: directories $(EXEC)

$(EXEC): $(OBCC)
ifeq ($(OS), Linux)
	@echo -e "\x1B[34mLibft:\x1B[0m\n"
	@make -C ./libft
	@echo -e "\x1B[34m$(EXEC):\x1B[0m"
	@clang $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) $(LFLAGS)
	@echo -e "\x1b[36m  + Compile program:\x1B[0m $@"
else
	@echo "\x1B[34mLibft:\x1B[0m\n"
	@make -C ./libft
	@echo "\x1B[34m$(EXEC):\x1B[0m"
	@$(CC) $(CFLAGS) -o $@ $(OBCC) $(INCLUDE) $(LFLAGS) -lpthread -D_REENTRANT
	@echo "\x1b[36m  + Compile program:\x1B[0m $@"
	@echo "\x1B[31m\c"
	@norminette srcs/* incs/* | grep -B 1 "Error" || true
	@echo "\x1B[0m\c"
endif

$(ODIR)%.o: $(SDIR)%.c
	@$(CC) $^ $(CFLAGS) -c -o $@ $(INCLUDE)
ifeq ($(OS), Linux)
	@echo -e "\r\x1B[32m  + Compile:\x1B[0m $(notdir $^)"
else
	@echo "\r\x1B[32m  + Compile:\x1B[0m $(notdir $^)"
endif

directories: ${OUT_DIR} ${SRC_DIR} ${INC_DIR}

${OUT_DIR}:
	@mkdir -p ${OUT_DIR}

${SRC_DIR}:
	@mkdir -p ${SRC_DIR}

${INC_DIR}:
	@mkdir -p ${INC_DIR}

clean:
	@make -C ./libft clean
	@rm -rf $(OUT_DIR)
ifeq ($(OS), Linux)
	@echo -e "\x1B[31m  - Remove:\x1B[0m objs"
else
	@echo "\x1B[31m  - Remove:\x1B[0m objs"
endif

fclean: clean
	@make -C ./libft delete
	@rm -f $(EXEC)
ifeq ($(OS), Linux)
	@echo -e "\x1B[31m  - Remove:\x1B[0m $(EXEC)"
else
	@echo "\x1B[31m  - Remove:\x1B[0m $(EXEC)"
endif

re: fclean all

run: all
	@./$(EXEC) Mandelbrot

cleanlib:
	@make -C ./libft fclean


.PHONY: all clean fclean re run directories cleanlib
