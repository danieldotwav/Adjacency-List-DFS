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

    // Terminate program on invalid input
    if (!cin) {
        purgeInputErrors("\nError: Invalid Input Detected\n");
    }
    else {
        cin.ignore();  // Ignore the newline character left in the input buffer
        Graph g(numVertices);

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
    }

    cout << "Terminating Program...\n";
    return 0;
}

void purgeInputErrors(string error_message) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << error_message << endl;
}