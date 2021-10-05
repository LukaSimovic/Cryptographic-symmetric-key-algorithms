#include "autokey.h"

Autokey::Autokey(string k)
{
	this->k = k;
}

string Autokey::sifruj(string p)
{
	string sif = "";
	string key = "";
	int br = 0; 
	
	while (br < k.length()) {
		key += k[br++];
	}

	int b;
	for (int i = 0; i < p.length(); i++) {
		char c = p[i];
		int bc = (int)c;
		if (bc >= 65 && bc <= 90) {
			int k;
			if ((int)key[i] >= 65 && (int)key[i] <= 90)
				k = (int)key[i] - 65;
			else
				k = (int)key[i] - 97;
			b = 65 + (bc - 65 + k) % 26;
		}
		else if (bc >= 97 && bc <= 122) {
			int k;
			if ((int)key[i] >= 65 && (int)key[i] <= 90)
				k = (int)key[i] - 65;
			else
				k = (int)key[i] - 97;
			b = 97 + (bc - 97 + k) % 26;
		}
		else {
			b = bc;
		}
		sif += (char)b;
		if (br < p.length())
			key += c;
	}
	return sif;
}

string Autokey::desifruj(string s)
{
	string por = "";

	string key = "";
	int br = 0; 
	
	while (br < k.length()) {
		key += k[br++];
	}

	int b;
	int d;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		int bc = (int)c;
		if (bc >= 65 && bc <= 90) {
			int k;
			if ((int)key[i] >= 65 && (int)key[i] <= 90)
				k = (int)key[i] - 65;
			else
				k = (int)key[i] - 97;

			d = (bc - 65 - k);
			if (d < 0)
				d += 26;
			b = 65 + d % 26;
		}
		else if (bc >= 97 && bc <= 122) {
			int k;
			if ((int)key[i] >= 65 && (int)key[i] <= 90)
				k = (int)key[i] - 65;
			else
				k = (int)key[i] - 97;


			d = (bc - 97 - k);
			if (d < 0)
				d += 26;
			b = 97 + d % 26;
		}
		else {
			b = bc;
		}
		por += (char)b;
		if (br < s.length()) {
			key += (char)b;
		}
	}
	return por;
}
