CC = gcc
SRC = main6.c utilities.c _printf.c
OBJ = $(SRC:%.c=%.o)
NAME = printf
RM = rm
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format -g

all: $(OBJ) main.h
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	$(RM) -f *~ .*.*sw* .*.*swo* $(NAME)
oclean:
	$(RM) -f $(OBJ)
fclean: oclean
	$(RM) -f *~ .*.*sw* .*.*swo* $(NAME)
re: fclean all
