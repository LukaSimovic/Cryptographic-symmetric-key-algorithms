#pragma once

#include"algorithm.h"


class Monoalfabet : public Algoritam{
public:
	Monoalfabet(string k);
	string sifruj(string p);
	string desifruj(string s);
};