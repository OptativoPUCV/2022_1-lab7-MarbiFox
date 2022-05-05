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
   heapElem aux;
   aux.data = node->data;
   aux.priority = node->priority;
   node->data = parent->data;
   node->priority = parent->priority;
   parent->data = aux.data;
   parent->priority = aux.priority;
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
   //Insertar al final del árbol/arreglo.
   int i = pq->size;
   if (pq->heapArray[i].data == NULL){
      //enlarge(pq);
   }
   pq->heapArray[i].priority = priority;
   pq->heapArray[i].data = data;
   
   //Reordenar si es necesario.
   int parent = (i-1)/2;
   while (1){
      //Comparar prioridad del nodo con el de su "Padre".
      printf("\n%d son\n", pq->heapArray[i].priority);
      printf("\n%d parent\n------------", pq->heapArray[parent].priority);
      if (pq->heapArray[parent].priority > pq->heapArray[i].priority) {
        break;
      }
      swap(&(pq->heapArray[parent]), &(pq->heapArray[i]));
      printf("\n%d son\n", pq->heapArray[i].priority);
      printf("\n%d parent\n", pq->heapArray[parent].priority);
      parent = (parent-1)/2;
   }
   pq->size++;
}

void heap_pop(Heap* pq){

}