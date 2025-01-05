#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Edge {
  int src, dest , weight;
}Edge;

int find (int parent[],int i) {
  if (parent[i] == i) {
      return i;
  } 
  return find(parent, parent[i]);
}

void unionSets (int parent[],int rank[],int x,int y) {
    int rootX = find(parent,x);
    int rootY = find(parent,y);
    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

int compareEdges (const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)-> weight;
}

void kruskalMST (int graph[5][5],int n) {
  
}