/*******************************************************************************
*	AUTHOR	   : Jeffrey Lo
*	ASSIGN #10 : Undirected Graphs
*	CLASS      : CS1D
*	SECTION    : 5-9p T-Th
*	DUE DATE   : 3/10/2015
*******************************************************************************/

#ifndef GRAPH_H
#define	GRAPH_H

#include <list>
#include <queue>
#include <limits>
#include "Assignments.h"

template <class vertType, class wtType>
class Graph{
public:
    class Edge;
    class Vertex;

    
        class Vertex{
            public:
                Vertex();
                vertType name;
                int index;
                bool isUsed;
        };
        
        class Edge{
            public:
                Edge(const pair<Vertex, Vertex> vertPair, const wtType& w);
            private:
                pair<Vertex, Vertex> incedentVertices;
                wtType weight;
        };
    
    Graph(int numVerts);
    ~Graph();
    
    bool addVertex(vertType vName);
    bool addVertex(vertType vName, int i);
    void addEdge(int from, int to, wtType w);
    void DFS(int v);
    void DFS(int v, bool visited[]);
    void BFS();
    void VertList();
    
private:
    int totVerts;
    Vertex* vertList;
    int** matrix;
};

//Vertex Constructor
template <class vertType, class wtType>
Graph<vertType, wtType>::Vertex::Vertex(){
    name = vertType();
    index = 0;
    isUsed = false;
}

//Graph Constructor
template <class vertType, class wtType>
Graph<vertType, wtType>::Graph(int numVerts){
    totVerts = numVerts;
    
    vertList = new Vertex[numVerts];
    
    matrix = new int*[totVerts];
    for(int i = 0; i < totVerts; ++i){
        matrix[i] = new int[totVerts];
    }
    
    for(int i = 0; i < totVerts; ++i){
        for(int j = 0; j < totVerts; ++j){
            matrix[i][j] = 0;
        }
    }
}

//Graph Destructor
template <class vertType, class wtType>
Graph<vertType, wtType>::~Graph(){
    
    //Deleting vert list
    delete [] vertList;
    
    //Deleting matrix
    for(int i = 0; i < totVerts; ++i){
        delete [] matrix[i];
    }
    delete [] matrix;
}

template <class vertType, class wtType>
bool Graph<vertType, wtType>::addVertex(vertType vName){
    int i = 0;
    bool added = false;
    while(!added && i < totVerts){
        
        if(vertList[i].isUsed == false){
            vertList[i].index = i;
            vertList[i].name = vName;
            vertList[i].isUsed = true;
            
            added = true;
        }
        
        i++;
    }
    
    if(!added){
        cout << "Vertex: " << vName << "not added\n";
    }
    
    return added;
}

template <class vertType, class wtType>
bool Graph<vertType, wtType>::addVertex(vertType vName, int i){
    bool added = false;
    
    if(i < totVerts){
        vertList[i].index = i;
        vertList[i].name = vName;
        vertList[i].isUsed = true;
        
        added = true;
    }
    else{
        cout << "Vertex: " << vName << "not added\n";
    }
    
    return added;
}

template <class vertType, class wtType>
void Graph<vertType, wtType>::VertList(){
    for(int i = 0; i < totVerts; i++){
        cout << i << ". " << vertList[i].name;
    }
}

template <class vertType, class wtType>
void Graph<vertType, wtType>::addEdge(int from, int to, wtType w){
    if(vertList[from].isUsed && vertList[to].isUsed){
        matrix[from][to] = w;
        cout << "Added Edge: " 
             << vertList[from].name
             << " -- [" << w << "] --> " 
             << vertList[to].name 
             << endl;
    }
    else{
        cout << "vertices not found, edge not added" << endl;
    }
}

template <class vertType, class wtType>
void Graph<vertType, wtType>::DFS(int v){
    bool visited[totVerts];
    queue<int> edges;
    int smallest = std::numeric_limits<int>::max();
    int nextVert;

    
    for(int c = 0; c < totVerts; c++){
        visited[c] = false;
    }
    
    if(v < totVerts){
        cout << "DFS Start: " << endl;
        visited[v] = true;
        cout << vertList[v].name << endl;
        
        for(int k = 0; k < totVerts; k++){
            if( matrix[v][k] > 0 && (!visited[k]) ){
                edges.push(k);
                cout << "Possible Vertex: " << k << endl;
            }
        }
        //finds smallest edge
        while(!edges.empty()){
            int contender = matrix[v][edges.front()];
            cout << "vertex: " << edges.front() << " ";
            cout << contender << " vs. " << smallest << endl;

            if(contender < smallest){
                smallest = contender;
                nextVert = edges.front();
            }
            edges.pop();
        }
        DFS(nextVert, visited);
    }
    else{
        cout << "ERROR: OUT OF BOUNDS";
    }
}

template <class vertType, class wtType>
void Graph<vertType, wtType>::DFS(int v, bool visited[]){
    queue<int> edges;
    int smallest = std::numeric_limits<int>::max();
    int nextVert;
    
    visited[v] = true;
    cout << vertList[v].name << endl;

    for(int k = 0; k < totVerts; k++){
        if( matrix[v][k] > 0 && (!visited[k]) ){
            edges.push(k);
            cout << "Possible Vertex: " << k << endl;
        }
    }
    //finds smallest edge
    while(!edges.empty()){
        int contender = matrix[v][edges.front()];
        cout << "vertex: " << edges.front() << " ";
        cout << contender << " vs. " << smallest << endl;

        if(contender < smallest){
            smallest = contender;
            nextVert = edges.front();
        }
        edges.pop();
    }
    DFS(nextVert, visited);
}
#endif	/* GRAPH_H */

