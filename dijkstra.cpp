
#include <vector>
#include <set>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>     // uint**_t

using namespace std;
 
const uint32_t infty = 100001;
uint32_t n,m;
vector< pair<uint32_t,uint32_t> > adj[100000];        // Graph, adj[v].first=u adj[v].second=c v is connected with u with c cost.
 
vector<uint32_t> weight;                              // cost go to the city

bool cmp(uint32_t a, uint32_t b){
    if (weight[a]<=weight[b]) return true;
    else return false;
}

set<uint32_t,bool(*)(uint32_t,uint32_t)> mset(cmp);
 
 
void dijkstra(uint32_t s){
    uint32_t v, u, c=0;
    weight.clear();
    weight.resize(n, infty);                        // All cost are go to infinity.
 
    weight[s] = 0;                                  // You are in s town.
    mset.clear();
    mset.insert(s);
 
    while(!mset.empty()){
        u = *(mset.begin());
        mset.erase(mset.begin());
 
        for (uint32_t i=0; i<adj[u].size(); ++i){
            v = adj[u][i].first;
            c = adj[u][i].second;
            if (weight[u]+c < weight[v]){
                weight[v] = weight[u]+c;
                set<uint32_t>::iterator it=mset.find(v);        //if not in set add it
                if (it==mset.end()) mset.insert(v);
                else {
                    mset.erase(it);                             //if yes, it is on wrong position.
                    mset.insert(v);                             //need replace
                }
            }
        }
    } 
}
 
int main(void){
    uint32_t a,b,c;
 
    scanf("%u %u",&n,&m);
    for (uint32_t i=0; i<m; i++)    {
        scanf("%u %u %u",&a,&b,&c);
        adj[a-1].push_back(pair<uint32_t,uint32_t>(b-1,c));
        adj[b-1].push_back(pair<uint32_t,uint32_t>(a-1,c));
    }
    dijkstra(0);
    for (uint32_t i = 1; i < n; ++i){
        printf("%u ",weight[i]);
    }
    printf("\n");
    return 0;
}