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

typedef struct id_nom ID_NOM;
struct id_nom {
	int taille;
	int array[50];
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

ID_NOM initTab_char(ID_NOM t) {
	int n;
	t.taille=30;
	for(n=0; n<t.taille; n++){
		t.array[n]='\0';
	}
	return t;	
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

ID_NOM id_station(int chiffre) {

    FILE* fichier = NULL;
    int ligne, carac=0;
    char caractereActuel = 0;
    ID_NOM station;

    fichier = fopen("metro.txt", "r");
    //fichier = fopen("test.txt", "r");

    if(fichier != NULL) {
		for(ligne=-4; ligne<chiffre; ligne++){//s permet de recuperer la ligne du fichier, -4 car 4ligne au début
	        do {
	        	caractereActuel=fgetc(fichier);
	        	if(chiffre-1==ligne){
		        	station.array[carac]=caractereActuel;
					//printf("%c", station[30]);
	        	}
	        	carac++;
	        }while(caractereActuel != '\n' && caractereActuel != EOF);  //\n met cela pour les ligne du for au dessus
			carac=0;
		}      
		fclose(fichier);
    }else
        printf("Impossible d'ouvrir le fichier des stations de métro...\n");

    return station;
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
		        if(379==s && n==1){ //n permet de recuperer 
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

	//TABLEAU t;
	//t=initTab(t);
	int s,n;
	ID_NOM station;


	station=initTab_char(station);
	station=id_station(0);

	for(s=0;s<30;s++){
		printf("%c", station.array[s]);
	}


/*
	for(s=0;s<30;s++){
		printf("%c", id_toute_station[0].station.array[s]);
	}
*/


	//t=temps_station(t);


	return 0;
}