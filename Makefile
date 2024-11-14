
NAME = libftprintf.a

SRC = ft_putchar_fd.c ft_putstr_fd.c ft_printf.c ft_putnbr_fd.c ft_putuh.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ)
	@$(AR) $(NAME) $(OBJ)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJ)

fclean : clean 
	@$(RM) $(NAME)

re : fclean all
