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
   new->heapArray = (heapElem *) malloc (3 * sizeof(heapElem));
   new->size = 0;
   new->capac = 3;
   return new;
}

void* heap_top(Heap* pq){
  return pq->heapArray[0].data;
   if (pq->heapArray[0].data == NULL) {
      return NULL;
   }
   return pq->heapArray[0].data;
}

void heap_push(Heap* pq, void* data, int priority){
   //Insertar al final del árbol/arreglo.
   pq->size++;
   int i = pq->size - 1;
   if (pq->heapArray[i].data == NULL){
      enlarge(pq);
   }
   pq->heapArray[i].priority = priority;
   pq->heapArray[i].data = data;

   //Reordenar si es necesario.
   int aux = i;
   int parent = (aux-1)/2;
   while (parent >= 0){
      //Comparar prioridad del nodo con el de su "Padre".
      if (pq->heapArray[parent].priority > pq->heapArray[aux].priority) break;
      swap(&(pq->heapArray[parent]), &(pq->heapArray[aux]));
      parent = (parent-1)/2;
   }
}

void heap_pop(Heap* pq){

}