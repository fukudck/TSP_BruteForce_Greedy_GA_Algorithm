#include<iostream>
#include"Matrix.h"
#include "BruteForce.h"
#include "Greedy.h"
#include "Genetic.h"
using namespace std;

int main() {

	Matrix tsp;

	string filename = "fri26_d.txt";

	ifstream file(filename);
	if (!file.is_open()) {
		cout << "File can't open" << endl;
		return 0;
	}
	tsp.importFromFile(file);
	BruteForce tsp1;
	Greedy tsp2;
	Genetic tsp3;
	
	tsp1 = tsp; tsp2 = tsp; tsp3 = tsp;
	cout << "So thanh pho: " << tsp1.cities_num << endl;
	//tsp.print();
	if (tsp.cities_num < 10) {
		tsp1.BFSolver(0);
		cout << "Bruteforce: \nMin cost: " << tsp1.min_cost << endl;
		tsp1.printPath();
		tsp1.printTimeEx();
	}
	tsp2.GSolver(0);
	cout << "Greedy: \nMin cost: " << tsp2.cost << endl;
	tsp2.printPath();
	tsp2.printTimeEx();

	tsp3.GASolver(0, 937, false);
	cout << "Genetic: \nMin cost: " << tsp3.min_cost << endl;
	tsp3.printPath();
	tsp3.printTimeEx();

	//tsp1.BFSolver(0);
	//cout << endl << tsp1.min_cost;
	//file.close();


	//tsp1.GSolver(0);
	//cout << endl << tsp1.cost<< endl;
	//tsp1.printPath();


	//vector<int> randomPath = tsp1.generateRandomPath(1);

	//std::cout << "Random path: ";
	//for (int city : randomPath) {
	//	std::cout << city << " ";
	//}
	//std::cout << std::endl;


	file.close();
	return 0;
}