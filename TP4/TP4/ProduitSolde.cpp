#include "ProduitSolde.h"

ProduitSolde::ProduitSolde(int pourcentageRabais)
    : Produit(),
      Solde(pourcentageRabais)
{
}

ProduitSolde::ProduitSolde(Fournisseur *fournisseur, const string &nom,
                           int reference, double prix, int pourcentageRabais)
    : Produit(fournisseur, nom, reference, prix),
      Solde(pourcentageRabais)
{
}

double ProduitSolde::obtenirPrix() const
{
	
		double prixSolde = prix_ - 5;
		return prixSolde;
	
}

void ProduitSolde::afficher() const
{
	cout << "		" << nom_ << endl
		<< "     reference:	" << reference_ << endl
		<< "     prix:	    " << prix_ << endl
		<< "	 rabais:	" << (prix_- *this.obtenirPrix() << endl;
}
