
#include"liste_conf.h"

struct partie_s
{
	piece_t* damier [10][10];
	liste_coup_t* c;
	liste_conf_t* f;
	int joueur;
};
typedef struct partie_s partie_t;

int case_vide (partie_t *partie , int x , int y ) ;
void modifer_case(partie_t * partie, piece_t *piece, int x , int y ) ;
void changer_joueur ( partie_t * partie ) ;
void afficher_plateau (partie_t * partie);
void modifier_damier(partie_t* partie , maillon_t *m);
void annuler_mouv(partie_t *partie);
coord_t saisie_case();
partie_t *partie_creer();
void detruire_partie(partie_t *partie);
partie_t* partie_nouvelle();
void partie_sauvegarder(partie_t* partie, char* nom_fich,char* nom_chemin);
partie_t* replay_charger(char* nom);
