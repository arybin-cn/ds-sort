#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* data;
  int size;
}IntArray, *PIntArray;

typedef void (*IntArraySorter)(PIntArray);
//random integers in range [1,max]

PIntArray buildIntArray(int size){
  PIntArray pIntArray;
  pIntArray=(PIntArray)malloc(sizeof(IntArray));
  pIntArray->data=(int*)malloc(sizeof(int)*size);
  if(!pIntArray || !pIntArray->data){
    printf("Fail to allocate memory..\n");
    return NULL;
  }
  pIntArray->size=size;
  return pIntArray;
}

PIntArray randomIntArray(int min,int max,int size){
  int i;
  PIntArray pIntArray;
  pIntArray=buildIntArray(size);
  if(!pIntArray){
    return NULL;
  }
  srand(time(0));
  for(i=0;i<size;i++){
    pIntArray->data[i]=min+(rand()%(max-min+1));
  }
  return pIntArray;
}

PIntArray cloneIntArray(PIntArray source){
  int i;
  PIntArray pIntArray;
  pIntArray = buildIntArray(source->size);
  if(!pIntArray){
    return NULL;
  }
  for(i=0;i<source->size;i++){
    pIntArray->data[i]=source->data[i];
  }
  return pIntArray;
}

void printIntArray(PIntArray pIntArray){
  int i;
  for(i=0;i<pIntArray->size;i++){
    printf("%d",pIntArray->data[i]);
    if(i<pIntArray->size-1){
      printf(" ");
    }
  }
}


void printlnIntArray(PIntArray pIntArray){
  printIntArray(pIntArray);
  printf("\n");
}

void releaseIntArray(PIntArray pIntArray){
  free(pIntArray->data);
  free(pIntArray);
}

void sortIntArrayBy(PIntArray pIntArray,IntArraySorter sorter){
  sorter(pIntArray);
}
int main(){

  PIntArray pIntArrayA = randomIntArray(10,15,10);
  printlnIntArray(pIntArrayA);
  PIntArray pIntArrayB = cloneIntArray(pIntArrayA);
  printlnIntArray(pIntArrayB);
  pIntArrayB->data[0]=99;
  printlnIntArray(pIntArrayA);
  printlnIntArray(pIntArrayB);
  
  return 0;

}
