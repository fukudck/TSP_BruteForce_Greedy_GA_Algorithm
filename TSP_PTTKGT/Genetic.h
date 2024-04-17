#pragma once
#include "Matrix.h"
#include <random>
#include <chrono>
class Genetic :public Matrix
{
public:
	//Note
	int POPULATION_SIZE = 100;
	double CROSSOVER_RATE = 1;
	double MUTATION_RATE = 1;
	int NUM_GENERATIONS = 100;

	int seed = 30041975;

	double min_cost;
	vector<int> best_path;

	Genetic();
	//To-Do
	vector<vector<int>> population;

	void GASolver(int start_point, int desired_cost);

	vector<int> generateRandomPath(int start_point);

	double calculateCost(vector<int> path);

	void randomCrossover();

	void randomMutation();

	bool comparePaths(const vector<int>& path1, const vector<int>& path2) {
		return calculateCost(path1) < calculateCost(path2);
	}



	Genetic& operator=(const Matrix& other) {
		this->matrix = other.matrix;
		this->cities_num = other.cities_num;
		return *this;
	}

	//Debugging Function
	void printPopulation();
	double randomRate() {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_real_distribution<> dis(0, 1);
		double rate = dis(gen);//Tao rate
		return rate;
	}
	void removeDuplicated();
};

