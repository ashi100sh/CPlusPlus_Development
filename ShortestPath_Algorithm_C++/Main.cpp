//
//  Main.cpp
//  C++
//
//  Created by Ashish Rakesh Singh on 06/03/16.
//
//

#include<iostream>
#include "ShortestPath.h"

int main()
{
    
    cout << endl;
    cout << " --------------------------------------------------------------------------" << endl;

    // Testing purpose Vertex "5" is define
    Graph g(5,40,1,10);
    g.printGraph();
    
    ShortestPath ss(g);
    ss.dijkstra();
    cout << "***** Cost of shortest path from node 0 to all nodes ******** " <<endl;

    ss.print_queue();
    float avg_len = ss.average_path_lenth();
    cout << "\nCalculating the average path length.. (consider source as 0): " << avg_len << endl;
    
    cout << endl << " Print: PathSize and Path for every possibility using dijkstra " << endl;
    ss.print_path();
    
    return 0;
}


