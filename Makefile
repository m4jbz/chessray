CC=g++
CFLAGS=-Wall -Wextra -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

game: game.cpp
	$(CC) -o game game.cpp $(CFLAGS)
