/*********************************************************
* Nom du projet :     MasterMind
* Nom du fichier : fonction.cpp
* Créé le : 03/12/2024 par EiProX
* Mis à jour le : 16/12/2024 par EiProX
*********************************************************/

#include <mastermind.h>

int main() {
    bool rejouer = true;
    while (rejouer) {
        afficherMenu();
        int choix = obtenirChoixMenu();

        if (choix == 1) {
            jouerPartie();
            rejouer = demanderRejouer();
        } else if (choix == 2) {
            afficherRegles();
        } else if (choix == 3) {
            cout << "Merci d'avoir joué. Au revoir !" << endl;
            rejouer = false;
        } else {
            cout << "Choix invalide. Veuillez réessayer." << endl;
        }
    }
    return 0;
}
