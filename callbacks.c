#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "agent.h"


void
on_button1_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *Gestiondesagents;
GtkWidget *window1;

window1=create_window1();
gtk_widget_show(window1);
Gestiondesagents=lookup_widget(objet_graphique,"Gestiondesagents");
gtk_widget_hide(Gestiondesagents);

}



void
on_button3_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestiondesagents;
GtkWidget *window3;

window3=create_window3();
gtk_widget_show(window3);
Gestiondesagents=lookup_widget(objet_graphique,"Gestiondesagents");
gtk_widget_hide(Gestiondesagents);
}


void
on_button6_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestiondesagents;
GtkWidget *window1;

Gestiondesagents=create_Gestiondesagents();
gtk_widget_show(Gestiondesagents);
window1=lookup_widget(objet_graphique,"window1");
gtk_widget_hide(window1);

}



void
on_button10_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestiondesagents;
GtkWidget *window3;

Gestiondesagents=create_Gestiondesagents();
gtk_widget_show(Gestiondesagents);
window3=lookup_widget(objet_graphique,"window3");
gtk_widget_hide(window3);
}


void
on_button11_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
treeview1=lookup_widget(objet_graphique,"treeview1");
afficher_agent(treeview1);
}


void
on_button5_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
agent a;

GtkWidget*input1;
GtkWidget*input2;
GtkWidget*input3;
GtkWidget*combobox1;
GtkWidget*input5;
GtkWidget*input6;
GtkWidget*input7;
GtkWidget*sortie20;


GtkWidget *window1;

input1=lookup_widget(objet_graphique,"entry3");
input2=lookup_widget(objet_graphique,"entry4");
input3=lookup_widget(objet_graphique,"entry7");
combobox1=lookup_widget(objet_graphique,"combobox1");
input5=lookup_widget(objet_graphique,"entry6");
input6=lookup_widget(objet_graphique,"entry8");
input7=lookup_widget(objet_graphique,"entry15");

sortie20=lookup_widget(objet_graphique,"label35");

strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(a.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(a.cin,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(a.adresse,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(a.email,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(a.telephone,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(a.date,gtk_entry_get_text(GTK_ENTRY(input7)));

ajouter_agent(a);
GdkColor color;
gdk_color_parse ("green", &color);
gtk_widget_modify_fg (sortie20, GTK_STATE_NORMAL, &color);



gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(combobox1),"");
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_entry_set_text(GTK_ENTRY(input6),"");
gtk_entry_set_text(GTK_ENTRY(input7),"");
gtk_label_set_text(GTK_LABEL(sortie20),"L'ajout est effectué ");


}



void
on_button14_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{

char cin[20];
GtkWidget *input18;

input18=lookup_widget(objet_graphique,"entry20");

strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input18)));
 
rechercher(cin);

gtk_entry_set_text(GTK_ENTRY(input18), "");
GtkWidget *treeview1;
treeview1 = lookup_widget(objet_graphique,"treeview1");
afficher_agent_rechercher(treeview1);

}


void
on_button9_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget  *input1;

GtkWidget*sortie21;


    char cin[40];
    char nom1[40] ;
    char prenom1[40] ; 
    char cin1[20] ;
    char adresse1 [50] ; 
    char email1[40] ;
    char telephone1[30] ;
    char date1[30] ;
FILE *l;
	input1=lookup_widget(objet_graphique,"entry21");
	sortie21=lookup_widget(objet_graphique,"label37");

	strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input1)));
        l=fopen("/home/samos/Projects/project3/src/agent.txt","a+");
while (fscanf(l,"%s %s %s %s %s %s %s\n",nom1,prenom1,cin1,adresse1,email1,telephone1,date1)!=EOF)
	{
	if (strcmp(cin,cin1)==0)
	{
	gtk_label_set_text(GTK_LABEL(sortie21)," La suppression est effectué ");
	supprimer_agent(cin);

	GdkColor color;
	gdk_color_parse ("green", &color);
	gtk_widget_modify_fg (sortie21, GTK_STATE_NORMAL, &color);

	gtk_entry_set_text(GTK_ENTRY(input1), "");
 
	}
	else 
	{     
        GdkColor color;
	gdk_color_parse ("green", &color);
	gtk_widget_modify_fg (sortie21, GTK_STATE_NORMAL, &color);
	gtk_label_set_text(GTK_LABEL(sortie21),"le cin n'est pas correcte ");
	}
}


}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
   {
	
gchar *NOM; 
gchar *PRENOM;
gchar *CIN;
gchar *ADRESSE;
gchar *EMAIL;
gchar *TELEPHONE;
gchar *DATE;

GtkWidget *window2;
GtkWidget *current;
GtkTreeIter iter;

GtkWidget *E1;
GtkWidget *E2;
GtkWidget *E3;
GtkWidget *combobox2;
GtkWidget *E5;
GtkWidget *E6;
GtkWidget *E7;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&NOM,1,&PRENOM,2,&CIN,3,&ADRESSE,4,&EMAIL,5,&TELEPHONE,6,&DATE,-1);}
window2=create_window2();


E1=lookup_widget(window2,"SB1");
E2=lookup_widget(window2,"SB2");
E3=lookup_widget(window2,"SB3");
combobox2=lookup_widget(window2,"combobox2");
E5=lookup_widget(window2,"SB5");
E6=lookup_widget(window2,"SB6");
E7=lookup_widget(window2,"SB7");

gtk_entry_set_text(GTK_ENTRY(E1),NOM);
gtk_entry_set_text(GTK_ENTRY(E2),PRENOM);
gtk_entry_set_text(GTK_ENTRY(E3),CIN);
gtk_entry_set_text(GTK_ENTRY(combobox2),ADRESSE);
gtk_entry_set_text(GTK_ENTRY(E5),EMAIL);
gtk_entry_set_text(GTK_ENTRY(E6),TELEPHONE);
gtk_entry_set_text(GTK_ENTRY(E7),DATE);




gtk_widget_show (window2);

}
}


void
on_button7_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
char nom[50];
char prenom[50];
char cin[50];
char adresse[50];
char email[50];
char telephone[50];
char date[50];

GtkWidget *input100;
GtkWidget *input101;
GtkWidget *input102;
GtkWidget *combobox20;
GtkWidget *input104;
GtkWidget *input105;
GtkWidget *input106;
GtkWidget*sortie25;

GtkWidget *window2;


input100=lookup_widget(objet_graphique,"SB1");
input101=lookup_widget(objet_graphique,"SB2");
input102=lookup_widget(objet_graphique,"SB3");
combobox20=lookup_widget(objet_graphique,"combobox2");
input104=lookup_widget(objet_graphique,"SB5");
input105=lookup_widget(objet_graphique,"SB6");
input106=lookup_widget(objet_graphique,"SB7");

sortie25=lookup_widget(objet_graphique,"label38");

strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input100))); 
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input101)));
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input102)));
strcpy(adresse,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox20)));
strcpy(email,gtk_entry_get_text(GTK_ENTRY(input104)));
strcpy(telephone,gtk_entry_get_text(GTK_ENTRY(input105)));
strcpy(date,gtk_entry_get_text(GTK_ENTRY(input106)));

modifier (nom,prenom,cin,adresse,email,telephone,date);
GdkColor color;
gdk_color_parse ("green", &color);
gtk_widget_modify_fg (sortie25, GTK_STATE_NORMAL, &color);


gtk_entry_set_text(GTK_ENTRY(input100), "");
gtk_entry_set_text(GTK_ENTRY(input101), "");
gtk_entry_set_text(GTK_ENTRY(input102), "");
gtk_entry_set_text(GTK_ENTRY(combobox20),"");
gtk_entry_set_text(GTK_ENTRY(input104), "");
gtk_entry_set_text(GTK_ENTRY(input105), "");
gtk_entry_set_text(GTK_ENTRY(input106), "");

gtk_label_set_text(GTK_LABEL(sortie25),"La modification est effectué ");

}


void
on_button8_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestiondesagents;
GtkWidget *window2;

Gestiondesagents=create_Gestiondesagents();
gtk_widget_show(Gestiondesagents);
window2=lookup_widget(objet_graphique,"window2");
gtk_widget_hide(window2);
}

