#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	char id[30];
	char date[30] ;
	char prix[30];
}excursion;

enum   
{
ID,
DATE,
PRIX,
COLUMN
};

void afficher(GtkWidget *liste);
void ajouter_excursion(excursion exc);
void rechercher(char id[20]) ;
void afficher_rechercher(GtkWidget *liste);
void modifier(char id[30],char date[30],char prix[30]);
void supprimer (char id[30],char date[30]);
