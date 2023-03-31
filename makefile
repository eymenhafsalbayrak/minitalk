NAME = libft.a
LIBFT = libft
FLAG = -Wall -Wextra -Werror
all: $(NAME)
		gcc $(FLAG) server.c $(NAME) -o server
		gcc $(FLAG) client.c $(NAME) -o client
$(NAME): $(LIBFT)
		make -C $(LIBFT)
		cp libft/libft.a .
clean:
		make clean -C $(LIBFT)
fclean: clean
		make fclean -C $(LIBFT)
		rm -rf $(NAME)
		rm -rf server client
re: fclean all

.PHONY: clean fclean all