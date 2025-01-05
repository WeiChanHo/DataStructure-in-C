#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_HEAP_SIZE 100
#define MAX_COMMAND_LENGTH 100

typedef struct
{
  int arr[MAX_HEAP_SIZE];
  int size;
} MinHeap;

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapifyUp(MinHeap *heap, int index)
{
  while (index > 0)
  {
    int parent = (index - 1) / 2;
    if (heap->arr[parent] > heap->arr[index])
    {
      swap(&heap->arr[parent], &heap->arr[index]);
      index = parent;
    }
    else
    {
      break;
    }
  }
}

void heapifyDown(MinHeap *heap, int index)
{
  int leftChild, rightChild, smallest;

  while (1)
  {
    leftChild = 2 * index + 1;
    rightChild = 2 * index + 2;
    smallest = index;

    if (leftChild < heap->size && heap->arr[leftChild] < heap->arr[smallest])
      smallest = leftChild;
    if (rightChild < heap->size && heap->arr[rightChild] < heap->arr[smallest])
      smallest = rightChild;

    if (smallest != index)
    {
      swap(&heap->arr[index], &heap->arr[smallest]);
      index = smallest;
    }
    else
    {
      break;
    }
  }
}

void insert(MinHeap *heap, int value)
{
  if (heap->size >= MAX_HEAP_SIZE)
  {
    printf("Heap is full\n");
    return;
  }
  heap->arr[heap->size] = value;
  heapifyUp(heap, heap->size);
  heap->size++;
}

int findIndex(MinHeap *heap, int value)
{
  for (int i = 0; i < heap->size; i++)
  {
    if (heap->arr[i] == value)
    {
      return i;
    }
  }
  return -1;
}

void deleteValue(MinHeap *heap, int value)
{
  int index = findIndex(heap, value);
  if (index == -1)
  {
    printf("Value not found in the heap\n");
    return;
  }
  heap->arr[index] = heap->arr[heap->size - 1];
  heap->size--;
  heapifyUp(heap, index);
  heapifyDown(heap, index);
}

void printHeap(MinHeap *heap)
{
  for (int i = 0; i < heap->size; i++)
  {
    printf("%d ", heap->arr[i]);
  }
  printf("\n");
}

int main()
{
  MinHeap heap;
  heap.size = 0;

  char command[MAX_COMMAND_LENGTH];

  while (1)
  {
    if (fgets(command, sizeof(command), stdin) == NULL)
    {
      break;
    }

    size_t len = strlen(command);
    if (command[len - 1] == '\n')
    {
      command[len - 1] = '\0';
    }

    if (strlen(command) == 0)
    {
      break;
    }

    char operation[10];
    int value;
    if (sscanf(command, "%s %d", operation, &value) == 2)
    {
      if (strcmp(operation, "insert") == 0)
      {
        insert(&heap, value);
      }
      else if (strcmp(operation, "delete") == 0)
      {
        deleteValue(&heap, value);
      }
    }
  }

  printHeap(&heap);

  return 0;
}
