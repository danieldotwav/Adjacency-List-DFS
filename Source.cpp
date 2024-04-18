#include <iostream>
#include <list>
#include <limits>
#include <sstream>
#include "graph.h"
using namespace std;

int main() {
    // We need a list for each node that contains which nodes are adjact to it (adjacency list)
    vector<list<int>> adj_list;

    for (int i = 0; i < NUM_LISTS; ++i) {
        // Create temp list
        list<int> temp;

        // Prompt user to enter values into list
        cout << "\nAdjaceny list of vertex " << i << ": ";

        // Parse numbers to build list
        string input;
        getline(cin, input);

        // Read input into a string stream for processing
        istringstream line_stream(input);

        int number;
        while (line_stream >> number) {
            temp.push_back(number);
            cout << number << " ";
        }

        // Handle invalid input
        if (line_stream.fail()) {
            line_stream.clear();
            line_stream.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        adj_list.push_back(temp);
    }

    // Generate a graph using the adjacency lists
    Graph g(NUM_LISTS, adj_list);

    // Test by printing
    g.printLists();


    return 0;
}
