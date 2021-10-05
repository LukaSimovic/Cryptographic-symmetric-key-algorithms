#include"user.h"
#include"caesar.h"
#include"monoalphabet.h"
#include<iostream>
#include"gauss.h"
#include"playfair.h"
#include"vigenere.h"
#include"hill.h"
#include"autokey.h"


int Korisnik::sid = 0;

Korisnik::Korisnik(int sa)
{
	id = ++sid;
	string first = "Korisnik";
	string second = to_string(id);
	ime = first + second;
	sifAlg = sa;
}

string Korisnik::getName()
{
	return ime;
}

int Korisnik::getId()
{
	return id;
}

string Korisnik::posalji()
{
	if (sifAlg == 1) {
		Cezar cezar(kljucS);
		sifra = cezar.sifruj(mojaPoruka);
		cout <<sifra;
	}
	else if (sifAlg == 2) {
		Monoalfabet monoalf(kljucS);
		sifra = monoalf.sifruj(mojaPoruka);
		cout << sifra;
	}
	else if (sifAlg == 3) {
		Gaus gaus(kljucS);
		sifra = gaus.sifruj(mojaPoruka);
		cout << sifra;
	}
	else if (sifAlg == 4) {
		Playfair pf(kljucS);
		sifra = pf.sifruj(mojaPoruka);
		cout << sifra;
	}
	else if (sifAlg == 5) {
		Vigenere vig(kljucS);
		sifra = vig.sifruj(mojaPoruka);
		cout << sifra;
	}
	else if (sifAlg == 6) {
		Autokey ak(kljucS);
		sifra = ak.sifruj(mojaPoruka);
		cout << sifra;
	}
	else if (sifAlg == 7) {
		Hill hill(kljucS);
		sifra = hill.sifruj(mojaPoruka);
		cout << sifra;
	}
	cout << endl << endl;
	return sifra;
}

string Korisnik::primi(string s)
{
	sifra = s;
	if (sifAlg == 1) {
		Cezar cezar(kljucS);
		mojaPoruka = cezar.desifruj(sifra);
	}
	else if (sifAlg == 2) {
		Monoalfabet monoalf(kljucS);
		mojaPoruka = monoalf.desifruj(sifra);
	}
	else if (sifAlg == 3) {
		Gaus gaus(kljucS);
		mojaPoruka = gaus.desifruj(sifra);
	}
	else if (sifAlg == 4) {
		Playfair pf(kljucS);
		mojaPoruka = pf.desifruj(sifra);
	}
	else if (sifAlg == 5) {
		Vigenere vig(kljucS);
		mojaPoruka = vig.desifruj(sifra);
	}
	else if (sifAlg == 6) {
		Autokey ak(kljucS);
		mojaPoruka = ak.desifruj(sifra);
	}
	else if (sifAlg == 7) {
		Hill hill(kljucS);
		mojaPoruka = hill.desifruj(sifra);
	}
	
	return mojaPoruka;
}

void Korisnik::setMP(string s)
{
	mojaPoruka = s;
}

void Korisnik::setK(string k)
{
		kljucS = k;
}
