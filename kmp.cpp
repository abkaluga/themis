#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stdint.h>
#include <string.h>
 
uint32_t  n, m, k, q, pi[1000001];
char  P[1000001]; // P[] - wzorzec o dlugosci m
char  T[1000001]; // T[] - tekst o dlugosci n
 
void CPF(){
        pi[0] = 0; q = 0;
        for(k=1; k<m; k++){
                while(q>0 && P[k] != P[q]) q=pi[q-1];
                	if (P[k] == P[q]) pi[k] = ++q;
                	else pi[k] = 0;
        }
}
 
void kmp()
{
    q=0;
    for(uint32_t i=0; i<n; i++){
        while(q>0 && T[i] != P[q]) q = pi[q-1];
        if (T[i] == P[q]) q++;
        if(q == m){
            printf("%u\n", i-m + 1);
            q = pi[q-1];
        }
    }
}
 
int main(){
    uint32_t Test;
    scanf("%u\n", &Test);
    while(Test--)
    {
        scanf("%s", P);  m = strlen(P);
        scanf("%s", T); n = strlen(T);
        CPF();
        if(m <= n) kmp();
    }
    return 0;
}