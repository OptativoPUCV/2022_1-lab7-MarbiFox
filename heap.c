#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void swap(heapElem * parent, heapElem * node) {
   heapElem aux = *node;
   *node = *parent;
   *parent = aux;
}

void enlarge(Heap * heap){
   heapElem * aux = heap->heapArray;
   heap->heapArray = (heapElem *) malloc ((heap->capac * 2) * sizeof(heapElem));
   for (int i = 0; i < heap->size; i++) {
      heap->heapArray[i] = aux[i];
   }
}

Heap* createHeap(){
   Heap * new = (Heap *) malloc (sizeof(Heap));
   new->heapArray = (heapElem *) calloc (3, sizeof(heapElem));
   new->size = 0;
   new->capac = 3;
   return new;
}

void* heap_top(Heap* pq){
   if (pq->heapArray[0].data == NULL || pq->size == 0) {
      return NULL;
   }
   return pq->heapArray[0].data;
}

void heap_push(Heap* pq, void* data, int priority){


void heap_pop(Heap* pq){

}