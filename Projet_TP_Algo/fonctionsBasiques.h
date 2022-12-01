#ifndef FONCTIONBASIQUES_H
#define FONCTIONBASIQUES_H

//Ce fichier contient les fonctions qui premettent de creer les listes
//ansi que les differentes definitions de types

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<windows.h>
#include<conio.h>


#define taille 200
#define maxMot 40
#define Max 1000

typedef char chaine[taille] ;

typedef struct noeudFreq *ListeFreq ;
typedef struct noeudFreq {
        char *mot   ;
		int   freq  ;
        ListeFreq suiv ;
}noeudFreq;

typedef struct noeudMot* ListeMots ;

typedef struct noeudMot {
        char  *mot  ;
        ListeMots suiv ;
}noeudMot;

typedef struct {
	ListeMots mots ;
	ListeFreq *contextes ;

}DictContext;

ListeMots creerPremierMots(char* mot) ;
ListeMots dernierNoeudMots(ListeMots T) ;
void creerNoeudMots(ListeMots *T, char *mot) ;

ListeFreq creerPremierFreq(char* mot, int freq) ;
ListeFreq dernierNoeudFreq(ListeFreq T) ;
void creerNoeudFreq(ListeFreq *T, char *mot, int x) ;

ListeFreq creerNoeudLIFO(ListeFreq T, char* mot, int freq ) ;

#endif



