#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int* data;
  int size;
}IntArray, *PIntArray;

typedef void (*IntArraySorter)(int *data,int size);

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

void printIntArrayRaw(int *data,int size){
  int i;
  for(i=0;i<size;i++){
    printf("%.2d",data[i]);
    if(i<size-1){
      printf(" ");
    }
  }
}

void printlnIntArrayRaw(int *data,int size){
  printIntArrayRaw(data,size);
  printf("\n");
}

void printIntArray(PIntArray pIntArray){
  printIntArrayRaw(pIntArray->data,pIntArray->size);
}


void printlnIntArray(PIntArray pIntArray){
  printIntArray(pIntArray);
  printf("\n");
}

void releaseIntArray(PIntArray pIntArray){
  free(pIntArray->data);
  free(pIntArray);
}

PIntArray sortedIntArrayBy(PIntArray pOldArray,IntArraySorter sorter){
  PIntArray pNewArray = cloneIntArray(pOldArray);
  sorter(pNewArray->data,pNewArray->size);
  return pNewArray;
}

void bubbleSort(int *data,int size){
  int i,j,swap;
  for(i=0;i<size;i++){
    for(j=0;j<size-i-1;j++){
      if(data[j+1]<data[j]){
        swap=data[j];
        data[j]=data[j+1];
        data[j+1]=swap;
      }
    }
  }
}

void innerShellSort(int *data,int size,int d){
  int i,j,k,tmp;
  for(i=0;i<d;i++){
    for(j=i+d;j<size;j+=d){
      if(data[j-d]>data[j]){
        tmp=data[j];
        k=j;
        do{
          data[k]=data[k-d];
          k-=d;
        }while(k>i && data[k-d]>tmp);
        data[k]=tmp;
      }
    }
  }
}


void normalShellSort(int *data,int size){
  int i;
  for(i=size/2;i>0;i/=2){
    innerShellSort(data,size,i);
  }
}

void normalInsertSort(int *data,int size){
  innerShellSort(data,size,1);
}

void binInsertSort(int *data,int size){
  int i,j,low,middle,high,tmp;
  for(i=1;i<size;i++){
    tmp=data[i];
    low=0;high=i-1;
    if (tmp<data[i-1]){
      while(low<=high){
        middle=(low+high)/2;
        if(data[middle]<=tmp){
          low=middle+1;
          continue;
        }
        high=middle-1;
      }
      for(j=i;j>low;j--){
        data[j]=data[j-1];
      }
      data[low]=tmp;
    }
  }
}

void innerQuickSort(int *data,int from,int to){
  int tmp,i,j;
  if(to>from){
    tmp=data[from];i=from,j=to;
    while(j>i){
      while(data[j]>=tmp && j>i) j--;
      data[i]=data[j];
      while(data[i]<=tmp && j>i) i++;
      data[j]=data[i];
    }
    data[i]=tmp;
    innerQuickSort(data,from,i-1);
    innerQuickSort(data,i+1,to);
  }
}

void quickSort(int *data,int size){
  innerQuickSort(data,0,size-1);
}

void normalSelectSort(int *data,int size){
  int i,j,changed,minIndex,swap;
  for(i=0;i<size;i++){
    minIndex=i;changed=0;
    for(j=i;j<size;j++){
      if(data[j]<data[minIndex]){
        changed=1;
        minIndex=j;
      }
    }
    if(changed){
      swap=data[minIndex];
      data[minIndex]=data[i];
      data[i]=swap;
    }
  }
}

void buildHeapDown(int *data,int index,int size){
  int greaterChild,leftChild=2*index+1,rightChild,swap;
  while(leftChild<size){
    rightChild=leftChild+1;
    greaterChild=leftChild;
    if(rightChild<size && data[rightChild]>data[leftChild]){
      greaterChild=rightChild;
    }
    if(data[greaterChild]>data[index]){
      swap=data[greaterChild];
      data[greaterChild]=data[index];
      data[index]=swap;
    }
    index=greaterChild;
    leftChild=2*index+1;
  }
}

void heapSelectSort(int *data,int size){
  int i,swap;
  for(i=size-1;i>-1;i--){
    buildHeapDown(data,i,size);
  }
  while(size>1){
    swap=data[size-1];
    data[size-1]=data[0];
    data[0]=swap;
    buildHeapDown(data,0,--size);
  }
}



int main(){
  PIntArray pIntArray = randomIntArray(1,20,15);
  printlnIntArray(pIntArray);
  //select sort
  printlnIntArray(sortedIntArrayBy(pIntArray,normalSelectSort));
  printlnIntArray(sortedIntArrayBy(pIntArray,heapSelectSort));
  //insert sort
  printlnIntArray(sortedIntArrayBy(pIntArray,normalShellSort));
  printlnIntArray(sortedIntArrayBy(pIntArray,normalInsertSort));
  printlnIntArray(sortedIntArrayBy(pIntArray,binInsertSort));
  //swap sort
  printlnIntArray(sortedIntArrayBy(pIntArray,bubbleSort));
  printlnIntArray(sortedIntArrayBy(pIntArray,quickSort));
  return 0;
}
