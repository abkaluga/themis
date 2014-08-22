#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int32_t BinarySearch(int32_t key,int32_t tab[],int32_t num){
	int32_t l=0,u=num-1,i=0;
	while (u>=l){
		i=(l+u)/2;
		if (key>tab[i]) l=i+1;
		else if (key<tab[i]) u=i-1;
		else {
			while ((tab[i-1]==tab[i]) and (i>1)) --i;
			return i;
		}
	}	
	return l;
}


int main(){

	int32_t num;
	scanf("%d",&num);
	int32_t tab[num];
	for (int i = 0; i < num; ++i){
		scanf("%d", &tab[i]);
	}
	int32_t loops;
	scanf("%d",&loops);
	for (int i = 0; i < loops; ++i){
		int32_t temp;
		scanf("%d",&temp);
		printf("%d ",num-BinarySearch(temp,tab,num));
	}
	printf("\n");
	return 0;
}