#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>


void initTable(uint32_t tab[], char templat[]){
	tab[0]=0; tab[1]=0; 
	uint32_t t=0,m=strlen(templat);
	for (uint32_t j=2; j<=m; j++){
	while ((t>0)&&(templat[t]!=templat[j-1])) t=tab[t];
		if (templat[t]==templat[j-1]) t++;
			tab[j]=t;
	}
}
 

 
int main(void){
	char *templat=(char*)calloc(1000000,sizeof(char));
	char *text=(char*)calloc(1000000,sizeof(char));
	strcpy(templat,"");
	read(0,templat,1000000);
	strcpy(text,"");
	read(0,text,1000000);
	uint32_t n=strlen(templat)-1, m=strlen(text)-1;
	uint32_t P[n];
	initTable(P,templat);
	uint32_t i=0, j=0;
	while (i<(m-n+1)){
		j=P[j];
		while((j<n)&&(templat[j]==text[i+j])) j++;
			if (j==n) printf("%d\n",i); i+=P[j]?P[j]:1;
	}


}


/*

	while (i<=n-m+1){
		printf("Drukuj kurwa%u\n",P[0]);
		j=P[j];
		while((j<m)&&(templat[j]==text[i+j-1])) j++;
			if (j==m) printf("%d\n",i);
			i=i+(1>j-P[j]?1:j-P[j]);
	}
	char wzorzec[100];
	char tekst[2000];
	int m,n,i,j,t;
	int P[100];//maksymalna dlugosc wzorca to 100 symboli
	printf("Podaj tekst\n");
	scanf("%s", tekst);
	printf("Podaj wzorzec\n");
	scanf("%s", wzorzec);
	n=strlen(tekst);
	m=strlen(wzorzec);
	printf("Indeksy poczatku wzorca w tekscie\n");
 
	//obliczenie tablicy P
	P[0]=0; P[1]=0; t=0;
	for (j=2; j<=m; j++){
	while ((t>0)&&(wzorzec[t]!=wzorzec[j-1])) t=P[t];
		if (wzorzec[t]==wzorzec[j-1]) t++;
			P[j]=t;
	}
 
	//algorytm KMP
	i=1; j=0;
	while (i<=n-m+1){
		j=P[j];
		while((j<m)&&(wzorzec[j]==tekst[i+j-1])) j++;
			if (j==m) printf("%d\n",i);
			i=i+(1>j-P[j]?1:j-P[j]);
	}
	return 0;



*/