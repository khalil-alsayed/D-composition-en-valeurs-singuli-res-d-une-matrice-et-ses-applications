#include <iostream>
#include <ostream>
#if !defined (__CASSERT_H)
#include <cassert>
#endif
#include <iostream>
#include <fstream>
#include <assert.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <ostream>
#include <vector>
#include "o.h"
using namespace std;

// Surcharge operateur + : somme de 2 vecteurs
vector<double> sommevecteur (const vector<double>& v1, const vector<double>& v2){
    assert((v1.size()>0)&&(v1.size()==v2.size()));
    vector<double> w(v1.size(),0);
    for (int i=0; i<v1.size(); i++)
         w[i]= v1[i]+v2[i];
    return w;
}
// Surcharge operateur - : difference de 2 vecteurs
vector<double> differencevecteur(const vector<double>& v1, const vector<double>& v2){
    assert((v1.size()>0)&&(v1.size()==v2.size()));
    vector<double> w(v1.size(),0);
    for (int i=0; i<v1.size(); i++)
         w[i]= v1[i]-v2[i];
    return w;
}
// Surcharge operateur * : produit scalaire
double produitvecteur (const vector<double>& v1, const vector<double>& v2){
    assert((v1.size()>0)&&(v1.size()==v2.size()));
    double ps=0.0;
    for (int i=0; i<v1.size(); i++)
         ps += v1[i]*v2[i];
    return ps;
}
// Surcharge operateur * : produit vecteur x cte
vector<double> produitcons (const vector<double>& v, const double& cte){
    assert(v.size()>0);
    vector<double> w(v.size(),0);
    for (int i=0; i<v.size(); i++)
         w[i]= v[i]*cte;
    return w;
}
// Surcharge operator <<
ostream& operator << (ostream& s, const vector<double> & vect){
    assert(vect.size()>0);
    cout << " "  << endl;
    for (int i=0; i<vect.size(); i++)
        s << vect[i] << " ";
    s << endl;
    return s;
}

//-------------------------------------------------------

int fact(int k)
    {
        int c=1;
        for (int i=1; i<=k; i++)
        {
            c=c*i;
        }
        return c;
    }
//--------------------------------------------------------
// la fonction sign
double sign(double d){
if (d==0){
    return 0;
} else if (d>0){
    return 1;
} else {
    return -1;}
}
//---------------------------------------------------------------
// la fonction de givens
void givens(double a,double b,double &c,double &s ){
double r;
if (b==0)
{
    c=1;
    s=0;
}
else if(abs(b)>abs(a)){
    r=-(a/b);
    s=1/sqrt(1+pow(r,2));
    c=s*r;
}
else {
    r=-(b/a);
    c=1/sqrt(1+pow(r,2));
    s=c*r;
}


}
