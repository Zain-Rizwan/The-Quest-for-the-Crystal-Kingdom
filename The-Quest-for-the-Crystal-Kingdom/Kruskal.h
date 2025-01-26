#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int f(int* father, int i);

class Edge {
public:
    int u;
    int v;
    int weight;
};

// Comparator function to sort edges based on their weights
bool compare(Edge a,Edge b) {
    return b.weight > a.weight;
}
void unionSet(int *father, int rank[], int x, int y) {
    int xroot = f(father, x);
    int yroot = f(father, y);
    if (rank[xroot] < rank[yroot]) {
        father[xroot] = yroot;
    }
    else if (rank[xroot] > rank[yroot]) {
        father[yroot] = xroot;
    }
    else {
        father[yroot] = xroot;
        rank[xroot]++;
    }
}

// Function to find the of a vertex in a set
int f(int *father, int i) {
    if (father[i] == i) {
        return i;
    }
    return f(father, father[i]);
}

// Function to perform union of two sets

// Function to find minimum spanning tree using Kruskal's algorithm
void Kruskal(int** graph, int V) {
    Edge *edges=new Edge[40 * 40]; // Array to store edges
    int k = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0) {
                edges[k] = { i, j, graph[i][j] };
                ++k;
            }
        }
    }
    sort(edges, edges + k, compare); // Sort edges based on their weights
    int* father = new int[400];
    int* rank = new int[400];
    for (int i = 0; i < V; i++) {
        father[i] = i;
        rank[i] = 0;
    }
    Edge *tree=new Edge[400]; // Array to store minimum spanning tree edges
    int index = 0;
    for (int i = 0; i < k; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        int y = f(father, v);
        int x = f(father, u);
        if (y != x) {
            tree[index] = { u, v, weight };
            unionSet(father, rank, x, y);
            ++index;
        }
    }
    int temp = 0;
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 0; i < index; i++) {
        cout << "(" << tree[i].u << ", " << tree[i].v << ") - " << tree[i].weight << endl;
        temp++;
    }
    cout << temp << endl;
}
