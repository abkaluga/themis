#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>     // uint**_t

#define INF 1000001
using namespace std;
 
uint32_t n, m, s;
 
vector<vector<int32_t> >E;
vector<int32_t>D;
 
 
int main()
{
    scanf("%u %u %u", &n, &m, &s); 
    E.resize(m);
 
    for (uint32_t i = 0; i < m; ++i){
        uint32_t u , v;
        int32_t cost;
 
        scanf("%u %u %d", &u, &v, &cost);
        E[i].resize(3);
        E[i][0] = u;
        E[i][1] = v;
        E[i][2] = cost;
    }
 
    D.resize(n); 
    for (uint32_t i = 0; i < n; ++i) D[i]=INF;
    D[s] = 0;


    for(uint32_t i = 1; i<=n; ++i){
        for(uint32_t j = 0; j < m; ++j){
            uint32_t u = E[j][0], v = E[j][1];
            int32_t cost = E[j][2];
            if (D[u]!=INF && D[u]+cost < D[v]){
                D[v] = D[u]+cost; 
                if (i==n){
                    printf("NIE\n");
                    return 0;
                }
            }
        }
    }
 
    for (uint32_t i = 0; i < n; ++i){
        if (i!=s && D[i]<INF) printf("%d %d\n", i, D[i]);
    }
    return 0;
}