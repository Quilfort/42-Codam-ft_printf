NAME := libftprintf.a
LIBFT_NAME = libft/libft.a
CC := gcc
AR := ar rc
FLAGS ?= -c -Wall -Werror -Wextra
INCLUDE = -I libft
OBJ_FILES = $(SRC:%.c=%.o)
SRC =	ft_printf.c \
		ft_unsigned_putnbr.c \
		ft_putnbr_base.c

all : $(NAME)

$(NAME): $(OBJ_FILES)
	$(MAKE) -C libft
	cp $(LIBFT_NAME) $(NAME)
	$(AR) $(NAME) $(OBJ_FILES)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	@echo "Cleaning up .o files"
	@rm -f $(OBJ_FILES)
	$(MAKE) -C libft clean

fclean: clean
	@echo "We are cleaning now"
	@rm -f $(NAME)
	$(MAKE) -C libft fclean

re:	fclean all

.PHONY:	all clean fclean re