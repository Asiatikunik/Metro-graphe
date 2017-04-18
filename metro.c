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

typedef struct id_nom ID_NOM;
struct id_nom {
	int taille;
	int array[50];
};



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

ID_NOM initTab_char(ID_NOM t) {
	int n;
	t.taille=30;
	for(n=0; n<t.taille; n++){
		t.array[n]='\0';
	}
	return t;	
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

ID_NOM id_station(int chiffre) {

    FILE* fichier = NULL;
<<<<<<< HEAD
    int s,n=0;
=======
    int ligne, carac=0;
>>>>>>> d7b561bd119030ae6f1535a9786972b9d7529aca
    char caractereActuel = 0;
    ID_NOM station;

    fichier = fopen("metro.txt", "r");
    //fichier = fopen("test.txt", "r");

    if(fichier != NULL) {
		for(ligne=-4; ligne<chiffre; ligne++){//s permet de recuperer la ligne du fichier, -4 car 4ligne au début
	        do {
	        	caractereActuel=fgetc(fichier);
<<<<<<< HEAD
	        	if(chiffre-1==s ){
		        	station[n]=caractereActuel;
		        	n++;
=======
	        	if(chiffre-1==ligne){
		        	station.array[carac]=caractereActuel;
>>>>>>> d7b561bd119030ae6f1535a9786972b9d7529aca
					//printf("%c", station[30]);
	        	}
	        	carac++;
	        }while(caractereActuel != '\n' && caractereActuel != EOF);  //\n met cela pour les ligne du for au dessus
<<<<<<< HEAD
			n=0;
=======
			carac=0;
>>>>>>> d7b561bd119030ae6f1535a9786972b9d7529aca
		}      
		fclose(fichier);
    }else
        printf("Impossible d'ouvrir le fichier des stations de métro...\n");

    return station;
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
<<<<<<< HEAD
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
=======
		        caractereActuel=fgetc(fichier);
		        n++;
		        if(379==s && n==1){ //n permet de recuperer 
		        	printf("%c", caractereActuel);
		        	//caractereActuel
		        	//t.array[]
>>>>>>> d7b561bd119030ae6f1535a9786972b9d7529aca
		        }
	        }while(caractereActuel != '\n' && caractereActuel != EOF); 
		}      

		fclose(fichier);
    }else
        printf("Impossible d'ouvrir le fichier des stations de métro...\n");

    return resultat;
}



int main() {
<<<<<<< HEAD
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
=======

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
>>>>>>> d7b561bd119030ae6f1535a9786972b9d7529aca


	return 0;
}