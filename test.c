#include <stdio.h>
#include <stdlib.h>

int array_modif(int tab[10]){
	int s;
	for(s=0; s<10; s++){
		tab[s]=0;
	}

	return tab[10];
}

int main() {
	int tab[10];
	int s;

	//array[10]=array_modif(array);


	for(s=0; s<10; s++){
		tab[s]=1;
	}

	tab[0]=10;

	for(s=0; s<10; s++){
		printf("%d \n", tab[s]);
	}

	return 0;
}