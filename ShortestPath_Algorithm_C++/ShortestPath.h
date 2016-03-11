//
//  ShortestPath.h
//
//
//  Created by Ashish Rakesh Singh on 28/03/16.
//

#ifndef ShortestPath_h
#define ShortestPath_h

/*============================================================
 *       ShortestPath
 *=============================================================
 */

#include "PriorityQueue.h"
#include "Graph.h"
const int infinity= 100000; // infinity assume as "100000"

class ShortestPath
{
    private:
        Priority_Queue visited;
        Priority_Queue unvisited;
        Graph graph;
        void relax(int , int , int );

    public:
        ShortestPath(Graph g);
        void dijkstra(int source=0);
        void print_path(int option=0);
        float average_path_lenth();
        void path(int, int);
        int path_size(int ,int);
        void print_queue();

};

#endif
