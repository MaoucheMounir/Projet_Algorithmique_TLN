#include"DictMots.h"
#include"affichage.h"

//Les autres fichiers sont appeles par DictMots.h

int main() {

int operation, freq, n, recommencer;

char *nomFichier = allouerChaine(maxMot),
	 *mot = allouerChaine(maxMot) ,
	 *Contexte = allouerChaine(maxMot) ,
	 *chaineDuFichier ;

ListeMots LM ;
ListeFreq LF ;
DictContext Dict ;

afficherIntroduction() ;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);

gets(nomFichier) ;
chaineDuFichier = lireFichier(nomFichier) ;

Dict = creerDictContext(chaineDuFichier) ;  //On intialise au debut pour ne pas recreer le dictionnaire a chaque fois

   do {

afficherMenu() ;

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    scanf("%d", &operation) ;


switch(operation){

    case 1 :
        afficherMotsDe() ;

        LM = motsDe(chaineDuFichier) ;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
            printf("\n\nAffichage des mots du fichier :\n") ;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			afficherListeMots(LM) ;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
            printf("\n\nAppuyez sur \"entree\" pour continuer") ;
        break ;

	case 2 :
	    afficherFrequencesDe() ;

            LF = frequencesDe(chaineDuFichier) ;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                printf("\n\naffichage des frequences des mots du fichier\n") ;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                afficherListeFreq(LF) ;

           SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                printf("\n\nAppuyez sur \"entree\" pour continuer") ;

            break ;

	case 3 :
	    afficherContexte() ;

    do {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
            printf("\n\nDonner le mot dont vous voulez les contextes\n") ;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            scanf("%s", mot) ;

		LF = contexte(chaineDuFichier, mot) ;

		if(LF) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
            printf("\naffichage des contextes du mot \"%s\" : \n", mot ) ;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            afficherListeFreq(LF) ;
        }
        //Si le mot est non valide (m'existe pas ou est le dernier mot, la reponse sera dans la fonction contexte

        do{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                printf("\nVoulez-vous continuer a executer cette fonction ? ") ;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
                printf("\n\t\t\t\t\t\t\t\t\t taper votre choix [0] ou [1] ICI:\t");

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                scanf("%d", &recommencer ) ;
        }while(recommencer !=0 && recommencer != 1) ;

    }while(recommencer != 0) ;

    printf("\n\nAppuyez sur \"entree\" pour continuer") ;

				break ;

    case 4 :

        afficherDictionnaire() ;

        printf("\n\nAffichage du dictionnaire de contextes du fichier \"%s\" : \n", nomFichier) ;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            afficherDictContext(Dict) ;

        printf("\n\nAppuyez sur \"entree\" pour continuer") ;

        break ;

	case 5 :
	    afficherMaxContext() ;

    do {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
            printf("\n\nDonner le mot dont vous voulez voir le contexte le plus frequent \n") ;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			scanf("%s", mot) ;

        Contexte = maxContext(Dict, mot) ;

		if (Contexte) {//Comme ca si le mot n'existe pas, il va pas ecrire tout ca, ce qui doit etre ecrit est dans la fonction contexte

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                printf("\nle mot le plus frequent dans le context du mot \"%s\" est : ", mot) ;

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                printf("\"%s\" \n", Contexte);

        }

        do{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                printf("\n\nVoulez-vous continuer a executer cette fonction ? ") ;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
                printf("\n\t\t\t\t\t\t\t\t\t taper votre choix [0] ou [1] ICI:\t");

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                scanf("%d", &recommencer ) ;
        }while(recommencer !=0 && recommencer != 1) ;

    }while(recommencer != 0) ;

    printf("\n\nAppuyez sur \"entree\" pour continuer") ;

            break ;

	case 6 :
        afficherFreqCont() ;

    do{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
            printf("\n\nDonner le mot dont vous voulez le contexte\n") ;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			scanf("%s", mot) ;

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
            printf("\nDonner le contexte dont vous voulez le nombre d'apparitions\n") ;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			scanf("%s", Contexte) ;

		freq = freqCont(Dict, mot, Contexte) ;

        if(freq) {

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                printf("\nLe nombre d'apparitions du mot \"%s\" dans le contexte du mot \"%s\" est : ", Contexte, mot) ;

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                printf("%d\n", freq) ;

        }

        do{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                printf("\n\nVoulez-vous continuer a executer cette fonction ? ") ;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
                printf("\n\t\t\t\t\t\t\t\t\t taper votre choix [0] ou [1] ICI:\t");

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                scanf("%d", &recommencer ) ;
        }while(recommencer !=0 && recommencer != 1) ;

    }while(recommencer != 0) ;

    printf("\n\nAppuyez sur \"entree\" pour continuer") ;

                    break ;

 	case 7 :
 	    afficherGenererText() ;
        srand(time(NULL)) ;
    do {

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
            printf("\n\n\nDonner la taille de la sequence de mots a afficher ") ;

	 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            scanf("%d", &n) ;

        if( n>0)
			genererText(Dict, n) ;

        else printf("\nValeur non valide") ;

        do{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                printf("\nVoulez-vous continuer a executer cette fonction ? ") ;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
                printf("\n\t\t\t\t\t\t\t\t\t taper votre choix [0] ou [1] ICI:\t");

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                scanf("%d", &recommencer ) ;
        }while(recommencer !=0 && recommencer != 1) ;

	}while(recommencer != 0) ;

	printf("\n\nAppuyez sur \"entree\" pour continuer") ;

        break ;


    default:

            system("cls"); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
                printf("\n\n\tVous avez choisi de Quiter le Programme\n ");

				 break;

	}
getch();

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);

    if(operation!=0){
            system("cls");
            printf("\t\t\nVoulez vous quitter ou continuer ?");
    }
    else {printf("\t\t\netes vous sur de vouloir Quitter ?");}

    afficherSortie() ;

    do{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
            printf("\n\t\t\t\t\t\t\t\t\t taper votre choix [0] ou [1] ICI:\t");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            scanf("%d",&operation);

    }while(operation!=0 && operation!=1);


}while(operation!=0);


free(nomFichier) ;
free(mot) ;
free(Contexte) ;
free(chaineDuFichier) ;

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
printf("\n\n\t\t\tFin du programme, merci pour votre attention.\n\n") ;

SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);

    return 0;
}
