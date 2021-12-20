/*************************************************************
                     TP TRI DES ALLUMETTES

        fichier source de affichage.cpp

    ------------------------------------------------------

 Auteurs: Equipe pédagogique ALGPR
 Date: 21/04/2009
 Modification : 10/10/2013
 Fichier: affichage.cpp
 But: ensemble de fonctions permettant d'afficher pseudo-
 	  graphiquement des allumettes que l'on souhaite trier

*************************************************************/

#include <curses.h>	// pour le pseudo-affichage graphique
#include <ctime>			// pour la gestion de la tempo dans affiche
#include <string>
#include <vector>
#include <iostream>
using namespace std ;
#include "tris_def.h"
#include "affichage.h"

// Macros internes (Ne pas toucher)
#define gotoxy(x,y) move(y, x)
#define textcolor(color) attrset(COLOR_PAIR(color))

bool AFFICHE = true;

void displayInfo(const std::string & s)
{
  if(AFFICHE) 
  {
    textcolor(9);
    gotoxy(0,21);
    printw("\n%s\n",s.c_str());
    refresh();
  }
  else
  {
    cout << s << endl;
  }
}

void displayInfoWait(const std::string & s)
{
  if(AFFICHE) 
  {
    textcolor(9);
    gotoxy(0,21);
    printw("\n%s : appuyer sur une touche pour continuer\n",s.c_str());
    refresh();
    getchar();
  }
  else
  {
    cout << s << endl;
  }
}

// fonction init
// but : initialise l'affichage pseudo graphique
void finish()
{
  if(AFFICHE) 
  {
    textcolor(9);
    gotoxy(0,21);
    printw("\nFin : appuyer sur une touche pour terminer\n");
    refresh();

    getchar();
    endwin();
  }
}


// function finish
// but : Quitte proprement le mode pseudo graphique
void init()
{
  if(AFFICHE) 
  {
    initscr();      			/* initialize the curses library */
    keypad(stdscr, TRUE);  		/* enable keyboard mapping */
    nonl();         			/* tell curses not to do NL->CR/NL on output */
    cbreak();       			/* take input chars one at a time, no wait for \n */
    noecho();       			/* don't echo input */
    nodelay(stdscr, TRUE);		/* getch() don't wait for an input */
    if (has_colors())
    {
        start_color();

        // Initialise les couleurs
        // Seul le fond change, pour afficher des " " de diffÈrentes couleurs
        init_pair(0, COLOR_BLACK, COLOR_BLACK);
        init_pair(1, COLOR_BLACK, COLOR_WHITE);
        init_pair(2, COLOR_BLACK, COLOR_RED);
        init_pair(3, COLOR_BLACK, COLOR_YELLOW);
        init_pair(4, COLOR_BLACK, COLOR_BLUE);
        init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
        init_pair(6, COLOR_BLACK, COLOR_GREEN);

        // Une couleur pour l'Ècriture : blanc sur fond noir
        init_pair(9, COLOR_WHITE, COLOR_BLACK);
    }
    else
    {
        printw("Le terminal ne supporte pas les couleurs!\n");
        finish();
    }
  }
}


// function affiche
// Affiche un vecteur d'allumettes fourni en paramËtre
void affiche(const std::vector<Allumette> &A)
{
  if(AFFICHE) 
  {
    int i,j;
    int fin_attente=0;
    static unsigned int tempoAffichage = 50 ; //500; 	// delai initial, en us.
  /*
    static unsigned int cp=0 ;
    gotoxy(0,22);
    printw("cp : %d\n",cp);
    cp++;
*/
    for (i = 0; i < A.size(); i++)
    {
        // VÈrifie la taille
        if ( (A[i].taille>20) || (A[i].taille<1) )
        {
            gotoxy(1,21);
            printw("L'allumette no %u a une taille invalide : %u\n",i,A[i].taille);
        }

        // Vérifie la couleur, et la change pour celle de l'allumette
        if ( (A[i].couleur<BLANC) || (A[i].couleur>GREEN) )
        {
            gotoxy(1,22);
            printw("L'allumette no %u a une couleur invalide : %u\n",i,A[i].taille);
        }
        else
            textcolor(A[i].couleur);

        // Affiche l'allumette
        for (j = 0; j < A[i].taille; j++)
        {
            // Positionnement
            gotoxy((i*2),20-j);

            // Affiche un espace (la couleur de fond fait que ça affiche un carré
            printw(" ");
        }

        // Change la couleur pour celle du fond
        textcolor(0);

        // Efface l'allumette précédente (en affichant des carrés de la couleur du fond)
        for(j=A[i].taille; j<20; j++)
        {
            // Positionnement
            gotoxy((i*2),20-j);

            // Affiche un espace de la couleur du fond
            printw(" ");
        }
    }

    printw("\n");

    // Met à jour à l'affichage
    refresh();


    // attente et gestion des Èvenements
    time_t time=clock();
    while (!fin_attente)
    {
        // gestion des touches
        int key = getch();
        if (key==KEY_UP)
        {
            if (tempoAffichage > 100)
                tempoAffichage -= 100;
            else if (tempoAffichage > 10)
                tempoAffichage--;
        }
        if (key==KEY_DOWN)
        {
            if (tempoAffichage < 100)
                tempoAffichage++;
            else if (tempoAffichage < 5000)
                tempoAffichage += 100;
        }

        // vérification si on a attendu suffisamment longtemps
        fin_attente = ( (clock()-time)*5000/CLOCKS_PER_SEC ) > tempoAffichage;
    }
  }
}
