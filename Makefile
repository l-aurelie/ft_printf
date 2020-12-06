SRCS	= ft_printf.c ft_conversion.c ft_types_conv.c ft_int_utils.c\
ft_str_utils.c ft_parsing.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

LIB		= ./libft/libft.a

CC		=    gcc
RM		=    rm -f
CFLAGS	=    -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${lIB} ${OBJS}
			make -C ./libft/
			cp ./libft/libft.a ${NAME}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:		
			make clean -C ./libft/
			${RM} ${OBJS} 

fclean:		clean
			make fclean -C ./libft/
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
