/*******************************************************************************
*	AUTHOR	   : Jeffrey Lo
*	ASSIGN #10 : Undirected Graphs
*	CLASS      : CS1D
*	SECTION    : 5-9p T-Th
*	DUE DATE   : 3/10/2015
*******************************************************************************/
#include "Assignments.h"
#include "Graph.h"
#include <vector>

using namespace JeffreyLo;

int main() {
    OutputHeader(   NAME,
                    CLASS,
                    SECTION, 
                    AS_NUM, 
                    AS_NAME, 
                    AS_TYPE,
                    cout); 
    
    string cities[12] = { "Boston",         "New York",         "Chicago", 
                          "Atlanta",        "Seattle",          "Miami",      
                          "San Francisco",  "Denver",           "Houston",  
                          "Los Angeles" ,   "Dallas",           "Kansas City"};
    
    enum   vNum{    BOSTON,
                    NY,
                    CHICAGO,
                    ATLANTA,
                    SEATTLE,
                    MIAMI,
                    SF,
                    DENVER,
                    HOUSTON,
                    LA,
                    DALLAS,
                    KC};
    
    cout << "Adding Vertices...\n";
    Graph<string, int> myGraph(12);
    for(int i = 0; i < 12; i++){
        myGraph.addVertex(cities[i]);
    }
    
    //Adding Edges
    myGraph.addEdge(BOSTON, NY, 214);
    myGraph.addEdge(NY, CHICAGO, 787);
    myGraph.addEdge(NY, ATLANTA, 888);
    myGraph.addEdge(CHICAGO, BOSTON, 983);
    myGraph.addEdge(CHICAGO, SEATTLE, 2097);
    myGraph.addEdge(SEATTLE, SF, 807);
    myGraph.addEdge(SEATTLE, DENVER, 1331);
    myGraph.addEdge(SF, LA, 381);
//    myGraph.addEdge(LA, DENVER, 1015);
    myGraph.addEdge(DENVER, SF, 1267);
    myGraph.addEdge(DENVER, CHICAGO, 1003);
    myGraph.addEdge(ATLANTA, MIAMI, 661);
    myGraph.addEdge(MIAMI, HOUSTON, 1187);
    myGraph.addEdge(HOUSTON, DALLAS, 239);
    myGraph.addEdge(HOUSTON, ATLANTA, 810);
    myGraph.addEdge(DALLAS, KC, 496);
    myGraph.addEdge(KC, CHICAGO, 533);
    myGraph.addEdge(KC, DENVER, 599);
    myGraph.addEdge(KC, LA, 1663);
    myGraph.addEdge(KC, NY, 1260);
    
    
    
    cout << "Finished Adding" << endl;
    
    cout << "\nPerforming Depth First Search: " << endl;
    myGraph.DFS(BOSTON);
    
    cout << "\n\nProgram End" << endl;
    return 0;
}

