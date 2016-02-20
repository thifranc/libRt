# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thifranc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 19:24:34 by thifranc          #+#    #+#              #
#    Updated: 2016/02/20 17:03:29 by thifranc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRC = ./src/ft_atoi.c  ./src/ft_memalloc.c  ./src/ft_putchar.c  ./src/ft_strcat.c  ./src/ft_striter.c  ./src/ft_strncpy.c  ./src/ft_strtrim.c  ./src/ft_bzero.c  ./src/ft_memccpy.c  ./src/ft_putchar_fd.c   ./src/ft_strchr.c  ./src/ft_striteri.c  ./src/ft_strnequ.c  ./src/ft_tolower.c  ./src/ft_isalnum.c  ./src/ft_memchr.c  ./src/ft_putendl.c ./src/ft_strlcat.c ./src/ft_strclr.c  ./src/ft_strjoin.c  ./src/ft_strnew.c  ./src/ft_toupper.c  ./src/ft_isalpha.c  ./src/ft_memcmp.c  ./src/ft_putendl_fd.c   ./src/ft_strcmp.c  ./src/ft_strlen.c  ./src/ft_strnstr.c  ./src/ft_isascii.c  ./src/ft_memcpy.c  ./src/ft_putnbr.c  ./src/ft_strcpy.c  ./src/ft_strmap.c  ./src/ft_strrchr.c  ./src/ft_isdigit.c  ./src/ft_memdel.c  ./src/ft_putnbr_fd.c  ./src/ft_strdel.c  ./src/ft_strmapi.c  ./src/ft_strsplit.c  ./src/ft_isprint.c  ./src/ft_memmove.c  ./src/ft_putstr.c  ./src/ft_strdup.c  ./src/ft_strncat.c  ./src/ft_strstr.c  ./src/ft_itoa.c  ./src/ft_memset.c  ./src/ft_putstr_fd.c  ./src/ft_strequ.c  ./src/ft_strncmp.c  ./src/ft_strsub.c 

OBJ = ft_atoi.o  ft_memalloc.o  ft_putchar.o  ft_strcat.o  ft_striter.o  ft_strncpy.o  ft_strtrim.o  ft_bzero.o  ft_memccpy.o  ft_putchar_fd.o   ft_strchr.o  ft_striteri.o  ft_strnequ.o  ft_tolower.o  ft_isalnum.o  ft_memchr.o  ft_putendl.o  ft_strclr.o  ft_strjoin.o  ft_strnew.o  ft_toupper.o  ft_isalpha.o  ft_memcmp.o  ft_putendl_fd.o   ft_strcmp.o  ft_strlcat.o ft_strlen.o  ft_strnstr.o  ft_isascii.o  ft_memcpy.o  ft_putnbr.o  ft_strcpy.o  ft_strmap.o  ft_strrchr.o  ft_isdigit.o  ft_memdel.o  ft_putnbr_fd.o  ft_strdel.o  ft_strmapi.o  ft_strsplit.o  ft_isprint.o  ft_memmove.o  ft_putstr.o  ft_strdup.o  ft_strncat.o  ft_strstr.o  ft_itoa.o  ft_memset.o  ft_putstr_fd.o  ft_strequ.o  ft_strncmp.o ft_strsub.o
all: $(NAME)

$(NAME):
	@gcc -c $(FLAGS) $(SRC)
	@ar rc $(NAME) $(OBJ)

clean :
	@/bin/rm -f $(OBJ)

fclean : clean
	@/bin/rm -f $(NAME)
re : fclean all
