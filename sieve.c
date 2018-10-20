#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "sieve.h"

int sieve(int targetPrime){
  int len;
  if(targetPrime < 5000){
    len = (int)(log((double)targetPrime)*targetPrime*1.3+10);
  }
  else{
    len = (int)(log((double)targetPrime)*targetPrime*1.15+.5);
  }
  int *buckets = calloc(len, sizeof(int));
  int numPrime = 1;
  int curPrime = 2;
  *(buckets+2) = 1;
  
  while(numPrime < targetPrime){
    for(int i = curPrime+1; i<len; i++){
      if(i % curPrime == 0 && *(buckets+i) == 0){
	*(buckets+i) = 1;
      }
    }
    
    while(*(buckets+curPrime) != 0){
      curPrime++;
    }
    numPrime++;
    *(buckets+curPrime) = 1;
  }
  return curPrime;
}

int main(){
  printf("10th prime (should be 29): %d\n",sieve(10));
  printf("25th prime (should be 97): %d\n",sieve(25));
  printf("1000th prime (should be 7919): %d\n",sieve(1000));
  printf("10000th prime (should be 104729): %d\n",sieve(10000));
  return 0;
}
