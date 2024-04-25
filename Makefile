CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
SRC = ft_printf.c \
printer_char.c \
printer_hex.c \
printer_int.c \
printer_pointer.c \
printer_string.c \
printer_unsigned.c
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