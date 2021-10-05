#pragma once

#include<string>
using namespace std;

class Korisnik {
private:
	static int sid;
	int id;
	string ime;
	int sifAlg; //1-cezar, 2-
	string mojaPoruka;
	string kljucS;
	string sifra;

public:
	Korisnik(int sa);
	string getName();
	int getId();
	void setMP(string s);
	void setK(string k);
	string posalji();
	string primi(string s);
};
