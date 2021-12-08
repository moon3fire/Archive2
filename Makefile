CFLAGS = -g -pthread

all: main.cpp
	g++ $(CFLAGS) main.cpp ParallelMatrix.cpp -o cp
	
clean:
	rm cp
