#include "Greedy.h"
#include <iostream>

void Greedy::GSolver(int start_point)
{
	visited.resize(matrix.size());
	int current_city = start_point;
	best_path.push_back(start_point);

	bool flag = true;
	while (flag) {
		double current_min_cost = INT_MAX;
		int nearest_city;
		visited[current_city] = true;

		for (int i = 0; i < matrix.size(); i++) {
			if (matrix[current_city][i] != 0 && !visited[i]) {
				if (matrix[current_city][i] < current_min_cost) {
					current_min_cost = matrix[current_city][i];
					nearest_city = i;
				}
			}
		}
		if (current_min_cost != INT_MAX) {
			cost += current_min_cost;
			best_path.push_back(nearest_city);
			current_city = nearest_city;

		}
		else {
			cost += matrix[current_city][start_point];
			visited.clear();
			best_path.push_back(start_point);
			flag = false;
		}


	}



}

void Greedy::printPath()
{
	for (auto city : best_path) {
		cout << city << "\t";
	}
}
