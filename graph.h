#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int NUM_LISTS = 5;

class Graph {
private:
    int V;
    vector<list<int>> l;

public:
    // Use an initialization list for constructor
    Graph(int vertices, const vector<list<int>>& adj_lists) : V(vertices), l(adj_lists) {}

    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void printLists() {
        for (int i = 0; i < V; ++i) {
            list<int>list = l[i];
            cout << "List " << i << ": [ ";
            for (int number : list) {
                cout << number << " ";
            }
            cout << "]\n";
        }
    }

};



#endif