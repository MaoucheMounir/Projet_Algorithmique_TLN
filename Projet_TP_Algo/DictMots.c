#include"DictMots.h"


DictContext creerDictContext(char* c) {
	ListeMots T ;
	DictContext Dict ;
	int i=0  ;

Dict.mots = motsDe(c) ;

Dict.contextes = (ListeFreq*) malloc( (longueurListeMots(Dict.mots)) *sizeof(ListeFreq) ) ;

T = Dict.mots ;

while(T!= NULL && T->mot != NULL) {

	Dict.contextes[i] = contexte(c, T->mot) ;
	T = T->suiv ; i++ ;
	}
	return Dict ;

}


void afficherDictContext(DictContext Dict) {
	ListeMots T = Dict.mots  ;
	int i=0 ;

    while(T!= NULL) {

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
            printf("\nLe contexte Du Mot \"%s\" est \n", T->mot) ;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            afficherListeFreq(Dict.contextes[i]) ;

        T = T->suiv ; i++ ;
    }
}


char* maxContext(DictContext D, char* m) { //retourne le mot le plus frequent dans le contexte de m.

	int pos = posMotListeMots(D.mots, m) ; //on Cherchela position du mot demande dans la liste des mots

	if(pos == 0 ) {
		printf("\nMot non valide\n") ;
		return NULL ;
	}
    return( D.contextes[pos-1]->mot );  //on chercher le contexte de ce mot, qui se trouve dans le tableau de contextes a pos-1 car le tableau commence de 0
                                        //La liste des contextes est triee par ordre decroissant, donc il suffit de retourner le 1er mot pour avoir le plus grand contexte
}

int freqCont(DictContext D, char* m, char* n) {//Retourne le nombre d'apparition du mot n dans le contexte de m.

	int pos = posMotListeMots(D.mots, m) ;

	if(pos == 0 ) {
		printf("\nMot non valide\n") ;
		return 0 ;
	}

	ListeFreq T = chercherMotListeFreq(D.contextes[pos-1], n) ;  //on chercher le contexte de ce mot, qui se trouve dans le tableau de contextes a pos-1 car le tableau commence de 0

	if(T == NULL ) {
		printf("\nContexte non valide\n") ;
		return 0 ;
	}

	return T->freq ;
}


void genererText(DictContext D, int n) {

    int i, k = rand() % (longueurListeMots(D.mots)+1) ;
    ListeMots L ;
    char *S = allouerChaine(maxMot) ;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
        printf("\nGeneration du texte :\n") ;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);

    L = allerPosMots(D.mots, k) ;
    printf("\n%s  ", L->mot) ;

    S = L->mot ;

    for(i=1; i<n; i++) {

        S = maxContext(D, S) ;
        printf("%s  ", S) ;
    }
    printf("\n") ;

free(S) ;
}

