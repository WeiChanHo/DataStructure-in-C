#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Edge {
    int src, dest, weight;
} Edge;

// Function to find the root of an element (Union-Find)
int find(int parent[], int i) {
    if (parent[i] == i) 
        return i;
    return find(parent, parent[i]);
}

// Function to perform union of two subsets
void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    if (rank[rootX] < rank[rootY]) 
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY]) 
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

// Comparator function to sort edges by weight in increasing order
int compareEdges(const void *a, const void *b) {
  return ((Edge *)a)->weight - ((Edge *)b)->weight;    
}

// Kruskal's algorithm for Minimum Spanning Tree
void kruskalMST(int graph[5][5], int n) {
    Edge edges[MAX];
    int edgeCount = 0;
    
    // Collect all edges
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != 0) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }
    
    // Sort edges by weight in descending order
    qsort(edges, edgeCount, sizeof(Edge), compareEdges);
    
    // Union-Find setup
    int parent[n], rank[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    
    printf("Edges in the Minimum Spanning Tree (from highest to lowest weight):\n");
    for (int i = 0, included = 0; i < edgeCount && included < n - 1; i++) {
        Edge edge = edges[i];
        int rootSrc = find(parent, edge.src);
        int rootDest = find(parent, edge.dest);
        
        if (rootSrc != rootDest) { // If adding this edge doesn't form a cycle
            printf("(%d -- %d) weight: %d\n", edge.src, edge.dest, edge.weight);
            unionSets(parent, rank, rootSrc, rootDest);
            included++;
        }
    }
}

int main() {
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    kruskalMST(graph, 5);
    return 0;
}
