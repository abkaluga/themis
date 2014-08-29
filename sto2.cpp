#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <utility>
#include <stack>
using namespace std;

/**************************************************************
TODO: FIND NULL POINTER!
**************************************************************/

#define MAX 1000
std::pair<int32_t,uint32_t> COSTS[MAX][MAX];

#define MIN2(a,b,j) COSTS[a][j-1]<COSTS[b][j-1]?a:b                         //Quicker then function
#define MIN3(a,b,c,j) COSTS[a][j-1]<COSTS[b][j-1]?MIN2(a,c,j):MIN2(b,c,j)        //and look fabolus


int32_t t,n,m;
stack<uint32_t> mstack;

int main(){
    scanf("%u",&t);
    t++;                                                // :D
    while(--t){
        scanf("%u %u",&n,&m);
        int32_t MAP[n][m];
        for(int32_t i=0;i<n;++i){
            for (int32_t j=0;j<m;++j){
                scanf("%d",&MAP[i][j]);
                COSTS[i][j].first=MAP[i][j];

            }
        }
        for (int32_t j=1;j<m;++j){
            for(int32_t i=0;i<n;++i){
                    if (i==0){
                        COSTS[i][j].second=MIN2(i,i+1,j);
                        COSTS[i][j].first+=COSTS[COSTS[i][j].second][j-1].first;

                    } else if (i==n-1){
                        COSTS[i][j].second=MIN2(i,i-1,j);
                        COSTS[i][j].first+=COSTS[COSTS[i][j].second][j-1].first;
                    } else  {
                        COSTS[i][j].second=MIN3(i,i+1,i-1,j);
                        COSTS[i][j].first+=COSTS[COSTS[i][j].second][j-1].first;
                    }
            }
        }
        int32_t min=1<<30;
        uint32_t imin=1001;
        for(int32_t i=0;i<n;++i){
            if (min>COSTS[i][m-1].first){
                imin=i;
                min=COSTS[i][m-1].first;
            }
        }
        while (!mstack.empty()) mstack.pop();
        for (int32_t j = m-1; j>=0; --j){
            mstack.push(imin);
            imin=COSTS[imin][j].second;

        }
         while (!mstack.empty()){
            printf("%u ",mstack.top());
            mstack.pop();
         }
        printf("\n");
    }
}