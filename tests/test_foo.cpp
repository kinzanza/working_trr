#include <gtest/gtest.h>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include "../Graph.h"
#include "../Parser.h"
#include "../Edge.h"
#include "../Point.h"
#include "../Graph.h"

TEST(NAME, NAME1) {
    // Correctly initialize x and y vectors
    std::vector<int> x = {1, 1, 2, 2, 3};
    std::vector<int> y = {6, 5, 6, 4, 5};

    // Mock input for x
    std::string x_input = "data.txt";
    // Assuming you have a way to mock input or directly use the string

    Graph myGraph = Graph();

    Parser parser = Parser(x_input); // Use the mocked input
    parser.parse();

    myGraph.points_list = parser.points_list;
    myGraph.edges_list = parser.edges_list;

    myGraph.create_minimal_tree();

    for(int i = 0; i < myGraph.minimal_tree.size(); i++) {
        EXPECT_EQ(myGraph.minimal_tree[i].start->id, x[i]);
        EXPECT_EQ(myGraph.minimal_tree[i].finish->id, y[i]);
    }
}
