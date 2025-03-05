
#####################################################
#####                   files                   #####
#####################################################

SRC = 	src/check/ft_isalnum.c \
		src/check/ft_isalpha.c \
		src/check/ft_isascii.c \
		src/check/ft_isdigit.c \
		src/check/ft_isprint.c \
\
		src/convert/ft_atoi.c \
		src/convert/ft_itoa.c \
		src/convert/ft_putnbr_fd.c \
\
		src/get_next_line/get_next_line_utils.c \
		src/get_next_line/get_next_line.c \
\
		src/linked_list/ft_lstadd_back.c \
		src/linked_list/ft_lstadd_front.c \
		src/linked_list/ft_lstclear.c \
		src/linked_list/ft_lstdelone.c \
		src/linked_list/ft_lstiter.c \
		src/linked_list/ft_lstlast.c \
		src/linked_list/ft_lstmap.c \
		src/linked_list/ft_lstnew.c \
		src/linked_list/ft_lstsize.c \
\
		src/memory/ft_bzero.c \
		src/memory/ft_calloc.c \
		src/memory/ft_memchr.c \
		src/memory/ft_memcmp.c \
		src/memory/ft_memcpy.c \
		src/memory/ft_memmove.c \
		src/memory/ft_memset.c \
\
		src/ft_printf/ft_printf_useful_01.c \
		src/ft_printf/ft_printf_useful_02.c \
		src/ft_printf/ft_printf.c \
\
		src/string/ft_putchar_fd.c \
		src/string/ft_putendl_fd.c \
		src/string/ft_putstr_fd.c \
		src/string/ft_split.c \
		src/string/ft_strchr.c \
		src/string/ft_strdup.c \
		src/string/ft_striteri.c \
		src/string/ft_strjoin.c \
		src/string/ft_strlcat.c \
		src/string/ft_strlcpy.c \
		src/string/ft_strlen.c \
		src/string/ft_strmapi.c \
		src/string/ft_strncmp.c \
		src/string/ft_strnstr.c \
		src/string/ft_strrchr.c \
		src/string/ft_strtrim.c \
		src/string/ft_substr.c \
		src/string/ft_tolower.c \
		src/string/ft_toupper.c \

#####################################################
#####                 variables                 #####
#####################################################

NAME = libft.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = inc/libft.h inc/projets/ft_printf.h inc/projets/get_next_line.h

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

#####################################################
#####                  commands                 #####
#####################################################

all: $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER) Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I inc -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re