typedef struct {
  int* data;
  int size;
}IntArray, *PIntArray;

typedef void (*IntArraySorter)(int *data,int size);

int timeInMS();

int isOrdered(PIntArray pIntArray);

PIntArray buildIntArray(int size);
PIntArray buildIntArrayFrom(int *array,int size);
PIntArray randomIntArray(int min,int max,int size);
PIntArray cloneIntArray(PIntArray source);

void printIntArrayRaw(int *data,int size);
void printlnIntArrayRaw(int *data,int size);
void printIntArray(PIntArray pIntArray);
void printlnIntArray(PIntArray pIntArray);

void releaseIntArray(PIntArray pIntArray);


void sortIntArrayBy(PIntArray pOldArray,IntArraySorter sorter);
PIntArray sortedIntArrayBy(PIntArray pOldArray,IntArraySorter sorter);
void bubbleSort(int *data,int size);
void cockTailSort(int *data,int size);
void normalShellSort(int *data,int size);
void normalInsertSort(int *data,int size);
void binShellSort(int *data,int size);
void binInsertSort(int *data,int size);
void quickSort(int *data,int size);
void normalSelectSort(int *data,int size);
void heapSelectSort(int *data,int size);
void mergeSort(int *data,int size);
void linkSort(int *data,int size);
void radixSort(int *data,int size);
