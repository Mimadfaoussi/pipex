NAME	:= pipex

CC		:=	cc
CFLAGS	:=	-Wextra -Wall -Werror

SRCS	:=	ft_split.c pipex.c pipex_utils.c setup.c ft_error.c

OBJS	:=	${SRCS:.c=.o}

all: $(NAME)


$(NAME): $(OBJS)
	@echo "Compiling pipex ..."
	@$(CC) $(OBJS) -o $(NAME)

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJS)

fclean: clean
	@echo "Cleaning pipex"
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re