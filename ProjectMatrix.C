/*-----------------------------------------------------------------
    This is the code file for the 2d array in Project 3. 
    Within is the detailed code of setting up the matrix and meathods to add edges to the graph. 
    
    Alban Schnider
    4/19/17
-----------------------------------------------------------------*/

#include "ProjectMatrix.h"
#include <iostream>
#include <climits>

//Public Functions

    //This is the constructor and it makes the 2d array, initializing all values to -1. 
    //-1 represents no edge in the graph between the two nodes that share that point. 
    Matrix::Matrix(int n){
        curCol = 0;
        curRow = 0;
        nodecount = n;
        for(int i=0; i<50; i++){
            for(int j=0; j<50; j++){
                matrix[i][j] = -1;
            }
        }
    }
    
    Matrix::~Matrix(){
   // delete matrix*[50][50];
    }

    //This is the method to adds edges to the 2d array. 
    //This requires the two nodes that share that edge and the edge distance. 
    //This graph is undirsted so the point is added in two spots on the graph. 
    void Matrix::AddEdge(int x, int y, int dist){
        matrix[x][y] = dist;
        matrix[y][x] = dist;
    }


    //This method gets the first edge in the graph that is connected to the current node. 
    //This is why the method requres the current node. 
    int Matrix::GetFirst(int current){
        curRow = current;
        int i = 0;
        while(i<nodecount){
            if(matrix[current][i] != -1){
              curCol=i;
            return i;
            }
            i++;
        }
    }


    //This method looks for the next node in the 2d array that is connected to the current node.
    int Matrix::GetNext(){
        curCol++;
        while(matrix[curRow][curCol] == -1 && curCol < nodecount){
           curCol = curCol + 1;
        }   
        
        if(curCol > nodecount){
            return (-1);
        }
        return curCol;
    }

    //This method goes and gets the value at a point given and return that vlaue. 
    int Matrix::GetEdge(int x, int y){
       int i = 0; 
        i = matrix[x][y];
        return i;
    }
