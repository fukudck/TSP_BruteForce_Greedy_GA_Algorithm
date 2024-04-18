#include "Matrix.h"
#include <iostream>
#include <sstream>
#include <chrono> 
#include <iomanip>
using namespace std::chrono;

Matrix::Matrix()
{
    cities_num = 0;
}

void Matrix::importFromFile(ifstream& file)
{
    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        vector<double> row;
        istringstream iss(line);
        double number;

        while (iss >> number) {
            row.push_back(number);
        }

        matrix.push_back(row);
        
    }
    cities_num = matrix.size();
}

void Matrix::print()
{
    for (const auto& row : matrix) {
        for (auto val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}
