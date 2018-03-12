#include "Client.h"
#include "ProduitAuxEncheres.h"
#include <iostream>

Client::Client(unsigned int codeClient)
    : Usager(),
      codeClient_(codeClient)
{
}

Client::Client(const string &nom, const string &prenom, int identifiant,
               const string &codePostal, unsigned int codeClient)
    : Usager(nom, prenom, identifiant, codePostal),
      codeClient_(codeClient)
{
}

unsigned int Client::obtenirCodeClient() const
{
    return codeClient_;
}

vector<Produit *> Client::obtenirPanier() const
{
    return panier_;
}

double Client::obtenirTotalAPayer() const
{	
	double somme = 0;
	for (int i = 0; i < panier_.size(); i++)
	{
		somme += panier_[i]->obtenirPrix();
	}
	return somme;
}

void Client::afficherPanier() const
{
    cout << "PANIER (de " << obtenirNom() << ")"
         << "\n";
    for (unsigned int i = 0; i < panier_.size(); i++)
        panier_[i]->afficher();
    cout << endl;
}

void Client::afficherProfil() const
{
	cout <<"	" <<  obtenirNom() << ", " << obtenirPrenom() << " (" << obtenirIdentifiant() << ")" << endl
		<< "	code postal:    " << obtenirCodePostal() << endl
		<< "	code client:    " << obtenirCodeClient() << endl
		<< "	panier:         " << panier_.size() << "elements" << endl;
}

void Client::modifierCodeClient(unsigned int codeClient)
{
    codeClient_ = codeClient_;
}

void Client::enleverProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
    {
        if (panier_[i] == produit)
        {
            panier_[i] = panier_[panier_.size() - 1];
            panier_.pop_back();
            return;
        }
    }
}

void Client::ajouterProduit(Produit *produit)
{
    for (unsigned int i = 0; i < panier_.size(); i++)
        if (panier_[i] == produit)
            return;
    panier_.push_back(produit);
}

void Client::reinitialiser()
{
	for (unsigned int i = panier_.size(); i > 0; i--)
	{
		const ProduitAuxEncheres* produit = dynamic_cast<const ProduitAuxEncheres*>(panier_[i]);
	}
	if (produit)
	{
		produit->mettreAjourEnchere(nullptr, produit->obtenirPrixInitial());
	}
	else
		panier_.pop_back();
	
}

	
