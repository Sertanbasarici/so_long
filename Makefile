NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := main.c map.c deep_first_search.c image.c
PRINTF := ft_printf/*c
GETNEXTLINE := get_next_line/*c
LIBRARY := -Lminilibx-linux -lmlx_linux -LX11 -lXext
MINILIBX := minilibx-linux/


all:
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(PRINTF) $(LIBRARY) -o $(NAME)

clean:


fclean: clean
		make clean -C $(MINILIBX)
		rm -rf $(NAME)


re: fclean all
