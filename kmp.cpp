#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#define MAX 1000000


void initTable(uint32_t tab[], char templat[], uint32_t m){
	tab[0]=0; tab[1]=0; 
	uint32_t t=0;
	for (uint32_t j=2; j<=m; j++){
	while ((t>0)&&(templat[t]!=templat[j-1])) t=tab[t];
		if (templat[t]==templat[j-1]) t++;
			tab[j]=t;
	}
}
 
void kmp(uint32_t P[], char templat[], uint32_t m, char text[],uint32_t n){
	uint32_t i=0, j=0;
	while (i<(m-n+1)){
		j=P[j];
		while((j<n)&&(templat[j]==text[i+j])) j++;
		/*magic*/
		if (j==n) printf("%d\n",i); 
		i+=P[j]?P[j]:1;
	}

}

 
int main(void){
	char templat[MAX], text[MAX];
	uint32_t P[MAX],loops;
	scanf("%u\n",&loops);
	while((loops--)>0){
		scanf("%s",templat);
		scanf("%s",text);
		uint32_t n=strlen(templat), m=strlen(text);
		templat[n]='\n';
		--n;
		if (m<n) continue;
		initTable(P,templat,m);
		kmp(P,templat,m,text,n);
		memset (P,0,m);
	}

}

