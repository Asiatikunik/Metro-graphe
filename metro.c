#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_TAB 375


/***************************************************************************/
//Structure
typedef struct tableau TABLEAU;
struct tableau {
	int taille;
	int array[500][500];
}; 

/*****************************************************************************/
//Gestion de tableau

TABLEAU initTab(TABLEAU t) {
	int n,m;
	t.taille=TAILLE_TAB;

	for(n=0; n<t.taille; n++){
		for(m=0; m<t.taille; m++){
			t.array[n][m]=-1;
		}
	}
	return t;	
}

char initTab_char(char tab[30]) {
	int n;

	for(n=0; n<30; n++){
		tab[n]='\0';
	}
	return tab[30];	
}

void afficherTab(TABLEAU t) {

	int n,m;
	for(m=0; m<TAILLE_TAB; m++){
		for(n=0; n<TAILLE_TAB; n++) {
				printf("%d ",t.array[n][m]);
		}
		printf("\n");
	}
}

/******************************************************************************/
//Gestion de fichier

char id_station(int chiffre) {

    FILE* fichier = NULL;
    int s;
    char caractereActuel = 0;
    char station[30];

    fichier = fopen("metro.txt", "r");
    //fichier = fopen("test.txt", "r");

    if(fichier != NULL) {
    	//printf("Le fichier est ouvert! \n");

		for(s=-4; s<chiffre; s++){//s permet de recuperer la ligne du fichier, -4 car 4ligne au début
	        do {
	        	caractereActuel=fgetc(fichier);
	        	if(chiffre-1==s ){
		        	station[30]=caractereActuel;
					printf("%c", station[30]);
	        	}

	        }while(caractereActuel != '\n' && caractereActuel != EOF);  //\n met cela pour les ligne du for au dessus
		}      

		fclose(fichier);
    }else
        printf("Impossible d'ouvrir le fichier des stations de métro...\n");

    return station[30];
}


TABLEAU temps_station(TABLEAU t) {

    FILE* fichier = NULL;
    int s, n=0;
    char caractereActuel = 0;

    fichier = fopen("metro.txt", "r");

    if(fichier != NULL) {

		for(s=0; s<852; s++){//s permet de recuperer la ligne du fichier
	        do{
		        caractereActuel=fgetc(fichier);
		        n++;
		        if(379==s && n==4){ //n permet de recuperer 
		        	printf("%c", caractereActuel);
		        	//caractereActuel
		        	//t.array[]
		        }
	        }while(caractereActuel != '\n' && caractereActuel != EOF);
	        n=0;  
		}      

		fclose(fichier);
    }else
        printf("Impossible d'ouvrir le fichier des stations de métro...\n");

    return t;
}

int main() {

	TABLEAU t;
	t=initTab(t);
	int s;

/*
	char station[30];
	station[30]=initTab_char(station);
	station[30]=id_station(1);
	for(s=0;s<30;s++){
		printf("%c", station[s]);
	}
*/


	t=temps_station(t);


	return 0;
}