//
//  Graph.cpp
//
//
//  Created by Ashish Rakesh Singh on 28/03/16.
//
//  Graph: Adjacency matrix method is used in Graph ADT

#include "Graph.h"
using namespace std;


// Graph() : constructor
// Argument:
// vertex : intital vertex
// density: relative edge density value
// min_cost: minimum value cost
// max_cost: maximum value cost
Graph::Graph(int vertex,float density,int min_cost,int max_cost):vertex(vertex), density(density), min_cost(min_cost), max_cost(max_cost)
{
    edges = 0; // Initally edges count is zero
    
    srand(time(0));
    adjacency_cost_matrix = new int*[vertex];
    
    for (int i=0; i<vertex; ++i)
    {
        adjacency_cost_matrix[i] = new int[vertex];
    }
    
    //intialize the cost of edges
    
    for(int i=0; i<vertex; ++i)
    {
        //Instead of intializing the j with 0, initialize with i to avoid the ovewrite again and again
        for(int j=i; j<vertex; ++j)
        {
            if (i==j)
            {
                //Avoiding the self loop
                adjacency_cost_matrix[i][j] =0;
            }
            else
            {
                adjacency_cost_matrix[i][j] = adjacency_cost_matrix[j][i] = edge_probability(density,min_cost,max_cost);
            }
            
        }
    }
    
}


// edge_probability(): Return the value of edge using density & cost value
// Argument:
// density: relative edge density value
// min_cost: minimum value cost
// max_cost: maximum value cost
int Graph::edge_probability(float density, int min_cost, int max_cost)
{
    int cost = rand() % max_cost + min_cost;
    if(cost<ceil((max_cost - min_cost)*density/100))
    {
        return 0;
    }
    else
    {
        return cost;
    }
}

// V(): Return the number of vertex
int Graph::V()
{
    return vertex;
}


// E(): Return the number of edge
int Graph::E()
{
    if (!edges)
    {
        int no_of_edges = 0;
        for(int i=0; i<this->vertex; ++i)
        {
            for(int j=i; j<this->vertex; ++j)
            {
                if(adjacency_cost_matrix[i][j] != 0)
                {
                    //cout << "Value of i:" << i << "j:" << j << endl;
                    no_of_edges++;
                }
            }
        }
        edges = no_of_edges;
        return no_of_edges;
    }
    else
    {
        edges;
    }
    
}

// adjacent(): Return the value of edge between user input vertex1 -> vertex2
// Argument:
// vertex1 : Source Point vertex
// vertex2 : Destination Point vertex
bool Graph::adjacent(int vertex1, int vertex2)
{
    if(adjacency_cost_matrix[vertex1][vertex2] == 0)
        return false;
    return true;
}

// neighbors(): Return the neighbour (vector o/p) of input vertex
// Argument:
// v : Input vertex to determine neigbour
vector<int> Graph::neighbors (int v)
{
    vector<int> neighbor;
    for(int i=0;i<this->vertex ;++i)
    {
        if(adjacency_cost_matrix[i][v] != 0)
        {
            neighbor.push_back(i);
        }
    }
    return neighbor;
}

// get_node_value(): Return node value of input vertex
// Argument:
// vertex: Input vertex to determine node value
int Graph::get_node_value(int vertex)
{
    return vertex_cost[vertex];
}

// set_node_value(): Set the node value of vertex
// Argument:
// vertex: vertex
// value: value set for i/p vertex
void  Graph::set_node_value(int vertex,int value)
{
    vertex_cost[vertex] = value;
}

// get_edge_value(): Return the edge value
// Argumnet:
// vertex1: source of edge
// vertex2: destination of edge
int Graph::get_edge_value(int vertex1, int vertex2)
{
    return adjacency_cost_matrix[vertex1][vertex2];
}

// set_edge_value(): Set the value of edge
// Argument:
// vertex1: source of edge
// vertex2: destination of edge
// value: value to set -> edge
void Graph::set_edge_value(int vertex1, int vertex2, int value)
{
    //Need to set vertex1,vertex2 and vertex2,vertex1 both array value
    adjacency_cost_matrix[vertex1][vertex2] = adjacency_cost_matrix[vertex2][vertex1] = value;
}


// set_parent_node(): Set the value of parent node
// Argument:
// vertex: vertex
// partent_value: value set to parent node
void Graph::set_parent_node(int vertex,int parent_value)
{
    parent_vertex[vertex] = parent_value;
}

// get_parent_node(): Return the parent value of given vertex node
// Argument:
// vertex: vertex node
int Graph::get_parent_node(int vertex)
{
    return parent_vertex[vertex];
}


// printGraph(): Print the Graph in matrix form
void Graph::printGraph()
{
    //---- Formatting
    for(int i=0; i<vertex; ++i)
    {
        cout << "=========";
    }
    cout << endl << "\t\tGRAPH" <<endl;
    for(int i=0; i<vertex; ++i)
    {
        cout << "=========";
    }
    
    cout << endl;
    // ---- Formatting end
    
    for(int i=0; i<vertex; ++i){
        for(int j=0; j<vertex; ++j){
            cout <<adjacency_cost_matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    for(int i=0; i<vertex; ++i)
    {
        cout << "=========";
    }
    cout << endl;
}

// add_edge(): Add the edge and value determine through "edge_probability()"
// Argument:
// vertex1: Source vertex
// vertex2: Destination vertex
bool Graph::add_edge(int vertex1, int vertex2)
{
    int cost = 0;
    cout << "Add Edge: Vertiexs " << vertex1 << "--" << vertex2 << endl;
    if (adjacency_cost_matrix[vertex1][vertex2] == 0)
    {
        //possibility that edge_probability return 0, but here we want add the edge therfore iterate till it become non-zero
        do
        {
            cost = edge_probability(density, min_cost, max_cost);
        }
        while(cost == 0);
        
        set_edge_value(vertex1, vertex2, cost);
        cout << "Newly added edge [" << vertex1 << "," << vertex2 << "] = " << get_edge_value(vertex1,vertex2)<< endl;
        return true;
    }
    else
    {
        cout << "Edge already exist , value is" << adjacency_cost_matrix[vertex1][vertex2] << endl;
        return false;
    }
    
}

// delete_edge(): Delete the edge
// Argument:
// vertex1: Source vertex
// vertex2: Destination vertex
bool Graph::delete_edge(int vertex1, int vertex2)
{
    cout << "Delete Edge: Vertiexs " << vertex1 << "--" << vertex2 << endl;
    
    if (adjacency_cost_matrix[vertex1][vertex2] !=0)
    {
        cout << "Deleted vetex value is [" << vertex1 << "," << vertex2 << "] = " << get_edge_value(vertex1, vertex2) << endl;
        set_edge_value(vertex1,vertex2,0);
        return true;
    }
    else
    {
        cout << "Edge is not exist already" << endl;
        return false;
    }
    
}



