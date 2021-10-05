#include "hill.h"
#include<iostream>

int Hill::determ(int **a, int n)
{
	int det = 0, p, h, k, i, j;
	int** temp;
	temp = new int* [n];
	for (int i = 0; i < n; ++i)
		temp[i] = new int[n];


	if (n == 1) {
		return a[0][0];
	}
	else if (n == 2) {
		det = (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
		return det;
	}
	else {
		for (p = 0; p < n; p++) {
			h = 0;
			k = 0;
			for (i = 1; i < n; i++) {
				for (j = 0; j < n; j++) {
					if (j == p) {
						continue;
					}
					temp[h][k] = a[i][j];
					k++;
					if (k == n - 1) {
						h++;
						k = 0;
					}
				}
			}
			det = det + a[0][p] * pow(-1, p) * determ(temp, n - 1);
		}
		return det;
	}
}

int** Hill::transponujMat(int** a) {

	int** temp;
	temp = new int* [dimMK];
	for (int i = 0; i < dimMK; ++i)
		temp[i] = new int[dimMK];

	for (int i = 0; i < dimMK; i++) {
		for (int j = 0; j < dimMK; j++) {
			temp[j][i] = a[i][j];
		}
	}
	
	return temp;
}

int** Hill::adjungovanaMat(int** a) {

	int** temp;
	temp = new int* [dimMK];
	for (int i = 0; i < dimMK; ++i)
		temp[i] = new int[dimMK];

	for (int i = 0; i < dimMK; i++) {
		for (int j = 0; j < dimMK; j++) {

			int** temp2;
			temp2 = new int* [dimMK-1];
			for (int k = 0; k < dimMK-1; ++k)
				temp2[k] = new int[dimMK-1];

			int r = 0, s = 0;
			for (int m = 0; m < dimMK; m++) {
				for (int n = 0; n < dimMK; n++) {
					if (i == m || j == n)
						continue;
					temp2[r][s] = a[m][n];
					s++;
					if (s == dimMK - 1) {
						s = 0;
						r++;
					}
				}
			}


			temp[i][j] = determ(temp2, dimMK - 1);

			for (int p = 0; p < dimMK-1; ++p)
				delete[] temp2[p];
			delete[] temp2;

			if ((i + j) % 2 == 1)
				temp[i][j] *= -1;

			while (temp[i][j] < 0) {
				temp[i][j] += 26;
			}
			temp[i][j] %= 26;
		}
	}


	return temp;
}


Hill::Hill(string k)
{
	k = pretvoriUVelika(k);

	this->k = k;
	dimMK = sqrt(k.length());
	matK = new int* [dimMK];
	for (int i = 0; i < dimMK; ++i)
		matK[i] = new int[dimMK];

	int br = 0;
	for (int i = 0; i < dimMK; i++) {
		for (int j = 0; j < dimMK; j++) {
			char c = k[br++];
			matK[i][j] = (int)c - 65;
		}
	}

	cout << endl << "KLJUC:" << endl;
	for (int i = 0; i < dimMK; i++) {
		for (int j = 0; j < dimMK; j++) {
			cout << matK[i][j] << "\t";
		}
		cout << endl;
	}
	
}

string Hill::sifruj(string p)
{
	string sif = "";

	/*
	cout <<endl<< "KLJUC:" << endl;
	for (int i = 0; i < dimMK; i++) {
		for (int j = 0; j < dimMK; j++) {
			cout << matK[i][j] << "\t";
		}
		cout << endl;
	}
	*/
	int br = 0;
	int* deo = new int[dimMK];
	while (br+dimMK <= p.length()) {
		for (int pom = 0; pom < dimMK; pom++) {
			int sl = (int)p[br++];
			if (sl >= 65 && sl <= 90)
				deo[pom] = sl - 65;
			else if (sl >= 97 && sl <= 122)
				deo[pom] = sl - 97;
			else
				deo[pom] = sl;
		}

		int obr = 0;
		while (obr < dimMK) {
			int elem = 0;
			for (int tmp = 0; tmp < dimMK; tmp++) {
				elem += matK[tmp][obr] * deo[tmp];
			}
			elem %= 26;
			sif+=(char)(elem+65);
			obr++;
		}
	}
	int ost = p.length() - br;
	int n = 0;
	if(ost!=0){
		while (ost != 0) {
			int sl = (int)p[br++];
			if (sl >= 65 && sl <= 90)
				deo[n] = sl - 65;
			else if (sl >= 97 && sl <= 122)
				deo[n] = sl - 97;
			else
				deo[n] = sl;

			n++;
			ost--;
		}
		while (n < dimMK) {
			deo[n++] = (int)('X' - 65);
		}

		int obr = 0;
		while (obr < dimMK) {
			int elem = 0;
			for (int tmp = 0; tmp < dimMK; tmp++) {
				elem += matK[tmp][obr] * deo[tmp];
			}
			elem %= 26;
			sif += (char)(elem + 65);
			obr++;
		}
	}

	delete deo;

	return sif;
}

string Hill::desifruj(string s)
{
	string por = "";

	//DET(K):
	int det = determ(matK, dimMK);
	while (det < 0) {
		det += 26;
	}

	//DET(K)^-1:
	int i;
	for ( i = 0; i < 26; i++) {
		if ((det * i) % 26 == 1)
			break;
	}
	int b=0;
	if (i != 26) {
		b = i;
	}
	else {
		cout << "\n\nPORUKA SE NE MOZE DESIFROVATI SA OVIM KLJUCEM! ZAMOLITE POSILJAOCA DA POSALJE OPET PORUKU SA NEKIM DRUGIM KLJUCEM!\n\n";
		return "/";
	}

	//TRANSPONOVANA:
	matK= transponujMat(matK);

	//ADJUNGOVANA:
	matK = adjungovanaMat(matK);

	//INVERZNA: 
	for (int i = 0; i < dimMK; i++) {
		for (int j = 0; j < dimMK; j++) {
			matK[i][j] *= b;
			matK[i][j] %= 26;
		}
	}
	

	//MNOZENJE C*K^-1:
	int br = 0;
	int* deo = new int[dimMK];
	while (br < s.length()) {
		for (int pom = 0; pom < dimMK; pom++) {
			int sl = (int)s[br++];
			if (sl >= 65 && sl <= 90)
				deo[pom] = sl - 65;
			else
				deo[pom] = sl;
		}

		int obr = 0;
		while (obr < dimMK) {
			int elem = 0;
			for (int tmp = 0; tmp < dimMK; tmp++) {
				elem += matK[tmp][obr] * deo[tmp];
			}
			elem %= 26;
			por += (char)(elem + 65);
			obr++;
		}
	}
	//br=s.length()
	int duz = por.length();
	int del = 0;
	br--;
	while (por[br] == 'X') {
		br--;
		del++;
	}
	por=por.substr(0, duz - del);

	return por;
}

Hill::~Hill()
{
	for (int i = 0; i < dimMK; ++i)
		delete[] matK[i];
	delete[] matK;
}
