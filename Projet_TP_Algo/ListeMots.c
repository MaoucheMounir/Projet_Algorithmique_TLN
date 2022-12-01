#include"ListeMots.h"


ListeMots motsDe(char *t) {  //le principe de cette fonction est de determiner le premier mot de la liste, verifier qu'il n'est pas deja present dans la liste, si il ne l'est pas, le copier dans la liste des mots, et le supprimer de la chaine et copier le premier mot, ainsi de suite jusqu'a ce que la chaine soit vide
	ListeMots L ;

	char *S = copyPremierMot(t) ; //cette fonction copie le premier mot ou caractere lexicographique de la chaine

	L = creerPremierMots(S) ;

	t = supprPremierMot(t) ;
	S = copyPremierMot(t) ;

	while( S != NULL) {

		if( !chercherMotListeMots(L, S) ) {
			creerNoeudMots(&L, S) ;
		}

		t = supprPremierMot(t) ;
		S = copyPremierMot(t) ;
		if(S == NULL ) break ;
	}

free(S) ;
	return L ;
}


void afficherListeMots(ListeMots L) {
        printf("\n\n{") ;

		while(L != NULL) {
            if(L->suiv == NULL) {
                printf("\"%s\"", L->mot) ;
            }

            else printf("\"%s\" ,  ", L->mot) ;

            L = L->suiv ;
		}
	printf("}\n") ;
}

int longueurListeMots(ListeMots L) {
	int i= 0 ;

	while(L != NULL) {
	i++ ;
    L = L->suiv ;
	}
	return i ;
}


ListeMots allerPosMots(ListeMots T, int pos) {   //RETOURNE UN POINTEUR SUR LE NOEUD A LA POSITION POS

	int i  ;
	ListeMots p= T ;

	for(i=1; i<pos; i++)
		p = p->suiv ;

	return p ;
	}


int chercherMotListeMots(ListeMots L, char *mot) {//RETOURNE SI LE MOT EXISTE OU PAS
    ListeMots p = L ;

	while(p != NULL && strcmp(p->mot, mot) != 0)
		p = p->suiv ;

	if(p != NULL)
		return 1 ;
	else {
	//printf("La valeur demandee n'existe pas \n") ;
	return (0) ;
	}
}


int posMotListeMots(ListeMots L, char *mot) {//RETOURNE La position du mot
    ListeMots p = L ;
	int pos = 1 , trouve = 0;


	if ( strcmp(p->mot, mot) == 0 )
		trouve = 1 ;

	while(p->suiv != NULL && !trouve) {
		pos++ ;
		p = p->suiv ;

		if ( strcmp(p->mot, mot) == 0 )
			trouve = 1 ;
	}

	if(trouve)
		return pos ;
	else
		return 0 ;

}

