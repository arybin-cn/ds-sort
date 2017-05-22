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

  //Ex1
  //For textbook p258
  int array[]={49,38,65,97,76,13,27,49};
  pRawArray=buildIntArrayFrom(array,8);
  printf("Raw int array:\n");
  printlnIntArray(pRawArray);

  pSortedArray=sortedIntArrayBy(pRawArray,normalShellSort);
  printf("After sorting by normalShellSort:\n");
  printlnIntArray(pSortedArray);releaseIntArray(pSortedArray);

  pSortedArray=sortedIntArrayBy(pRawArray,binShellSort);
  printf("After sorting by binShellSort:\n");
  printlnIntArray(pSortedArray);releaseIntArray(pSortedArray);

  pSortedArray=sortedIntArrayBy(pRawArray,linkSort);
  printf("After sorting by linkSort:\n");
  printlnIntArray(pSortedArray);releaseIntArray(pSortedArray);

  printf("\n****************************\n\n");

  //Ex2
  //For random int array(length>1000)
  pRawArray = randomIntArray(1,30000,1000);
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
