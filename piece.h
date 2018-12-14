#include<stdlib.h>
#include<stdio.h>
#include<math.h>
struct piece_s
{
int joueur;
char statut;
};
typedef struct piece_s piece_t;

piece_t piece_creer(int joueur, char statut);
int piece_joueur( piece_t piece);
piece_t piece_identifier ( char s) ;
char piece_caractere (piece_t piece);
char piece_caractere (piece_t piece);
