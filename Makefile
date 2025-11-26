CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRC_FIL = ft_abc.c ft_additional.c ft_additional_second.c ft_fd.c ft_is.c \
	ft_mem.c ft_split.c ft_str.c ft_str_second.c
OBJS = $(SRC_FIL:.c=.o)

BONUS_FIL = ft_bonus.c ft_second_bonus.c
BONUS_OBJS = $(BONUS_FIL:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

bonus: .bonus

.bonus: $(NAME) $(BONUS_OBJS)
	ar -rcs $(NAME) $(BONUS_OBJS)
	touch .bonus

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	rm -f .bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
