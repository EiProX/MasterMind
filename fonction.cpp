/*********************************************************
* Nom du projet :     MasterMind
* Nom du fichier : fonction.cpp
* Créé le : 03/12/2024 par EiProX
* Mis à jour le : 03/12/2024 par EiProX
*********************************************************/

#include <mastermind.h>

void clearConsole() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls"); // Commande pour Windows
    #else
        system("clear"); // Commande pour Linux/macOS
    #endif
}


void afficherMenu(){
    clearConsole();
    cout << "=============================" << endl;
    cout << "        Mastermind" << endl;
    cout << "=============================" << endl;
    cout << "1. Nouvelle Partie" << endl;
    cout << "2. Règles du Jeu" << endl;
    cout << "3. Quitter" << endl;
    cout << "=============================" << endl;
}

int obtenirChoixMenu() {
    int choix;
    cout << "Votre choix : ";
    cin >> choix;
    return choix;
}

void afficherRegles(){
    clearConsole();
    cout << "=============================" << endl;
    cout << "          Règles du Jeu" << endl;
    cout << "=============================" << endl;
    cout << "1. Une combinaison de 5 couleurs est générée aléatoirement." << endl;
    cout << "2. Les couleurs disponibles sont :" << endl;
    cout << "   R = Rouge, V = Vert, B = Bleu" << endl;
    cout << "   J = Jaune, O = Orange, P = Violet" << endl;
    cout << "3. Après chaque tentative, vous recevrez des indices :" << endl;
    cout << "   - Bien placés : Nombre de couleurs à la bonne position." << endl;
    cout << "   - Mal placés : Nombre de couleurs correctes mais mal positionnées." << endl;
    cout << "4. Vous avez 10 tentatives pour deviner la combinaison." << endl;
    cout << "=============================" << endl;
    cout << "Appuyez sur une touche pour revenir au menu principal." << endl;
    unsigned char sortir;
    cin>>sortir;
    if(sortir != NULL){
        afficherMenu();
    }
}



void genererCombinaison(char combinaisonSecrete[]) {
    srand(time(0));
    for (int i = 0; i < LONGUEUR_COMBINAISON; ++i) {
        combinaisonSecrete[i] = COULEURS_DISPONIBLES[rand() % 6];
    }
    combinaisonSecrete[LONGUEUR_COMBINAISON] = '\0'; // Terminer avec un caractère nul
}


void lireTentative(char tentative[]){
    bool valide;
    do{
        cout<<"Les couleurs disponibles sont R, V, B, J, O P "<<endl;
        cin>>tentative;
        for (int i = 0; i < strlen(tentative); i++) {
            tentative[i] = toupper(tentative[i]);
        }
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
            cout<<"Les caractere saisie ne sont pas valide ou trop de saisie"<<endl;
    } while(!valide);

 }

void calculerIndices(const char combinaisonSecrete[], const char tentative[], int& bienPlaces, int& malPlaces) {
    bool marqueSecret[LONGUEUR_COMBINAISON] = {false};
    bool marqueTentative[LONGUEUR_COMBINAISON] = {false};

    bienPlaces = 0;
    malPlaces = 0;

    for (int i = 0; i < LONGUEUR_COMBINAISON; ++i) {
        if (tentative[i] == combinaisonSecrete[i]) {
            bienPlaces++;
            marqueSecret[i] = true;   // Marquer comme utilisé dans la combinaison secrète
            marqueTentative[i] = true; // Marquer comme utilisé dans la tentative
        }
    }

    for (int i = 0; i < LONGUEUR_COMBINAISON; ++i) {
        if (!marqueTentative[i]) { // Ne considérer que les caractères non déjà utilisés
            bool trouver = false;    // Variable pour suivre si une correspondance est trouvée
            for (int j = 0; j < LONGUEUR_COMBINAISON && !trouver; ++j) {
                if (!marqueSecret[j] && tentative[i] == combinaisonSecrete[j]) {
                    malPlaces++;
                    marqueSecret[j] = true; // Marquer comme utilisé dans la combinaison secrète
                    trouver = true;          // Correspondance trouvée
                }
            }
        }
    }
}

void afficherEtatJeu(int tentativesRestantes, const char historique[][LONGUEUR_COMBINAISON + 1], const int bienPlaces[], const int malPlaces[], int tentativesUtilisées) {
    clearConsole();
    cout << "=============================" << endl;
    cout << "    Devinez la combinaison   " << endl;
    cout << "=============================" << endl;
    cout << "Tentatives restantes : " << tentativesRestantes << endl;

    cout << "Historique :" << endl;
    for (int i = 0; i < tentativesUtilisées; ++i) {
        cout << i + 1 << ". " << historique[i]
             << " - Bien placés : " << bienPlaces[i]
             << ", Mal placés : " << malPlaces[i] << endl;
    }
    for (int i = tentativesUtilisées; i < TENTATIVES_MAX; ++i) {
        cout << i + 1 << ". ----  - Bien placés : -, Mal placés : -" << endl;
    }
}

void afficherFinDePartie(bool victoire, const char combinaisonSecrete[]) {
    cout << "=============================" << endl;
    cout << "       Partie Terminée       " << endl;
    cout << "=============================" << endl;
    if (victoire) {
        cout << "Vous avez gagné !" << endl;
    } else {
        cout << "Vous avez perdu." << endl;
    }
    cout << "La combinaison était : " << combinaisonSecrete << endl;
}

bool demanderRejouer() {
    char choix;
    cout << "Rejouer ? (O/N) : ";
    cin >> choix;
    return (choix == 'O' || choix == 'o');
}

void jouerPartie() {
    char combinaisonSecrete[LONGUEUR_COMBINAISON + 1];
    char tentative[LONGUEUR_COMBINAISON + 1];
    char historique[TENTATIVES_MAX][LONGUEUR_COMBINAISON + 1] = {};
    int bienPlaces[TENTATIVES_MAX] = {};
    int malPlaces[TENTATIVES_MAX] = {};

    int tentativesRestantes = TENTATIVES_MAX;
    int tentativesUtilisées = 0;
    bool gagner=false;
    bool sortie=false;

    genererCombinaison(combinaisonSecrete);

    while (tentativesRestantes > 0 && !sortie) {
        afficherEtatJeu(tentativesRestantes, historique, bienPlaces, malPlaces, tentativesUtilisées);

        lireTentative(tentative);
        calculerIndices(combinaisonSecrete, tentative, bienPlaces[tentativesUtilisées], malPlaces[tentativesUtilisées]);

        // Copier la tentative dans l'historique
        for (int i = 0; i < LONGUEUR_COMBINAISON; ++i) {
            historique[tentativesUtilisées][i] = tentative[i];
        }
        historique[tentativesUtilisées][LONGUEUR_COMBINAISON] = '\0';

        tentativesUtilisées++;
        tentativesRestantes--;

        if (bienPlaces[tentativesUtilisées - 1] == LONGUEUR_COMBINAISON) {
            afficherFinDePartie(true, combinaisonSecrete);
            gagner=true;
            sortie = true;
        }
    }
    if (!gagner)
    afficherFinDePartie(false, combinaisonSecrete);
}

void genererCombinaison(char combinaisonSecrete[LONGUEUR_COMBINAISON])
{
    srand(time(0));
    for (int i=0 ; i<LONGUEUR_COMBINAISON; i++){
        combinaisonSecrete[i]= COULEURS_DISPONIBLES[rand()%6];
        cout<<combinaisonSecrete[i]<<endl;
    }
}
