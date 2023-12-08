#include <iostream>
#include <string>
#include <limits>
#include <cstring>
#include <iomanip>

using namespace std;

const int MAXTAILLECHAINE = 16;

struct Eleve
{
 char nom[MAXTAILLECHAINE];
 char prenom[MAXTAILLECHAINE];
 float moyenne;
};

void SaisieEleve(Eleve &eleve);
void AfficheEleve(Eleve eleve[], int NBEleves);
void AfficheMenu(Eleve eleve[], int NBEleves);
int NBEleves;

int main()
{

 cout << "Entrez le nombre d'eleves de la classe : ";
 cin >> NBEleves;
 while (NBEleves <= 1)
 {
  cout << "Le nombre d'eleve doit etre un entier  superieur a 1 : " << endl;
  cin >> NBEleves;
 }
 Eleve *eleve = new Eleve[NBEleves];

 for (int i = 0; i < NBEleves; i++)
 {
  SaisieEleve(eleve[i]);
 }
 cout << "******Fin de la saisie des noms, prenoms et notes des " << NBEleves << " eleves de la classe" << endl;
 system("pause");
 cout << "*****Verification des saisies*****" << endl;
 AfficheEleve(eleve, NBEleves);
 system("pause");
 AfficheMenu(eleve, NBEleves);
 delete[] eleve;
 return 0;
}
//////////FONCTIONS/////////////////
void SaisieEleve(Eleve &eleve)
{
 cout << "Entrez le nom d'un eleve : ";

 cin >> ws;
 cin.get(eleve.nom, MAXTAILLECHAINE);
 cin.ignore(numeric_limits<streamsize>::max(), '\n');

 cout << "Entrez le prenom d'un eleve : ";

 cin >> ws;
 cin.get(eleve.prenom, MAXTAILLECHAINE);
 cin.ignore(numeric_limits<streamsize>::max(), '\n');

 cout << "Entrez la moyenne d'un eleve : ";
 cin >> eleve.moyenne;
 while (eleve.moyenne < 0 || eleve.moyenne > 20)
 {
  cout << "Valeur incorrecte. La moyenne doit etre comprise entre 0 et 20. Veuillez la saisir a nouveau :";
  cin >> eleve.moyenne;
 }
 cout << "L'eleve " << eleve.nom << " " << eleve.prenom << " a " << eleve.moyenne << " de moyenne" << endl;
}
////////////
void AfficheEleve(Eleve eleve[], int NBEleves)
{
 system("cls");
 for (int i = 0; i < NBEleves; i++)
 {
  cout << setfill(' ') << setw(2) << i + 1 << " : " << setw(20) << eleve[i].nom << setw(20) << eleve[i].prenom << setw(20) << eleve[i].moyenne
       << endl;
 }
}
void AfficheMenu(Eleve eleve[], int NBEleves)
{
 system("cls");

 cout
     << "Veuillez choisir le menu" << endl;
 cout << "Choix 1 = Afficher la classe" << endl;
 cout << "Choix 2 = Modifier un eleve" << endl;
 cout << "Choix 3 = Afficher le graphique" << endl;
 cout << "Choix 4 = Quitter le programme" << endl;
 cout
     << "******Menu*******" << endl;
 int choix;

 cin >> choix;
 while (choix < 1 || choix > 4)
 {
  cout << "Veuillez choisir entre 1, 2, 3 ou 4" << endl;
  cin >> choix;
 }
 switch (choix)
 {
 case 1:
  cout << "Voici la liste des eleves de la classe : " AfficheEleve(eleve, NBEleves);
  break;
 case 2:
  /*SaisieEleve(eleve[i]);*/
  break;
 case 3: /*Affiche le graphique*/
  break;
 case 4: /*Fermer le programme*/
  break;

 default:
  break;
 }
}