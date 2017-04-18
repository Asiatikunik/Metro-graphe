#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TAILLE_TAB 375


/***************************************************************************/
//Structure
typedef struct tableau TABLEAU;
struct tableau {
	int taille;
	int tab[5];
};

struct station{
	int depart;
	int arrivee;
	int temps;
};
typedef struct station STATION;

/*****************************************************************************/
//Gestion de tableau
/*
STATION initStation(STATION S[376]) {
	int i,j;
	for(i=0;i<376;i++){
		S[i].numero = 0;
		S[i].nbliaison = 0;
		for(j=0; j<10; j++){
			S[i].apres[j].idsuivante = 0;
			S[i].apres[j].temps = 0;
		}
	}
	return *S;	
}*/

char initTab_char(char tab[30]) {
	int n;

	for(n=0; n<30; n++){
		tab[n]='\0';
	}
	return tab[30];	
}
/*
void afficherTab(TABLEAU t) {

	int n,m;
	for(m=0; m<TAILLE_TAB; m++){
		for(n=0; n<TAILLE_TAB; n++) {
				printf("%d ",t.tab[n][m]);
		}
		printf("\n");
	}
}*/

/******************************************************************************/
//Gestion de fichier

char id_station(int chiffre) {

    FILE* fichier = NULL;
    int s,n=0;
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
		        	station[n]=caractereActuel;
		        	n++;
					//printf("%c", station[30]);
	        	}

	        }while(caractereActuel != '\n' && caractereActuel != EOF);  //\n met cela pour les ligne du for au dessus
			n=0;
		}      

		fclose(fichier);
    }else
        printf("Impossible d'ouvrir le fichier des stations de métro...\n");

    return station[30];
}
TABLEAU init_tableau(TABLEAU t){
	int i;
	t.taille = 5;
	for(i=0; i<t.taille;i++){
		t.tab[i] = -1;
	}
	return t;
}

int tab_to_int(TABLEAU t){
	int nombre=0;
	if(t.tab[4]==-1 && t.tab[3]==-1 && t.tab[2]==-1 && t.tab[1]==-1){
		nombre=t.tab[0];
		return nombre;
	}


	if(t.tab[4]==-1 && t.tab[3]==-1 && t.tab[2]==-1){
		nombre = t.tab[0]*10;
		nombre += t.tab[1];
		return nombre;
	}

	
	if(t.tab[4]==-1 && t.tab[3]==-1){
		nombre = t.tab[0]*100;
		nombre += t.tab[1]*10;
		nombre += t.tab[2];
		return nombre;
	}
	
	if(t.tab[4]==-1){

		nombre = t.tab[0]*1000;
		nombre += t.tab[1]*100;
		nombre += t.tab[2]*10;
		nombre += t.tab[3];
		return nombre;
	}

	nombre=-1; //if erreur
	return nombre;

}

STATION init_StationSuivante(int station) {

    FILE* fichier = NULL;
    int ligne; //la ligne ou on en est
    int i =0;
    STATION resultat;
    int nombrelu = -1;
    char caractereActuel = 0; //le caractere qui est lu
    int nbEspace = 0; //le nombre d'espace
    TABLEAU chiffre; //tableau pour un nombre
    chiffre = init_tableau(chiffre); //-1 dans toutes les cases du tableau

    fichier = fopen("metro.txt", "r");

    if(fichier != NULL) {

		for(ligne=0; ligne<852; ligne++){//permet de recuperer la ligne du fichier
	        do{
		        caractereActuel = fgetc(fichier);
		        if(ligne >= 379){//on est au debut de la partie des temps entre station
		        	while(caractereActuel != '\n'){ //temps qu'on est pas au bout de la ligne
		        		while(nbEspace < 1){
		       				caractereActuel == fgetc(fichier);
		       				if(caractereActuel == ' '){
		       					nbEspace++;
		       				}
		       			}
		       			while(nbEspace < 2){
		       				caractereActuel = fgetc(fichier);
		       				if(caractereActuel == ' '){
		       					nbEspace++;
		       				}
		       				chiffre.tab[i] = atoi(&caractereActuel);
		       				i++;
		       			}
		       			nombrelu = tab_to_int(chiffre);
		       			printf("%d\n", nombrelu);
		       			resultat.depart = nombrelu;
		       			chiffre = init_tableau(chiffre);
		       			nbEspace++;
		       			i = 0;
		       			if(nombrelu == station){
		       				while(nbEspace < 3){
		       					caractereActuel = fgetc(fichier);
		       					chiffre.tab[i] = atoi(&caractereActuel);
		       					i++;
		       				}
		       				nombrelu = tab_to_int(chiffre);
		       				printf("%d\n", nombrelu);
		       				resultat.arrivee = nombrelu;
		       				chiffre = init_tableau(chiffre);
		       				i = 0;
		       				while(caractereActuel != '\n'){
		       					caractereActuel = fgetc(fichier);
		       					chiffre.tab[i] = atoi(&caractereActuel);
		       				}
		       				nombrelu = tab_to_int(chiffre);
		       				printf("%d\n", nombrelu);
		       				resultat.temps = nombrelu;
		       			}
		       		}
		        }
	        }while(caractereActuel != '\n' && caractereActuel != EOF); 
		}      

		fclose(fichier);
    }else
        printf("Impossible d'ouvrir le fichier des stations de métro...\n");

    return resultat;
}

int main() {
	/*
	char station[30];
	station[30]=initTab_char(station);
	station[30]=id_station(1);
	for(s=0;s<30;s++){
	printf("%c", station[s]);
	}
*/
	STATION i;

	i = init_StationSuivante(0);
	printf("depart : %d arrivee : %d temps : %d\n", i.depart, i.arrivee, i.temps);


	return 0;
}