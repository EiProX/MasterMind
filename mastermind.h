/*********************************************************
* Nom du projet :     MasterMind
* Nom du fichier : fonction.cpp
* Créé le : 03/12/2024 par EiProX
* Mis à jour le : 03/12/2024 par EiProX
*********************************************************/

#ifndef MASTERMIND_H
#define MASTERMIND_H


#include <iostream>
#include <cstring>
#include <random>

using namespace std;

void afficherRegles();
void afficherMenu();


const int LONGUEUR_COMBINAISON = 5; // Longueur de la combinaison secrète.
const int TENTATIVES_MAX = 10; // Nombre maximum de tentatives.
const char COULEURS_DISPONIBLES[6] = {'R', 'V', 'B', 'J', 'O', 'P'};

char combinaisonSecrete[LONGUEUR_COMBINAISON]; // Tableau contenant la combinaison générée.
char tentative[LONGUEUR_COMBINAISON]; // Tableau pour stocker la tentative du joueur.
int bienPlaces; // Compteur des couleurs bien placées.
int malPlaces; // Compteur des couleurs mal placées.
int tentativesRestantes; // Nombre de tentatives restantes.



#endif // MASTERMIND_H
