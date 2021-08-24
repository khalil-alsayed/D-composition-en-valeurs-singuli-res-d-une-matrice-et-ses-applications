#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED
#if !defined (__VECTOR_H)
#include <vector>
#endif
#if !defined (__FSTREAM_H)
#include <fstream>
#endif

using namespace std;
class matrice
{
protected:
    int size1;
    int size2;
    vector<double>* matrix;
public:
    matrice()
    {
        this->size1 = this->size2 = 0;
    };
    matrice(int,int);
    matrice(const matrice&);
    ~matrice();
    int dim1() const
    {
        return this->size1;   // retourne la 1ere dimension de la matrice
    }
    int dim2() const
    {
        return this->size2;   // retourne la 2eme dimension de la matrice
    }
    vector<double>& operator [] (int) const;  // retourne une ligne complete
    double& operator () (int,int) const;      // retourne un coefficient
    matrice& operator = (const matrice&); // surcharge de = (affectation)
    void  egale(const int , const vector<double>&); // Surcharge = (affectation) vecteur
    matrice transpose();    // transpose une matrice
    vector<double> colonne(const int);    // une colonne de la matrice
    matrice operator+(const matrice&); // somme de 2 matrices
    matrice operator-(const matrice&); // difference de 2 matrices
    matrice operator*(matrice&); // produit de 2 matrices, pas const matrice& à cause de transpose()
    matrice operator*(const double&); // matrice x cte
    vector<double> operator*(const vector<double>&); // produit A*v
    friend vector<double> operator*(const vector<double>&, matrice&); // produit v^t * A
    friend ostream& operator << (ostream&, const matrice &);        // surcharge << pour une matrice
    friend istream& operator >> (istream&, const matrice &);        // surcharge >> pour une matrice
    void save_matr(const char*); // ecriture dans un fichier
    void read_matr(const char *);  // lecture dans un fichier
};



#endif // MATRICE_H_INCLUDED
