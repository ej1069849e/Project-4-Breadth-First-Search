
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

	Graph(int); // one argument constructor
	
	void addEdge(int, int);//add a new edge from vertex v1 to v2
	                       //edge also needs to be added from v2 to v1
	
	vector<int> BFS(); // Implement Breadth First Search algorithm, using an STL queue
					   // Using an STL queue is mandatory
	                   	
	vector<int> BFS_Shortest_Distance(int); // Find Shortest Distance from src vertex
										// Using an STL queue is mandatory
	
	void print_graph(); //optional, for debugging
};

Graph::Graph(int){

	
	
}

void Graph::addEdge(int, int){

	
}

vector<int> Graph::BFS(){

	
}

vector<int> Graph::BFS_Shortest_Distance(int) {

	
}



void Graph::print_graph(){

	
}