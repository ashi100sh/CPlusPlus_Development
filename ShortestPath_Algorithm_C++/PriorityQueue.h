//
//  PriorityQueue.h
//
//
//  Created by Ashish Rakesh Singh on 28/03/16.
//


#ifndef PriorityQueue_h
#define PriorityQueue_h

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;


struct node
{
    int priority;
    int info;
    struct node *link;
};

/*
 * Class Priority Queue
 */

class Priority_Queue
{
private:
    node *front;
public:
    Priority_Queue();
    void insert(int, int);
    bool contain(int);
    void chgPriority(int, int);
    int minPriority();
    bool isempty();
    void display();
    int top();
    int size();
    void erase_all();
};

#endif
