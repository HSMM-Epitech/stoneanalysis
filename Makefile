##
## EPITECH PROJECT, 2025
## B-CCP-400-MPL-4-1-panoramix-morgan.guichard
## File description:
## Makefile
##

NAME	= stone_analysis
SRC	=	./src/main.cpp \
		./src/analyze/analyze.cpp \
		./src/cypher/cypher.cpp \
		./src/decypher/decypher.cpp

OBJ = $(SRC:.cpp=.o)

CFLAGS = -Wall -Wextra -Werror -I./src/

CC = g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)


clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
