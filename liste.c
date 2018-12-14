#include"liste.h"

/*Création d'une coordonnée*/
coord_t creer_coord ( int x, int y) 
{
	coord_t p ;
	p.x = x ;
	p.y = y ;
	return p ;
}


/*Affiché la coordonnée*/
void affichage_coord (coord_t p)
{
	printf( " les coordonnées du point p sont:(%d,%d)\n ",p.x ,p.y);
}




/*Une focntion qui compare deux coordonnées*/
int comparer_coord ( coord_t p, coord_t q )
{
	if (( p.x == q.x ) && ( p.y == q.y ))
	{
		return 1;
	}
	else if ((p.x ==! q.x ) || ( p.y ==! q.y))
	{
		return 0 ;
	}
}





/*Une foction pour créer un mouvement */
mouv_t creer_mouvement ( coord_t initiale , coord_t* intermediaire , coord_t finale , piece_t piece , int promotion , int capture )
{
	mouv_t *m = malloc(sizeof(mouv_t));
	m->initiale = initiale;
	m->intermediaire = intermediaire;
	m->finale = finale ;
	m->piece = piece ;
	m->promotion = promotion ; 
	m-> capture = capture ;
	

	return *m;
} 


/*Une fonction pour détruire le mouvement*/

void detruire_mouvement( mouv_t *m) 
{
	free(m);
}




/*Une fonction pour créer un maillon */
maillon_t *creer_maillon (mouv_t *mouvement)
{
	maillon_t *p =malloc(sizeof(maillon_t));
	p->mouvement=mouvement;
	p->suivant=NULL;
	p->precedent=NULL;
	return p ;
}



/*Une fonction pour détruire un maillon  */
void detruire_maillon(maillon_t *res)
{
	detruire_mouvement(res->mouvement);
	free(res);
}



/*Initialisation d'un coup */
liste_coup_t* liste_initialiser()
{
	liste_coup_t *liste= malloc(sizeof(liste_coup_t));
	liste->debut=NULL;
	liste->fin=NULL;
	liste->taille=0;
	return liste ;
}




/*Vérifier si la liste des coup est vide ou pas */
int liste_vide(liste_coup_t liste)
{
	if( liste.taille == 0)
	return 1 ;
	return 0 ;
}


/*Extraction d'un coup a la fin de la liste*/
maillon_t *liste_extraire_fin(liste_coup_t* liste)
{
	if (liste->taille==0)
	{
		return NULL;
	}
	else 
	{
		maillon_t *tmp = liste->fin;
		liste->fin =tmp->precedent;
		tmp->precedent=NULL;
		liste->fin->suivant=NULL;
		liste->taille--;
	return tmp;
	}
}





/*Extraction d'un coup au début de la liste */
maillon_t *liste_extraire_debut(liste_coup_t *liste)
{
	if(liste->taille==0)
	{
		return NULL;
	}
	else 
	{
		maillon_t *tmp = liste->debut;
		liste->debut = tmp->suivant;
		tmp->precedent=NULL;
		liste->debut->precedent=NULL;
		liste->taille--;
	return tmp ;
	}
}




/*Ajout d'un coup au début de la liste*/
void liste_ajouter_debut (liste_coup_t *liste , maillon_t *m)
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




/*Ajout d'un coup a la fin de la liste */
void liste_ajouter_fin(liste_coup_t*liste , maillon_t *m)
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



/*déstruction de la liste des coups*/
void liste_detruire(liste_coup_t*liste)
{
	free(liste);
}












	
	
