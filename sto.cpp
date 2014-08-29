#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MIN2(a,b) a<b?a:b                      //Quicker then function
#define MIN3(a,b,c) a<b?MIN2(a,c):MIN2(b,c)   //and look fabolus
#define MAX 1000

int32_t t,n,m;

int main(){
    scanf("%u",&t);
    t++;                                                // :D
    while(--t){
        scanf("%u %u",&n,&m);
        int32_t MAP[n][m],COSTS[n][m];
        for(int32_t i=0;i<n;++i){
            for (int32_t j=0;j<m;++j){
                scanf("%d",&MAP[i][j]);
                COSTS[i][j]=MAP[i][j];
            }
        }
        for (int32_t j=1;j<m;++j){
            for(int32_t i=0;i<n;++i){
                    if (i==0){
                        COSTS[i][j]+= MIN2(COSTS[i][j-1],COSTS[i+1][j-1]);
                    } else if (i==n-1){
                        COSTS[i][j]+= MIN2(COSTS[i][j-1],COSTS[i-1][j-1]);
                    } else  {
                        COSTS[i][j]+= MIN3(COSTS[i][j-1],COSTS[i+1][j-1],COSTS[i-1][j-1]);
                    }
            }
        }
        int32_t min=1<<30;
        for(int32_t i=0;i<n;++i){
            min=MIN2(min,COSTS[i][m-1]);
        }
        printf("%d\n",min);

    }
}