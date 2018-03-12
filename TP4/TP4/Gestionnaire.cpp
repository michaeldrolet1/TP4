#include "Gestionnaire.h"

vector<Usager *> Gestionnaire::obtenirUsagers() const
{
    return usagers_;
}

void Gestionnaire::afficherLesProfils() const
{
	cout << "PROFILS" << endl;
	for (int i = 0; i < usagers_.size(); i++)
	{
		cout << usagers_[i]->afficherProfil << endl;
		
	}
	
}

double Gestionnaire::obtenirChiffreAffaires() const
{
	double somme = 0;
	for (int i = 0; i < usagers_.size(); i++)
	{
		
		somme += usagers_[i]->obtenirTotalAPayer;
		
	}
	return somme;
}

void Gestionnaire::ajouterUsager(Usager *usager)
{
	bool nonpresent = true;
	for (int i = 0; i < usagers_.size(); i++)
	{
		if (usagers_[i] = usager)
			nonpresent = false;

	}
	if (nonpresent)
	usagers_.push_back(usager);
}

void Gestionnaire::reinitialiser()
{
	for (int i = 0; i < usagers_.size(); i++)
	{

		usagers_[i]->reinitialiser();

	}
}

void Gestionnaire::encherir(Client *client, ProduitAuxEncheres *produit, double montant) const
{
	if (*produit->obtenirPrix < montant)
		produit->mettreAJourEnchere(client, montant);
}
