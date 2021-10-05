#pragma once

#include"algorithm.h"

class Gaus : public Algoritam{
private:

	int a[3],e[3], o[3],i[3];

	int n[2], r[2], s[2], t[2], u[2];

	int ba, be, bo, bi, bn, br, bs, bt, bu;

public:
	Gaus(string k);
	string sifruj(string p);
	string desifruj(string s);
};