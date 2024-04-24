CC = cc
CFLAGS = -Wall -Wextra -Werror -I.libft/includes/
AR = ar
ARFLAGS = rcs
SRC = ft_printf.c \
hex_printer.c \
unsigned_printer.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a 

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C ./libft 
	@ cp libft/libft.a $(NAME)
	@$(AR) $(ARFLAGS) $@ $(OBJ)
	@ranlib $@

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(MAKE) clean -C ./libft
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re