#include"gauss.h"
#include<iostream>

Gaus::Gaus(string klj)
{

	a[0] = klj[0];
	a[1] = klj[1];
	a[2] = klj[2];
	e[0] = klj[6];
	e[1] = klj[7];
	e[2] = klj[8];
	i[0] = klj[12];
	i[1] = klj[13];
	i[2] = klj[14];
	o[0] = klj[21];
	o[1] = klj[22];
	o[2] = klj[23];
	n[0] = klj[19];
	n[1] = klj[20];
	r[0] = klj[26];
	r[1] = klj[27];
	s[0] = klj[28];
	s[1] = klj[29];
	t[0] = klj[30];
	t[1] = klj[31];
	u[0] = klj[32];
	u[1] = klj[33];

	k = "";
	for (int i = 0; i < 39; i++) {
		if (i != 1 && i != 2 && i != 7 && i != 8 && i != 13 && i != 14 && i != 22 && i != 23 && i != 20 && i != 27 && i != 29 && i != 31 && i != 33) {
			k += klj[i];
		}
	}
	
	ba=be= bo= bi= bn= br =bs= bt=bu = 0;
}

string Gaus::sifruj(string p)
{
	string sif = "";


	for (unsigned char c : p) {
		char cc;
		int bc = (int)c;

		if (bc >= 65 && bc <= 90) {

			if (bc == 65 || bc == 69 || bc == 73 || bc == 79) {
				if (bc == 65) {
					cc = a[ba];
					ba = (ba + 1) % 3;
				}
				else if (bc == 69) {
					cc = e[be];
					be = (be + 1) % 3;
				}
				else if (bc == 73) {
					cc = i[bi];
					bi = (bi + 1) % 3;
				}
				else if (bc == 79) {
					cc = o[bo];
					bo = (bo + 1) % 3;
				}
			}
			else if (bc == 78 || bc == 82 || bc == 83 || bc == 84 || bc == 85) {
				if (bc == 78) {
					cc = n[bn];
					bn = (bn + 1) % 2;
				}
				else if (bc == 82) {
					cc = r[br];
					br = (br + 1) % 2;
				}
				else if (bc == 83) {
					cc = s[bs];
					bs = (bs + 1) % 2;
				}
				else if (bc == 84) {
					cc =t[bt];
					bt = (bt + 1) % 2;
				}
				else if (bc == 85) {
					cc = u[ bu];
					bu = (bu + 1) % 2;
				}
			}
			else {
				cc = k[bc - 65];
			}
		}
		else if ((int)c >= 97 && (int)c <= 122) {
			if (bc == 97 || bc == 101 || bc == 105 || bc == 111) {
				if (bc == 97) {
					cc = a[ba];
					ba = (ba + 1) % 3;
				}
				else if (bc == 101) {
					cc = e[be];
					be = (be + 1) % 3;
				}
				else if (bc == 105) {
					cc = i[bi];
					bi = (bi + 1) % 3;
				}
				else if (bc == 111) {
					cc = o[bo];
					bo = (bo + 1) % 3;
				}
			}
			else if (bc == 110 || bc == 114 || bc == 115 || bc == 116 || bc == 117) {
				if (bc == 110) {
					cc = n[bn];
					bn = (bn + 1) % 2;
				}
				else if (bc == 114) {
					cc = r[br];
					br = (br + 1) % 2;
				}
				else if (bc == 115) {
					cc = s[bs];
					bs = (bs + 1) % 2;
				}
				else if (bc == 116) {
					cc = t[bt];
					bt = (bt + 1) % 2;
				}
				else if (bc == 117) {
					cc = u[bu];
					bu = (bu + 1) % 2;
				}
			}
			else {
				cc = k[bc - 97];
			}
		}
		else {
			cc = c;
		}
		sif += cc;
	}

	return sif;
}

string Gaus::desifruj(string sif)
{
	string p = "";

	for (unsigned char c : sif) {
		char cc;
		int find = 0;
		for (int i = 0; i < k.length(); i++) {
			if (c == k[i]) {
				find = 1;
				cc = (char)(i + 65);
				break;
			}
		}
		if (find == 0) {
			for (int j = 1; j < 3; j++) {
				if (c == a[j]) {
					find = 1;
					cc = 'A';
					break;
				}
				else if (c == e[j]) {
					find = 1;
					cc = 'E';
					break;
				}
				else if (c == i[j]) {
					find = 1;
					cc = 'I';
					break;
				}
				else if (c == o[j]) {
					find = 1;
					cc = 'O';
					break;
				}
			}
		}
		if (find == 0) {
			for (int j = 1; j < 2; j++) {
				if (c == n[j]) {
					find = 1;
					cc = 'N';
					break;
				}
				else if (c == r[j]) {
					find = 1;
					cc = 'R';
					break;
				}
				else if (c == s[j]) {
					find = 1;
					cc = 'S';
					break;
				}
				else if (c == t[j]) {
					find = 1;
					cc = 'T';
					break;
				}
				else if (c == u[j]) {
					find = 1;
					cc = 'U';
					break;
				}
			}
		}
		if (find == 0) { //nije slovo
			cc = c;
		}

		p += cc;
	}


	return p;
}
