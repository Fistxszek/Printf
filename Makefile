CC = cc
CFLAGS = -Wall -Wextra -Werror -I./includes/
AR = ar
ARFLAGS = rcs
SRC = ft_printf.c \
srcs/printer_char.c \
srcs/printer_hex.c \
srcs/printer_int.c \
srcs/printer_pointer.c \
srcs/printer_string.c \
srcs/printer_unsigned.c
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