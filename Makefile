CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
SRC = ft_printf.c \
hex_printer.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a 

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./Libft 
	@$(AR) $(ARFLAGS) $@ $(OBJ)
	@ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(MAKE) clean -C ./Libft
	@rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./Libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re