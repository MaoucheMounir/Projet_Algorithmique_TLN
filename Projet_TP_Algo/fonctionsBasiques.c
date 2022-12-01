#include"fonctionsBasiques.h"


ListeMots creerPremierMots(char* mot) {

    ListeMots L= (ListeMots) malloc(sizeof(noeudMot)) ;
    L->suiv = NULL ;

    L->mot  = mot   ;
	return L       ;
}

ListeMots dernierNoeudMots(ListeMots T) {

    ListeMots p = T ;

    if(T == NULL)
    	return NULL ;

    while(p->suiv != NULL)
        p = p->suiv ;

    return p ;
}

void creerNoeudMots(ListeMots *T, char *mot) {
    ListeMots p = dernierNoeudMots(*T), r = creerPremierMots(mot) ;
    p->suiv = r ;

}


ListeFreq creerPremierFreq(char* mot, int freq) {
    ListeFreq L = (ListeFreq) malloc(sizeof(noeudFreq)) ;
    if(L==NULL) exit(-1) ;

	L->suiv = NULL ;
    L->freq  = freq   ;
    L->mot  = mot   ;
	return L       ;
}

ListeFreq dernierNoeudFreq(ListeFreq T){
    ListeFreq p=T ;
    while(p->suiv != NULL){
        p = p->suiv ;
    }
    return p ;
}

void creerNoeudFreq(ListeFreq *T, char *mot, int x) {

	ListeFreq p = dernierNoeudFreq(*T), r = creerPremierFreq(mot, x) ;
    p->suiv = r ;

}

ListeFreq creerNoeudLIFO(ListeFreq T, char* mot, int freq ) {
	ListeFreq p = creerPremierFreq(mot, freq) ;
	p->suiv = T ;

return p ;
}
