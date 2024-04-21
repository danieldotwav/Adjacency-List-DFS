#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <sstream>

class Graph {
    int numVertices;
    std::list<int>* adjLists;
    bool* visited;

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void DFS(int startVertex);

    ~Graph() {
        delete[] adjLists;
        delete[] visited;
    }
};

// Initialize graph
Graph::Graph(int vertices) {
    numVertices = vertices;
    adjLists = new std::list<int>[vertices];
    visited = new bool[vertices];
}

// Add edges
void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);
}

// DFS algorithm
void Graph::DFS(int startVertex) {
    std::stack<int> stack;
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    stack.push(startVertex);

    while (!stack.empty()) {
        int currentVertex = stack.top();
        stack.pop();

        if (!visited[currentVertex]) {
            visited[currentVertex] = true;
            std::cout << currentVertex << " ";

            for (auto i = adjLists[currentVertex].rbegin(); i != adjLists[currentVertex].rend(); ++i) {
                int adjVertex = *i;
                if (!visited[adjVertex])
                    stack.push(adjVertex);
            }
        }
    }
    std::cout << std::endl;
}


#endif