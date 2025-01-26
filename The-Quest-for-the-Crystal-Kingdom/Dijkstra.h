#pragma once
#include <iostream>
#include <climits>
#include "AVL.h"

using namespace std;


// function to find the vertex with minimum distance from the source
int minDistance(int dist[], bool visited[], int num_vertices) {
    int min_dist = 9999, min_vertex=9999;
    for (int i = 0; i < num_vertices; i++) {
        if (!visited[i] && dist[i] < min_dist) {
            min_dist = dist[i];
            min_vertex = i;
        }
    }
    return min_vertex;
}

// function to find the shortest path between the source and target vertices
void Dijkstra(int **graph, int source, int target, int num_vertices,char **arr) {
    int* dist = new int[num_vertices];         // array to store the distance from the source vertex to all other vertices
    int* prev=new int[num_vertices];         // array to store the previous vertex in the shortest path
    bool* visited=new bool[num_vertices];     // array to keep track of visited vertices

    // initialize all distances as infinity and visited as false
    for (int i = 0; i < num_vertices; i++) {
        dist[i] = 9999;
        visited[i] = false;
    }
    for (int i = 0; i < num_vertices; i++) {
        prev[i] = 0;
    }

    // distance to source vertex is 0
    dist[source] = 0;

    // loop until the target vertex is visited or all vertices are visited
    while (!visited[target]) {
        // find the vertex with minimum distance from the source
        int u = minDistance(dist, visited, num_vertices);

        // mark the vertex as visited
        visited[u] = true;

        // update the distance of all adjacent vertices of the current vertex
        for (int v = 0; v < num_vertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != 99999 && dist[u] + graph[u][v] < dist[v]) {//Int max change
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }

    // print the shortest path from the source to target vertex
    int *path=new int[num_vertices], path_length = 0;
    int current = target;
    while (current != source) {
        path[path_length++] = current;
        current = prev[current];
    }
    path[path_length++] = source;

    //Reversing the array
    int st = 0;
    int ender = path_length;
    while (st < ender) {
        // Swap elements at start and end
        int temp = path[st];
        path[st] = path[ender];
        path[ender] = temp;

        // Move start and end towards the center
        st++;
        ender--;
    }
    int* avl = new int[path_length];
    for (int i = 1;i < path_length+1;++i) {
        avl[i] = path[i];
    }
    char* points = new char[path_length];
    int* point = new int[path_length];
    char* gamearr = new char[num_vertices];
    int k1 = 0;
    for (int i = 0;i < 20;++i) {
        for (int j = 0;j < 20;++j) {
            gamearr[k1] = arr[i][j];
            ++k1;
        }
    }
    std::cout << "Shortest path from vertex " << source << " to vertex " << target << ": ";
    AVLTree tree;
    Node* d();
    tree.insert(NULL, 0);
    int p = 0;
    for (int i = 1; i< path_length+1; i++) {
        std::cout << path[i];
        if (gamearr[path[i]] == 'C') {
            points[i - 1] = 'C';
            point[i - 1] = 0;

        }
        else if (gamearr[path[i]] == 'W') {
            points[i - 1] = 'W';
            p += 30;
            point[i - 1] = 30;
        }
        else if (gamearr[path[i]] == 'J') {
            points[i - 1] = 'J';
            p += 50;
            point[i - 1] = 50;
        }
        else if (gamearr[path[i]] == '*') {
            points[i - 1] = '*';
            point[i - 1] = 0;
        }
        else if (gamearr[path[i]] == '&') {
            points[i - 1] = '&';
            point[i - 1] = -50;
            p -= 50;
        }
        else if (gamearr[path[i]] == '#') {
            points[i - 1] = '#';
            point[i - 1] = -100;
            p -= 100;
        }
        else if (gamearr[path[i]] == 'P') {
            points[i - 1] = 'P';
            p += 70;
            point[i - 1] = 70;
        }
        else if (gamearr[path[i]] == '%') {
            points[i - 1] = '%';
            p = 0;
            std::cout << "You stepped on Death Path\nGame OvER\n";
            point[i - 1] = 0;
            p = 0;
            //break;
        }
        else if (gamearr[path[i]] == '@') {
            points[i - 1] = '@';
            p -= 30;
            point[i - 1] = -30;
        }
        else if (gamearr[path[i]] == '$') {
            points[i - 1] = '$';
            p -= 70;
            point[i - 1] = -70;
        }

        if (i != 0) {
            std::cout << " -> ";
        }
    }
    std::cout << endl;
    std::cout << "Shortest distance from vertex " << source << " to vertex " << target << ": " << dist[target] << endl;
    std::cout << endl << endl << endl;
   /* for (int i = 0;i < num_vertices;++i) {
        cout << gamearr[i] << " ";
    }*/
    std::cout << endl;
    
    for (int i = 0;i < path_length ;++i) {
        std::cout << points[i] << " " << "score is: " << point[i];
        std::cout << endl;
    }
    std::cout << endl;
    std::cout << "Total Points are: " << p << endl;
}