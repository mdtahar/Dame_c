#include"piece.h"
#define non_promu = 0/p
#define promu = 1 /d
#define joueur1 = 0
#define joueur2 = 1 // P, D


/*Création d'une piece*/
piece_t piece_creer(int joueur, char statut)
{
piece_t piece ;
piece.joueur=joueur;
piece.statut=statut;
return piece;
}

/*Elle renvoie le joeur en fonction de la piece donnée en argument */
int piece_joueur( piece_t piece)
{
return piece.joueur;
}


/*elle identifie la piece et renvoie sa correspendence */
piece_t piece_identifier ( char s) 
{
	piece_t piece;
	
		if ( s=='p'|| s=='d')
			return piece_creer(0,s);
	
		if (s== 'D' || s=='P')
			return piece_creer(1,s);
}

/*Elle renvoie le type de la piece entrée*/
char piece_caractere (piece_t piece)
{
	return piece.statut;
}

/*Affiche la piece entrée*/
void piece_afficher( piece_t piece)
{
	printf("%c",piece.statut);
}




































