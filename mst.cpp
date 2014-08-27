//algorytm Kruskala w oparciu o Union-Find z drzewem.

 
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>		// uint**_t
#include <utility>		// std::pair
#include <algorithm>	// sort

#define MaxN 7000
#define MaxM 300000


uint32_t tab[MaxN], count[MaxN];
 
uint32_t Find(uint32_t a){
	if (tab[a]==a) return a;
	uint32_t fa = Find(tab[a]);
	tab[a] = fa;						//Kompresja scieżki
	return fa;
}
 
bool Union(uint32_t a, uint32_t b){
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

std::pair< int,std::pair<int,int> > Edges[MaxM];

int main(int argc, char const *argv[]){
	uint32_t n,m,a,b,c,cost=0;
	scanf("%u %u",&n,&m);
	for(uint32_t i=0;i<n;++i){
		tab[i]=i;
		count[i]=1;
	}

	for(uint32_t i=0;i<m;++i){
		scanf("%u %u %u",&a,&b,&c);
		Edges[i]=std::make_pair(c,std::make_pair(a,b));
	}
	sort(Edges,Edges+m);
	for (int i=0; i<m; i++)
		if ( Union(Edges[i].second.first,Edges[i].second.second) ){
			cost += Edges[i].first;
	}

	printf("%u\n",cost);


	return 0;
}