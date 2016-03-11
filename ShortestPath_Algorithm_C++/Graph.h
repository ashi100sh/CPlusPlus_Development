//
//  Graph.h
//
//
//  Created by Ashish Rakesh Singh on 28/03/16.
//
//

#ifndef Graph_h
#define Graph_h

#include <iostream>
#include <map>
#include <cstdlib>
#include <string>
#include <utility>
#include <cmath>
#include <vector>
using namespace std;
/*============================================================
 *       GRAPH
 *=============================================================
 */

class Graph
{
private:
    int **adjacency_cost_matrix;
    map<int,int> vertex_cost;
    map<int,int> parent_vertex;
    int density;
    int min_cost;
    int max_cost;
    int vertex;
    int edges;
    int edge_probability(float, int, int );
    
public:
    
    Graph(int vertex,float density,int min_cost,int max_cost);
    int V();
    int E();
    bool adjacent(int ,int);
    vector<int> neighbors(int);
    int get_node_value(int);
    void set_node_value(int ,int);
    int get_edge_value(int , int);
    void set_edge_value(int ,int ,int);
    bool add_edge(int, int);
    bool delete_edge(int, int);
    void printGraph();
    void set_parent_node(int , int);
    int get_parent_node(int);
};

#endif
