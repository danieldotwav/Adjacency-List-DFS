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

        // Use a flag to break out of loop upon invalid input
        bool invalid_input_detected = false;

        // Build the graph using valid user input
        for (int i = 0; i < numVertices && !invalid_input_detected; ++i) {
            string line;
            cout << "\nAdjacency list for vertex " << i << ": ";

            getline(cin, line);
            istringstream iss(line);

            int vertex;
            while (iss >> vertex) {
                g.addEdge(i, vertex);
            }

            // Check for failure not at the end of file
            if (iss.fail() && !iss.eof()) { // Check for failure not at the end of file
                iss.clear();
                iss.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "\nError: Invalid Vertices Detected\n";
                invalid_input_detected = true;
            }
        }

        if (!invalid_input_detected) {
            int startVertex;
            cout << "Enter the starting node for DFS: ";
            cin >> startVertex;
            cout << "DFS: ";
            g.DFS(startVertex);
        }
    }

    cout << "Terminating Program...\n";
    return 0;
}

void purgeInputErrors(string error_message) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << error_message << endl;
}