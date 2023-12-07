#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAXTAILLECHAINE = 16;
const int NBEleves = 5;

struct Eleve
{
     char nom[MAXTAILLECHAINE];
     char prenom[MAXTAILLECHAINE];
     float moyenne;
};

int main(int argc, char const *argv[])
{
     Eleve tab[NBEleves];
     for (int i = 0; i < NBEleves; i++)
     {
          cout << "Entrez le nom d'un eleve : ";
          cin >> ws;

          cin.get(tab[i].nom, MAXTAILLECHAINE);
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');

          cout << "Entrez le prenom d'un eleve : ";
          cin >> ws;
          cin.get(tab[i].prenom, MAXTAILLECHAINE);
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Entrez la moyenne d'un eleve: ";
          cin >> tab[i].moyenne;
          while (tab[i].moyenne < 0 || tab[i].moyenne > 20)
          {
               cout << "Valeur incorrecte. La moyenne doit être comprise entre 0 et 20"
                    << "Veuillez la saisir a nouveau :";
               cin >> tab[i].moyenne;
          }
          cout << "L'eleve " << tab[i].nom << " " << tab[i].prenom << " a " << tab[i].moyenne << " de moyenne." << endl;
          return 0;
     }
}