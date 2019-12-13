#include <gtk/gtk.h>
typedef struct 
{char modele[20];
char matricule1[20];
char matricule2[20];
char couleur[20];
char prix[20];
}voiture;
typedef struct
{char nom[20];
char prenom[20];
char CIN[20];
}clients;
typedef struct 
{
int jour;
int mois;
int annee;
}Date;
typedef struct 
{
Date dt_res;
char  nbr_nuits[20];
}reservationvoiture ;

void afficher_voiture(GtkWidget *liste);
void ajouter_voiture(voiture v);
void modifier(char modele[20],char matricule1[20],char matricule2[20],char couleur[20],char prix[20]);
void rechercher(char modele[20]) ;
void afficher_voiture_rechercher(GtkWidget *liste);
void suprimmer(char matricule1[20],char  matricule2[20])  ;
void afficher_clients(GtkWidget *liste);
