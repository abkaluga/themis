
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
uint64_t pot_szybkie(uint64_t a, uint64_t n,uint64_t m)
{
  uint64_t w = 1;
  a%=m;
  while(n>0)
  {
    if (n&1){ 
        w *= a;
        w%=m;
    }
 
    a*= a;
    a%=m;
    n>>=1;
  }
  return w%m;
}
 
 
 
int main(void){

    uint32_t loops;
    uint64_t a,n,m;
    scanf("%u\n",&loops);

    for (uint32_t i = 0; i < loops; ++i)    {
        scanf("%llu %llu %llu",&a,&n,&m);
        printf("%llu\n",pot_szybkie(a,n,m));
    }


    return 0;
}