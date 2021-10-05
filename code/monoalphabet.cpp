#include"monoalphabet.h"

string Monoalfabet::sifruj(string p)
{
	string s="";


	for (unsigned char c : p) {
		char cc;
		if ((int)c >= 65 && (int)c <= 90) {
			cc = k[(int)c - 65];
		}
		else if ((int)c >= 97 && (int)c <= 122) {
			cc = k[(int)c - 97];
		}
		else {
			cc = c;
		}
		s += cc;
	}

	return s;
}

string Monoalfabet::desifruj(string s)
{
	string p="";

	for (unsigned char c : s) {
		char cc;
		int find = 0;
		for (int i = 0; i < k.length(); i++) {
			if (c == k[i]) {
				find = 1;
				cc = (char)(i + 65);
				break;
			}
		}
		if (find == 0) { //nije slovo
			cc = c;
		}	
		
		p += cc;
	}


	return p;
}

Monoalfabet::Monoalfabet(string k)
{
	this->k = k;
}
