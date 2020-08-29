FILENAME = a.exe

SRCS = main.cpp

OBJS = ${SRCS:.cpp=.o}

CC = g++

#CFLAGS = -c -Wall -Werror -Wextra
CFLAGS = -c

RM = rm -f

all:
	${CC} ${CFLAGS} ${SRCS}
	${CC} ${OBJS} -o ${FILENAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${FILENAME}

re: fclean all

.PHONY: all fclean clean re
