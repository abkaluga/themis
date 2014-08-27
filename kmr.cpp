#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <string>

#define MAX 1000000

bool cmp(std::string l,std::string r){ 
//	printf("%u\n",l<r);
	return l<r;
}

int main(){
	char word[MAX],subword[MAX];
	uint32_t classes[MAX];
	scanf("%s",word);
	uint32_t cla=0,len=strlen(word);
	std::map<std::string,int,bool(*)(std::string,std::string)> mmap(cmp);
	uint32_t j=1;
	for(uint32_t i=0;i<len;++i){
		memset(subword,0,MAX);
		strncpy(subword,word+i,j);
		if (mmap[subword]==0) {
			mmap[subword]=++cla;
		}
			classes[i]=mmap[subword];
	}


	return 0;
}