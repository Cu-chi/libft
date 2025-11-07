CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = includes
NAME = libft.a

SRC_DIR = .
SRC_FIL = ft_abc.c \
	ft_additional.c \
	ft_is.c \
	ft_mem.c \
	ft_str.c \
	ft_str2.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FIL))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $@ $^

.c.o:
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
