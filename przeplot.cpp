#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){

	char *a=(char*)calloc(1000,sizeof(char));
	char *b=(char*)calloc(1000,sizeof(char));
	char *c=(char*)calloc(2000,sizeof(char));
	read(0,a,1000);
	read(0,b,1000);
	read(0,c,2000);
	uint16_t ward1=0,ward2=0,ward3=0;
	while( strlen(a)!=ward1 && strlen(b)!=ward2){
		if (strncmp(a+ward1,c+ward3,1)==0)		{
			printf("Przesunięto ward1 i ward3\n");
			++ward1; ++ward3;
		} else if (strncmp(b+ward2,c+ward3,1)==0){
			printf("Przesunięto ward2 i ward3\n");
			++ward2; ++ward3;
		} else break;

	}

	if(ward3==strlen(c)) printf("TAK\n");
	else printf("NIE\n");


}