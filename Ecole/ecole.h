#ifndef ECOLE_H_INCLUDED
#define ECOLE_H_INCLUDED
#include <string>
#include <vector>
#include <cstdlib>
//convert int to string
#include <sstream>


using namespace std;



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

//#############################################

//namespace liste{

// redefinition de structure
    typedef struct eltmono * elementmono;
    typedef struct eltmono eltmono;
    typedef struct eltbi * elementbi;
    typedef struct eltbi eltbi;

    struct eltmono{
        Classe info;
        elementmono next;
    };
    struct eltbi{
        Etudiant info;
        elementbi next;
        elementbi prec;
    };

/*
class liste{

    protected:
        int taille;


    public:
        liste() {};
        //~liste(){};
        virtual void initialise()=0;
        virtual void add(int nbr);
        /*virtual bool deleteOne(int pos);
        virtual bool deleteAll(int val);
        virtual int get(int pos);
        virtual int get(int * val);
        virtual void add(int nbr, int pos);
        virtual void show();
        virtual bool isVide()=0;

};
*/


class listemono{
public:
    elementmono T, Q;
    int taille;

public:
    void initialise();
    bool isVide();
    void add(Classe c);
    void show();
    listemono();
    ~listemono();

};




class listebi{

public:
    elementbi T, Q;
    int taille;
public:
    void initialise();
    bool isVide();
    void add(Etudiant e);
    void show();
    listebi();
    ~listebi();
};


//}



//string const fichierId= "C:/squall/fichierId.txt";
//string const fichierClasse= "C:/squall/fichierClasse.txt";
//string const fichierEtudiant= "C:/squall/fichierEtudiant.txt";


int menu();
Classe saisirClasse();
void ajoutClasse(listemono * lm);
void saveFileClasse(elementmono T, elementmono Q);
void afficherTabClasses(listemono * lm);
void afficherClasse(Classe cl);
Etudiant saisirEtudiant(listemono * lm);
void ajouterEtudiant(listebi * lb, Etudiant e);
void afficheEtudiantsParClasse(listebi * lb, Classe cl);
void afficherEtudiant(Etudiant e) ;


void afficheClasseCroissant(listemono * lm);


void initialiserId();
int getIdClasse();
int getIdEtudiant();
void setIdClass(int i);
void setIdEtu(int i);


void saveFileEtudiant(elementbi T);

//##########################################

Classe getclassebyid(listemono * lm, int idcl);


//###############################################################



#endif // ECOLE_H_INCLUDED
