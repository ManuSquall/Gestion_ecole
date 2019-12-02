#include <iostream>
#include <cstdlib>
#include "ecole.h"
#include <vector>
#include <fstream>

using namespace std;
//using namespace liste;


enum CASE{
    AJOUTCLASSE=1,
    LISTECLASSE,
    AJOUTETUDIANT,
    AFFICHEETUDIANT,
    AFFICHERCLASSE,
    QUITTER
};




int main() {

    listemono * lm = new listemono();
    listebi * lb = new listebi();

    lm->initialise();
    lb->initialise();




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
            ajoutClasse(lm);
            saveFileClasse(lm->T, lm->Q);
            system("pause");
            break;
            /************************************************************************/
        case LISTECLASSE :
            system("cls");
            cout << "------------- LISTE DES CLASSES -------------" << endl;
            afficherTabClasses(lm);
            break;
        case AJOUTETUDIANT:
            system("cls");
            cout << "------------- AJOUTER UN ETUDIANT  -------------" << endl;
            if(lm->isVide()== false){
            ajouterEtudiant(lb, saisirEtudiant(lm));
            saveFileEtudiant(lb->T);
            }else{
            cout << "Vous n'avez pas encore créé de classe";
            }
            system("pause");
            break;

        case AFFICHEETUDIANT:
            system("cls");
            cout << "------------- AFFICHER LISTE DES ETUDIANTS D UNE CLASSE -------------" << endl;
            int idClasse;
            do{
                afficherTabClasses(lm);
                cout << "Veuillez choisir un id de classe" << endl;
                cin >> idClasse;
            }while(idClasse <1 || idClasse > lm->taille);
            afficheEtudiantsParClasse(lb, getclassebyid(lm, (idClasse)));
            system("pause");
            break;

        case AFFICHERCLASSE:
            system("cls");
            cout << "------------- AFFICHAGE DES CLASSES PAR ORDRE CROISSANT SUR L EFFECTIF -------------" << endl;

             afficheClasseCroissant(lm);
            system("pause");
            break;
            //*/
        }

    }while(choix!=QUITTER);
    return 0;
}
