#include "Parser.h"
#include <iostream>
#include <fstream>
void Parser:: parse()
	{
		std::ifstream inFile(filename);

		if (!inFile)
		{
			std::cerr << "Unable to open file " << filename << std::endl;
			return;
		}

		double first, second;
		int id;

		while (inFile >> id >> first >> second)
		{
			Point* point = new Point(id, first, second);
			points_list.push_back(point);
		}

		inFile.close();

		for (size_t i = 0; i < points_list.size(); ++i)
		{
			for (size_t j = i + 1; j < points_list.size(); ++j)
			{
				if (points_list[i]->id != points_list[j]->id)
				{
					edges_list.insert(Edge(points_list[i], points_list[j]));
				}
			}
		}
		return;

	};