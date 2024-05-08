CC = gcc
SRC = main6.c p_ut.c s_ut.c _printf.c
OBJ = $(SRC:%.c=%.o)
NAME = printf
RM = rm
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format -g

all: $(OBJ) main.h
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	$(MAKE) oclean
clean:
	$(RM) -f *~ .*.*sw* .*.*swo* $(NAME)
oclean:
	$(RM) -f $(OBJ)
fclean: oclean
	$(RM) -f *~ .*.*sw* .*.*swo* $(NAME)
re: fclean all
