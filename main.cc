#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAXTAILLECHAINE = 16;

char chaine[6] = "Salut";
char nom[MAXTAILLECHAINE];
char prenom[MAXTAILLECHAINE];
float moyenne;

int main()
{

 cout << "Entrez votre nom" << endl;
 cin >> nom; // cin >> nom
 cin >> ws;
 cin.get(nom, MAXTAILLECHAINE);
 cin.clear();
 cin.ignore(numeric_limits<streamsize>::max(), '\n');

 cout << "Entrez votre prenom" << endl;
 cin >> prenom;
 cin >> ws;
 cin.get(prenom, MAXTAILLECHAINE);
 cin.clear();
 cin.ignore(numeric_limits<streamsize>::max(), '\n');

 cout << "Entrez votre moyenne :" << endl;
 cin >> moyenne;
 cout << "Votre moyenne est " << moyenne << endl;
 while (moyenne < 0 || moyenne > 20)
 {
  cout << "Votre moyenne doit être comprise entre 0 et 20. Saisissez à nouveau votre moyenne :" << endl;
  cin >> moyenne;
 }
 cout << "L'eleve " << nom << " " << prenom << " a " << moyenne << " de moyenne." << endl;
 system("pause");
 // return 0;
}