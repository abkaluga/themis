#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <list>
int main(){

	char *a=(char*)calloc(1000,sizeof(char));
	char *b=(char*)calloc(1000,sizeof(char));
	char *c=(char*)calloc(2000,sizeof(char));

	scanf("%s\n%s%s\n",a,b,c);
	std::list<char> lista(a, a +strlen(a)),listb(b, b +strlen(b)),listc(c, c +strlen(c));		//Copy array to list

	std::list<char>::iterator ita=lista.begin(),itc=listc.begin();								//Iterator 
	while(ita!=lista.end() && itc!=listc.end()){												//"Erase" word a from word c
		while (*ita!=*itc && itc!=listc.end()) ++itc;

		if (*ita==*itc) listc.erase(itc++);
		ita++;
	}
	std::list<char>::iterator itb=listb.begin();
	itc=listc.begin();
	while (itc!=listc.end()&& itb!=listb.end()){												//Check is word c is now word b.
		if (*itc!=*itb) {
			break;
		}
		++itc;++itb;
	}
	if(itc==listc.end()&& itb==listb.end())	printf("TAK\n");
	else printf("NIE\n");
	return 0;
}