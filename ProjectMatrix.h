#ifndef _ProjectMatrix_H
#define _ProjectMatrix_H

/*----------------------------------------------------------------------
Graph Class 
    This class contains a 2d array. In the array is where the edges are held for the graph. 

Alban Schneider
4/7/17
------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

class Matrix {
    
    private:
    
        int matrix [50][50];
        int curRow;
        int curCol;
        int nodecount;
    
    public: 
        //This is the constructor and destructor. 
        Matrix(int n);
        ~Matrix();
        
        //This is the method that adds a value to a point in the 2d array. That value represents an edge in the graph. 
        void AddEdge(int x, int y, int dist);
    
        //This is the return method for the values stored in the graph. 
        int GetEdge(int x, int y);
    
        //This is the method that looks for the first edge in the graph that is connected to the start node. 
       int GetFirst(int current);
    
        //This is the method that searches for the next edge connected to the current node. 
        int GetNext();
        
        
        
};

#endif