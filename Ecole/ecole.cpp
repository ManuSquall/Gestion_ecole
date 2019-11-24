#include <iostream>
#include <cstdlib>
#include "ecole.h"
#include <vector>
#include <sstream>
#include <fstream>
int g_idClasse = getIdClasse();
int g_idEtudiant = getIdEtudiant();


using namespace std;


ofstream oFichId;
ofstream oFichClass;
ofstream oFichEtud;


int menu() {
    int choix;
    do{
        cout << "1 : ..........................Ajouter une Classe" << endl;
        cout << "2 : .........................Afficher les Classe" << endl;
        cout << "3 : ........................Ajouter un Etudiant dans la Classe" << endl;
        cout << "4 : .......................Liste des Etudiant d'une classe" << endl;
        cout << "5 : ....Afficher les classes par ordre croissant sur le nombre d etudiants" << endl;
        cout << "6 : QUITTER..............................................................";
        cin >> choix;
        if(choix<1 || choix >6) {
            cout << endl << "CHOIX IMPOSSIBLE :(" << endl;
            system("pause");
            system("cls");
        }
    }while(choix<1 || choix >6);

     return choix;
}
void afficherEtudiant(Etudiant e) {
    cout << "ID : " << e.id << endl;
    cout << "NOM : " << e.nom << endl;
    cout << "PRENOM : " << e.prenom << endl;
    cout << "AGE : " << e.age << endl;
    cout << "CLASSE : " << e.classe.libelle << endl;
}

Classe saisirClasse(){
    Classe c;
    c.id = ++g_idClasse;
    // on incrémente l'id classe dans le fichier
    setIdClass(g_idClasse);
    cout << "Donner le libelle de la classe " << endl;
    cin >> c.libelle;
    do{
        cout << "Donnez le seuil de l effectif de la classe" << endl;
        cin >> c.seuilEffectif;
        if(c.seuilEffectif < 1) {
            cout << "Seuil invalide " << endl;
        }
    }while(c.seuilEffectif < 1);
    c.effectif = 0;
    return c;
}
void ajoutClasse(vector<Classe> &vecClasse){
    vecClasse.push_back(saisirClasse());

}
void afficherTabClasses(vector<Classe> &vecClasse) {
    int i;
    for(i=0; i<(vecClasse.size()); i++) {
        afficherClasse(vecClasse[i]);
        cout << "---------------------------------------------" << endl;
    }
    system("pause");
}
void afficherClasse(Classe cl) {
    cout << "CLASSE : " << cl.libelle << endl;
    cout << "ID CLASSE : " << cl.id << endl;
    cout << "EFFECTIF CLASSE : " << cl.effectif << endl;
    cout << "EFFECTIF LIMITE DE La CLASSE : " << cl.seuilEffectif << endl;
}


Etudiant saisirEtudiant(vector<Classe> &vecClasse){
    Etudiant e;
    int idClasse;
    e.id = ++g_idEtudiant;
    // on incrémente l'id etudiant dans le fichier
    setIdEtu(g_idEtudiant);
    string classe;
    cout << "Donnez le nom de l'etudiant" << endl;
    cin >> e.nom;
    cout << "Donnez le prenom de l'etudiant" << endl;
    cin >> e.prenom;
    do{
        cout << "Donnez son age [Min 16] : " << endl;
        cin >> e.age;
        if(e.age <=16) {
            cout << "Age invalide !!! " << endl;
        }
    }while(e.age <=16);
    do{
        afficherTabClasses(vecClasse);
        cout << "Veuillez choisir un id de classe" << endl;
        cin >> idClasse;
    }while(idClasse <1 || idClasse > vecClasse.size());
    e.classe = vecClasse[idClasse-1];
    vecClasse[idClasse-1].effectif++;
    return e;
}
void ajouterEtudiant(vector<Etudiant> &vecEtudiant, Etudiant e) {
    vecEtudiant.push_back(e);
}

void afficheEtudiantsParClasse(vector<Etudiant> &vecEtudiant, Classe cl){
    int i;
    bool isEmpty = true;
    for(i=0; i<vecEtudiant.size(); i++) {
        if(vecEtudiant[i].classe.id == cl.id) {
            afficherEtudiant(vecEtudiant[i]);
            cout << "------------------------------------------------" << endl;
            isEmpty = false;
        }
    }
    if(isEmpty) {
        cout << "Aucun etudiant trouve pour cette classe" << endl;
    }
}



void afficheClasseCroissant(vector<Classe> &vecClasse){
    Classe svg;
    for(int i(0); i<(vecClasse.size()-1); i++){
        for(int j(0); j<(vecClasse.size()-1); j++){
            if(vecClasse[j].effectif > vecClasse[j+1].effectif){
                svg = vecClasse[j];
                vecClasse[j]=vecClasse[j+1];
                vecClasse[j+1]=svg;
            }
        }
    }

    afficherTabClasses(vecClasse);

}







//
//
//
//
//


void initialiserId(){
    //ofstream fluxo1(fichierId.c_str(), ios::app);
    ofstream fluxo1(fichierId.c_str());
    ifstream fluxi1(fichierId.c_str());

    if(fluxi1)
    {
         string ligne; //Une variable pour stocker les lignes lues

         if(getline(fluxi1, ligne)){
                // si les id sont deja dans le fichier
                if(fluxo1){
                fluxo1 << 0 <<endl;
                fluxo1 << 0;
             }
            // cout<< "squall";

         }else{
             // si le fichier est vide
             if(fluxo1){
                fluxo1 << 0 <<endl;
                fluxo1 << 0;
             }
         }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir en lecture le fichier des id." << endl;
    }
}

int getIdClasse(){
    ofstream fluxo1(fichierId.c_str(), ios::app);
    ifstream fluxi1(fichierId.c_str());
    int a=0;
    if(fluxi1)
    {
             string ligne; //Une variable pour stocker les lignes lues

             if(getline(fluxi1, ligne)){
                    // si les id sont deja dans le fichier
                    return a= atoi(ligne.c_str());

             }

    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir en lecture le fichier des id." << endl;
    }
    return a;
}
int getIdEtudiant(){
    ofstream fluxo1(fichierId.c_str(), ios::app);
    ifstream fluxi1(fichierId.c_str());
    int b = 0;
    if(fluxi1)
    {
             string ligne; //Une variable pour stocker les lignes lues

             if(getline(fluxi1, ligne)){
                    // si les id sont deja dans le fichier
                    getline(fluxi1, ligne);
                    b= atoi(ligne.c_str());
                    return b;

             }

    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir en lecture le fichier des id." << endl;
    }
    return b;
}

void setIdClass(int i){

    int Line_to_Erase=1;
    string File=fichierId.c_str();


    std::string Buffer = ""; //Variable contenant le texte à réécrire dans le fichier
    std::ifstream ReadFile(File.c_str());
    if (ReadFile) //Si le fichier est trouvé
    {
        std::string line;
        int Line = 0;
        while ( std::getline( ReadFile, line ) ) //on parcours le fichier et on initialise line à la ligne actuelle
        {
            Line++;
            if(Line != Line_to_Erase) //Si la ligne atteinte est différente de la ligne à supprimer...
            {
                Buffer += line + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire
            }else{
                ostringstream oss;
                oss << i;
                Buffer += oss.str();

                  Buffer += "\n";


            }

        }
    }
    ReadFile.close(); //On ferme le fichier en lecture

    std::ofstream WriteFile( File.c_str() ); //On ouvre ce même fichier en écriture
    WriteFile << Buffer; //On écris le texte dedans
    WriteFile.close(); //et on ferme le fichier
}
void setIdEtu(int i){
    int Line_to_Erase=2;
    string File="C:/squall/fichierId.txt";


    std::string Buffer = ""; //Variable contenant le texte à réécrire dans le fichier
    std::ifstream ReadFile(File.c_str());
    if (ReadFile) //Si le fichier est trouvé
    {
        std::string line;
        int Line = 0;
        while ( std::getline( ReadFile, line ) ) //on parcours le fichier et on initialise line à la ligne actuelle
        {
            Line++;
            if(Line != Line_to_Erase) //Si la ligne atteinte est différente de la ligne à supprimer...
            {
                Buffer += line + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire
            }else{
                ostringstream oss;
                oss << i;
                Buffer += oss.str();

                  Buffer += "\n";


            }

        }
    }
    ReadFile.close(); //On ferme le fichier en lecture

    std::ofstream WriteFile( File.c_str() ); //On ouvre ce même fichier en écriture
    WriteFile << Buffer; //On écris le texte dedans
    WriteFile.close(); //et on ferme le fichier
}


void saveFileEtudiant(vector<Etudiant> &vecEtudiant){
    //ofstream fluxo3(fichierEtudiant.c_str(), ios::app);
    ofstream fluxo3(fichierEtudiant.c_str());
    Etudiant e;
    if(fluxo3)
    {
        int i;
        for(i=0; i<vecEtudiant.size(); i++) {
            e= vecEtudiant[i];
            fluxo3 << "---------------------------------------"<<endl;
            fluxo3 << "ID : " << e.id << endl;
            fluxo3 << "NOM : " << e.nom << endl;
            fluxo3 << "PRENOM : " << e.prenom << endl;
            fluxo3 << "AGE : " << e.age << endl;
            fluxo3 << "CLASSE : " << e.classe.libelle << endl;
            fluxo3 << "---------------------------------------"<< endl;
        }
        cout << "Etudiants enregistres dans le fichier: " <<fichierEtudiant <<endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

}


void saveFileClasse(vector<Classe> &vecClasse){
    //ofstream fluxo2(fichierClasse.c_str(), ios::app);
    ofstream fluxo2(fichierClasse.c_str());
    Classe cl;
    if(fluxo2)
    {
        int i;
        for(i=0; i<vecClasse.size(); i++) {
            cl= vecClasse[i];
            fluxo2 << "---------------------------------------"<< endl;
            fluxo2 << "CLASSE : " << cl.libelle << endl;
            fluxo2 << "ID CLASSE : " << cl.id << endl;
            fluxo2 << "EFFECTIF CLASSE : " << cl.effectif << endl;
            fluxo2 << "EFFECTIF LIMITE DE La CLASSE : " << cl.seuilEffectif << endl;
            fluxo2 << "---------------------------------------"<< endl;
        }

        cout << "Classes enregistree dans le fichier: " <<fichierClasse <<endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

}



//*/
