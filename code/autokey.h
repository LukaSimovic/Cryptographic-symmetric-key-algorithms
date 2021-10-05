#pragma once

#include"algorithm.h"

class Autokey : public Algoritam {
public:
	Autokey(string k);
	string sifruj(string p);
	string desifruj(string s);
};