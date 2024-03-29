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
   heap->capac = heap->capac * 2 + 1;
   heap->heapArray = (heapElem *) realloc (heap->heapArray, (sizeof(heapElem) * heap->capac));
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
   if (pq->size == pq->capac){
      enlarge(pq);
   }
   pq->heapArray[i].priority = priority;
   pq->heapArray[i].data = data;
   pq->size++;
   
   //Reordenar si es necesario.
   int parent = (i-1)/2;
   while (i > 0){
      //Comparar prioridad del nodo con el de su "Padre".
      if (pq->heapArray[parent].priority > pq->heapArray[i].priority) {
        break;
      }
      //Intercambio.
      swap(&(pq->heapArray[parent]), &(pq->heapArray[i]));
      //Actualizar Valores.
      i = (i-1)/2;
      parent = (parent-1)/2;
    }
  return;
}

void heap_pop(Heap* pq){
   //Cambiar el nodo raíz por el nodo final.
   swap(&(pq->heapArray[0]), &(pq->heapArray[pq->size-1]));
   //Eliminar el nodo raíz.
   pq->heapArray[pq->size-1].priority = 0;
   pq->heapArray[pq->size-1].data = NULL;
   pq->size--;
   //Intercambiar nodos.
   int i = 0;
   while (i < pq->size) {
      //Comparar Hijo Izquierdo. (Menor)
      if (pq->heapArray[i].priority < pq->heapArray[2*i+1].priority && pq->heapArray[2*i+1].priority > pq->heapArray[2*i+2].priority) {
         swap(&(pq->heapArray[i]), &(pq->heapArray[2*i+1]));
         i = 2*i+1;
         continue;
      }
      //Comparar Hijo Derecho. (Mayor)
      if (pq->heapArray[i].priority < pq->heapArray[2*i+2].priority) {
         swap(&(pq->heapArray[i]), &(pq->heapArray[2*i+2]));
         i = 2*i+2;
         continue;
      }
      break;
   }
}