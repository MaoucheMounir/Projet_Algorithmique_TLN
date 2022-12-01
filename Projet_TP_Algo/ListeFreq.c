#include"ListeFreq.h"


ListeFreq frequencesDe(char *t) {

	ListeFreq F, p ;
	char *C = copyPremierMot(t) ;

	F = creerPremierFreq(C, 1) ;

	t = supprPremierMot(t) ;
	C = copyPremierMot(t) ;  //determine le premier mot (ou caractere lexicographique)

	while( C != NULL) {

		if((p = chercherMotListeFreq(F, C) ) == NULL)   //si il n'a pas deja ete examine, on cree un nouveau noeud avec une frequence = 1,
			creerNoeudFreq(&F, C, 1) ;

		else 											//sinon on augmente sa freguence de 1
    		p->freq ++ ;


		t = supprPremierMot(t) ;  //on supprime le mot examine et on passe au suivant
		C = copyPremierMot(t) ;
	}

	F = trierListeCroissantFreq(F) ;

	free(C) ;
	return F ;
}

ListeFreq contexte(chaine S, chaine m) {
	char *p, *k =  allouerChaine(maxMot), *L = allouerChaine(Max) ;
	ListeFreq F ;

	p  = strstr(S, m)  ;   //on chercher le mot dans la chaine et on verifie qu'il existe

	if(p == NULL) {
		printf("\nLe mot n'existe pas ") ;
		return NULL ;
	}

	if(!estLexicographique(*p)) { //Si on cherche un mot, il faut verifier que le mot existe de maniere independante (pas contenu dans un autre mot) au moins une fois

		while((p!= NULL) && (estLettre(*(p+strlen(m)) ) || estLettre(*( p-1 ) ) ) )
			p = strstr(p+1, m) ;

		if(p==NULL)
			return NULL ;
	}

    if( *(p+strlen(m)) == '\0') {   // On verifie que le mot n'est pas le tout dernier mot dans le texte
		printf("\nLe mot <%s> est le dernier mot, il n'a pas de contexte ", m) ;
		return NULL ;
	}

	p = supprPremierMot(p) ;   //pour supprimer le mot et copier le mot juste apres, c'est a dire son contexte

	strcpy(L, copyPremierMot(p)) ;
	p = strstr(p, m) ;


	//cette boucle trouve toutes les occurences valides du mot, et copie leurs contextes dans une chaine

	while(p != NULL && *(p+strlen(m)) != '\0' ) {

		if(!estLexicographique(*p)) {  //On cherche une occurence valide du mot

			while( p!=NULL && (estLettre(*(p+strlen(m)) ) || estLettre(*(p-1) ) ) )
				p = strstr(p+1, m) ;
		}

		if(p != NULL) {

			p = supprPremierMot(p) ;  //On supprime le mot, on copie son contexte et on le concatene dans la chaine

			strcat(L, " ") ;
			k = copyPremierMot(p) ;

			if(k != NULL ) {    //si le mot dont il faut chercher le contexte est le tout dernier du fichier, il faut faire ce test
		  		strcat(L, k) ;

		  }
		  p = strstr(p, m)  ;
		}

	}

	F = frequencesDe(L) ;    // Il suffit maintenant de determiner les frequences des mots de la chaine

	F = fifoVersLIFO(F) ;  //Inverser l'ordre de la liste

	free(k) ; free(L) ;
	return F ;

}

void afficherListeFreq(ListeFreq L) {

    if(L == NULL)
        printf("\nAucun contexte") ;

    while(L != NULL) {
    	printf("\nLe mot \"%s\" apparait %d fois ", L->mot, L->freq) ;
    	L = L->suiv ;
    }
	printf("\n\n") ;
}

int longueurListeFreq(ListeFreq L) {
	int i= 0 ;

	while(L != NULL) {
		i++ ;
    	L = L->suiv ;
	}
	return i ;
}



ListeFreq chercherMotListeFreq(ListeFreq L, char* mot) {   //RETOURNE UN POINTEUR SUR LA POSITION DU MOT DANS LA LISTE
	ListeFreq p = L ;

	while(p != NULL && strcmp(p->mot, mot) != 0)
		p = p->suiv ;

	if(p != NULL)
		return p ;
	else
	    return (NULL) ;
}

ListeFreq allerPosFreq(ListeFreq T, int pos) { //RETOURNE UN POINTEUR SUR LE NOEUD A LA POSITION POS

int i  ;
	ListeFreq p= T ;

	for(i=1; i<pos; i++)
		p = p->suiv ;

	return p ;
}

int posMotListeFreq(ListeFreq L, char *mot) {//RETOURNE LA POSITION DU MOT
	ListeFreq p = L ;
	int pos = 1 , trouve = 0 ;

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



ListeFreq supprimerMotListeFreq(ListeFreq F, char *mot) {

	int pos = posMotListeFreq(F, mot) ;
	ListeFreq T = allerPosFreq(F, pos), r ;

	if(T == F) {
		F = T->suiv ;
		free(T) ;
	}
	else {
    	r = allerPosFreq(F, pos-1) ;
		r->suiv = T->suiv ;
		free(T) ;
	}
	return F ;
}


ListeFreq minListeSelonFreq(ListeFreq T) { //RETOURNE UN POINTEUR SUR LA PLUS PETITE FREQUENCE
	int i, n = longueurListeFreq(T) ;
	int fmin = T->freq ;
	ListeFreq p = T, r = p  ;

	for(i=0; i < n; i++) {

	if(p->freq < fmin) {
			fmin = p->freq ;
			r = p ;
		}
	p = p->suiv ;
	}

	return r ;
}

ListeFreq trierListeCroissantFreq(ListeFreq F) { //TRIE LA LISTE PAR ORDRE CROISSANT DE FREQUENCES
	ListeFreq T, tmp = minListeSelonFreq(F) ;

	T = creerPremierFreq(tmp->mot, tmp->freq) ;
	F = supprimerMotListeFreq(F, tmp->mot) ;

	while(F != NULL) {
		tmp = minListeSelonFreq(F) ;
		creerNoeudFreq(&T, tmp->mot, tmp->freq) ;
		F = supprimerMotListeFreq(F, tmp->mot) ;
	}
	return T ;

}



ListeFreq fifoVersLIFO(ListeFreq F) {
	int i, n = longueurListeFreq(F) ;
	ListeFreq T = creerPremierFreq(F->mot, F->freq) ,
			  p = F->suiv ;

	for(i=1; i<n; i++) {
		T = creerNoeudLIFO(T, p->mot, p->freq) ;
		p = p->suiv ;
	}
	return T ;
}

