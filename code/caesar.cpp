#include "caesar.h"

string Cezar::desifruj(string s) 
{

	string por = "";

	for (unsigned char c : s) {
		char cc;
		if ((int)c >= 65 && (int)c <= 90) {
			if((int)c - 65 - kljuc >=0)
				cc = (char)(65 + ((int)c - 65 - kljuc) % 26);
			else
				cc = (char)(65 + ((int)c - 65 - kljuc +26) % 26);
		}
		else if ((int)c >= 97 && (int)c <= 122){
			if ((int)c - 97 - kljuc >= 0)
				cc = (char)(97 + ((int)c - 97 - kljuc) % 26);
			else
				cc = (char)(97 + ((int)c - 97 - kljuc + 26) % 26);
		}
		else
			cc = c;
		por += cc;
	}

	return por;
}

string Cezar::sifruj(string s)
{
	
	string sif = "";

	for (unsigned char c : s) {
		char cc;
		if ((int)c >= 65 && (int)c <= 90)
			cc = (char)(65 + ((int)c - 65 + kljuc) % 26);
		else if ((int)c >= 97 && (int)c <= 122)
			cc = (char)(97 + ((int)c - 97 + kljuc) % 26);
		else
			cc = c;
		sif += cc;
	}

	return sif;
}

Cezar::Cezar(string k)
{
	this->k = k;

	kljuc = stoi(k);
	while (kljuc < 0) {
		kljuc += 26;
	}
	kljuc %= 26;



}
