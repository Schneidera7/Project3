/*----------------------------------------------------------------------
Shortest Path Class 
    This class contains 3 arrays that work in unison to kep track of nodes that were visited, their tenative distance, and their predocessor node. 

Alban Schneider
4/19/17
------------------------------------------------------------------------*/

#include "ProjectShort.H"
#include <iostream>
#include <climits>

//Public Meathods

    //This is the constructor that initializes all the nodes to max size and not been visited. 
    //The following lines to the loop are to give the shorestest path algorithem a place to start. 

    SPath::SPath(int n){
        int i = 1;
    while(i<n){
       visit[i] = false;
       tendistance[i] = INT_MAX;
        i++;
        }
    visit[0] = false;           //These two lines set the 
    tendistance[0] = 0;         //first nodes values. 
    }
    
    SPath::~SPath(){
       // delete visit[];
       // delete parent[];
        //delete tendistance[];
    }
    
//This is the method to retrieve the value for an index in the array visit[]. 
   bool SPath::GetVisited(int x){
       return visit[x];
   }
        
//This is the method to retrieve the value for an index in the array tendistance[].
    int SPath::GetDist(int x){
        return tendistance[x];
    }
    
//This method sets the value in array visit to true. This is because they are were all initialized as false. 
    void SPath::SetVisit(int current){
        visit[current] = true;
    }
        
//This method sets the value in the array tendistance to a new value. The value can only be changed to a value smalled than Int_Max. 
    void SPath::SetDist(int cur, int x){
        tendistance[cur] = x;
    }

//This method looks through both arrays and finds the next node that has the smallest value and is unvisited. 
    int SPath::NextNode(int n){
        int returnnode;
        int smallest = INT_MAX;
        int i=0;
        while(i<n){
            if(visit[i] == false && tendistance[i] <= smallest){
                smallest = tendistance[i];
                returnnode = i;
                }
            i++;
            }
        return returnnode;
        }
