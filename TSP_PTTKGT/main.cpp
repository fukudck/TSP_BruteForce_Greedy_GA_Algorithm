#include<iostream>
#include"Matrix.h"
#include "BruteForce.h"
#include "Greedy.h"
using namespace std;

int main() {
	ifstream file("input.txt");// Dataset file
	if (!file.is_open()) {
		cout << "File can't open" << endl;
		return 0;
	}
	Matrix tsp;
	tsp.importFromFile(file);
	Greedy tsp1;
	
	tsp1 = tsp;
	cout << "So thanh pho: " << tsp1.cities_num << endl;
	tsp1.print();

	//tsp1.BFSolver(0);
	//cout << endl << tsp1.min_cost;
	//file.close();
	
	tsp1.GSolver(0);
	cout << endl << tsp1.cost<< endl;
	tsp1.printPath();

	file.close();
}