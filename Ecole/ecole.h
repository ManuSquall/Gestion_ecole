#ifndef ECOLE_H_INCLUDED
#define ECOLE_H_INCLUDED
#include <string>
#include <vector>
#include <cstdlib>
//convert int to string
#include <sstream>


using namespace std;


//string const fichierId= "C:/squall/fichierId.txt";
//string const fichierClasse= "C:/squall/fichierClasse.txt";
//string const fichierEtudiant= "C:/squall/fichierEtudiant.txt";


string const fichierId= "fichiers/fichierId.txt";
string const fichierClasse= "fichiers/fichierClasse.txt";
string const fichierEtudiant= "fichiers/fichierEtudiant.txt";



struct Classe{
    int id;
    string libelle;
    int effectif;
    int seuilEffectif;
};

struct Etudiant{
    int id;
    string nom;
    string prenom;
    int age;
    Classe classe;
};

int menu();
Classe saisirClasse();
void afficherTabClasses(vector<Classe> &vecClasse);
void ajoutClasse(vector<Classe> &vecClasse);
void afficherClasse(Classe cl);
void ajouterEtudiant(vector<Etudiant> &vecEtudiant, Etudiant e);
Etudiant saisirEtudiant(vector<Classe> &vecClasse);
void afficheEtudiantsParClasse(vector<Etudiant> &vecEtudiant, Classe cl);
void afficherEtudiant(Etudiant e) ;
void afficheClasseCroissant(vector<Classe> &vecClasse);


void initialiserId();
int getIdClasse();
int getIdEtudiant();
void setIdClass(int i);
void setIdEtu(int i);


void saveFileEtudiant(vector<Etudiant> &vecEtudiant);
void saveFileClasse(vector<Classe> &vecClasse);



#endif // ECOLE_H_INCLUDED
