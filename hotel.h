#include <gtk/gtk.h>

typedef struct
{
char nom_hotel[20];
char Destination[20];
char prix_par_nuitee[20];
}hotel1;


void ajouter_hotel( hotel1 h1);
void modifier (hotel1 x);
void afficher_hotel(GtkWidget *liste);
void rechercher(char nom_hotel[20]);
void afficher_hotel_rechercher(GtkWidget *liste);
void suprimmer(char Destination[20]) ;

