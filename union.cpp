#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

uint32_t tab[300000], count[300000];
 
uint32_t Find(uint32_t a)
{
	if (tab[a]==a) return a;
	uint32_t fa = Find(tab[a]);
	tab[a] = fa;
	return fa;
}
 
bool Union(uint32_t a, uint32_t b)
{
	uint32_t fa = Find(a);
	uint32_t fb = Find(b);
 
	if (fa==fb) return false;
	if (count[fa] <= count[fb])	{
		count[fb] += count[fa];
		tab[fa] = fb;
	}
	else{
		count[fa] += count[fb];
		tab[fb] = fa;
	}
	return true;
}

bool Connected(uint32_t a, uint32_t b){
	return Find(a)==Find(b);
}
void Init(uint32_t n){
	for (uint32_t i = 0; i < n; ++i){
		tab[i]=i;
		count[i]=1;
	}
}

void Past(uint32_t m){
	uint32_t a,b;
	for (uint32_t i = 0; i < m; ++i)	{
		scanf("%u %u",&a,&b);
		Union(a,b);
	}
}

void Now(uint32_t q){
	uint8_t event;
	uint32_t a,b;
	for (uint32_t i = 0; i < q; ++i){
		scanf("%hhu %u %u",&event,&a,&b);
		if (event){
			Union(a,b);
		} else {
			if (Connected(a,b)) printf("TAK\n");
			else printf("NIE\n");
		}
	}
}

int main(){
	uint32_t n,m,q;
	scanf("%u %u %u",&n,&m,&q);
	Init(n);
	Past(m);
	Now(q);

}