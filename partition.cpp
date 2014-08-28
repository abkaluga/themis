#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>		// uint**_t
#include <queue>

void wyrzuc(std::queue<uint32_t> st){
	while(!st.empty()){
		printf("%u ",st.front());
		st.pop();

	}
}

int main(){

	uint32_t n,p;
	scanf("%u %u",&n,&p);
	--p;
	uint32_t tab[n];
	for (uint32_t i = 0; i < n; ++i){
		scanf("%u",&tab[i]);
	}
	std::queue<uint32_t> low,eq,hi;
//	printf("%u\n",tab[p] );						//DON'T FORGET ABOUT FUCKING TESTS PRINTFS!!!
	for (uint32_t i = 0; i < n; ++i){
		if (tab[i]<tab[p]) 	low.push(tab[i]);
		if (tab[i]>tab[p]) 	hi.push(tab[i]);
		if (tab[i]==tab[p])	eq.push(tab[i]);
	}

	wyrzuc(low);
	wyrzuc(eq);
	wyrzuc(hi);
	printf("\n");
	return 0;
}