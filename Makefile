NAME = ft_printf.a

LIB = libft/libft.a

SRC			=	ft_printf.c			\
				ft_print_hexa.c		\
				ft_print_int.c		\
				ft_putnbr_base.c	\

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all	: $(NAME) 

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o : %.c Makefile libft.h ft_printf.h
	cc -Wall -Wextra -Werror -c $<

bonus : $(BONUS_OBJ)
	ar -rcs $(NAME) $(BONUS_OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re