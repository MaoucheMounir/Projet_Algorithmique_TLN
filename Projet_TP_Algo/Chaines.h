#ifndef CHAINES_H
#define CHAINES_H

//Ce fichier contient les fonctions qui manipules les chaines de caracteres

#include"fonctionsBasiques.h"

char* allouerChaine(int n) ;

int estLettre(char p) ;      //verifie si le caractere est une lettre
int estLexicographique(char x) ;  //verifie si le caractere est lexicographique different du vide et les caracteres de controle

char* majMin(char *S) ;  //transforme les caracteres en majuscule de la chaine en minuscule

char* copyPremierMot(char*S) ;  //Copie le premier mot (mot constitue de lettres ou bien un caractere lexicographique
char* supprPremierMot(char *S) ;  //Supprime le premier mot de la chaine

char* lireFichier(char *file_name) ;

#endif
