#pragma once

#include<string>
#include"algorithm.h"
using namespace std;

class Cezar : public Algoritam{
private:
	int kljuc; //od 0 do 25
public:
	Cezar(string k);
	string sifruj(string s) override;
	string desifruj(string s) override;

};
