#pragma once
#include <iostream>
#include <climits>
#include <cstring>

using namespace std;
void printpath(int v, int* father,char* game);

void floydAlgo(int **graph, int V, int start, int end) {
    int** dis = new int* [400];
    for (int i = 0;i < 400;i++) {
        dis[i] = new int[400];
    }
    int** father = new int* [400];
    for (int i = 0;i < 400;i++) {
        father[i] = new int[400];
    }

    // Initializing distance matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (j == i) {
                father[i][j] = -1;
                dis[i][j] = 0;
            }
            else if (graph[i][j] != 0) {
                father[i][j] = i;
                dis[i][j] = graph[i][j];
            }
            else {
                father[i][j] = -1;
                dis[i][j] = 9999;
            }
        }
    }
    // Applying Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dis[i][j] > dis[i][k] + dis[k][j] && dis[i][k] != 9999 && dis[k][j] != 9999) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    father[i][j] = father[k][j];
                }
            }
        }
    }

    // Printing the shortest distance between start and end vertices
    if (dis[start][end] == 9999) {
        cout << "No path exists between " << start << " and " << end << endl;
    }
    else {
        cout << "Shortest distance between " << start << " and " << end << ": " << dis[start][end] << endl;
    }
    int t = dis[start][end];
    char* game = new char[t];
    printpath(end, father[start],game);
    cout << endl;
    cout << "lob\n";
    for (int i = 0;i < t;++i) {
        cout << game[i] << " ";
    }
    cout << endl;
}

void printpath(int v, int* father,char *game) {
    if (father[v] == -1) {
        return;
    }
    printpath(father[v], father, game);
    cout << v << "->";
    //game[v] = father[v];
}