#include <iostream>
#include <string>
#include <limits>
#include <cstring>
#include <iomanip>
#include "GL/freeglut.h"

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
void Graphique();
void GraphiqueAffichage();
void GraphiqueRedim(int x, int y);
float CalculMoyenneGenerale();
int NBEleves;
Eleve *eleve = NULL;
int main()
{

    cout << "Entrez le nombre d'eleves de la classe : ";
    cin >> NBEleves;
    while (NBEleves < 2)
    {
        cout << "Le nombre d'eleve doit etre un entier  superieur a 1 : " << endl;
        cin >> NBEleves;
    }
    eleve = new Eleve[NBEleves];

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
        cout << "Voici la liste des eleves de la classe : " << endl;
        AfficheEleve(eleve, NBEleves);
        break;
    case 2:
        system("cls");
        cout << "Entrez le numero de l'eleve : " << endl;
        int num;
        cin >> num;
        while (num < 1 || num > NBEleves)
        {
            cout << "Entrez le numero valide compris entre 1 et :" << NBEleves << endl;
            cin >> num;
        }
        SaisieEleve(eleve[num - 1]);

        break;
    case 3:
        Graphique(); // creation de la fenetre graphique

        break;
    case 4: /*Fermer le programme*/
        break;

    default:
        break;
    }
}
////////////Graphique////////
void GraphiqueAffichage()
{
    // definit la couleur de fond
    glClearColor(1.0, 1.0, 1.0, 1.0);
    // efface l'ecran
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    // ci-apres les fonctions d'affichage
    glColor3d(0.3, 0.3, 1.0); // passe en couleur bleue claire
                              // commence l'affichage d'une ligne brisée
    glBegin(GL_LINES);

    // place tous les points
    for (int i = 0; i <= 20; i += 5)
    {
        glVertex2d(0, i);
        glVertex2d(NBEleves - 1, i);
        // glVertex2d(i, eleve[i].moyenne);
    }
    // termine la ligne
    glEnd();
    // glColor3d(0.0, 0.0, 0.0); // passe en couleur noire

    glBegin(GL_LINE_STRIP);
    // place tous les points
    for (int i = 0; i < NBEleves; i++)
    {
        glVertex2d(i, eleve[i].moyenne);
    }

    glEnd();
    glColor3d(1.0, 0.0, 0.0); // passe en couleur rouge
    glBegin(GL_LINES);        // commence l'affichage de la ligne
    float Moyenne = CalculMoyenneGenerale();
    glVertex2d(0, Moyenne);
    glVertex2d(NBEleves - 1, Moyenne);
    glEnd();
    glFlush(); // fin de l'affichage
    //////
}
void GraphiqueRedim(int x, int y)
{
    glViewport(10, 10, x - 20, y - 20);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);
}
// creation de la fenetre
void Graphique()
{
    int argc = 1;
    char *argv[1] = {(char *)"Something"};
    glutInit(&argc, argv);
    glutInitWindowPosition(10, 10); // position de la fenetre
    glutInitWindowSize(640, 480);   //  taille de la fenetre
    // type d'affichages
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    // Affiche la fenetre
    glutCreateWindow("Graphique");
    // specifie les fonctions d'affichage
    glutDisplayFunc(GraphiqueAffichage);
    // specifie les fonctions de redimensionnement
    glutReshapeFunc(GraphiqueRedim);
    // lance la boucle de traitement GLUT
    glutMainLoop();
}
float CalculMoyenneGenerale()
{
    float moyGen = 0.0f;
    // parcourt les eleves un par un
    for (int i = 0; i < NBEleves; i++)
    {
        moyGen += eleve[i].moyenne;
    }
    moyGen /= NBEleves;

    return moyGen;
}