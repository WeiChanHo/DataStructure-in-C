#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <stdbool.h>
#define MAX_HEAP_SIZE 100
#define MAX_COMMAND_lENGTH 100

typedef struct {
    int arr[MAX_HEAP_SIZE];
    int size;
} MinHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap *heap, int index) {
    while (index>0) {
        int parent = (index-1)/2;
        if (heap->arr[parent] > heap->arr[index]) {
            swap(&heap->arr[parent],&heap->arr[index]);
            index = parent;
        }else {
            break;
        }
    }
}

void heapifyDown(MinHeap *heap, int index) {
    int leftChild,rightChild,smallest;

    while(1) {
        leftChild = 2*index+1;
        rightChild = 2*index+2;
        smallest =index;
        if(leftChild < heap->size && heap->arr[leftChild] < heap->arr[smallest]) {
            smallest = leftChild;
        }
        if(rightChild < heap->size && heap->arr[rightChild] < heap->arr[smallest]) {
            smallest = rightChild;
        }
        if(smallest != index) {
            swap(&heap->arr[index],&heap->arr[smallest]);
        }else {
            break;
        }
    }
}

void insert(MinHeap *heap, int value) {
    if (heap->size >= MAX_HEAP_SIZE) {
        printf("heap is full\n");
        return;
    }
    heap->arr[heap->size] = value;
    heapifyUp(heap,heap->size);
    heap->size++;    
}

int findIndex(MinHeap *heap, int value) {
    for (int i =0; i < heap->size ; i++){
        if(heap->arr[i]==value){
            return i;
        }
    }
    return -1;
}

void deletevalue(MinHeap *heap, int value) {
    int index =findIndex(heap,value);
    if (index == -1){
        printf("Value not found in the heap\n");
        return;
    }
    heap->arr[index] = heap->arr[heap->size-1];
    heap->size--;
    heapifyUp(heap,index);
    heapifyDown(heap,index);
}

void printHeap(MinHeap *heap) {
    for(int i=0; i<heap->size ; i++){
        printf("%d",heap->arr[i]);
    }
    printf("\n");
}
