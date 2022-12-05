NAME = libftprintf.a

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_H = $(LIBFT_PATH)/libft.h

LIBFT_SRC	= 	$(LIBFT_PATH)/ft_atoi.c			\
				$(LIBFT_PATH)/ft_bzero.c			\
				$(LIBFT_PATH)/ft_calloc.c		\
				$(LIBFT_PATH)/ft_isalnum.c		\
				$(LIBFT_PATH)/ft_isalpha.c		\
				$(LIBFT_PATH)/ft_isascii.c		\
				$(LIBFT_PATH)/ft_isdigit.c		\
				$(LIBFT_PATH)/ft_isprint.c		\
				$(LIBFT_PATH)/ft_isset.c			\
				$(LIBFT_PATH)/ft_isspace.c		\
				$(LIBFT_PATH)/ft_itoa.c			\
				$(LIBFT_PATH)/ft_memalloc.c		\
				$(LIBFT_PATH)/ft_memccpy.c		\
				$(LIBFT_PATH)/ft_memchr.c		\
				$(LIBFT_PATH)/ft_memcmp.c		\
				$(LIBFT_PATH)/ft_memcpy.c		\
				$(LIBFT_PATH)/ft_memdel.c		\
				$(LIBFT_PATH)/ft_memmove.c		\
				$(LIBFT_PATH)/ft_memset.c		\
				$(LIBFT_PATH)/ft_putchar.c		\
				$(LIBFT_PATH)/ft_putchar_fd.c	\
				$(LIBFT_PATH)/ft_putendl.c		\
				$(LIBFT_PATH)/ft_putendl_fd.c	\
				$(LIBFT_PATH)/ft_putnbr.c		\
				$(LIBFT_PATH)/ft_putnbr_fd.c		\
				$(LIBFT_PATH)/ft_putstr.c		\
				$(LIBFT_PATH)/ft_putstr_fd.c		\
				$(LIBFT_PATH)/ft_split.c			\
				$(LIBFT_PATH)/ft_strcat.c		\
				$(LIBFT_PATH)/ft_strchr.c		\
				$(LIBFT_PATH)/ft_strclr.c		\
				$(LIBFT_PATH)/ft_strcmp.c		\
				$(LIBFT_PATH)/ft_strcpy.c		\
				$(LIBFT_PATH)/ft_strdel.c		\
				$(LIBFT_PATH)/ft_strdup.c		\
				$(LIBFT_PATH)/ft_strequ.c		\
				$(LIBFT_PATH)/ft_striter.c		\
				$(LIBFT_PATH)/ft_striteri.c		\
				$(LIBFT_PATH)/ft_strjoin.c		\
				$(LIBFT_PATH)/ft_strlcat.c		\
				$(LIBFT_PATH)/ft_strlcpy.c		\
				$(LIBFT_PATH)/ft_strlen.c		\
				$(LIBFT_PATH)/ft_strmap.c		\
				$(LIBFT_PATH)/ft_strmapi.c		\
				$(LIBFT_PATH)/ft_strncat.c		\
				$(LIBFT_PATH)/ft_strncmp.c		\
				$(LIBFT_PATH)/ft_strncpy.c		\
				$(LIBFT_PATH)/ft_strndup.c		\
				$(LIBFT_PATH)/ft_strnequ.c		\
				$(LIBFT_PATH)/ft_strnew.c		\
				$(LIBFT_PATH)/ft_strnstr.c		\
				$(LIBFT_PATH)/ft_strrchr.c		\
				$(LIBFT_PATH)/ft_strstr.c		\
				$(LIBFT_PATH)/ft_strtrim.c		\
				$(LIBFT_PATH)/ft_substr.c		\
				$(LIBFT_PATH)/ft_tolower.c		\
				$(LIBFT_PATH)/ft_toupper.c		\
				$(LIBFT_PATH)/ft_lstnew.c		\
				$(LIBFT_PATH)/ft_lstadd_front.c	\
				$(LIBFT_PATH)/ft_lstadd_back.c	\
				$(LIBFT_PATH)/ft_lstsize.c		\
				$(LIBFT_PATH)/ft_lstlast.c		\
				$(LIBFT_PATH)/ft_lstdelone.c		\
				$(LIBFT_PATH)/ft_lstclear.c		\
				$(LIBFT_PATH)/ft_lstiter.c		\
				$(LIBFT_PATH)/ft_lstmap.c		\

SRC			=		ft_printf.c			\
				ft_print_hexa.c		\
				ft_print_int.c		\
				ft_putnbr_base.c	\

OBJ = $(SRC:.c=.o)

all	: lib $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJ)

%.o : %.c Makefile libft/libft.h ft_printf.h
	cc -Wall -Wextra -Werror -c $< -I libft

lib : $(LIBFT)

$(LIBFT) : $(LIBFT_SRC) $(LIBFT_H)
	make -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re lib