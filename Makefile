CC = cl
FLAGS = /std:c++17 /WX /EHsc
OBJECTS = test.obj main.obj 

assignment10: $(OBJECTS)
	$(CC) /Fe"assignment10" $(OBJECTS)

test.obj: src\test.cpp src\WeightedGraph.h
	$(CC) $(FLAGS) /I lib\ -c src\test.cpp

main.obj: src\main.cpp
	$(CC) $(FLAGS) /I lib\ -c src\main.cpp

clean:
	del assignment10.exe *.obj
