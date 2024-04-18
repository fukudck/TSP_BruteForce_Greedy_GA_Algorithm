#pragma once
#include<vector>
#include <fstream>
#include <algorithm>
#include<iostream>

using namespace std;
class Matrix
{
public:
	vector<vector<double>> matrix;
	int cities_num;
	float time;

	Matrix();

	void importFromFile(ifstream& file);
	void print();
	void printTimeEx() {
		std::cout << "Time run: " << time << " s" << endl;
	}
};

