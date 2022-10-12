NAME = gol

SRC = main.c \
	buttons.c \
	map.c \
	free.c \

CFLAGS = -o $(NAME) -I/usr/include/SDL2 -I/usr/include/SDL -lSDL2 -lSDL_ttf

CC = gcc
all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(SRC) $(CFLAGS)

clean :
	/bin/rm $(NAME)