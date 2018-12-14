
#include"piece.h"

struct coord_s
{
int x;
int y;
};
typedef struct coord_s coord_t;
struct mouv_s
{
	coord_t initiale;
	coord_t *intermediaire; /*tableau*/
	coord_t finale ;
	piece_t piece;
	int tailleInter;
	int promotion;
	int capture ;
};
typedef struct mouv_s mouv_t;


struct maillon_s
{
	mouv_t *mouvement ;
	struct maillon_s *suivant ;
	struct maillon_s *precedent;
};
typedef struct maillon_s maillon_t;

struct liste_coup_s 
{
	maillon_t *debut;
	maillon_t *fin;
	int taille ;
};
typedef struct liste_coup_s liste_coup_t;
coord_t creer_coord ( int x, int y) ;
void affichage_coord (coord_t p);
int comparer_coord ( coord_t p, coord_t q );
mouv_t creer_mouvement (coord_t initiale , coord_t* intermediaire , coord_t finale , piece_t piece , int promotion , int capture );
void detruire_mouvement( mouv_t *m) ;
maillon_t *creer_maillon (mouv_t *mouvement);
void detruire_maillon(maillon_t *res);
liste_coup_t* liste_initialiser();
int liste_vide(liste_coup_t liste);
maillon_t *liste_extraire_debut(liste_coup_t *liste);
maillon_t *liste_extraire_fin(liste_coup_t* liste);
void liste_detruire(liste_coup_t*liste);
void liste_ajouter_debut (liste_coup_t *liste , maillon_t *m);
void liste_ajouter_fin(liste_coup_t*liste , maillon_t *m);
