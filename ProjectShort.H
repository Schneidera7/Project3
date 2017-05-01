
/*----------------------------------------------------------------------
Shortest Path Class 
    This class contains 3 arrays that work in unison to kep track of nodes that were visited, their tenative distance, and their predocessor node. 

Alban Schneider
4/19/17
------------------------------------------------------------------------*/
#ifndef _ProjectShort_H
#define _ProjectShort_H
#include <iostream>
 
using namespace std;

class SPath{ 
//Stands for shortest path. 

    private: 
        bool visit [];
        int parent [];
        int tendistance [];
        
    public:
        //This is the constructor and the destructor. 
        SPath(int n);
        ~SPath();
        
        //This is the method to retrieve the value for an index in the array visit. 
        bool GetVisited(int x);  //These three meathods just return methods for all the values in the node. 
    
        //This is the method to retrieve the value for an index in the tendistance array. 
        int GetDist(int x);
    
        //This is the method to set the value of an index in the visit array. 
        void SetVisit(int current);
      
        //This is the method to set the value of an index in the tendistance array. 
        void SetDist(int cur, int x); //Sets the new distance of a node. 
    
        //This method looks for the next unvisited node that has the smallest value. 
        int NextNode(int n);
};

#endif