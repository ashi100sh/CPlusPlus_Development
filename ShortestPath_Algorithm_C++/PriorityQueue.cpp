//
//  PriorityQueue.cpp
//
//
//  Created by Ashish Rakesh Singh on 28/03/16.
//
//  Priority Queue: Implementation of Priority Queue using link list method

#include "PriorityQueue.h"

// Priority_Queue(): Constructor of Priority_Queue
Priority_Queue::Priority_Queue()
{
    front = NULL;
}

// insert(): Insert the element in Priority Queue
// Argument:
// item: Value insert to queue
// priority: priority of inserted item
void Priority_Queue::insert(int item, int priority)
{
    node *tmp, *q;
    tmp = new node;
    tmp->info = item;
    tmp->priority = priority;
    if (front == NULL || priority < front->priority)
    {
        tmp->link = front;
        front = tmp;
    }
    else
    {
        q = front;
        while (q->link != NULL && q->link->priority <= priority)
        {
            q=q->link;
        }
        tmp->link = q->link;
        q->link = tmp;
    }
}

// contain(): Determine whether item is present or not
// Argument:
// item: Item searching in Queue
// Return true if present otherewise false
bool Priority_Queue::contain(int item)
{
    node *q;
    bool found=false;
    if(front != NULL)
    {
        q = front;
        while (q!=NULL)
        {
            if(q->info == item)
            {
                found = true;
                break;
            }
            else
            {
                q = q->link;
            }
        }
    }
    return found;
}

// chgPriority():Change priority of item present in queue
// Argument:
// item: item whose priority need to changes
// priority: new value of priority
void Priority_Queue::chgPriority(int item, int priority)
{
    node *q,*temp;
    int found=0;
    if(front != NULL)
    {
        q = front;
        if(front->info==item)
        {
            temp = front;
            found = 1;
            front = q->link;
        }
        else
        {
            while(q->link != NULL)
            {
                if(q->link->info==item)
                {
                    temp = q->link;
                    q->link = q->link->link ;
                    found =1 ;
                    break;
                }
                
                q = q->link;
                
            }
        }
        
        if(found)
        {
            free(temp);
            this->insert(item,priority);
        }
    }
    
}

// minPriority(): Delete from Priority Queue and returns the minimum node value
int Priority_Queue::minPriority()
{
    node *tmp;
    int min_val = 0 ;
    if(front == NULL)
        cout<<"Queue Underflow\n";
    else
    {
        min_val = front->info;
        tmp = front;
        front = front->link;
        free(tmp);
    }
    
    return min_val;
}

// display(): Print Priority Queue in Tabular form
void Priority_Queue::display()
{
    node *ptr;
    ptr = front;
    cout<<"-------------------------------" << endl;
    if (front == NULL)
        cout<<"Queue is empty\n";
    else
    {	cout<<"Queue Contains :\n";
        cout<<"-------------------------------" << endl;
        cout<<"Priority\tItem\n";
        cout<<"--------\t----\n";
        while(ptr != NULL)
        {
            cout<<ptr->priority<<"\t\t"<<ptr->info<<endl;
            ptr = ptr->link;
        }
    }
    cout<<"-------------------------------" << endl;
}

// isempty(): Check whether queue is empty or not.
// Return : True if queue is empty otherwise false
bool Priority_Queue::isempty()
{
    if(front==NULL)
        return true;
    else
        return false;
}

// top(): Return the first element of priority queue
int Priority_Queue::top()
{
    if (front == NULL)
    {
        return front->info;
    }
    else
        return NULL;
}

// size(): Return the number of element in Queue
int Priority_Queue::size()
{
    int size=0;
    node *q;
    
    if(!isempty())
    {
        size = 1;
        q = front;
        while (q->link!=NULL)
        {
            q = q->link;
            size++;
        }
    }
    
    return size;
    
}


// erase_all(): Delete all element of queue
void Priority_Queue::erase_all()
{
    node *ptr = NULL;
    node *temp = NULL;
    ptr = front;
    
    while (ptr != NULL) {
        temp = ptr->link;
        if (ptr != NULL) {
            free(ptr);
        }
        ptr = temp;
    }
    
    front = NULL;
}


