#include<stdlib.h>
#include<stdio.h>
#include"partie.h"


/*Vérifier si la case est vide en un point */
int case_vide (partie_t *partie , int x , int y ) 
{ 
	if (partie -> damier[x][y]->statut == 'p' || 'd' || 'D' || 'P')
	return 0;
	return 1;
			
}




/*Modification d'une piéce en un point */
void modifer_case(partie_t * partie, piece_t *piece, int x , int y ) 
{
	if (case_vide(partie,x,y)==1)
		partie->damier[x][y]=piece;
	else
		printf("la casse est deja occupé par une piéce\n");
}


	

/*Changement de joueur en cours de la partie */
void changer_joueur ( partie_t * partie ) 
{
	if(partie->joueur==0)
	{
		partie->joueur=1;
		printf("c'est le joueur 1 qui a le trait\n");
	}
	else 
	{	partie->joueur=0;
		printf("c'est le joueur 0 qui a le trait \n");
	}
}




/*Affichage du plateau*/
void afficher_plateau (partie_t * partie)
{
	int i;
	int j;

	
	for(j=0;j<=9;j++)
	{
		printf("  %d",j);
	}
	printf("\n");
	

	for(i=9;i>=0;i--)
	{	printf("%d ",i);
		
		
		if(i==4 || i==5)
			for(j=0;j<=9;j++)
			{
				if((j+i)%2==0)
					printf("   ");
				else
					printf(".  ");
			
			}
			
		if(i==0 || i==1 || i==2 || i==3)
			for(j=0;j<=9;j++)
			{
				if((j+i)%2==0)
				{
					printf("   ");
				}
				else
				{
					printf("P  ");
				}
		
			}
			
		if(i==6 || i==7 || i==8 || i==9)
			for(j=0;j<=9;j++)
			{	
				if((j+i)%2==0)
				{
					printf("   ");
				}
				else 
				{
					printf("p  ");
				}	
		
			}
		
		printf("\n");
	}
}





/*Modification du damier*/
void modifier_damier(partie_t* partie , maillon_t *m)
{
	m=creer_maillon (partie->damier[10][10]);
	liste_ajouter_debut(partie->c,m);
}





/*Annulation d'un mouvement*/
void annuler_mouv(partie_t *partie)
{
	detruire_maillon(liste_extraire_debut(partie->c));
}





/*Saisie d'une case , si elle n'éxiste pas elle est créer*/
coord_t saisie_case()
{
	int x,y;
	do
	{
		printf("Entrez les deux coordonnées: ");
		scanf("%d %d",&x,&y);
	}
	while((x  >9 && x < 0) && (9 < y && 0 > y));
		return creer_coord(x,y);
}





/*Création d'une partie de jeu de dame*/
partie_t *partie_creer()
{
	int x;
	char y;
        piece_t p;
	partie_t *res=malloc(sizeof(partie_t*));
	res->c=liste_initialiser();
	res->f=liste_conf_initialiser();
	res->joueur=0;
	p=(piece_creer(x,y));
	res->damier[10][10] = &p;
	
	return res;
}
	



/*déstruction de la partie*/
void detruire_partie(partie_t *partie)
{
	detruire_liste_conf(partie->c);
	liste_detruire(partie->c);
}




/*Lancer une nouvelle partie*/
partie_t* partie_nouvelle()
{
	partie_t *partie;
	partie = partie_creer();
	return partie;
	
}

/*fonction pour sauvegarder la*/
void partie_sauvegarder(partie_t* partie, char* nom_fich,char* nom_chemin)	
{
	int x,y;
	liste_coup_t* liste;
	FILE *fich=NULL;
	fich=fopen(nom_fich,"w+");
	if (fich!=NULL){
		fprintf(fich,"PL\n");
		for(x=0;y<10;x++){
			for(y=0;y<10;y++)
				fprintf(fich,"%c ",partie->damier[x][y]->statut);
			fprintf(fich,"\n");
		}
    	}    	
    	else
	{        
		printf("Impossible d'ouvrir le fichier %s",nom_fich);
       		fclose(fich);
        }


	fich=fopen(nom_chemin,"w+");
        if (fich !=NULL)
		{
	        	fprintf(fich,"PR\n");
	        	liste=partie->c->debut;
	        	for(x=0;x<partie->c->taille;x++){
	        		fprintf(fich,"%d %d ; %d %d ;%d %d %d\n",liste->debut->mouvement->initiale.x, liste->debut->mouvement->initiale.y, liste->debut->mouvement->finale.x, liste->debut->mouvement->finale.y, liste->debut->mouvement->promotion, liste->debut->mouvement->capture , liste->debut->mouvement->intermediaire);
        		liste=liste->debut->suivant;
        	}
        }
        else
        	printf("Impossible d'ouvrir le fichier %s",nom_chemin);
        fclose(fich);
	
}

/*partie_t* replay_charger(char* nom)
{
    char m[100];
    int x, y, z, j, r, k , a , b;
    liste_coup_t* liste;
    coord_t coord1,coord2,coord3 ;
    partie_t* partie;
    partie=partie_creer();
    FILE *fich=NULL;
    fich=fopen(nom,"a+");
    fscanf(fich,"%s",x);
    
    while(!feof(fich)){
        fscanf(fich,"%d %d ; %d %d ;%d %d;%d %d\n", &x, &y, &z, &j, &r, &k, &a, &b);
      
        coord1=creer_coord(x,y);
        coord2=creer_coord(z,j);
	coord3=creer_coord(r,k);        
	    liste=creer_mouvement(coord1, coord2,coord3,a, b);
        liste_ajouter_fin(partie->c, liste);
    }
    changer_joueur(partie);
    replay_jouer(partie);
        printf("\t\tC'est au joueur %d de jouer.\n", partie->joueur);    
    return partie;
}*/













 

	
