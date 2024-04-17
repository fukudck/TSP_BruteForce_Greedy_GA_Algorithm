#include "BruteForce.h"
#include<iostream>
using namespace std;


void BruteForce::BFSolver(int start_point)
{
	vector<int> cities;
	for (int i = 0; i < matrix.size(); i++) {
		if (i != start_point) {
			cities.push_back(i);
		}
	}
	generatePermutations(cities, 0, all_paths);
	
	for (auto& arr : all_paths) {
		arr.insert(arr.begin(), start_point);
		arr.push_back(start_point);
	}

	for (auto path : all_paths) {
		if (calculateCost(path) < min_cost) {
			min_cost = calculateCost(path);
		}
	}

}

void BruteForce::generatePermutations(vector<int>& _cities, int start, vector<vector<int>>& _all_path)
{
	if (start == _cities.size() - 1) {
		_all_path.push_back(_cities);
		return;
	}
	for (int i = start; i < _cities.size(); i++) {
		swap(_cities[start], _cities[i]);
		generatePermutations(_cities, start + 1, _all_path);
		swap(_cities[start], _cities[i]);
	}
}

double BruteForce::calculateCost(vector<int> path)
{
	double cost = 0;
	for (int i = 0; i < path.size() - 1; i++) {
		//debug	cout <<endl << matrix[path[i]][path[i + 1]];
		cost += matrix[path[i]][path[i + 1]];
	}
	return cost;
}

void BruteForce::printAllPaths()
{
	for (const auto& path : all_paths) {
		for (int num : path) {
			cout << num << " ";
		}
		cout << endl;
	}
}
