#include"affichage.h"


void afficherIntroduction() {

system("cls");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);

printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);

    printf("\n\t\t\t\t\t\t%c      Bonjour\t     %c",186,186);

printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    printf("\n\n\n\t\t\tOn dispose d'un programme qui effectue des traitements sur un fichier texte ") ;

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    printf("\n\nVeuillez donner le fichier a ouvrir en precisant le format :   ") ;

}


void afficherMenu() {

    system("cls");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);

printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);

    printf("\n\t\t\t\t\t\t%c     Projet TP Algo  \t %c",186,186);


printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
printf("\n\n") ;

printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);

                                                                  printf("\n\t%c  Menu des operations \t %c",186,186);

printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);


SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

        printf("\n\n\n\t\t1-MotsDe: renvoie les differents mots du fichier\n");
        printf("\n\t\t2-FrequencesDe: Retourne la liste des frequences des mots du fichier\n");
        printf("\n\t\t3-Contexte: Retourne la liste des contextes d'ordre 1 d'un mot\n");
        printf("\n\t\t4-DictContext: Affiche le dictionnaire des contextes du fichier\n");
        printf("\n\t\t5-MaxContext: Retourne Le mot le plus frequent dans le contexte d'un mot\n");
        printf("\n\t\t6-FreqCont: Retourne le nombre d'apparitions d'un mot dans le contexte d'un autre mot\n");
        printf("\n\t\t7-GenererText: affiche la sequence de n mots ou chaque mot est le contexte le plus frequent du precedent\n") ;
        printf("\n\t\t\t\t\t\t\t0-Quiter Le Programme ") ;

printf("\n");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);

       printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);

    printf("\n\t%c      Choisir l'operation a effectuer    %c",186,186);



printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    printf("\n\t\t\t\t\t\t\t\t\ttaper votre choix ICI:\t");


}

void afficherMotsDe() {
system("cls");   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
 printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);

    printf("\n\t\t\t\t\t\t%c\t  MotsDe\t %c",186,186);

printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

}

void afficherFrequencesDe() {

system("cls");   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
 printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);

    printf("\n\t\t\t\t\t\t%c      FrequencesDe \t %c",186,186);

printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);


}

void afficherContexte() {

system("cls"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
 printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);

    printf("\n\t\t\t\t\t\t%c\tContexte \t %c",186,186);

printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

}

void afficherDictionnaire() {

system("cls"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);

    printf("\n\t\t\t\t\t\t%c\tDictContext \t %c",186,186);

printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);


}

void afficherMaxContext() {

system("cls"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);

    printf("\n\t\t\t\t\t\t%c\tMaxContext:\t %c",186,186);

printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);


}

void afficherFreqCont() {

        system("cls"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
 printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);

    printf("\n\t\t\t\t\t\t%c\t FreqCont \t %c",186,186);

printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

}

void afficherGenererText() {

 system("cls"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
 printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);

    printf("\n\t\t\t\t\t\t%c\tGenererText \t %c",186,186);

printf("\n\t\t\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);


}


void afficherSortie() {

printf("\n\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\n\t\t\t\t%c     0---->Quitter\t %c",186,186);

printf("\n\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
printf("\n\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\n\t\t\t\t%c     1---->Continuer\t %c",186,186);

printf("\n\t\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);


}

