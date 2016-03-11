//
//  ShortestPath.cpp
//
//
//  Created by Ashish Rakesh Singh on 28/03/16.
//
//  ShortestPath : Implementation of Dijkstra Algoithm  and  have interface for calculation of  average path & path source


#include "ShortestPath.h"
#include "PriorityQueue.h"
#include "Graph.h"

// ShortestPath(): Constructor where initializing the node and its parent node.
ShortestPath::ShortestPath(Graph g):graph(g)
{
    for (int i=0; i<graph.V(); i++)
    {
        graph.set_node_value(i,infinity);
        graph.set_parent_node(i,infinity);
        unvisited.insert(i,infinity);
    }
}

// relax(): Set the minimum node value and store the parent node
void ShortestPath::relax(int source, int destination, int edge_cost)
{
    int cost_u  = graph.get_node_value(source);
    int cost_v  = graph.get_node_value(destination);
    
    if (cost_v > (cost_u+edge_cost))
    {
        graph.set_node_value(destination, (cost_u+edge_cost));
        unvisited.chgPriority(destination, (cost_u+edge_cost));
        graph.set_parent_node(destination, source);
    }
    
}

// dijkstra(): Dijkstra algorithm is implemented
// Argument:
// source  : Start point from where to find the sortest path
// Default value of source is zero
void ShortestPath::dijkstra(int source)
{
    graph.set_node_value(source, 0);
    // Here setting parent node of source as source
    graph.set_parent_node(source, source);
    unvisited.chgPriority(source, 0);

    while (!unvisited.isempty())
    {
        int u = unvisited.minPriority();
        vector<int> adjacent_nodes = graph.neighbors(u);
        
        for(int i=0; i<adjacent_nodes.size();++i)
        {
            int v = adjacent_nodes.at(i);
            if (unvisited.contain(v))
            {
                relax( u, v, graph.get_edge_value(u ,v));
            }
        }
        visited.insert(u , graph.get_node_value(u));
    }
    
}

// average_path_lenth(): Return the average path
float ShortestPath::average_path_lenth()
{
    float sum_of_path_cost = 0;
    float avg_path_length;
    
    for (int i=0; i<graph.V(); ++i)
    {
        if (graph.get_node_value(i)< infinity)
        {
            sum_of_path_cost= sum_of_path_cost + graph.get_node_value(i);
        }
    }
    
    avg_path_length = sum_of_path_cost/graph.V();
    return avg_path_length ;
    
}

// path_size(): Return the path size using dijkstra algorithm
// Argument:
// source: Start point
// destination: Destination point
int ShortestPath::path_size(int source, int destination)
{
    //------------- reset call start----------
    visited.erase_all();
    unvisited.erase_all();
    
    for (int i=0; i<graph.V(); i++)
    {
        graph.set_node_value(i,infinity);
        graph.set_parent_node(i,infinity);
        unvisited.insert(i,graph.get_node_value(i));
    }
    //------------- Common reset call end----------
    
    dijkstra(source);
    
    if(graph.get_node_value(destination)<infinity)
        return graph.get_node_value(destination);
    else
        return 0;
    
}

// path(): Print the path , here dijkstra algorithm used
// Argument:
// source: Start point
// destination: Destination point
void ShortestPath::path(int source ,int destination)
{
    
    //------------- reset call start----------
    visited.erase_all();
    unvisited.erase_all();
    
    for (int i=0; i<graph.V(); i++)
    {
        graph.set_node_value(i,infinity);
        graph.set_parent_node(i,infinity);
        unvisited.insert(i,graph.get_node_value(i));
    }
    //------------- reset call end----------
    
    
    dijkstra(source);
    
    vector<int> path;
    //cout << "Now printing the shortest path from node "<< source << " to node " << destination <<endl;
    
    if (source == destination)
    {
        cout << "[" << source << "]";
        //cout << "Source and destination is same" << endl;
        return;
    }
    
    if(graph.get_node_value(destination) < infinity)
    {
        path.push_back(destination);
        
        while(graph.get_parent_node(destination)!=source)
        {
            destination = graph.get_parent_node(destination);
            path.push_back(destination);
        }
        
        path.push_back(source);
        int flag = 0;
        cout << "[";
        for(int i=path.size()-1; i>=0; i--)
        {
            if (flag)
            {
                cout << "]->[" ;
            }
            flag = 1;
            cout << path.at(i);
        }
        cout << "]";
    }
    else
    {
        cout << "destination is unreachable from source " << source << " ";
    }
}

// print_queue(): Print the queue
void ShortestPath::print_queue()
{
    visited.display();
}

// print_path(): Print the path and path size
// If option 1: Print the path size and path
// If option 2: Print the path
// If option 3: Print the path size
void ShortestPath::print_path(int option)
{
    
    cout << "----------------------------------------------------------" << endl;
    
    if (option == 0)
    {
        cout << "Path Size \t\t Path" << endl;
        cout << "--------- \t\t ----" << endl;
    }
    else if (option == 1)
    {
        cout << "Path" << endl;
        cout << "----" << endl;
    }
    else if (option == 2)
    {
        cout << "Path Size" << endl;
        cout << "---------" << endl;
    }
    
    
    for(int i=0; i<graph.V(); i++)
    {
        for(int j=0; j<graph.V(); j++)
        {
            if (option == 0)
            {
                cout << "path_size(" << i << "," << j << ") = " << path_size(i,j) << "\t" ;
                cout << "path(" << i << "," << j << ") => " ;
                this->path(i,j);
                cout << endl;
                
            }
            else if (option == 1)
            {
                //Print the "Path" for all possibility
                cout << "path(" << i << "," << j << ") => " ;
                this->path(i,j);
                cout << endl;
            }
            else if(option == 2) {
                //Print the "path_size" for all possibility
                cout << "path_size(" << i << "," << j << ") => " << path_size(i,j) << endl;
                
            }
            else
            {
                cout << "Wrong option";
            }
            //cout << "Path_Size(" <<i << "," << j << ")" << path_size(i,j) << endl;
            
        }
    }
    cout << "----------------------------------------------------------" << endl;
}
