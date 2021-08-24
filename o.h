#ifndef O_H_INCLUDED
#define O_H_INCLUDED
#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <ostream>

using namespace std;

// Surcharge operateur + : somme de 2 vecteurs
vector<double> sommevecteur (const vector<double>& , const vector<double>& );
// Surcharge operateur - : difference de 2 vecteurs
vector<double> differencevecteur(const vector<double>& , const vector<double>& );
// Surcharge operateur * : produit scalaire
double produitvecteur (const vector<double>& , const vector<double>& );
// Surcharge operateur * : produit vecteur x cte
vector<double> produitcons (const vector<double>& , const double& );
// Surcharge operator <<
ostream& operator << (ostream& , const vector<double> & );


// Lire un vecteur depuis un fichier
template <class T>
void lire_vect(string nom_fichier, vector<T> & vect){
    ifstream file;
    T val;
    file.open(nom_fichier,ios::in); // ouverture du fichier
    assert(!file.fail()); // verifier ouverture correcte du fichier
    while (!file.eof()){ // on lit tant qu'on est pas à la fin du fichier
        file >> val;
        vect.push_back(val);
    }
    file.close();
    //return vect;
    }
// Ecrire un vecteur dans un fichier
template <class T>
void ecrire_vect(string nom_fichier, vector<T> & vect){
    ofstream file;
    file.open(nom_fichier,ios::out); // ouverture du fichier
    assert(!file.fail()); // verifier ouverture correcte du fichier
    for (int i=0; i<vect.size(); i++)
        file << " " << vect[i];
    file.close();
}
//-----------------------------------------------------------------------------
int fact(int);
//-------------------------------------------------------
double sign(double); // fonction sign
void givens(double ,double ,double &,double &); //fonction givens


#endif // O_H_INCLUDED
