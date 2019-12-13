#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ajouter_voiture.h"
#include <gtk/gtk.h>
enum
{
	 MODELE,
         MATRICULE1,
         MATRICULE2,
         COULEUR,
         PRIX ,
	COLUMNS
};
enum
{	
	NOM,
	PRENOM,
	CIN,
	COLUMNS1
};
void ajouter_voiture(voiture v)
{

 FILE *f;
  f=fopen("/home/ala/Projects/atelier/src/voitures.txt","a+");
  if(f!=NULL) 
  {
  fprintf(f,"%s %s %s %s %s\n",v.modele,v.matricule1,v.matricule2,v.couleur,v.prix);
}
 fclose(f);

}

void afficher_voiture(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

char modele[20];
char matricule1[20];
char matricule2[20];
char couleur[20];
char prix[20];
       
 store=NULL;

        FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  modele", renderer, "text",MODELE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" matricule1", renderer, "text",MATRICULE1, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" matricule2", renderer, "text",MATRICULE2, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" couleur", renderer, "text",COULEUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  prix", renderer, "text",PRIX, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}


	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING );

	f = fopen("/home/ala/Projects/atelier/src/voitures.txt", "r");

	if(f==NULL)
	{

		return;
	}
	else

	{ f = fopen("/home/ala/Projects/atelier/src/voitures.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s \n",modele,matricule1,matricule2,couleur,prix)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, MODELE, modele, MATRICULE1, matricule1, MATRICULE2, matricule2, COULEUR, couleur,PRIX,prix, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
//modifier
void modifier (char modele[20],char matricule1[20],char matricule2[20],char couleur[20],char prix[20])
{
FILE* f;
FILE* f1;
char modele1[20];
char matricule01[20];
char matricule02[20];
char couleur1[20];
char prix1[20];
f=fopen("/home/ala/Projects/atelier/src/voitures.txt","r");
f1=fopen("/home/ala/Projects/atelier/src/voiturestmp.txt","w");
while (fscanf(f,"%s %s %s %s %s\n",modele1,matricule01,matricule02,couleur1,prix1)!=EOF)
{
	if(strcmp(matricule2,matricule02)==0)
	{
		fprintf(f1,"%s %s %s %s %s\n",modele,matricule1,matricule2,couleur,prix);
	}
	else
	{
		fprintf(f1,"%s %s %s %s %s\n",modele1,matricule01,matricule02,couleur1,prix1);
	}
}
fclose(f);
fclose(f1);
remove("/home/ala/Projects/atelier/src/voitures.txt");
rename("/home/ala/Projects/atelier/src/voiturestmp.txt","voitures.txt");
}
// recherche 
void rechercher(char modele[20])  
{
FILE* f; 
FILE* f1;
char modele1[20];
char matricule01[20];
char matricule02[20];
char couleur1[20];
char prix1[20];
f=fopen("/home/ala/Projects/atelier/src/voitures.txt","r");
f1=fopen("/home/ala/Projects/atelier/src/voiturech.txt","w");
while (fscanf(f,"%s %s %s %s %s\n",modele1,matricule01,matricule02,couleur1,prix1)!=EOF)
	{
		if (strcmp(modele,modele1)==0)
		{
		fprintf(f1,"%s %s %s %s %s\n",modele1,matricule01,matricule02,couleur1,prix1);
		}
	}
	fclose(f);
	fclose(f1);
remove("/home/ala/Projects/atelier/src/voiturecherche.txt");
rename ("/home/ala/Projects/atelier/src/voiturerech.txt","voiturecherche.txt");
}
//affichervoiture rechercher
void afficher_voiture_rechercher(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

char modele[20];
char matricule1[20];
char matricule2[20];
char couleur[20];
char prix[20];
       
 store=NULL;

        FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  modele", renderer, "text",MODELE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" matricule1", renderer, "text",MATRICULE1, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" matricule2", renderer, "text",MATRICULE2, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" couleur", renderer, "text",COULEUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  prix", renderer, "text",PRIX, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}


	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING );

	f = fopen("/home/ala/Projects/atelier/src/voiturech.txt", "r");

	if(f==NULL)
	{

		return;
	}
	else

	{ f = fopen("/home/ala/Projects/atelier/src/voiturech.txt", "a+");
              while(fscanf(f,"%s %s %s %s %s \n",modele,matricule1,matricule2,couleur,prix)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, MODELE, modele, MATRICULE1, matricule1, MATRICULE2, matricule2, COULEUR, couleur,PRIX,prix, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}//suppression du voiture 
void suprimmer(char matricule1[20],char  matricule2[20]) 
{
	char modele1[20];
	char matricule01[20];
	char matricule02[20];
	char couleur1[20];
	char prix1[20];


	FILE *l;
	FILE *t;
	l=fopen("/home/ala/Projects/atelier/src/voitures.txt","r");
	t=fopen("/home/ala/Projects/atelier/src/voiturestmp.txt","a+");
	while (fscanf(l,"%s %s %s %s %s\n",modele1,matricule01,matricule02,couleur1,prix1)!=EOF)
	{
		if (strcmp(matricule2,matricule02)!=0)
		{
			if (strcmp(matricule2,matricule02)!=0)
{
			fprintf(t,"%s %s %s %s %s\n",modele1,matricule01,matricule02,couleur1,prix1);
}
		}
	}
	fclose(l);
	fclose(t);
	remove("/home/ala/Projects/atelier/src/voitures.txt");
	rename("/home/ala/Projects/atelier/src/voiturestmp.txt","voitures.txt");
}

void afficher_clients(GtkWidget *liste)
{	
	voiture v;
	clients c;
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

char nom[20];
char prenom[20];
char cin[20];
       
 store=NULL;

        FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  nom", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" prenom", renderer, "text",PRENOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" cin", renderer, "text",CIN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		
	}


	store=gtk_list_store_new (COLUMNS1, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING );

	f = fopen("/home/ala/Projects/atelier/src/clients.txt", "r");

	if(f==NULL)
	{

		return;
	}
	else

	{ f = fopen("/home/ala/Projects/atelier/src/clients.txt", "a+");
              while(fscanf(f,"%s %s %s  \n",nom,prenom,cin)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NOM, nom, PRENOM, prenom, CIN, cin, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
