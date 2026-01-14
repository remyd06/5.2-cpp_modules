# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdedola <rdedola@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 11:42:09 by rdedola           #+#    #+#              #
#    Updated: 2026/01/14 12:22:40 by rdedola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE			:=	PmergeMe

# Files
SRC			:=	sources/main.cpp \
				sources/PmergeMe.cpp \

# Variables
CC			:=	c++
CFLAGS		:=	-Wall -Wextra -Werror -std=c++98 -Iincludes -fsanitize=address -g

# Colors
DEF_COLOR	= \033[0;39m
COLOR		= \033[1;32m

# Makefile
all			:	${EXE}

${EXE}		:	${SRC}
				${CC} ${CFLAGS} ${SRC} -o ${EXE}
				@echo "${COLOR}╔══════════════════════════╗${DEF_COLOR}"
				@echo "${COLOR}║     PmergeMe compiled    ║${DEF_COLOR}"
				@echo "${COLOR}╚══════════════════════════╝${DEF_COLOR}"
				

clean		:
				rm -rf ${EXE}
				@echo "${COLOR}╔══════════════════════════╗${DEF_COLOR}"
				@echo "${COLOR}║     PmergeMe cleaned     ║${DEF_COLOR}"
				@echo "${COLOR}╚══════════════════════════╝${DEF_COLOR}"

re			:	clean all

.PHONY		:	all clean re
