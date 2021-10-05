#pragma once

#include"algorithm.h"

class Vigenere : public Algoritam{
public:
	Vigenere(string k);
	string sifruj(string p);
	string desifruj(string s);
};
