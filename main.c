#include <stdio.h>
#include "sort.h"

#define Test(SortMethod) \
  printf("%16s",#SortMethod);\
  time=timeInMS();\
  pSortedArray=sortedIntArrayBy(pRawArray,SortMethod);\
  printf(" %6dms",timeInMS()-time);\
  printf(" %10s\n",isOrdered(pSortedArray)?"sorted":"unsorted");\
  releaseIntArray(pSortedArray);\


int main(){
  int time;
  PIntArray pRawArray,pSortedArray;
  pRawArray = randomIntArray(1,30000,20000);
  //sortIntArrayBy(pRawArray,quickSort);
  printf("%s",isOrdered(pRawArray)?"Sorted":"Unsorted");
  printf(" raw int array with size %d\n",pRawArray->size);
  //select sort
  Test(normalSelectSort);
  Test(heapSelectSort);
  //insert sort
  Test(linkSort);
  Test(normalShellSort);
  Test(binShellSort);
  Test(normalInsertSort);
  Test(binInsertSort);
  //swap sort
  Test(bubbleSort);
  Test(cockTailSort);
  Test(quickSort);
  //merge sort
  Test(mergeSort);
  //radix sort
  Test(radixSort);

  return 0;
}
