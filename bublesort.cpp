#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

bool isSorted(uint32_t tab[],uint32_t size);
void printTab(uint32_t tab[],uint32_t size);
void nextIter(uint32_t tab[],uint32_t size);


int main(){

	uint32_t size;
	scanf("%d\n",&size);
	uint32_t tab[size];
	for (int i = 0; i < size; ++i){
		scanf("%d",&tab[i]);
	}

	while (!isSorted(tab,size)){
		nextIter(tab,size);
		printTab(tab,size);
	}

	return 0;

}

bool isSorted(uint32_t tab[],uint32_t size){
	for(uint32_t i=1;i<size;++i){
		if (tab[i-1]>tab[i]) return false;
	}
	return true;
}

void printTab(uint32_t tab[],uint32_t size){
	for(uint32_t i=0;i<size;++i){
		printf("%u ",tab[i]);
	}
	printf("\n");
}
void nextIter(uint32_t tab[],uint32_t size){
	for(uint32_t i=1;i<size;++i){
		if(tab[i-1]>tab[i]){
			uint32_t temp=tab[i];
			tab[i]=tab[i-1];
			tab[i-1]=temp;
		}
	}
}
