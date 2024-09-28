/*
The main.cpp file serves as a command-line interface to interact with the AVL tree data structure. 
It takes user input to perform operations on the tree such as inserting nodes, removing nodes by ID, 
removing nodes by their in-order position, and printing the tree in various traversal orders (in-order, 
pre-order, and post-order). The program starts by reading the number of commands to execute and then parses 
each line to identify the command and its arguments (like name, ID, or position). It also validates that 
IDs are exactly 8 digits long before performing operations like insertion, deletion, and search, ensuring 
that only valid data is processed. This setup allows users to easily manipulate and view the contents of 
the AVL tree through text-based commands.
*/



#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "AVLTree.h" // Correctly include the AVLTree header

using namespace std;


// Utility function to check if an ID is exactly 8 digits long
bool isValidId(int id) {
    return id >= 10000000 && id <= 99999999;
}

int main(int argc, char* argv[]) {
    AVLTree tree;
    int numberOfCommands;
    cin >> numberOfCommands;
    cin.ignore(); // Ignore the newline after reading the number

    for (int i = 0; i < numberOfCommands; ++i) {
        string line, command;
        getline(cin, line);
        istringstream iss(line);
        iss >> command;

        if (command == "insert") {
            string name;
            int id;
            getline(iss >> ws, name, '"'); // Read up to the first quote
            getline(iss, name, '"'); // Read the actual name
            iss >> id; // Read the id

            // Validate ID before insertion
            if (isValidId(id)) {
                tree.insert(name, id);
            } else {
                cout << "Error: ID must be 8 digits long." << endl;
            }
        } else if (command == "remove") {
            int id;
            iss >> id;

            // Validate ID before removal
            if (isValidId(id)) {
                tree.remove(id);
            } else {
                cout << "Error: ID must be 8 digits long." << endl;
            }
        } else if (command == "removeInorder") {
            int n;
            iss >> n;
            tree.removeInorder(n);
        } else if (command == "printInorder") {
            tree.printInorder();
        } else if (command == "printPreorder") {
            tree.printPreorder();
        } else if (command == "printPostorder") {
            tree.printPostorder();
        } else if (command == "printLevelCount") {
            tree.printLevelCount();
        } else if (command == "search") {
            string searchQuery;
            getline(iss >> ws, searchQuery);
            if (searchQuery.front() == '"') { // It's a name search
                string name = searchQuery.substr(1, searchQuery.length() - 2); // Extract name without quotes
                tree.search(name);
            } else { // It's an ID search
                int id = stoi(searchQuery);

                // Validate ID before search
                if (isValidId(id)) {
                    tree.search(id);
                } else {
                    cout << "Error: ID must be 8 digits long." << endl;
                }
            }
        } else {
            cout << "Unknown command: " << command << endl;
        }
    }

    return 0;
}
