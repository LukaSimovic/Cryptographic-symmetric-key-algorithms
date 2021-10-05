#pragma once

#include"algorithm.h"

const int MAX = 10;

class Hill : public Algoritam{
private:
	int dimMK;
	int** matK;
	int determ(int **a, int n);
	int** transponujMat(int** a);
	int** adjungovanaMat(int** a);

public:
	Hill(string k);
	string sifruj(string p);
	string desifruj(string s);
	~Hill();
};