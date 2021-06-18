##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile <alizee.soussan@epitech.eu>
##


SRC		=	src/main.c			\
			src/my_free_tab.c		\
			src/utils.c			\
			src/check_word.c		\
			src/error.c			\
			src/s_flag.c			\
			src/get_flags.c

NAME	=	boggle

COMPIL	=	-Llib/my -lmy

TFLAG	=	./tests/test_my_boggle.c -lcriterion --coverage -fprofile-arcs

CFLAGS	=	-I include/

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) $(CFLAGS) -Wall -Wextra

clean:
		rm -f $(OBJ)
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re:		fclean all

tests_run:
		make -C ./lib/my re
		gcc -o $(NAME) $(SRC) $(TFLAG) $(COMPIL) $(CFLAGS)
		-./$(NAME)
		gcovr --exclude tests/
		rm -f *.gcno
		rm -f *.gcda

debug:	$(OBJ)
		gcc -o $(NAME) $(SRC) -g $(CFLAGS)
