#include <iostream>
#include <vector>
#include "matrice.h"
#include <string>
#include "cmath"
#include <vector>
#include <fstream>
#include <math.h>

#include "o.h"

using namespace std;
int main()
{
// ouvrire ici le crochet seulement si vous voulez essayer l'exemple analyse textuelle m=4061 n=58 (ferme le sinon)

/*matrice A(4601,58);
ifstream monspam;
monspam.open("C:/Users/khalil al sayed/Desktop/spam9.txt", ios::in);
for (int i=0;i<4601;i++){
    for (int j=0;j<58;j++)
    {
        monspam>>A[i][j];
    }
}
int m=4601;
int n=58;*/
//-------------------------------------------------------------------------

// ouvrire ici le crochet seulement si vous voulez essayer la decomposition svd pour des matrice de taille normal m<10 et n<10 (ferme le sinon)

/*int m,n;
cout<<"donner le nombre des lignes m :"<<endl;
cin>>m;
cout<<"donner le nombre des colonnes n :"<<endl;
cin>>n;
matrice A(m,n); // remplissage de la matrice A
for (int i=0;i<m;i++)
{
    for (int j=0;j<n;j++)
    {
        cout<<"donner le coeficient A["<<i+1<<"]["<<j+1<<"] :"<<endl;
        cin>>A[i][j];
    }
}
cout<<"la matrice A est:"<<A<<endl;*/
//----------------------------------------------------------------------------

// Bidiagonalisation de Golub-kahan
matrice QQ(n,100);
matrice PP(m,100);
QQ(0,1)=1;

vector<double> beta(100,0);
vector<double> alpha(100,0);

int o=0;
for (int k=1;k<n+1;k++)
  {     o+=1;

        PP.egale(k,differencevecteur(A*QQ.colonne(k),produitcons(PP.colonne(k-1),beta[k-1])));

        alpha[k]= sqrt(produitvecteur(PP.colonne(k),PP.colonne(k)));
        PP.egale(k,produitcons(PP.colonne(k),1/alpha[k]));
        QQ.egale(k+1,differencevecteur(A.transpose()*PP.colonne(k),produitcons(QQ.colonne(k),alpha[k]))) ;
        beta[k]=sqrt(produitvecteur(QQ.colonne(k+1),QQ.colonne(k+1)));

        if (beta[k]<pow(10,-4))
        {
            break;
        }

        QQ.egale(k+1,produitcons(QQ.colonne(k+1),1/beta[k]));


}
matrice B(o,o);
matrice Q(n,o);
matrice P(m,o);
for (int i=0; i<o ;i++)
{
    P.egale(i,PP.colonne(i+1));
    Q.egale(i,QQ.colonne(i+1));
}

for (int i=0; i<o; i++)
{
    B(i,i)=alpha[i+1];
    if (i<o-1)
    {
      B(i,i+1)=beta[i+1];
    }

}
matrice T;
matrice BT;
BT=B.transpose();
matrice TT;
T=B.transpose()*B;
TT=B*BT;
//-------------------------------------------------------------------------

// Algorithme QR (pour chercher la matrice V)
vector <double> a(n,0);
vector <double> b(n-1,0);
a[n-1]=T(n-1,n-1);
for (int i=0;i<n-1;i++)
{
    a[i]=T(i,i);
    b[i]=T(i,i+1);
}
int M=n-1;
double d;
double s;
double c;
double x;
double y;
double w;
double z;
double f;
double g;
double L;
matrice QQQ(n,n);
for (int i=0;i<n;i++)
{
    QQQ(i,i)=1;
}
while (M>0) {
        d= (a[M-1]-a[M])/2; // calcule de shift de Wilkinson
        if (d==0)
        {
            s= a[M]-abs(b[M-1]);
        }
        else {
            s=a[M]-(pow(b[M-1],2)/(d+sign(d)*sqrt(pow(d,2)+pow(b[M-1],2))));}
        x= a[0]-s; // QR step commence ici
        y= b[0];
        for (int k=0; k<M;k++)
        {
            if (M>1)
            {
                givens(x,y,c,s);
            }
            else{
                c=1;
                s=((a[0]-a[1])-sqrt(pow((a[0]-a[1]),2)+4*pow(b[0],2)))/(2*b[0]);
            }
            w=c*x-s*y;
            d=a[k]-a[k+1];
            z=(2*c*b[k]+d*s)*s;
            a[k]=a[k]-z;
            a[k+1]=a[k+1]+z;
            b[k]=d*c*s+(pow(c,2)-pow(s,2))*b[k];
            x=b[k];
            if (k>0)
            {
                b[k-1]=w;
            }
            if (k<M-1)
            {
                y=-s*b[k+1];
                b[k+1]=c*b[k+1];
            }
            for (int i=0;i<n;i++)
            {   f=QQQ(i,k);
                g=QQQ(i,k+1);
                QQQ(i,k)=f*c-g*s;
                QQQ(i,k+1)=f*s+g*c;
            }


        }
        if  (abs(b[M-1])<pow(10,-5)*(abs(a[M-1])+abs(a[M]))) // tester la convergence
        {
            M=M-1;
        }

}
//--------------------------------------------------------------------------------------------
// Algorithme QR (pour chercher la matrice U)
vector <double> aa(n,0);
vector <double> bb(n-1,0);
aa[n-1]=TT(n-1,n-1);
for (int i=0;i<n-1;i++)
{
    aa[i]=TT(i,i);
    bb[i]=TT(i,i+1);
}
int MM=n-1;
double dd;
double ss;
double cc;
double xx;
double yy;
double ww;
double zz;
double ff;
double gg;
double LL;
matrice QQQU(n,n);
for (int i=0;i<n;i++)
{
    QQQU(i,i)=1;
}
while (MM>0) {
        d= (aa[MM-1]-aa[MM])/2; // calcule de shift de Wilkinson
        if (dd==0)
        {
            ss= aa[MM]-abs(bb[MM-1]);
        }
        else {
            ss=aa[MM]-(pow(bb[MM-1],2)/(dd+sign(dd)*sqrt(pow(dd,2)+pow(bb[MM-1],2))));}
        xx= aa[0]-ss; // QR step commence ici
        yy= bb[0];
        for (int k=0; k<MM;k++)
        {
            if (MM>1)
            {
                givens(xx,yy,cc,ss);
            }
            else{
                cc=1;
                ss=((aa[0]-aa[1])-sqrt(pow((aa[0]-aa[1]),2)+4*pow(bb[0],2)))/(2*bb[0]);
            }
            ww=cc*xx-ss*yy;
            dd=aa[k]-aa[k+1];
            zz=(2*cc*bb[k]+dd*ss)*ss;
            aa[k]=aa[k]-zz;
            aa[k+1]=aa[k+1]+zz;
            bb[k]=dd*cc*ss+(pow(cc,2)-pow(ss,2))*bb[k];
            xx=bb[k];
            if (k>0)
            {
                bb[k-1]=ww;
            }
            if (k<MM-1)
            {
                yy=-ss*bb[k+1];
                bb[k+1]=cc*bb[k+1];
            }
            for (int i=0;i<n;i++)
            {   ff=QQQU(i,k);
                gg=QQQU(i,k+1);
                QQQU(i,k)=ff*cc-gg*ss;
                QQQU(i,k+1)=ff*ss+gg*cc;
            }


        }
        if  (abs(bb[MM-1])<pow(10,-5)*(abs(aa[MM-1])+abs(aa[MM]))) // tester la convergence
        {
            MM=MM-1;
        }

}
//-----------------------------------------------------------------------------
// la dernière touche pour construire U et V et Sigma
matrice V(n,n);
vector<double> VV;
V=Q*QQQ;
matrice U(m,n);
vector<double> UU;
U=P*QQQU;
if (a[n-1]>a[n-2]){
L=a[n-2];
a[n-2]=a[n-1];
a[n-1]=L;
VV=V.colonne(n-2);
V.egale(n-2,V.colonne(n-1));
V.egale(n-1,VV);
UU=U.colonne(n-2);
U.egale(n-2,U.colonne(n-1));
U.egale(n-1,UU);}
for (int i=0;i<n;i++)
{
    a[i]=sqrt(a[i]);
}
matrice Sigma(m,n);
for (int i=0;i<n;i++)
{
    Sigma[i][i]=a[i];
}
//----------------------------------------------------------------------------

// ouvrire ici le crochet seulement si vous voulez essayer la decomposition svd pour des matrice de taille normal m<10 et n<10 (ferme le sinon)

/*cout<<"le matrice Sigma des valeurs singuliers de A est : "<<Sigma<<endl;

cout<<"le matrice V de SVD est : "<<V<<endl;

cout<<"le matrice U de SVD est : "<<U<<endl;*/
//--------------------------------------------------------------------------------

// ouvrire ici le crochet seulement si vous voulez essayer l'exemple analyse textuelle m=4061 n=58 (ferme le sinon)

/*ofstream file1;
file1.open("C:/Users/khalil al sayed/Desktop/aa.txt",ios::in);
for (int i=0;i<n;i++)
{
    file1<<a[i]<<'\t';
}

ofstream file2;
file2.open("C:/Users/khalil al sayed/Desktop/VV.txt",ios::in);
for (int i=0;i<n;i++)
{
    for (int j=0;j<n;j++)
    {
        file2<<V[i][j]<<'\t';
    }
    file2<<'\n';

}


ofstream file3;
file3.open("C:/Users/khalil al sayed/Desktop/UU.txt",ios::in);
for (int i=0;i<m;i++)
{
    for (int j=0;j<n;j++)
    {
        file3<<U[i][j]<<'\t';
    }
    file3<<'\n';

}

*/

//-------------------------------------------------------------------------





}
