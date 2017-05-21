#include <stdio.h>
#include "sort.h"

#define N_FROM 1000
#define N_STEP 100
#define N_TO 30000

#define K_FROM 1
#define K_MUL 10
#define K_TO 100000

#define Data(SortMethod) \
  pF=fopen("data/" #SortMethod "_sorted.csv","w+");\
  for(n=N_FROM;n<=N_TO;n+=N_STEP){\
    for(k=K_FROM;k<=K_TO;k*=K_MUL){\
      printf("Evaluating " #SortMethod " k:%d,n:%d\n",k,n);\
      pRawArray=randomIntArray(1,k,n);\
      sortIntArrayBy(pRawArray,quickSort);\
      time=timeInMS();\
      releaseIntArray(sortedIntArrayBy(pRawArray,SortMethod));\
      fprintf(pF,"%d",timeInMS()-time);\
      if(k<K_TO) fprintf(pF,",");\
      releaseIntArray(pRawArray);\
    }\
    fprintf(pF,"\n");\
  }\
  fclose(pF);\

int main(){
  FILE *pF;int time,n,k;
  PIntArray pRawArray,pSortedArray;
  //select sort
  Data(normalSelectSort);
  Data(heapSelectSort);
  //insert sort
  Data(linkSort);
  Data(normalShellSort);
  Data(binShellSort);
  Data(normalInsertSort);
  Data(binInsertSort);
  //swap sort
  Data(bubbleSort);
  Data(cockTailSort);
  Data(quickSort);
  //merge sort
  Data(mergeSort);
  //radix sort
  Data(radixSort);
  return 0;
}
