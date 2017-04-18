#include <stdlib.h>
#include <stdio.h>

typedef struct tableau TABLEAU;
struct tableau {
	int taille;
	int tab[5];
}; 

TABLEAU init_tab(TABLEAU t){
	int n;

	t.taille=5;
	for(n=0; n<t.taille; n++){
		t.tab[n]=-1;
	}

	return t;
}


void show_tab(TABLEAU t){
	int n;
	for(n=0; n<t.taille; n++){
		printf("%d ", t.tab[n]);
	}
	printf("\n");

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

int main(){

	int a=0;
	TABLEAU t; 

	t=init_tab(t);
	//show_tab(t);

	t.tab[0]=6;
	t.tab[1]=7;
	//t.tab[2]=8;
	//t.tab[3]=9;
	a=tab_to_int(t);

	show_tab(t);
	printf("%d \n", a);


	return 0;
}