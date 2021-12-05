//componenti.cpp
#include <iostream>
#include "componenti.h"
using namespace std;

//workaround veloce per stampare i float con una cifra decimale
string cutDecimal (float f) {
	string tmp = to_string(f);
	for (int i = 0; i < 5; i++) tmp.pop_back();
	return tmp;
}

//************************************
//--          Protagonista          --
//************************************
Protagonista::Protagonista(std::string n, float v, float s, float f, float m) {
	Protagonista::setNick(n);
	Protagonista::setVita(v);
	Protagonista::setVelocita(s);
	Protagonista::setForza(f);
	Protagonista::setMagia(m);
}

Protagonista::~Protagonista() {
	cout << "protagonista distrutto" << endl;
}

float Protagonista::getForza() const { return forza; }
void Protagonista::setForza(float forza) { this->forza = forza; }
float Protagonista::getMagia() const { return magia; }
void Protagonista::setMagia(float magia) { this->magia = magia; }
std::string Protagonista::getNick(){ return nick; }
void Protagonista::setNick(const std::string &nick) { this->nick = nick; }
float Protagonista::getVelocita() const { return velocita; }
void Protagonista::setVelocita(float Velocita) { this->velocita = Velocita; }
float Protagonista::getVita() const { return vita; }
void Protagonista::setVita(float vita) { this->vita = vita; }

std::string Protagonista::toString() {
	return "**STATS(" + Protagonista::getNick() + ")** vita: " + cutDecimal(Protagonista::getVita()) + " velocita: " + cutDecimal(Protagonista::getVelocita()) + " forza: " + cutDecimal(Protagonista::getForza()) + " magia: " + cutDecimal(Protagonista::getMagia());
}

//************************************
//--            Nemico              --
//************************************
Nemico::Nemico(float r) { Nemico::setReward(r); }
Nemico::~Nemico() { cout << "Nemico distrutto "; }

float Nemico::getReward() const { return reward;}
void Nemico::setReward(float reward) { this->reward = reward; }
bool Nemico::combatti(Protagonista &p) { return false; } //non dovrebbe essere mai chiamato...
std::string Nemico::toString() { return "*nemico* reward: " + cutDecimal(Nemico::getReward()); }

//************************************
//--              Drago             --
//************************************
Drago::Drago(float r, float f):Nemico(r) { Drago::setForza(f); }
Drago::~Drago() { cout << "drago distrutto "; }

float Drago::getForza() const { return this->forza; }
void Drago::setForza(float forza) { this->forza = forza;}
std::string Drago::toString() {
	//string tmp;
	//sprintf(tmp, "*Drago* reward: %.2f forza: %.2f", Nemico::getReward(), Drago::getForza());
	//return tmp;
	return "*Drago* reward: " + cutDecimal(Nemico::getReward()) + " forza: " + cutDecimal(Drago::getForza());
}
bool Drago::combatti(Protagonista &p) {
	if (p.getForza() >= Drago::getForza()) {		//nemico sconfitto, incremento i valori del protagonista
		p.setForza(p.getForza()+Nemico::getReward()*Drago::getForza());
		return true;
	}
	else {											//il nemico ha vinto, diminuisco la vita del giocatore
		p.setVita(p.getVita()-Nemico::getReward()*Drago::getForza());
		return false;
	}
}

//************************************
//--              Mago              --
//************************************
Mago::Mago(float r, float m):Nemico(r) { Mago::setMagia(m); }
Mago::~Mago() { cout << "mago distrutto "; }

float Mago::getMagia() const { return this->magia; }
void Mago::setMagia(float magia) { this->magia = magia; }

std::string Mago::toString() { return "*Mago* reward: " + cutDecimal(Nemico::getReward()) + " magia: " + cutDecimal(Mago::getMagia()); }
bool Mago::combatti(Protagonista &p) {
	if (p.getMagia() >= Mago::getMagia()) {		//nemico sconfitto, incremento i valori del protagonista
		p.setMagia(p.getMagia()+Nemico::getReward()*Mago::getMagia());
		return true;
	}
	else {											//il nemico ha vinto, diminuisco la vita del giocatore
		p.setVita(p.getVita()-Nemico::getReward()*Mago::getMagia());
		return false;
	}
}

//************************************
//--           DragoMagico          --
//************************************
DragoMagico::DragoMagico(float r, float f, float m): Nemico(r), Drago (r, f), Mago(r, m) { }
DragoMagico::~DragoMagico() { cout << "drago magico distrutto ";}

std::string DragoMagico::toString() { return "*DragoMagico* reward: " + cutDecimal(Nemico::getReward()) + " forza: " + cutDecimal(Drago::getForza()) + " magia: " + cutDecimal(Mago::getMagia()); }

bool DragoMagico::combatti(Protagonista &p) {
	if ((p.getForza() >= Drago::getForza()) && p.getMagia() >= Mago::getMagia() ) {		//nemico sconfitto, incremento i valori del protagonista
		p.setForza(p.getForza()+Nemico::getReward()*Drago::getForza());
		p.setMagia(p.getMagia()+Nemico::getReward()*Mago::getMagia());
		return true;
	}
	else {											//il nemico ha vinto, diminuisco la vita del giocatore
		p.setVita(p.getVita()-Nemico::getReward()*(Drago::getForza()+Mago::getMagia()));
		return false;
	}
}

//************************************
//--              Elfo              --
//************************************
Elfo::Elfo(float r, float v):Nemico(r) { Elfo::setVelocita(v); }
Elfo::~Elfo() { cout << "Elfo distrutto "; }

float Elfo::getVelocita() const { return this->velocita; }
void Elfo::setVelocita(float velocita) { this->velocita = velocita; }

std::string Elfo::toString() { return "*Elfo* reward: " + cutDecimal(Nemico::getReward()) + " velocita: " + cutDecimal(Elfo::getVelocita()); }
bool Elfo::combatti(Protagonista &p) {
	if (p.getVelocita() >= Elfo::getVelocita()) {		//nemico sconfitto, incremento i valori del protagonista
		p.setVelocita(p.getVelocita()+Nemico::getReward()*Elfo::getVelocita());
		return true;
	}
	else {											//il nemico ha vinto, diminuisco la vita del giocatore
		p.setVita(p.getVita()-Nemico::getReward()*Elfo::getVelocita());
		return false;
	}
}
