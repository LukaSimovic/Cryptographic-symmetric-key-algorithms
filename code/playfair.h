#pragma once

#include"algorithm.h"

class Playfair : public Algoritam{
private:
	char mat[5][5];
	string pretvoriUVelika(string k);


public:
	Playfair(string k);
	string sifruj(string p);
	string desifruj(string s);
};