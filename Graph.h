#ifndef GRAPH_H
#define GRAPH_H
#include <ostream> 
#include <vector>
#include <set>
#include "Edge.h"

class Graph {
public:
    std::vector<Point*> points_list;
    std::set<Edge> edges_list;
    std::vector<Edge> minimal_tree;

    Graph() = default;

    void recolor(int color1, int color2);
    std::vector<Edge> create_minimal_tree();
    friend std::ostream& operator<<(std::ostream& os, const Graph& graph);

};
//std::ostream& operator<<(std::ostream& os, const Graph& Graph)// {
	
//};

#endif // GRAPH_H
std::ostream& operator<<(std::ostream& os, const Graph& graph);