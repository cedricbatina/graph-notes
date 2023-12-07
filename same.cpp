#include <iostream>
#include <cstring>
using namespace std;

const int MAXTAILLECHAINE = 16;
char nom[MAXTAILLECHAINE];
char prenom[MAXTAILLECHAINE];
float moyenne;

int main()
{
 cout << "Entrez votre nom : " << endl;
 cin >> nom;
 cout << "Entrez votre prenom : " << endl;
 cin >> prenom;
 cout << "Entrez votre moyenne :" << endl;
 cin >> moyenne;
 cout << "Votre moyenne est " << moyenne << endl;

 while (moyenne < 0 || moyenne > 20)
 {
  cout << "Votre moyenne doit être comprise entre 0 et 20. Saisissez à nouveau votre moyenne :" << endl;
  cin >> moyenne;
 }

 cout << "L'élève " << nom << " " << prenom << " a " << moyenne << " de moyenne" << endl;
 system("pause");
 return 0;
}
