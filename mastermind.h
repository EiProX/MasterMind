/*********************************************************
* Nom du projet :     MasterMind
* Nom du fichier : fonction.cpp
* Créé le : 03/12/2024 par EiProX
* Mis à jour le : 03/12/2024 par EiProX
*********************************************************/

#ifndef MASTERMIND_H
#define MASTERMIND_H


#include <iostream>
#include <random>

using namespace std;

const int LONGUEUR_COMBINAISON = 5; // Longueur de la combinaison secrète.
const int TENTATIVES_MAX = 10; // Nombre maximum de tentatives.
const char COULEURS_DISPONIBLES[6] = {'R', 'V', 'B', 'J', 'O', 'P'};

int strlen(const char chaine[]);
void clearConsole();
void afficherMenu();//
int obtenirChoixMenu();//
void afficherRegles();//
void afficherEtatJeu(int tentativesRestantes, const char historique[][LONGUEUR_COMBINAISON + 1], const int bienPlaces[], const int malPlaces[], int tentativesUtilisées); //
void afficherFinDePartie(bool victoire, const char combinaisonSecrete[]); //
void jouerPartie();
void genererCombinaison(char combinaisonSecrete[]);//
void lireTentative(char tentative[]);//
void calculerIndices(const char combinaisonSecrete[], const char tentative[], int& bienPlaces, int& malPlaces);//
bool demanderRejouer();



#endif // MASTERMIND_H
