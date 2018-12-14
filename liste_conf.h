#include"liste.h"


struct conf_s
{
	piece_t damier[10][10];
};
typedef struct conf_s conf_t;


struct maillon_conf_s
{
conf_t* damier [10][10];
struct maillon_conf_s *suivant ;
struct maillon_conf_s *precedent;
}; 

typedef struct maillon_conf_s maillon_conf_t ; 


struct liste_conf_s
{
	maillon_conf_t *debut;
	maillon_conf_t *fin;
	int taille ;
};
typedef struct liste_conf_s liste_conf_t;
maillon_conf_t *creer_maillon_conf (piece_t* damier[10][10]);
int liste_conf_vide (liste_conf_t liste);
void maillon_conf_detruire (maillon_conf_t* liste);
liste_conf_t* liste_conf_initialiser();
void liste_conf_ajouter_debut (liste_conf_t *liste , maillon_conf_t *m);
void liste_conf_ajouter_fin(liste_conf_t*liste , maillon_conf_t *m);
maillon_t *liste_conf_extraire_fin(liste_conf_t* liste);
void detruire_liste_conf (liste_conf_t*liste);
