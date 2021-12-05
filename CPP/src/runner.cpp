//runner.cpp

#include <memory>
#include <iostream>
#include <vector>
#include "componenti.h"
using namespace std;

int sceltaNemico(std::vector<std::unique_ptr<Nemico>> &n) {
	int scelta;
	cout << "elenco nemici:" << endl;
	for (std::vector<std::unique_ptr<Nemico>>::iterator it = n.begin(); it != n.end(); it++) {
		cout << it-n.begin() << ". " << (*it)->toString() << endl;
	}
	cout << "scegli un nemico e combatti! scelta: ";
	cin >> scelta;
	return scelta;
}

void popolaNemici(std::vector<std::unique_ptr<Nemico>> &n) {	//pass by reference (altrimenti modifico una copia!)
	std::unique_ptr<Nemico> nem0 = std::make_unique<Drago> (0.5, 8);
	std::unique_ptr<Nemico> nem1 = std::make_unique<Drago> (0.1, 4);
	std::unique_ptr<Nemico> nem2 = std::make_unique<Mago> (0.5, 3);
	std::unique_ptr<Nemico> nem3 = std::make_unique<Mago> (0.6, 8);
	std::unique_ptr<Nemico> nem4 = std::make_unique<DragoMagico> (0.8, 3, 7);
	std::unique_ptr<Nemico> nem5 = std::make_unique<DragoMagico> (0.1, 5, 5);
	std::unique_ptr<Nemico> nem6 = std::make_unique<Elfo> (0.5, 5);
	std::unique_ptr<Nemico> nem7 = std::make_unique<Elfo> (0.5, 6);
	std::unique_ptr<Nemico> nem8 = std::make_unique<Elfo> (0.1, 8);
	n.push_back(std::move(nem0));
	n.push_back(std::move(nem1));
	n.push_back(std::move(nem2));
	n.push_back(std::move(nem3));
	n.push_back(std::move(nem4));
	n.push_back(std::move(nem5));
	n.push_back(std::move(nem6));
	n.push_back(std::move(nem7));
	n.push_back(std::move(nem8));
}

int main(int argc, char **argv) {
	cout << "benvenuto! immetti il tuo nick:" << endl;
	string nome;
	cin >> nome;
	cout << "REGOLE: vinci contro gli avversari con stats inferiori!" << endl;
	bool game = true;
	{
		//giocatore: smart pointer di tipo unico.. (rimosso alla fine dello scope)
		std::unique_ptr<Protagonista> prot = std::make_unique<Protagonista>(nome, 10, 5, 5, 5);
		//creo lista di nemici (unique pointer)
		std::vector<std::unique_ptr<Nemico>> nemici;
		popolaNemici(nemici);

		while (game) {
			cout << prot->toString() << endl;
			int n_index = sceltaNemico(nemici);
			if (n_index < nemici.size()) {
				if (nemici.at(n_index)->combatti(*prot)) {
					//elimina nemico sconfitto
					std::vector<std::unique_ptr<Nemico>>::iterator it = nemici.begin() + n_index;
					//cout << "rimuovo: " << nemici[n_index]->toString() <<endl;
					nemici.erase(it);
					//cout << "NEMICO SCONFITTO!" <<endl;
					cout << endl;
				}
				else cout << "azz, HAI PERSO LO SCONTRO!" << endl;
			}
			else cout << "scelta invalida" << endl;

			//check fine gioco
			if (nemici.size() == 0) {
				cout << "non è rimasto più nessun nemico, hai vinto!" <<endl;
				//stampa statistiche giocatore
				game = false;
			}
			else if (prot->getVita() <= 0) {
				cout << "giocatore esausto! fine partita." <<endl;
				cout << "ci sono ancora " << nemici.size() << " nemici vivi, hai perso!"<<endl;
				game = false;
			}
			cout << endl;
		}
	}
}

