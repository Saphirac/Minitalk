# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 18:58:56 by mcourtoi          #+#    #+#              #
#    Updated: 2022/05/12 01:34:27 by mcourtoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMESERVER = server

NAMECLIENT = client

CC = gcc

SRCSSERVER = srcs_server/server.c utils/utils.c 

SRCSCLIENT = srcs_client/client.c utils/utils.c

OBJSCLIENT = ${SRCSCLIENT:.c=.o}
OBJSSERVER = ${SRCSSERVER:.c=.o}

INC = ./includes

FLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${FLAGS} -I${INC} -c $< -o ${<:.c=.o}

${NAMESERVER}:    ${OBJSSERVER}
	    ${CC} ${FLAGS} ${OBJSSERVER} -o ${NAMESERVER}

${NAMECLIENT}:	${OBJSCLIENT}
		${CC} ${FLAGS} ${OBJSCLIENT} -o ${NAMECLIENT} 

all:    ${NAMESERVER}  ${NAMECLIENT}

clean:
	rm -f ${OBJSCLIENT} ${OBJSSERVER}

fclean: clean
	rm -f ${NAMECLIENT} ${NAMESERVER}

re: fclean all

.PHONY: all clean fclean re