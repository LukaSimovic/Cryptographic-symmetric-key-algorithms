#include "algorithm.h"

string Algoritam::pretvoriUVelika(string k)
{
	string ret = "";

	for (char c : k) {
		int cc = (int)c;
		if (cc >= 97 && cc <= 122)
			cc -= 32;
		char p = (char)cc;
		ret += p;
	}

	return ret;
}
