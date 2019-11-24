#include <iostream>
#include <cstdlib>
#include "ecole.h"
#include <vector>
#include <fstream>

using namespace std;
enum CASE{
    AJOUTCLASSE=1,
    LISTECLASSE,
    AJOUTETUDIANT,
    AFFICHEETUDIANT,
    AFFICHERCLASSE,
    QUITTER
};




int main() {

    // initialiser les id
    initialiserId();


    int choix;
    vector<Classe> vecClasse(0);
    vector<Etudiant> vecEtudiant(0);


    do {
        system("CLS");
        choix = menu();
        switch(choix) {
        case AJOUTCLASSE:
            /***********************************************************************/
            system("cls");
            cout << "------------- AJOUTER UNE CLASSE -------------" << endl;
            ajoutClasse(vecClasse);
            saveFileClasse(vecClasse);
            system("pause");
            break;
            /************************************************************************/
        case LISTECLASSE :
            system("cls");
            cout << "------------- LISTE DES CLASSES -------------" << endl;
            afficherTabClasses(vecClasse);
            break;
        case AJOUTETUDIANT:
            system("cls");
            cout << "------------- AJOUTER UN ETUDIANT  -------------" << endl;
            ajouterEtudiant(vecEtudiant, saisirEtudiant(vecClasse));
            saveFileEtudiant(vecEtudiant);
            system("pause");
            break;

        case AFFICHEETUDIANT:
            system("cls");
            cout << "------------- AFFICHER LISTE DES ETUDIANTS D UNE CLASSE -------------" << endl;
            int idClasse;
            do{
                afficherTabClasses(vecClasse);
                cout << "Veuillez choisir un id de classe" << endl;
                cin >> idClasse;
            }while(idClasse <1 || idClasse > vecClasse.size());
            afficheEtudiantsParClasse(vecEtudiant, vecClasse[idClasse-1]);
            system("pause");
            break;

        case AFFICHERCLASSE:
            system("cls");
            cout << "------------- AFFICHAGE DES CLASSES PAR ORDRE CROISSANT SUR L EFFECTIF -------------" << endl;

             afficheClasseCroissant( vecClasse);
            system("pause");
            break;
            //*/
        }

    }while(choix!=QUITTER);
    return 0;
}
