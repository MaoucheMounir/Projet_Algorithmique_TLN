#ifndef LISTEFREQ_H
#define LISTEFREQ_H

//Ce fichier contient les fonctions qui mqnipulent les listes de frequences

#include"fonctionsBasiques.h"
#include"Chaines.h"

ListeFreq frequencesDe(char*) ;
ListeFreq contexte(char *, char *) ;

void afficherListeFreq(ListeFreq L) ;
int longueurListeFreq(ListeFreq L) ;

ListeFreq chercherMotListeFreq(ListeFreq L, char* mot) ;  //Retourne un pointeur sur le mot
ListeFreq allerPosFreq(ListeFreq T, int pos) ;
int posMotListeFreq(ListeFreq L, char *mot) ;    //Retourne la position du mot

ListeFreq supprimerMotListeFreq(ListeFreq F, char *mot) ;

ListeFreq minListeSelonFreq(ListeFreq T) ;
ListeFreq trierListeCroissantFreq(ListeFreq F) ;




ListeFreq fifoVersLIFO(ListeFreq F) ;

#endif
