#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* data;
  int size;
}IntArray, *PIntArray;

typedef PIntArray (*IntArraySorter)(PIntArray);
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

PIntArray sortIntArrayBy(PIntArray pIntArray,IntArraySorter sorter){
  return sorter(pIntArray);
}
//typedef void (*IntArraySorter)(PIntArray);
void linkSort(PIntArray pIntArray){
  printf("%d\n",pIntArray->size);
  pIntArray->data[0]=1234;
}

PIntArray bubbleSort(PIntArray pOldArray){
  PIntArray pNewArray=cloneIntArray(pOldArray);
  int i,j;
  for(i=0;i<pNewArray->size;i++){
    for(j=0;j<pNewArray->size-i-1;j++){
      if(pNewArray->data[j+1]<pNewArray->data[j]){
        pNewArray->data[j]^=pNewArray->data[j+1];
        pNewArray->data[j+1]^=pNewArray->data[j];
        pNewArray->data[j]^=pNewArray->data[j+1];
      }
    }
  }
  return pNewArray;
}

PIntArray normalInsertSort(PIntArray pOldArray){
  PIntArray pNewArray=buildIntArray(pOldArray->size);
  int i,j;
  int *tmp=(int*)malloc(pOldArray->size*sizeof(int)+1);
  for(i=1;i<pOldArray->size+1;i++){
    tmp[i]=pOldArray->data[i-1];
  }
  for(i=1;i<pOldArray->size+1;i++){
    tmp[0]=tmp[i];
    j=i;
    while(tmp[j-1]>tmp[0]){
      tmp[j]=tmp[j-1];
      j--;
    }
    tmp[j]=tmp[0];
  }
  for(i=0;i<pOldArray->size;i++){
    pNewArray->data[i]=tmp[i+1];
  }
  return pNewArray;
}

PIntArray binInsertSort(PIntArray pOldArray){
  PIntArray pNewArray=cloneIntArray(pOldArray);
  int i,j,low,middle,high,tmp;
  for(i=1;i<pNewArray->size;i++){
    tmp=pNewArray->data[i];
    low=0;high=i-1;
    if (tmp<pNewArray->data[i-1]){
      while(low<=high){
        middle=(low+high)/2;
        if(pNewArray->data[middle]<=tmp){
          low=middle+1;
          continue;
        }
        high=middle-1;
      }
      for(j=i;j>low;j--){
        pNewArray->data[j]=pNewArray->data[j-1];
      }
      pNewArray->data[low]=tmp;
    }
  }
  return pNewArray;
}

int main(){
  PIntArray pIntArray = randomIntArray(1,30,10);
  printlnIntArray(pIntArray);
  printlnIntArray(sortIntArrayBy(pIntArray,binInsertSort));
  printlnIntArray(sortIntArrayBy(pIntArray,normalInsertSort));
  printlnIntArray(sortIntArrayBy(pIntArray,bubbleSort));
  return 0;
}
