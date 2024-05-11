#ifndef PARSER_H
#define PARSER_H
#include "Edge.h"
#include <string>
#include <vector>
#include "Point.h"
#include <set>
class Parser {
public:
    std::string filename;
    std::vector<Point*> points_list;
    std::set<Edge> edges_list;

    Parser(const std::string& filename) : filename(filename) {}

    void parse();
};

#endif // PARSER_H
