#ifndef DICTMOTS_H
#define DICTMOTS_H

//Ce fichier contient les fonctions qui manipulent les dictionnaires de mots

#include"ListeMots.h"
#include"ListeFreq.h"

DictContext creerDictContext(char* c) ;

void afficherDictContext(DictContext Dict) ;

char* maxContext(DictContext D, char* m) ; //retourne le mot le plus frequent dans le contexte de m.
int freqCont(DictContext D, char* m, char* n) ;//Retourne le nombre d'apparition du mot n dans le contexte de m.

void genererText(DictContext D, int n) ;


#endif
