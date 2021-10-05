#include<iostream>
#include <time.h> 
#include"user.h"

using namespace std;

string ukloniRazmake(string p) {
	string ret = "";

	for (unsigned char c : p) {
		if ((int)c != 32)
			ret += c;
	}

	return ret;
}

void main() {

	int sa;
	int kom;
	string k, p,s;


	ALG:
	do {
		k = "";

		cout << "Sta zelite?\n\t0: Sifrovanje\n\t1: Desifrovanje\n\n\t-1: KRAJ\n\n";
		cin >> kom;
		
		if (kom == 0) {
			cout << "Kojim algoritmom zelis da K1 sifruje poruku?\n 1: CEZAROV ALGORITAM\n 2: MONOALFABETSKA SIFRA\n" <<
				" 3: GAUSOVA METODA\n 4: PLAYFAIR ALGORITAM\n 5: VIZENJEROV ALGORITAM\n 6: AUTOKEY ALGORITAM\n 7: HILOVA SIFRA\n\n";
			cin >> sa;

			Korisnik k1(sa);

			switch (sa) {
			case 1:

				cout << "Kljuc (Unesite broj od 1 do 25):\n";
				cin >> k;

				goto KOMUNIKACIJA;

			case 2:

				int niz[26];
				int find;
				srand(time(NULL));
				for (int i = 0; i < 26; ) {
					find = 0;
					int r = rand() % 26;
					for (int j = 0; j < i; j++) {
						if (niz[j] == r) {
							find = 1; break;
						}
					}
					if (find == 0) {
						niz[i] = r;
						i++;
					}
				}
				for (int i = 0; i < 26; i++) {
					k += (char)(niz[i] + 65);
				}
				cout << "Kljuc: ABCDEFGHIJKLMNOPQRSTUVWXYZ\n       " << k << endl;

				goto KOMUNIKACIJA;

			case 3:
				int nizG[39];
				int findG;
				int pom;
				pom = 34;
				srand(time(NULL));
				for (int i = 0; i < 39; ) {
					findG = 0;
					int r = (rand() % 26) + 65;
					for (int j = 0; j < i; j++) {
						if (nizG[j] == r) {
							findG = 1; break;
						}
					}
					if (findG == 0) {
						nizG[i] = r;
						if (i == 0 || i == 6 || i == 12 || i == 21) { //dva dodatna
							nizG[++i] = pom++;
							nizG[++i] = pom++;
						}
						else if (i == 19 || i == 26 || i == 28 || i == 30 || i == 32) { //jedno dodatno
							nizG[++i] = pom++;
						}
						i++;
					}
				}
				for (int i = 0; i < 39; i++) {
					k += (char)(nizG[i]);
				}

				cout << "Kljuc: A  BCDE  FGHI  JKLMN O  PQR S T U VWXYZ\n       " << k << endl;
				goto KOMUNIKACIJA;

			case 4:
			case 5:
			case 6:
				cout << "Kljuc:   ";
				cin >> k;
				goto KOMUNIKACIJA;

			case 7:

				int pok;
				pok = 0;
				do {
					if (pok != 0) {
						cout << "ZADATI KLJUC NE ISPUNJAVA USLOV! POKUSAJTE OPET!" << endl;
					}
					else {
						cout << "Kljuc: \n";
					}
					cin >> k;


					pok++;
					if (pok == 10) {
						cout << "VI STE RETARDIRANI! IZABERITE DRUGI ALGORITAM!" << endl;
						goto ALG;
					}
				} while (k.length() != 1 && k.length() != 4 && k.length() != 9 && k.length() != 16 && k.length() != 100
					&& k.length() != 25 && k.length() != 36 && k.length() != 49 && k.length() != 64 && k.length() != 81);

				goto KOMUNIKACIJA;

			KOMUNIKACIJA:
				k1.setK(k);
				cout << "Poruka:   ";
				cin.ignore();
				getline(cin, p);
				p = ukloniRazmake(p);
				k1.setMP(p);
				cout << "\nK1 poslao poruku:   ";
				s = k1.posalji();

				int odg;
				cout << "Da li zelite da korisnik K2 desifruje poruku?\n\t 0: NE\n\t 1: DA\n";
				cin >> odg;

				if(odg==1){
					Korisnik k2(sa);
					k2.setK(k);
					p = k2.primi(s);
					cout << "\n\nK2 primio poruku, poruka:   " << p << "\n\n";
				}
			}

		}
		else if (kom == 1) {
		cout << "Kojim algoritmom zelis da K1 desifruje poruku?\n 1: CEZAROV ALGORITAM\n 2: MONOALFABETSKA SIFRA\n" <<
			" 3: GAUSOVA METODA\n 4: PLAYFAIR ALGORITAM\n 5: VIZENJEROV ALGORITAM\n 6: AUTOKEY ALGORITAM\n 7: HILOVA SIFRA\n\n";
		cin >> sa;

		Korisnik k1(sa);

		cout << "\nUnesite kljuc:  ";
		cin >> k;
		k1.setK(k);
		cout << "Unesite sifru:  ";
		cin >> s;
		p = k1.primi(s);
		cout << "\nK2 primio sifru, poruka:  " << p << "\n\n";

		}
		else if (kom != -1) {
			cout << "Pogresan unos! Pokusajte opet: " << endl;
		}

		
		
	} while (kom != -1);

}


