CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = includes
NAME = libft.a

SRC_DIR = .
SRC_FIL = ft_abc.c \
	ft_additional.c \
	ft_additional2.c \
	ft_fd.c \
	ft_is.c \
	ft_mem.c \
	ft_split.c \
	ft_str.c \
	ft_bonus.c \
	ft_bonus2.c \
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

bonus: 

.PHONY: all clean fclean re bonus
