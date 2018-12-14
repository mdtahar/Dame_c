#include"liste_conf.h"


/*Création d'un maillon de configuration */
maillon_conf_t *creer_maillon_conf (piece_t* damier[10][10])
{
	int i,j;
	maillon_conf_t* res=malloc(sizeof(maillon_conf_t*));
	res->damier[10][10]=malloc(10*10*sizeof(piece_t*));
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
				res->damier[10][10]=damier[i*10+j];
	res->suivant=NULL;
	res->precedent=NULL;
	return res;
}



/*Vérifier si la liste de configuration est vide ou pas */
int liste_conf_vide (liste_conf_t liste)
{
	if(liste.taille==0)
	return 1;	
	return 0;
}



/*Déstruction du maillon de configuration*/
void maillon_conf_detruire (maillon_conf_t* liste)
{
	free(liste);
}



/*Initialisation de la liste de configuration*/
liste_conf_t* liste_conf_initialiser()
{
	liste_conf_t *liste= malloc(sizeof(liste_conf_t));
	liste->debut=NULL;
	liste->fin=NULL;
	liste->taille=0;
	return liste ;
}



/*Ajout d'une liste de configuration au début*/
void liste_conf_ajouter_debut (liste_conf_t *liste , maillon_conf_t *m)
{
	if(liste->taille==0)
	{
		liste->debut = m;
		liste->fin=m;
	}
	else
	{
		m->suivant=liste->debut;
		liste->debut->precedent=m;
		liste->debut=m;
	}
	liste->taille++;

}




/*Ajout d'une liste de configuration a la fin */
void liste_conf_ajouter_fin(liste_conf_t*liste , maillon_conf_t *m)
{
	if(liste->taille==0)
	{
		liste->debut = m;
		liste->fin=m;
	}
	else
	{
		liste->fin->suivant=m;
		m->precedent=liste->fin;
		liste->fin=m;
	}
	liste->taille++;
	
}




/*Extraction d'une configuration en debut de la liste*/
maillon_t *liste_conf_extraire_debut(liste_conf_t *liste)
{
	if(liste->taille==0)
	{
		return NULL;
	}
	else 
	{
		maillon_conf_t *tmp = liste->debut;
		liste->debut = tmp->suivant;
		tmp->precedent=NULL;
		liste->debut->precedent=NULL;
		liste->taille--;
	return tmp ;
	}
}




/*Extraction d'une configuration a la fi de la liste*/
maillon_t *liste_conf_extraire_fin(liste_conf_t* liste)
{
	if (liste->taille==0)
	{
		return NULL;
	}
	else 
	{
		maillon_conf_t *tmp = liste->fin;
		liste->fin =tmp->precedent;
		tmp->precedent=NULL;
		liste->fin->suivant=NULL;
		liste->taille--;
	return tmp;
	}
}





/*Déstruction de la liste de configuration */
void detruire_liste_conf (liste_conf_t*liste)
{
	
	free(liste);
}
