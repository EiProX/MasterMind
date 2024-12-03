# Mastermind en C++

## Description

Mastermind est un jeu de réflexion où le joueur doit deviner une combinaison secrète de couleurs générée par l’ordinateur. Ce projet est une implémentation console en C++.

---

## Règles du jeu

- Une **combinaison secrète** de 5 couleurs est générée par l'ordinateur.
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
   
- Génère une combinaison aléatoire de 4 couleurs parmi celles disponibles.

2. **Lecture de la tentative du joueur**
   
   ```cpp
   void lireTentative(char tentative[]);
   
- Demande au joueur d’entrer une combinaison de 4 couleurs et vérifie sa validité.

3. **Calcul des indices**
   
   ```cpp
   void calculerIndices(const char combinaisonSecrete[], const char tentative[], int& bienPlaces, int& malPlaces);
   
- Compare la tentative avec la combinaison secrète et met à jour les variables `bienPlaces` et `malPlaces`.
  
4. **Affichage des indices**
   
   ```cpp
   void afficherIndices(int bienPlaces, int malPlaces);
- Affiche les résultats du tour sous la forme :
  ```java
  Bien placés = 2, Mal placés = 1
  
5. **Affichage du menu principal**
   
   ```cpp
   void afficherMenu();
   
- Propose les options : Nouvelle partie, Règles du jeu, Quitter.

6. **Logique principale du jeu**
   
   ```cpp
   void jouerPartie();
   
- Gère les tentatives, affiche les messages et vérifie les conditions de fin de partie.

## Maquette
-
=============================
          Mastermind
=============================
1. Nouvelle Partie
2. Règles du Jeu
3. Quitter
=============================
Votre choix : _

- Après avoir choisi Nouvelle Partie :  
-
=============================
      Devinez la combinaison
=============================
Tentatives restantes : 10

Historique :
1. RVBO - Bien placés : 2, Mal placés : 1
2. BVRP - Bien placés : 1, Mal placés : 2
3. ----  - Bien placés : -, Mal placés : -

Votre tentative (R, V, B, J, O, P) : _

- En cas de victoire :
-  
=============================
         Partie Terminée
=============================
Vous avez perdu.
La combinaison était : RVBJ
=============================
Rejouer ? (O/N) : _

- Règles du jeu :
-
=============================
          Règles du Jeu
=============================
1. Une combinaison de 4 couleurs est générée aléatoirement.
2. Les couleurs disponibles sont :
   R = Rouge, V = Vert, B = Bleu
   J = Jaune, O = Orange, P = Violet
3. Après chaque tentative, vous recevrez des indices :
   - Bien placés : Nombre de couleurs à la bonne position.
   - Mal placés : Nombre de couleurs correctes mais mal positionnées.
4. Vous avez 10 tentatives pour deviner la combinaison.
=============================
Appuyez sur une touche pour revenir au menu principal.
