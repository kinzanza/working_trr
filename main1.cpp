#include <iostream>
#include <fstream>
#include "Graph.h"
#include "Parser.h"
int main() {
    std::string x;
    std::cin >> x;

    Graph myGraph = Graph();
    Parser parser(x);
    parser.parse();

    myGraph.points_list = parser.points_list;
    myGraph.edges_list = parser.edges_list;

    myGraph.create_minimal_tree();

    std::cout << myGraph;

    return 0;
}
