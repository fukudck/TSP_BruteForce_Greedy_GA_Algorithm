#pragma once
#include "Matrix.h"
class Greedy : public Matrix
{
public:
	double cost = 0;
	vector<int> best_path;

	vector<bool> visited ;

	Greedy& operator=(const Matrix& other) {
		this->matrix = other.matrix;
		this->cities_num = other.cities_num;

		return *this;
	}
	void GSolver(int start_point);

	// For debugging
	void printPath();
};

