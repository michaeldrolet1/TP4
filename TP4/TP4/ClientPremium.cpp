#include "ClientPremium.h"
#include <iostream>

ClientPremium::ClientPremium(unsigned int joursRestants)
    : Client(),
      joursRestants_(joursRestants)
{
}

ClientPremium::ClientPremium(const string &nom, const string &prenom, int identifiant,
                             const string &codePostal, unsigned int codeClient,
                             unsigned int joursRestants)
    : Client(nom, prenom, identifiant, codePostal, codeClient),
      joursRestants_(joursRestants)
{
}

unsigned int ClientPremium::obtenirJoursRestants() const
{
    return joursRestants_;
}

double ClientPremium::obtenirTotalAPayer() const
{
	double somme = 0;
	double rabais = 5;
	for (int i = 0; i < panier_.size(); i++)
	{
		somme += panier_[i]->obtenirPrix;
	}

	return somme-rabais;
}

void ClientPremium::afficherProfil() const
{
	cout <<"	" <<  obtenirNom() << ", " << obtenirPrenom() << " (" << obtenirIdentifiant() << ")" << endl
		<< "	code postal:    " << obtenirCodePostal() << endl
		<< "	code client:    " << obtenirCodeClient() << endl
		<< "	panier:         " << panier_.size() << "elements" << endl
		<< "	jours restants: " << obtenirJoursRestants() << endl;
}

void ClientPremium::modifierJoursRestants(unsigned int joursRestants)
{
    joursRestants_ = joursRestants_;
}
