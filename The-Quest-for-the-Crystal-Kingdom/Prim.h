#pragma once
#include <iostream>
#include <climits>

using namespace std;

void printPrim(int* father, int** graph, int n);
int minway(int* way, bool* mstSet, int n);

// Function to implement Prim's algorithm
void primAlgo(int** graph, int n)
{
    int* father=new int[n];
    int* way=new int[n];
    bool* mstSet=new bool[n];

    // Initialize all ways as INFINITE and mstSet[] as false
    for (int i = 0; i < n; i++)
        way[i] = 9999, mstSet[i] = false;

    // Always include the first vertex in Prim
    way[0] = 0;
    father[0] = -1; // First node is always root of Prim 

    for (int count = 0; count < n - 1; count++)
    {
        // Pick the minimum way vertex from the set of vertices not yet included in MST
        int u = minway(way, mstSet, n);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update way and father arrays
        for (int v = 0; v < n; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < way[v])
                father[v] = u, way[v] = graph[u][v];
    }
    // Print the constructed MST
    printPrim(father, graph, n);
}


// Function to print the MST using father array
void printPrim(int* father, int** graph, int n)
{
    cout << "Edge \tWeight\n";
    int temp = 0;
    for (int i = 1; i < n; i++) {
        cout << father[i] << " - " << i << "\t" << graph[i][father[i]] << endl;
        temp = i;
    }
    cout << "Total Edges are: " << temp << endl;
}

// Function to find the minimum way value vertex from the set of vertices not yet included in MST
int minway(int* way, bool* Set, int n)
{
    int min = 9999;
    int index = 9999;
    for (int v = 0; v < n; v++) {
        if (Set[v] == false && way[v] < min) {
            index = v;
            min = way[v];
        }
    }
    return index;
}