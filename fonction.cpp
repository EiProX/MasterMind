/*********************************************************
* Nom du projet :     MasterMind
* Nom du fichier : fonction.cpp
* Créé le : 03/12/2024 par EiProX
* Mis à jour le : 03/12/2024 par EiProX
*********************************************************/


void afficherRegles() {
    cout << "=============================" << endl;
    cout << "          Règles du Jeu      " << endl;
    cout << "=============================" << endl;
    cout << "1. Une combinaison de 5 couleurs est générée aléatoirement." << endl;
    cout << "2. Couleurs possibles : R (Rouge), V (Vert), B (Bleu), J (Jaune), O (Orange), P (Violet)." << endl;
    cout << "3. Indices après chaque tentative :" << endl;
    cout << "   - Bien placés : Couleurs correctes à la bonne position." << endl;
    cout << "   - Mal placés : Couleurs correctes mais à une mauvaise position." << endl;
    cout << "4. Vous avez 10 tentatives pour deviner la combinaison." << std;
    cout << "=============================" << std;
}
