#pragma once

#include<string>
using namespace std;

class Algoritam {
protected:
	string k;
public:
	virtual string sifruj(string p) = 0;
	virtual string desifruj(string s) = 0;
	string pretvoriUVelika(string k);
};
