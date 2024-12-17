/*********************************************************
* Nom du projet :     MasterMind
* Nom du fichier : fonction.cpp
* Créé le : 03/12/2024 par EiProX
* Mis à jour le : 16/12/2024 par EiProX
*********************************************************/

#ifndef MASTERMIND_H
#define MASTERMIND_H


#include <iostream>
#include <random>

using namespace std;

// Déclaration de constantes pour le jeu
const int LONGUEUR_COMBINAISON = 5;  // La longueur de la combinaison secrète, fixée à 5 couleurs.
const int TENTATIVES_MAX = 10;  // Le nombre maximum de tentatives que l'utilisateur peut faire.
const char COULEURS_DISPONIBLES[6] = {'R', 'V', 'B', 'J', 'O', 'P'};  // Liste des couleurs disponibles pour la combinaison secrète.

// Déclarations des fonctions utilisées dans le jeu
int strlen(const char chaine[]);  // Fonction pour calculer la longueur d'une chaîne de caractères.
void clearConsole();  // Fonction pour effacer l'écran en fonction du système d'exploitation.
void afficherMenu();  // Fonction pour afficher le menu principal du jeu.
int obtenirChoixMenu();  // Fonction pour obtenir le choix de l'utilisateur dans le menu.
void afficherRegles();  // Fonction pour afficher les règles du jeu.
void afficherEtatJeu(int tentativesRestantes, const char historique[][LONGUEUR_COMBINAISON + 1], const int bienPlaces[], const int malPlaces[], int tentativesUtilisées);  // Fonction pour afficher l'état actuel du jeu.
void afficherFinDePartie(bool victoire, const char combinaisonSecrete[]);  // Fonction pour afficher la fin du jeu, si l'utilisateur a gagné ou perdu.
void jouerPartie();  // Fonction principale pour jouer une partie complète du jeu.
void genererCombinaison(char combinaisonSecrete[]);  // Fonction pour générer une combinaison secrète aléatoire.
void lireTentative(char tentative[]);  // Fonction pour lire et valider la tentative de l'utilisateur.
void calculerIndices(const char combinaisonSecrete[], const char tentative[], int& bienPlaces, int& malPlaces);  // Fonction pour calculer les indices : bien placés et mal placés.
bool demanderRejouer();  // Fonction pour demander à l'utilisateur s'il veut rejouer.



#endif // MASTERMIND_H
