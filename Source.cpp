#include <iostream>
#include <limits>
#include "graph.h"
using namespace std;

void purgeInputErrors(string error_message);

int main() {
    cout << "Welcome to the Depth First Search traversal simulator!\n\n";
   
    // Allow the user to determine the number of vertices
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    // Handle invalid input
    if (!cin) {
        purgeInputErrors("Error: Invalid Input Detected\n");
    }

    Graph g(numVertices);
    cin.ignore();  // Ignores the newline character left in the input buffer

    // Build the graph based on user input
    for (int i = 0; i < numVertices; ++i) {
        string line;
        cout << "\nAdjacency list for vertex " << i << ": ";

        getline(cin, line);
        istringstream iss(line);

        int vertex;
        while (iss >> vertex) {
            g.addEdge(i, vertex);
        }
    }

    int startVertex;
    cout << "Enter the starting node for DFS: ";
    cin >> startVertex;
    cout << "DFS: ";
    g.DFS(startVertex);

    return 0;
}

void purgeInputErrors(string error_message) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << error_message << endl;
}