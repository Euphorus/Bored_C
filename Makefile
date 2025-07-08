CC = g++
CLAGS = -Wall -Wextra -std=c++20
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

game: main.cpp
	$(CC) $(CFLAGS) -o game main.cpp $(LIBS)

clean:
	rm -f game

.PHONY: clean


