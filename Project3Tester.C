#include "ProjectMatrix.h"
#include "ProjectShort.H"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

    int n = 4;  //This is the number of nodes in the graph. 

    Matrix projectGraph(n); //My adjacency matrix which contains the edges of the graph. 

    SPath arrays(n);    //My two arrays that keep track of the tenative distance 
                        //and whther or not a node has been visited. 



//This is the helper method that marks the nodes visited and checks whether or not the nodes tenative distance needs to be updated. 

void VisitNode(int current){
    arrays.SetVisit(current);
    int neighbor = projectGraph.GetFirst(current);
   // cout<<"Made it to Visit Node and establishd neighbor.//Above While loop."<<endl;
    while (neighbor < n){
         arrays.SetDist(0,0);
        int curDist = arrays.GetDist(current);
        int nDist = arrays.GetDist(neighbor);
        int edgeCost = projectGraph.GetEdge(current,neighbor);
        int sum = curDist + edgeCost;
        /*cout<< neighbor << " is current neighbor"<<endl;
        cout<<curDist<<" is the current distance"<<endl;
        cout<<edgeCost<<" is the edge cost"<<endl;
        cout<<sum<<" is the sum"<<endl;
        cout<<nDist<< " is neighbors distance"<<endl;*/
        if(sum < nDist){
            //cout<<sum<<endl;
            arrays.SetDist(neighbor,sum);
            //cout<<arrays.GetDist(neighbor)<<endl;
            //cout<<"the distance was updated to "<< arrays.GetDist(neighbor)<<endl;
        }
    neighbor = projectGraph.GetNext();
       // cout<<neighbor << " is the new neighbor"<<endl;
    //cout<<arrays.GetDist(neighbor)<<endl;
    }
    arrays.SetVisit(current);
    //cout<<arrays.GetVisited(current)<<endl;
}

//This is the initial method that finds the shortest path from the starting node to every other node. 

void FindShortest(int n){
    for(int i=0; i<n; i++){
        int current = arrays.NextNode(n);
        //cout<<current << " is the current node. In findshortest."<<endl;
        //cout<<arrays.GetDist(current)<<endl;
        VisitNode(current);
        }
    arrays.SetDist(0,0);
    }
    

int main (){
   
    int nodecount = 0; //This is a counter to interate through the results for printing. 
    
    projectGraph.AddEdge(0,1,2);
    projectGraph.AddEdge(0,3,1);
    projectGraph.AddEdge(1,2,4);
    projectGraph.AddEdge(2,3,7);
   
    
    
    FindShortest(n);
    
    cout<<"The following are distances from the source node 0 to each node in the graph:/n"<<endl;
    while(nodecount < n){
        cout<< arrays.GetDist(nodecount)<< " is the shortest distance from node 0 to node "<< nodecount<<endl;
        nodecount++;
    }
    
    return (0);}
