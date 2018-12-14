#include"partie.h"




int deplacement_valide(point_t pd,point_t pa, partie_t* pp){
	char c=pp->tablier[pd.x][pd.y].type;
	int s=pp->tablier[pd.x][pd.y].statue;
	int j=pp->tablier[pd.x][pd.y].joueur;
	if(pd.x==0||pd.y==0||pd.x==10||pd.y==10)
		return 0;
    if(pp->tablier[pd.x][pd.y].type=='.')
        return 0;
    if(pp->joueur!=pp->tablier[pd.x][pd.y].joueur)
        return 0;
	if(pp->tablier[pa.x][pa.y].type!='.')
		if(pp->tablier[pd.x][pd.y].joueur==pp->tablier[pa.x][pa.y].joueur)
			return 0;
	if(c=='p'||c=='d'||c=='P'||c=='D')
		return deplacement_valide_pion( pd, pa, s, j);
	if(c=='l'||c=='j'||c=='L'||c=='J')
		return deplacement_valide_lance( pd, pa, s, j,pp);	
	if(c=='n'||c=='c'||c=='N'||c=='C')
		return deplacement_valide_cavalier( pd, pa, s, j);
	if(c=='b'||c=='f'||c=='B'||c=='F')
		return deplacement_valide_fou( pd, pa, s, j,pp);
	if(c=='r'||c=='t'||c=='R'||c=='T')
		return deplacement_valide_tour( pd, pa, s, j,pp);
	if(c=='s'||c=='a'||c=='S'||c=='A')
		return deplacement_valide_general_argent( pd, pa, s, j);
	if(c=='g'||c=='G')
		return deplacement_valide_general_or( pd, pa, s, j);
	if(c=='k'||c=='K')
		return deplacement_valide_roi( pd, pa, s, j);
	return 0;
}
			
