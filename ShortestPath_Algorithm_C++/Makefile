output: Main.o Graph.o PriorityQueue.o ShortestPath.o
	g++ -o output Main.o Graph.o PriorityQueue.o ShortestPath.o

Main.o: Main.cpp
	g++ -c Main.cpp

Graph.o: Graph.cpp Graph.h
	g++ -c Graph.cpp Graph.h

PriorityQueue.o: PriorityQueue.cpp PriorityQueue.h
	g++ -c PriorityQueue.cpp PriorityQueue.h

ShortestPath.o: ShortestPath.cpp ShortestPath.h
	g++ -c ShortestPath.cpp ShortestPath.h

clean:
	rm -rf *.o *.gch output
