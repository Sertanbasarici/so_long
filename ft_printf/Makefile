NAME = ft_printf.a
SRCS = ft_hex.c ft_printf.c ft_putchar.c \
		ft_putnbr.c ft_putstr.c \
		ft_void_ptr.c
OBJS = $(SRCS:.c=.o)
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
all: $(NAME)
$(NAME): $(OBJS)
				$(CC) $(FLAGS) -c $(SRCS)
				ar rc $(NAME) $(OBJS)
clean:
				$(RM) $(OBJS)
fclean:
				$(RM) $(NAME) $(OBJS)
re: fclean all
.PHONY: all clean fclean re
