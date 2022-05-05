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
   heapElem * aux = (heapElem *) malloc (sizeof(heapElem));
   aux = node;
   node = parent;
   parent = aux;
}

Heap* createHeap(){
   Heap * new = (Heap *) malloc (sizeof(Heap));
   new->heapArray = (heapElem *) malloc (10 * sizeof(heapElem));
   new->size = 0;
   new->capac = 10;
   return new;
}

void* heap_top(Heap* pq){
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){
   //Insertar al final del árbol/arreglo.
   if (pq->heapArray[pq->size] == NULL){
      //enlarge(pq->heapArray);
   }
   pq->heapArray[pq->size].priority = priority;
   pq->heapArray[pq->size].data = data;

   //Reordenar si es necesario.
   int aux = pq->size;
   int parent = (aux-1)/2;
   while (parent >= 0){
      //Comparar prioridad del nodo con el de su "Padre".
      if (pq->heapArray[parent].priority > pq->heapArray[aux].priority) break;
      swap(&(pq->heapArray[parent]), &(pq->heapArray[aux]));
      parent = (parent-1)-2;
   }
   pq->size++;
}


void heap_pop(Heap* pq){

}


