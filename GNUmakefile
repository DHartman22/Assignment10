CC = g++
FLAGS = -std=c++17 -Wall -Werror -Wextra -Wpedantic
VPATH = src:lib
OBJECTS = test.o main.o 

assignment10: $(OBJECTS)
	$(CC) $(OBJECTS) -o assignment10

debug: FLAGS += -g
debug: assignment10

test.o: test.cpp WeightedGraph.h
	$(CC) $(FLAGS) -Ilib -c src/test.cpp

main.o: main.cpp
	$(CC) $(FLAGS) -Ilib -c src/main.cpp

clean:
	rm assignment10 *.o
