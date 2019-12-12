#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct
{ 
	char nom[50];
	char prenom[50];
	char cin[50];
	char adresse[50];
	char email[50];
	char telephone[50];
	char date[50];

}agent;


void afficher_agent(GtkWidget *liste);
void ajouter_agent(agent a);
void rechercher(cin) ;
void afficher_agent_rechercher(GtkWidget *liste);
void supprimer_agent(char cinp[]);
void modifier (char nom[20],char prenom[20],char cin[20],char adresse[50],char email[40],char telephone[20],char date[50]) ;
