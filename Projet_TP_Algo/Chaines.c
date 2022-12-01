#include"Chaines.h"


char* allouerChaine(int n) {
	char *S = (char*) malloc(n*sizeof(char)) ;
	if(!S) exit(-1) ;
	return S ;
}

int estLettre(char p) {

	if( ( p>='A' && p<='Z' ) || ( p>='a' && p<='z' ) )
		return 1 ;
	else return 0 ;
}

int estLexicographique(char x) {   //DIT SI C'EST UN CARACTERE LEXICOGRAPHIQUE DIFFERENT DU vide et des caracteres de controle
	if( !estLettre(x) && x!= ' ' && x!= '\t' && x!= '\v' && x!= '\b' && x!= '\r')
		return 1 ;
	else return 0 ;
}

char* majMin(char *S) {   //TRANSFORME TOUS LES CARACTERES D'UNE CHAINE EN MINUSCULE
	int i= 0;
	while(S[i] != '\0') {
		if( S[i] >='A' && S[i]<='Z' )
			S[i] = S[i] + 32 ;
		i++ ;
	}
	return S ;
}

char* copyPremierMot(char* S) { //COPIE LE PREMIER MOT OU CARACTERE LEXICOGRAPHIQUE D'UNE CHAINE
	char *ch =  allouerChaine(maxMot) ;
	int i = 0 ;

	if(S == NULL) return NULL ;

	while(*S == ' ' || *S == '\n' || *S == '\t' || *S == '\v' || *S == '\b' || *S == '\r')
		S++ ;

	if(*S == '\0')
		return NULL ;

	if(estLettre(*S)) {

		while(estLettre(*S)) {
			ch[i] = *S ;
			S++ ; i++ ;
		}
		ch[i] = '\0' ;
	}
	else {
		ch[0] = S[0] ;
		ch[1] = '\0' ;
		}
	return ch ;
}

char* supprPremierMot(char *b)  { //supprime le premier mot ou caractere lexicographique de la chaine

	char *a = copyPremierMot(b) ;
	char *r = strstr(b, a) ;

 	if(*(r +strlen(a)) == '\0')
		return NULL ;

	return ( r + strlen(a)  ) ;

}


char* lireFichier(char *file_name) {

    FILE *fich = fopen(file_name, "r");

    if (fich == NULL) {
        fprintf(stderr, "Error: Can't open file '%s'.", file_name);
        exit(EXIT_FAILURE);
    }

    // trouver la taille du fichier
    fseek(fich, 0, SEEK_END);
    long length = ftell(fich);

    fseek(fich, 0, SEEK_SET);

    // Allocation de la chaine qui va recevoir le contenu du fichier
    char *buffer = (char*) malloc((length +1) *sizeof(char) );

    buffer[length] = '\0';

    // Remplissage de la chaine
    fread(buffer, sizeof(char), length, fich);

    fclose(fich);

    majMin(buffer) ;

return buffer ;
}
