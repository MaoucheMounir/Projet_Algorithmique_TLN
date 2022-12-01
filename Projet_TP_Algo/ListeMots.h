#ifndef LISTEMOTS_H
#define LISTEMOTS_H

//Ce fichier contient les fonctions qui mqnipulent les listes de mots

#include"fonctionsBasiques.h"
#include"Chaines.h"

ListeMots motsDe(char*) ;

void afficherListeMots(ListeMots ) ;
int longueurListeMots(ListeMots ) ;

int chercherMotListeMots(ListeMots, char*) ; //RETOURNE SI LE MOT EXISTE OU PAS
ListeMots allerPosMots(ListeMots T, int pos) ;
int posMotListeMots(ListeMots , char*) ;    //Retourne la position du mot





#endif
