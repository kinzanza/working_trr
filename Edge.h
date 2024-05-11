#ifndef EDGE_H
#define EDGE_H
#include <cmath>
#include "Point.h"

struct Edge {
    Point* start;
    Point* finish;
    double len;

    Edge(Point* p1, Point* p2) : start(p1), finish(p2) {
        len = sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
    }

    bool operator<(const Edge& obj) const {
        return len < obj.len;
    }
};

#endif // EDGE_H
