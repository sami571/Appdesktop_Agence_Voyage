#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"





//afficher excursion 

void afficher(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter    iter;
GtkListStore *store;

char id[30];
char date[30];
char prix[30];
       
FILE *f;
store=NULL;
store=gtk_tree_view_get_model(liste);	
if (store == NULL)
{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text",ID,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("DATE", renderer, "text",DATE,NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("PRIX", renderer, "text",PRIX,NULL);	
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);		
	
		
}
		
store=gtk_list_store_new (COLUMN, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING);

f = fopen("/home/hassen/Projects/excursion/src/liste_excursion.txt","r");
if(f == NULL) {return;}		
else 
{
while (fscanf(f,"%s %s %s",id,date,prix)!=EOF) {

	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,ID,id,DATE,date,PRIX,prix, -1); 
}
fclose(f);
}
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
	g_object_unref (store);
	
}


//ajouter excursion

void ajouter_excursion(excursion exc)
{	char id[30];
	char date[30];
	char prix[30];
 FILE *f;
  f=fopen("liste_excursion.txt","a+");
  if(f!=NULL) 
  {
printf("test");
  fprintf(f,"%s %s %s\n",exc.id,exc.date,exc.prix);
}  
fclose(f);
}




//fonction rechercher
void rechercher(char id[20])  
{
FILE* f; 
FILE* f1;
char id1[20];
char date1[30];
char prix1[30];
f=fopen("/home/hassen/Projects/excursion/src/liste_excursion.txt","r");
f1=fopen("/home/hassen/Projects/excursion/src/liste_excursion2.txt","w");
while (fscanf(f,"%s %s %s\n",id1,date1,prix1)!=EOF)
	{
		if (strcmp(id,id1)==0)
		{
		fprintf(f1,"%s %s %s\n",id1,date1,prix1);
	}
		}
	fclose(f);
	fclose(f1);
remove("/home/hassen/Projects/excursion/src/liste_excursion3.txt");
rename("/home/hassen/Projects/excursion/src/liste_excursion2.txt","liste_excursion3.txt");
}

//afficher la recherche 
void afficher_rechercher(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

char id[30];
char date[30];
char prix[30];

       
 store=NULL;

        FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",ID, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("date", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("prix", renderer, "text",PRIX, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		renderer = gtk_cell_renderer_text_new ();

		
}

	store=gtk_list_store_new (COLUMN, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING );

	f = fopen("/home/hassen/Projects/excursion/src/liste_excursion3.txt","r");

	if(f==NULL)
	{

		return;
	}
	else

	{ f = fopen("/home/hassen/Projects/excursion/src/liste_excursion3.txt","a+");
              while(fscanf(f,"%s %s %s\n",id,date,prix)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, ID,id,DATE,date,PRIX,prix, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}


//mofifier excursion
void modifier(char id[30],char date[30],char prix[30])
{
FILE* f;
FILE* f1;
        char id1[30];
	char prix1[30];
	char date1[30];
f=fopen("/home/hassen/Projects/excursion/src/liste_excursion.txt","r");
f1=fopen("/home/hassen/Projects/excursion/src/liste_excursion4.txt","w");
while(fscanf(f,"%s %s %s  \n",id1,date1,prix1)!=EOF)
{
if(strcmp(id,id1)==0)
{
fprintf(f1,"%s %s %s\n",id,date,prix);
}
else
{
fprintf(f1,"%s %s %s\n",id1,date1,prix1);
}
}
  fclose(f);
  fclose(f1);
  remove("/home/hassen/Projects/excursion/src/liste_excursion.txt");
  rename("/home/hassen/Projects/excursion/src/liste_excursion4.txt","liste_excursion.txt");
}

//supprimer excursion

void supprimer (char id[30],char date[30])
{
	char id1[30];
	char date1[30];
	char prix1[30];


	FILE *l;
	FILE *t;
	l=fopen("/home/hassen/Projects/excursion/src/liste_excursion.txt","r");
	t=fopen("/home/hassen/Projects/excursion/src/liste_excursion5.txt","a+");
	while (fscanf(l,"%s %s %s\n",id1,date1,prix1 )!=EOF)
	{
		if (strcmp(id,id1)!=0)

		{
			if (strcmp(date,date1)!=0)
			{
			fprintf(t,"%s %s %s\n",id1,date1,prix1);
			}
		}
	}

	fclose(l);
	fclose(t);
	remove("/home/hassen/Projects/excursion/src/liste_excursion.txt");
	rename("/home/hassen/Projects/excursion/src/liste_excursion5.txt","liste_excursion.txt");

}


