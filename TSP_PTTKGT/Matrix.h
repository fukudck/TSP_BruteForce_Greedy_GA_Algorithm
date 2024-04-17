#pragma once
#include<vector>
#include <fstream>
#include <algorithm>
using namespace std;
class Matrix
{
public:
	vector<vector<double>> matrix;
	int cities_num;

	Matrix();

	void importFromFile(ifstream& file);
	void print();
};

