#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

uint32_t *tab=(uint32_t*)calloc(128,sizeof(uint32_t));

int main(){
	uint32_t num;
	uint16_t temp;
	scanf("%u",&num);
	for (uint32_t i = 0; i < num; ++i){
		scanf("%hu",&temp);
		tab[temp]++;
	}
	for (uint8_t i=0;i<128;++i){
		while (tab[i]>0){
			printf("%hu ",i);
			--tab[i];
		}
	}
}