CC = gcc
SRC = noone.c
OBJ = $(SRC:%.c=%.o)
NAME = one
RM = rm
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format -g

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	$(RM) -f *~ .*.*sw* .*.*swo* $(NAME)
oclean:
	$(RM) -f $(OBJ)
fclean: oclean
	$(RM) -f *~ .*.*sw* .*.*swo* $(NAME)
re: fclean all
