#include"playfair.h"
#include<iostream>

Playfair::Playfair(string k)
{
	int brk; brk = 0;
	int brm; brm = 65;
	int keyNotEnd; keyNotEnd = 1;
	int put = 0;

	k = pretvoriUVelika(k);

	for (int p = 0; p < k.length(); p++) {
		if (k[p] == 'J')
			k[p] = 'I';
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			put = 0;
			if (keyNotEnd) {
				while (brk < k.length()) {
					int find = 0;
					for (int pb = 0; pb < brk; pb++) {
						if (k[pb] == k[brk]) {
							find = 1;
							brk++;
							break;
						}
					}
					if (find == 0) {
						mat[i][j] = k[brk++];
						put = 1;
						break;
					}
				}
				if (brk == k.length())
					keyNotEnd = 0;
			}

			if (!keyNotEnd && put==0) {
				while (1) {
					char c = (char)brm;
					if (c == 'J') {
						brm++;
						c = (char)brm;
					}
					int find = 0;
					for (int p = 0; p < k.length(); p++) {
						if (k[p] == c) {
							find = 1;
							brm++;
							break;
						}
					}
					if (find == 0) {
						mat[i][j] = c;
						brm++;
						break;
					}
				}
			}

		}
	}

	


}

string Playfair::sifruj(string p)
{
	string sif = "";

	p = pretvoriUVelika(p);

	int br = 0;
	char c1, c2;
	int r1, k1, r2, k2;

	/*
	cout << "MATIRCA:\n";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
	*/

	while (br < p.length()) {

		
		 c1 = p[br++];
		 if (c1 == 'J') {
			 c1 = 'I';
		 }
		 if (br == p.length() ) {
			 c2 = 'X';
			 br++;
		 }
		 else {
			 c2 = p[br];
			 if (c2 == 'J') {
				 c2 = 'I';
			 }
			 if (c1 == c2) {
				 c2 = 'X';
			 }
			 else {
				 br++;
			 }
		 }
		 for (int i = 0; i < 5; i++) {
			 for (int j = 0; j < 5; j++) {
				 if (mat[i][j] == c1) {
					 r1 = i;
					 k1 = j;
				 }
				 if (mat[i][j] == c2) {
					 r2 = i;
					 k2 = j;
				 }
			 }
		 }
		 if (r1 == r2) {
				sif += mat[r2][(k1+1)%5];
				sif += mat[r2][(k2 + 1) % 5];
		 }
		 else if (k1 == k2) {
				 sif += mat[(r1+1)%5][k2];
				 sif += mat[(r2+1)%5][k2];
		 }
		 else {
			sif += mat[r1][k2];
			sif += mat[r2][k1];
		 }

	}

	return sif;
}

string Playfair::desifruj(string s)
{
	string por = "";

	int br = 0;
	char c1, c2;
	int r1, k1, r2, k2;
	char d1, d2;

	while (br < s.length()) {
		c1 = s[br++];
		c2 = s[br++];
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (c1 == mat[i][j]) {
					r1 = i; k1 = j;
				}
				if (mat[i][j] == c2) {
					r2 = i; k2 = j;
				}
			}
		}
		if (r1 == r2) {
			d1 = mat[r1][(k1 + 4) % 5];
			d2 = mat[r1][(k2 + 4) % 5];
		}
		else if (k1 == k2) {
			d1 = mat[(r1 + 4) % 5][k1];
			d2 = mat[(r2 + 4) % 5][k1];
		}
		else {
			d1= mat[r1][k2];
			d2= mat[r2][k1];
			
		}
		por += d1;
		if (d2 != 'X') 
			por += d2;
		

	}

	return por;
}

string Playfair::pretvoriUVelika(string k)
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
