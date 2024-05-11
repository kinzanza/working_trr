#include "Graph.h"
#include "Parser.h"

void Graph::recolor(int color1, int color2)
{
    for (Point* point : points_list)
    {
        if (point->color == color1)
        {
            point->color = color2;
        }
    }
}

std::vector<Edge> Graph:: create_minimal_tree()
	{
		int last_color = 1;
		int num_colors = 1;

		//std::sort(edges_list.begin(), edges_list.end());

		for (Edge new_Edge : edges_list)
		{
			if (new_Edge.finish->color == new_Edge.start->color && new_Edge.finish->color != 0) {}

			else if (new_Edge.start->color != 0 && new_Edge.finish->color != 0 && new_Edge.start->color != new_Edge.finish->color)
			{
				recolor(new_Edge.start->color, new_Edge.finish->color);
				num_colors -= 1;
				minimal_tree.push_back(new_Edge);
			}

			else if (new_Edge.start->color != 0)
			{
				new_Edge.finish->color = new_Edge.start->color;
				minimal_tree.push_back(new_Edge);
			}

			else if (new_Edge.finish->color != 0)
			{
				new_Edge.start->color = new_Edge.finish->color;
				minimal_tree.push_back(new_Edge);
			}

			else if (new_Edge.finish->color == 0 && new_Edge.start->color == 0)
			{
				new_Edge.finish->color = last_color;
				new_Edge.start->color = last_color;
				last_color += 1;
				num_colors += 1;
				minimal_tree.push_back(new_Edge);
			}

			if (num_colors == 1)
			{
				return minimal_tree;
			}
		}

		return minimal_tree;
	}

std::ostream& operator<<(std::ostream& os, const Graph& graph) {
  for (const auto& edge : graph.minimal_tree)
    {
       os << " " << edge.start->id << " <-----> " << edge.finish->id << std::endl;
    };
   return os;
   }