#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include "agent.h"
//fonction affichier :
enum
{
NOM,
PRENOM,
CIN,
ADRESSE,
EMAIL,
TELEPHONE,
DATE,
COLUMN
};
void afficher_agent(GtkWidget *liste)
{


GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char nom[50];
char prenom[50];
char cin[50];
char adresse[50];
char email[50];
char telephone[50];
char date[50];

FILE *f;
store=NULL;
store=gtk_tree_view_get_model(liste);
if (store == NULL)
{
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("NOM",renderer,"text",NOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("PRENOM",renderer,"text",PRENOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",CIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("ADRESSE",renderer,"text",ADRESSE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("EMAIL",renderer,"text",EMAIL,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
			column=gtk_tree_view_column_new_with_attributes("TELEPHONE",renderer,"text",TELEPHONE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("DATE",renderer,"text",DATE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



	
}
	store=gtk_list_store_new(COLUMN,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("/home/samos/Projects/project3/src/agent.txt","r");
if (f == NULL ) {return;}
else
{
while (fscanf(f,"%s %s %s %s %s %s %s",nom,prenom,cin,adresse,email,telephone,date)!=EOF) {

	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter,NOM,nom,PRENOM,prenom,CIN,cin,ADRESSE,adresse,EMAIL,email,TELEPHONE,telephone,DATE,date,-1);
}
fclose(f);

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
}
}
//fonction ajouter :
void ajouter_agent(agent a)
{
 
  FILE *f;
  f=fopen("/home/samos/Projects/project3/src/agent.txt","a+");
  if(f!=NULL) 
  {
  fprintf(f,"%s %s %s %s %s  %s  %s \n ",a.nom ,a.prenom ,a.cin ,a.adresse ,a.email ,a.telephone,a.date ) ;
  fclose(f);
  }
}
//fonction chercher selon le critere CIN :

void rechercher(char cin[20])  
{
FILE* f; 
FILE* f1;
char nom1[50];
char prenom1[50];
char cin1[50];
char adresse1[50];
char email1[50];
char telephone1[50];
char date1[50];

f=fopen("/home/samos/Projects/project3/src/agent.txt","r");
f1=fopen("/home/samos/Projects/project3/src/agentcher.txt","w");
while (fscanf(f,"%s %s %s %s %s %s %s \n",nom1,prenom1,cin1,adresse1,email1,telephone1,date1)!=EOF)
	{
		if (strcmp(cin,cin1)==0)
		{
		fprintf(f1,"%s %s %s %s %s %s %s \n",nom1,prenom1,cin1,adresse1,email1,telephone1,date1);
		}
	}
	fclose(f);
	fclose(f1);
remove("/home/samos/Projects/project3/src/agentchercher.txt");
rename ("/home/samos/Projects/project3/src/agentcher.txt","agentchercher.txt");
}
//affichage de l'agent a chercher :
void afficher_agent_rechercher(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

char nom[50];
char prenom[50];
char cin[50];
char adresse[50];
char email[50];
char telephone[50];
char date[50];
       
 store=NULL;

        FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  NOM", renderer, "text",NOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" PRENOM", renderer, "text",PRENOM, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" CIN", renderer, "text",CIN, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" ADRESSE", renderer, "text",ADRESSE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" EMAIL", renderer, "text",EMAIL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		column = gtk_tree_view_column_new_with_attributes("  TELEPHONE", renderer, "text",
TELEPHONE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();

		column = gtk_tree_view_column_new_with_attributes("  DATE", renderer, "text",DATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
	}


	store=gtk_list_store_new (COLUMN, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING);

	f = fopen("/home/samos/Projects/project3/src/agentchercher.txt","r");

	if(f==NULL)
	{

		return;
	}
	else

	{ f = fopen("/home/samos/Projects/project3/src/agentchercher.txt","a+");
              while(fscanf(f,"%s %s %s %s %s %s %s \n",nom,prenom,cin,adresse,email,telephone,date)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, NOM,nom,PRENOM,prenom,CIN,cin,ADRESSE,adresse,EMAIL,email,
TELEPHONE,telephone,DATE,date, -1); 
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}
//supprimer a partir de CIN :
void supprimer_agent(char cinp[]) 
{   char nom1[40] ;
    char prenom1[40] ; 
    char cin1[20] ;
    char adresse1 [50] ; 
    char email1[40] ;
    char telephone1[30] ;
    char date1[30] ;

	FILE *l;
	FILE *t;
	l=fopen("/home/samos/Projects/project3/src/agent.txt","a+");
	t=fopen("/home/samos/Projects/project3/src/agent_tmp.txt","w");
	while (fscanf(l,"%s %s %s %s %s %s %s\n",nom1,prenom1,cin1,adresse1,email1,telephone1,date1)!=EOF)
	{
		if (strcmp(cinp,cin1)!=0)
		{
			fprintf(t,"%s %s %s %s %s %s %s \n",nom1,prenom1,cin1,adresse1,email1,telephone1,date1);

		}
	}
	fclose(l);
	fclose(t);
	remove("/home/samos/Projects/project3/src/agent.txt");
	rename("/home/samos/Projects/project3/src/agent_tmp.txt","agent.txt");
}

// modifier :
void modifier (char nom[20],char prenom[20],char cin[20],char adresse[50],char email[40],char telephone[20],char date[50])
{
FILE* f;
FILE* f1;
char nom1[40];
char prenom1[40]; 
char cin1[20];
char adresse1[50]; 
char email1[40] ;
char telephone1[20];
char date1[50];

f=fopen("/home/samos/Projects/project3/src/agent.txt","a+");
f1=fopen("/home/samos/Projects/project3/src/agent_tmp.txt","w");
while (fscanf(f,"%s %s %s %s %s %s %s  \n",nom1,prenom1,cin1,adresse1,email1,telephone1,date1)!=EOF)
{
	if(strcmp(cin,cin1)==0)
	{
    	fprintf(f1,"%s %s %s %s %s %s %s \n",nom,prenom,cin,adresse,email,telephone,date);

	}
	else
	{
	fprintf(f1,"%s %s %s %s %s %s %s  \n",nom1,prenom1,cin1,adresse1,email1,telephone1,date1 );
	}
}
fclose(f);
fclose(f1);
remove("/home/samos/Projects/project3/src/agent.txt");
rename("/home/samos/Projects/project3/src/agent_tmp.txt","agent.txt");

}
