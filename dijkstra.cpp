
#include <vector>
#include <set>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>     // uint**_t

using namespace std;
 
const uint32_t infty = 100001;
uint32_t n,m;
vector< pair<uint32_t,uint32_t> > adj[100000];
 
vector<uint32_t> weight;
 
bool cmp(const uint32_t &a, const uint32_t &b){
        if (weight[a] < weight[b]) return true;
        if (weight[a] > weight[b]) return false;
        return a<b;
}

 
 
set<uint32_t,bool(*)(const uint32_t &a, const uint32_t &b)> mound(cmp);
 
 
void dijkstra(uint32_t s){
    uint32_t v, u, c;
    weight.clear();
    weight.resize(n, infty); //
 
    weight[s] = 0;
    mound.clear();
    mound.insert(s);
 
    while( !mound.empty()){
        u = *(mound.begin());
        mound.erase(mound.begin());
 
        for (uint32_t i=0; i<adj[u].size(); ++i){
            v = adj[u][i].first;
            c = adj[u][i].second;
            if (weight[u]+c < weight[v])
            {
                mound.erase(mound.find(v));
                weight[v] = weight[u]+c;
                mound.insert(v);
            }
        }
    }
 
 
}
 
int main(void){
    uint32_t a,b,c, s,t;
 
 //   cin >> n >> m;
    for (uint32_t i=0; i<m; i++)    {
   //     cin >> a >> b >> c; // c = koszt krawędzi od a do b
        adj[a].push_back(pair<uint32_t,uint32_t>(b,c));
        adj[b].push_back(pair<uint32_t,uint32_t>(a,c));
    }
 
    //cin >> s >> t; // s - źródło, t - wierzchołek, do którego najkrótszej odległości szukamy
 
    dijkstra(s); // alg. Dijkstry wypełni całą tablicę weight[..] najkrótszymi odległościami
    //cout << waga[t];
    return 0;
}