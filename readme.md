# Mastermind en C++

## Description

Mastermind est un jeu de réflexion où le joueur doit deviner une combinaison secrète de couleurs générée par l’ordinateur. Ce projet est une implémentation console en C++.

---

## Règles du jeu

- Une **combinaison secrète** de 4 couleurs est générée par l'ordinateur.
- Le joueur doit deviner cette combinaison en un maximum de 10 tentatives.
- Les couleurs disponibles sont :
  - R = Rouge
  - V = Vert
  - B = Bleu
  - J = Jaune
  - O = Orange
  - P = Violet
- Après chaque tentative, deux types d’indices sont donnés :
  - **Bien placés** : Nombre de couleurs correctes à la bonne position.
  - **Mal placés** : Nombre de couleurs correctes mais à une mauvaise position.
- Le jeu se termine lorsque :
  - La combinaison est trouvée (victoire).
  - Les 10 tentatives sont épuisées (défaite).

---

## Fonctionnalités

1. **Menu principal**
   - Lancer une nouvelle partie.
   - Lire les règles du jeu.
   - Quitter l'application.

2. **Gameplay**
   - Génération aléatoire d'une combinaison secrète.
   - Validation des entrées utilisateur (4 couleurs parmi celles disponibles).
   - Calcul et affichage des indices après chaque tentative.

3. **Fin de partie**
   - Affichage d'un message de victoire ou de défaite.
   - Proposition de rejouer ou de quitter.

---

## Variables utilisées

1. **Constantes**
   - `const int LONGUEUR_COMBINAISON = 4;` : Longueur de la combinaison secrète.
   - `const int TENTATIVES_MAX = 10;` : Nombre maximum de tentatives.
   - `const char COULEURS_DISPONIBLES[6] = {'R', 'V', 'B', 'J', 'O', 'P'};`

2. **Variables principales**
   - `char combinaisonSecrete[LONGUEUR_COMBINAISON];` : Tableau contenant la combinaison générée.
   - `char tentative[LONGUEUR_COMBINAISON];` : Tableau pour stocker la tentative du joueur.
   - `int bienPlaces;` : Compteur des couleurs bien placées.
   - `int malPlaces;` : Compteur des couleurs mal placées.
   - `int tentativesRestantes;` : Nombre de tentatives restantes.

---

## Fonctions principales

1. **Génération de la combinaison secrète**
   ```cpp
   void genererCombinaison(char combinaisonSecrete[]);
