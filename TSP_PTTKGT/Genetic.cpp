#include "Genetic.h"
#include <iostream>
#include<set>

unsigned int getSeed() {
	return std::chrono::system_clock::now().time_since_epoch().count();
}

bool hasUniqueElements(const std::vector<int>& vec) {
	set<int> uniqueElements;
	for (int element : vec) {
		if (uniqueElements.find(element) != uniqueElements.end()) {
			return false;
		}
		uniqueElements.insert(element);
	}
	return true;
}

Genetic::Genetic()
{
}

vector<int> Genetic::generateRandomPath(int start_point)
{	
	vector<int> path;
	for (int i = 0; i < cities_num; i++) {
		if (i == start_point) {
			continue;
		}
		path.push_back(i);
	}
	random_shuffle(path.begin(), path.end());
	path.insert(path.begin(), start_point);

	return path;
}

double Genetic::calculateCost(vector<int> path)
{
	double cost = 0;
	for (int i = 0; i < path.size() - 1; i++) {
		cost += matrix[path[i]][path[i + 1]];
	}
	cost += matrix[path.back()][path[0]];
	return cost;
}
void Genetic::randomCrossover()
{
	for(int i = 0; i < population.size() * CROSSOVER_RATE; i ++) {
		int parent1Index = rand() % population.size();
		int parent2Index = rand() % population.size();


		int point1 = rand() % (cities_num - 1) + 1;
		int point2 = rand() % (cities_num - point1) + point1;
		vector<int> child1 = population[parent1Index];
		vector<int> child2 = population[parent2Index];
		for (int i = point1; i < point2; i++) {
			swap(child1[i], child2[i]);
		}
		if (hasUniqueElements(child1)) {
			population.push_back(child1);
		}
		if (hasUniqueElements(child2)) {
			population.push_back(child2);
		}
	}

}
void Genetic::randomMutation()
{
	vector<vector<int>> mutationGens;
	double rate = randomRate();
	for (vector<int> gen : population) {
		if (rate < MUTATION_RATE) {
			vector<int> m_gen = gen;
			int idx1 = rand() % (cities_num - 1) + 1;
			int idx2 = rand() % (cities_num - idx1) + idx1;
			swap(m_gen[idx1], m_gen[idx2]);
			mutationGens.push_back(m_gen);
		}
	}
	population.insert(population.end(), mutationGens.begin(), mutationGens.end());

}
void Genetic::printPopulation()
{

}

void Genetic::removeDuplicated()
{
	set<vector<int>> uniquePaths;
	for (vector<int> element : population) {
		if (uniquePaths.find(element) != uniquePaths.end()) {
			continue;
		}
		else {
			uniquePaths.insert(element);
		}
	}
	population.clear();
	for (vector<int> element : uniquePaths) {
		population.push_back(element);
	}
	
}

void Genetic::GASolver(int start_point, int desired_cost)
{
	
	srand(getSeed());
	
	/* TO-DO
	* Khoi tao -> Tinh do thich hop -> Chon loc -> Cheo doan -> Dot Bien -> Danh Gia
	*/

	//Khoi tao
	for (int i = 0; i < POPULATION_SIZE; i++) {
		population.push_back(generateRandomPath(start_point));
	}
	
	//Lap the he
//	for (int gen = 0; gen < NUM_GENERATIONS; gen++) {
	while (true) {
		int gen = 0;
		
		srand(getSeed());
		//Danh gia
		sort(population.begin(), population.end(), [this](const auto& a, const auto& b) {
			return comparePaths(a, b);
			});

		cout << endl << endl;
		for (auto gen : population) {
			cout << calculateCost(gen) << "  ";
		}


		if (calculateCost(population[0]) <= desired_cost || gen == NUM_GENERATIONS-1) {
			min_cost = calculateCost(population[0]);
			best_path = population[0];
			best_path.push_back(start_point);
			break;
		}
		//TODO: CHON LOC
		
		if (population.size() > NUM_GENERATIONS) {
			population.erase(population.begin() + POPULATION_SIZE, population.end());
			removeDuplicated();
		}
		

		//Cheo doan

		randomCrossover();

		//Dot Bien
		randomMutation();


	}


	
}

