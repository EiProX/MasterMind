/*********************************************************
* Nom du projet :     MasterMind
* Nom du fichier : fonction.cpp
* Créé le : 03/12/2024 par EiProX
* Mis à jour le : 03/12/2024 par EiProX
*********************************************************/


#include <mastermind.h>



void afficherMenu(){
    cout << "=============================" << endl;
    cout << "        Mastermind" << endl;
    cout << "=============================" << endl;
    cout << "1. Nouvelle Partie" << endl;
    cout << "2. Règles du Jeu" << endl;
    cout << "3. Quitter" << endl;
    cout << "=============================" << endl;
}


void afficherRegles() {
    cout << "=============================" << endl;
    cout << "          Règles du Jeu      " << endl;
    cout << "=============================" << endl;
    cout << "1. Une combinaison de 5 couleurs est générée aléatoirement." << endl;
    cout << "2. Couleurs possibles : R (Rouge), V (Vert), B (Bleu), J (Jaune), O (Orange), P (Violet)." << endl;
    cout << "3. Indices après chaque tentative :" << endl;
    cout << "   - Bien placés : Couleurs correctes à la bonne position." << endl;
    cout << "   - Mal placés : Couleurs correctes mais à une mauvaise position." << endl;
    cout << "4. Vous avez 10 tentatives pour deviner la combinaison." << endl;
    cout << "=============================" << endl;
}
void genererCombinaison(char combinaisonSecrete[LONGUEUR_COMBINAISON])
{
    srand(time(0));
    for (int i=0 ; i<LONGUEUR_COMBINAISON; i++){
        combinaisonSecrete[i]= COULEURS_DISPONIBLES[rand()%6];
        cout<<combinaisonSecrete[i]<<endl;
    }
void lireTentative(char tentative[]){
    bool valide;
    do{
        cout<<"Les couleurs disponibles sont R, V, B, J, O P "<<endl;
        cin>>tentative;
        valide=(strlen(tentative)==LONGUEUR_COMBINAISON);
        for (int i=0 ;i<LONGUEUR_COMBINAISON &&valide ;i++){

           bool caractereValide = false;

           for(int j=0 ;j<strlen(COULEURS_DISPONIBLES);j++){

                if(tentative[i]==COULEURS_DISPONIBLES[j]){
                    caractereValide=true;
                    break;

                }
           }
           if(!caractereValide)
               valide=false;

       }
        if(!valide)
            cout<<"Les caractere saisie ne sont pas valide"<<endl;
    } while(!valide);

 }
