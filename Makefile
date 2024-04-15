CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
SRC = 
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a 

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./Work_Libft 
	@$(AR) $(ARFLAGS) $@ $(OBJ)
	@ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(MAKE) clean -C ./Work_Libft
	@rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./Work_Libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re