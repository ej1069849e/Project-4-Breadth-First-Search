
#pragma once
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph{

private:

	vector<vector<int>> adjacency_list; // mandatory
    
public:

	Graph() {} //default constructor

	Graph(int v); // one argument constructor
	
	void addEdge(int v1, int v2);//add a new edge from vertex v1 to v2
	                       //edge also needs to be added from v2 to v1
	
	vector<int> BFS(); // Implement Breadth First Search algorithm, using an STL queue
					   // Using an STL queue is mandatory
	                   	
	vector<int> BFS_Shortest_Distance(int); // Find Shortest Distance from src vertex
										// Using an STL queue is mandatory
	
	void print_graph(); //optional, for debugging
};

Graph::Graph(int v){
    
    adjacency_list.resize(v); // create adjacency_list of Graph with a given number of vertices

}

void Graph::addEdge(int v1, int v2){ /* add a new edge to the graph connecting vertex v1 to v2; Edge also                                        needs to be added from v2 to v1 */
    adjacency_list[v1].push_back(v2);
    adjacency_list[v2].push_back(v1);
}

vector<int> Graph::BFS(){
    vector <int> BFS;
    queue<int> q;
    vector<bool> visited(adjacency_list.size(), false);
    int currentV;
    
    q.push(0); //  Assume BFS begins at vertex 0. (startV pushed into queue)
    visited[0] = true; // adding start v to  visited


    while (! q.empty()) // when queue is not empty...
    {
        currentV = q.front(); // assign queue to front so I can then pop it
        q.pop();   // pop queue....
        cout << currentV << " "; // print or output currentV
        BFS.push_back(currentV);
        for (int i = 0; i < adjacency_list[currentV].size(); i++) {
            if (!visited[adjacency_list[currentV][i]]) {
                q.push(adjacency_list[currentV][i]);
                visited[adjacency_list[currentV][i]] = true;
                
            }
        }
    }
return BFS;
}

vector<int> Graph::BFS_Shortest_Distance(int startV) {
    vector<int> SD;
    SD.resize(adjacency_list.size());
    queue<int> q;
    vector<bool> visited(adjacency_list.size(), false);
    int currentV;
    q.push(startV);
    visited[startV] = true;
    SD.at(startV) = 0;
    
    while( !q.empty()) {
        currentV = q.front();
        q.pop();
        for (int i = 0; i < adjacency_list[currentV].size(); i++) {
            if (!visited[adjacency_list[currentV][i]]) {
                SD[adjacency_list[currentV][i]] = SD[currentV] + 1;
                q.push(adjacency_list[currentV][i]);
                visited[adjacency_list[currentV][i]] = true;
            }
        }
    }
    return SD;
}

void Graph::print_graph(){
    for(int i=0;i<adjacency_list.size();i++) {
        for(int j=0;j<adjacency_list[i].size();j++) {
            cout << adjacency_list[i][j]<<" ";
            cout << endl;
        }
    }
}

