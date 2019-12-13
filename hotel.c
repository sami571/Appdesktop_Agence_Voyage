#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hotel.h"
#include <gtk/gtk.h>

enum
{
	 NOM_HOTEL,
         DESTINATION,
         PRIX_PAR_NUITEE,
	COLUMNS
};

void ajouter_hotel(hotel1 h1)
{

 FILE *f;
 f=fopen("/home/wiem/Projects/project10/src/hotel.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s\n",h1.nom_hotel,h1.Destination,h1.prix_par_nuitee);
 }
 fclose(f);
 
 }

//modifier
void modifier (hotel1 x)
{
FILE* f;
FILE* f1;
char nom_hotel1[20];
char Destination1[20];
char prix_par_nuitee1[20];

f=fopen("/home/wiem/Projects/project10/src/hotel.txt","r");
f1=fopen("/home/wiem/Projects/project10/src/hoteltmp.txt","w");
while (fscanf(f,"%s %s %s\n",nom_hotel1,Destination1,prix_par_nuitee1)!=EOF)
{
	if(strcmp(x.Destination,Destination1)==0)
	{
		fprintf(f1,"%s %s %s\n",x.nom_hotel,x.Destination,x.prix_par_nuitee);
	}
	else
	{
		fprintf(f1,"%s %s %s\n",nom_hotel1,Destination1,prix_par_nuitee1);
	}
}
fclose(f);
fclose(f1);
remove("/home/wiem/Projects/project10/src/hotel.txt");
rename("/home/wiem/Projects/project10/src/hoteltmp.txt","hotel.txt");
}
//suppression du hotel 
void suprimmer(char Destination[20]) 
{
	char nom_hotel1[20];
	char Destination1[20];
	char prix_par_nuitee1[20];
	
	FILE *l;
	FILE *t;
	l=fopen("/home/wiem/Projects/project10/src/hotel.txt","r");
	t=fopen("/home/wiem/Projects/project10/src/hoteltmp.txt","a+");
	while (fscanf(l,"%s %s %s\n",nom_hotel1,Destination1,prix_par_nuitee1)!=EOF)
	{
		if (strcmp(Destination,Destination1)!=0)
		{
			fprintf(t,"%s %s %s\n",nom_hotel1,Destination1,prix_par_nuitee1);
		}
	}
	fclose(l);
	fclose(t);
	remove("/home/wiem/Projects/project10/src/hotel.txt");
	rename("/home/wiem/Projects/project10/src/hoteltmp.txt","hotel.txt");
}


void afficher_hotel(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

char nom_hotel[20];
char Destination[20];
char prix_par_nuitee[20];

store=NULL;

        FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nom_hotel", renderer, "text",NOM_HOTEL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Destination", renderer, "text",DESTINATION, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prix_par_nuitee", renderer, "text",PRIX_PAR_NUITEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		
	}


	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING );

	f = fopen("/home/wiem/Projects/project10/src/hotel.txt", "r");

	if(f==NULL)
	{

		return;
	}
	else

	{ f = fopen("/home/wiem/Projects/project10/src/hotel.txt", "a+");
              while(fscanf(f,"%s %s %s \n",nom_hotel,Destination,prix_par_nuitee)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NOM_HOTEL, nom_hotel, DESTINATION, Destination, PRIX_PAR_NUITEE, prix_par_nuitee, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}



// recherche 
void rechercher(char nom_hotel[20])  
{
FILE* f; 
FILE* f1;
char nom_hotel1[20];
char Destination1[20];
char prix_par_nuitee1[20];

f=fopen("/home/wiem/Projects/project10/src/hotel.txt","r");
f1=fopen("/home/wiem/Projects/project10/src/hotelch.txt","w");
while (fscanf(f,"%s %s %s\n",nom_hotel1,Destination1,prix_par_nuitee1)!=EOF)
	{
		if (strcmp(nom_hotel,nom_hotel1)==0)
		{
		fprintf(f1,"%s %s %s\n",nom_hotel1,Destination1,prix_par_nuitee1);
		}
	}
	fclose(f);
	fclose(f1);
remove("/home/wiem/Projects/project10/src/hotelrecherche.txt");
rename ("/home/wiem/Projects/project10/src/hotelrech.txt","hotelrecherche.txt");
}

//afficherhotel rechercher
void afficher_hotel_rechercher(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

char nom_hotel[20];
char Destination[20];
char prix_par_nuitee[20];

store=NULL;

        FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nom_hotel", renderer, "text",NOM_HOTEL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Destination", renderer, "text",DESTINATION, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prix_par_nuitee", renderer, "text",PRIX_PAR_NUITEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	}


	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING );

	f = fopen("/home/wiem/Projects/project10/src/hotelch.txt", "r");

	if(f==NULL)
	{

		return;
	}
	else

	{ f = fopen("/home/wiem/Projects/project10/src/hotelch.txt", "a+");
              while(fscanf(f,"%s %s %s \n",nom_hotel,Destination,prix_par_nuitee)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NOM_HOTEL, nom_hotel, DESTINATION, Destination, PRIX_PAR_NUITEE, prix_par_nuitee, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

