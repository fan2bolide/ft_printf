NAME = libftprintf.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC			=	ft_printf.c			\
				ft_print_hexa.c		\
				ft_print_int.c		\
				ft_putnbr_base.c	\

OBJ = $(SRC:.c=.o)

all	: lib $(NAME)

$(NAME): $(OBJ)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJ)

%.o : %.c Makefile libft/libft.h ft_printf.h
	cc -Wall -Wextra -Werror -c $< -I libft

lib : $(LIBFT)
	make -C $(LIBFT_PATH)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re lib