#pragma once
#include "Matrix.h"
class BruteForce : public Matrix
{
public:
	vector<int> best_path;
	double min_cost = INT_MAX;

	vector<vector<int>> all_paths;

	void BFSolver(int start_point);
	void generatePermutations(vector<int>& _cities, int start, vector<vector<int>>& _all_path);
	double calculateCost(vector<int> path);

	BruteForce& operator=(const Matrix& other) {
		this->matrix = other.matrix;
		this->cities_num = other.cities_num;

		return *this;
	}

	// For debugging
	void printAllPaths();
};

