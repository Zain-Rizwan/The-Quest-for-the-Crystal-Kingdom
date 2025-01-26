#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Dijkstra.h"
#include "Floyd.h"
#include "Kruskal.h"
#include "Prim.h"

using namespace std;

void clrscr()
{
    system("cls");
}

void getpythoncode() {
    system("python mapping.py > result.txt");
}
char** getfile() {
    char** arr = new char* [20];
    for (int i = 0; i < 20; i++) {
        arr[i] = new char[20];
    }
    ifstream inputFile("result.txt");
    if (!inputFile.is_open()) {
        cout << "Unable to open file." << endl;
    }

    // Read the file character by character and store in the array
    int i = 0, j = 0;
    char ch;
    string line;
    while (getline(inputFile, line)) {
        for (int k = 0; k < 40; ++k) {
            arr[i][j] = line[k];
            ++k;
            ++j;
        }
        j = 0;
        ++i;
    }
    // Close the file
    inputFile.close();
    return arr;
}


int** getadjancy(char** arr) {
    int** adj = new int* [20];
    for (int i = 0; i < 20; ++i) {
        adj[i] = new int[20];
    }
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (arr[i][j] != '#') {
                adj[i][j] = 1;
            }
            else {
                adj[i][j] = 100;
            }
        }
    }

    int vertic_num[400];

    int x = 0;
    for (int j = 0; j < 20; j++)
    {
        for (int k = 0; k < 20; k++)
        {
            vertic_num[x] = adj[j][k];
            x++;
        }
    }

    /*for (int i = 0; i < 400; i++)
    {
        cout << vertic_num[i] << " ";
    }
    cout << endl;*/

    int** adj_mat = new int* [400];
    for (int i = 0; i < 400; ++i) {
        adj_mat[i] = new int[400];
    }
    for (int i = 0; i < 400; ++i) {
        for (int j = 0; j < 400; ++j)
        {
            /*if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = INT_MAX;*/
            adj_mat[i][j] = 0;
        }
    }

    /*for (int i = 0; i < 400; ++i) {
        for (int j = 0; j < 400; ++j)
        {
            cout << adj_mat[i][j] << " ";
        }
    }
    cout << endl;*/

    int left;
    int right;
    int up;
    int down;

    for (int i = 0; i < 400; i++)
    {

        left = i - 1;
        right = i + 1;
        up = i - 20;
        down = i + 20;

        if (left >= 0 && left <= 399)
            adj_mat[i][left] = vertic_num[left];

        if (right >= 0 && right <= 399)
            adj_mat[i][right] = vertic_num[right];

        if (up >= 0 && up <= 399)
            adj_mat[i][up] = vertic_num[up];

        if (down >= 0 && down <= 399)
            adj_mat[i][down] = vertic_num[down];

    }
    int temp = 0;
    /*for (int i = 0; i < 400; ++i) {
        for (int j = 0; j < 400; ++j)
        {
            cout << adj_mat[i][j] << " ";
            temp = j;
        }
        cout << endl;
        cout << temp << endl;
    }
    cout << endl;*/

    return adj_mat;

}
int findCrystal(char** arr, int vertex) {
    int l = 0;
    for (int i = 0;i < 20;++i) {
        for (int j = 0;j < 20;++j) {
            if (arr[i][j] == '*') {
                return l;
            }
            else
                ++l;
        }
    }
    cout << "Crystal does not exist in the given map/n";
    return 0;
}

int main() {
    char spc;

    system("Color 03");

    cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t ------------------------------" << endl;
    cout << "\t\t\t\t\t|Welcome to Remains of Atlantis|" << endl;
    cout << "\t\t\t\t\t ------------------------------" << endl;
    cout << "\n\n\n\t\t\t\t\t   Press Enter to continue...";
    //cin >> spc;
    cin.ignore();

    clrscr();

    //getpythoncode();
    //cout << "Welcome to DS Project Made By Asjad Rauf Minhaaj Saqib and Zain Rizwan\nMap\n";

    //system("Color 07");

    //cout << "\n\n\n\n\t\t\t\t\t Map of the Remains of Atlantis\n" << endl;
    //char** arr = getfile();
    //for (int i = 0; i < 20; ++i) {
    //    cout << "\t\t\t\t    ";
    //    for (int j = 0; j < 20; ++j) {
    //        cout << arr[i][j] << " ";
    //    }
    //    // cout << "done\n";
    //    cout << endl;
    //}
    //cout << "\n";
    //cout << endl;
    //cout << endl;
    char choice = ' ';
    //cout << "Which Algorithm do you want to implement:\n1. Kruskal (Minimum Spanning Tree)\n2. Prim's (Minimum Spanning Tree)\n3. Dijkstra (Find Shortest Path to the Crystal)\n4. Floyd(Find Shortest Path to the Crystal)\n ";
    //cout << "Choose: ";
    int tru = 1;
    int choice_1;
    int choice_2;


    while (tru)
    {
        //cout << "\n\n\n";

        cout << "\n\t\t\t\t\t Map of the Remains of Atlantis\n" << endl;
        char** arr = getfile();
        for (int i = 0; i < 20; ++i) {
            cout << "\t\t\t\t    ";
            for (int j = 0; j < 20; ++j) {
                cout << arr[i][j] << " ";
            }
            // cout << "done\n";
            cout << endl;
        }
        cout << endl;

        system("Color 07");
        if (tru == 1)
            cout << "\tWelcome Adventurer, to the remains of the Once Great Atlantis" << endl;
        if (tru == 2 || tru == 4)
            cout << "\tWelcome back Adventurer, to the remains of the Once Great Atlantis" << endl;
        if (tru == 3)
            cout << "\tYou gave the wrong answer adventurer\n" << endl;;

        cout << "\t There are 4 ways to proceed" << endl;
        cout << "        1. Kruskal's way (Way of minimum span)" << endl;
        cout << "        2. Prim's way (Way of minimum span)" << endl;
        cout << "        3. Dijkstra's way (Way of shortest path)" << endl;
        cout << "        4. Floyd's way (Way of shortest path)" << endl;
        cout << "                        OR" << endl;
        cout << "        5. You can go back" << endl;

        cout << "\t Which path do you want to choose: ";
        cin >> choice;

        //cin >> choice;
        int location = findCrystal(arr, 400);
        bool flag = true;
        //int** adj = getadjancy(arr);
        //for (int i = 0; i < 20; ++i) {
        //    for (int j = 0; j < 20; ++j) {
        //        cout << adj[i][j] << " ";
        //    }
        //    // cout << "done\n";
        //    cout << endl;
        //}
        int** adj = getadjancy(arr);
        //while (flag) {
        if (choice == '1') {
            clrscr();
            system("Color 01");
            Kruskal(adj, 400);
            tru = 4;
            // flag = false;
        }
        else if (choice == '2') {
            clrscr();
            system("Color 09");
            //flag = false;
            primAlgo(adj, 400);
            tru = 4;
        }
        else if (choice == '3') {
            cout << "           From which location do you want to start (0-399)";
            cin >> choice_1;

            clrscr();
            system("Color 04");
            //flag = false;
            if (choice_1 == 0)
                Dijkstra(adj, 0, location, 400, arr);
            else
                Dijkstra(adj, choice_1, location, 400, arr);
            tru = 2;
        }
        else if (choice == '4') {
            cout << "           From which location do you want to start (0-399)";
            cin >> choice_2;

            clrscr();
            system("Color 0C");
            //cout << "4\n";
            //flag = false;
            if (choice_2 == 0)
                floydAlgo(adj, 400, 0, location);
            else
                floydAlgo(adj, 400, choice_2, location);
            tru = 2;
        }
        else if (choice == '5')
        {
            break;
        }
        else {

            tru = 3;
            //cout << "Choose: ";
            //cin >> choice;
            clrscr();
        }

        if (tru == 2)
        {

            cout << "\n\tCongratulations Adventurer, you found the crystal at location " << location << endl;
            cout << "\n\n\n\t\t\t\t\t   Press Enter to continue...";
            //cin >> spc;
            //cin.clear();
            cin.ignore();
            cin.ignore();
            clrscr();
        }
        else if (tru == 4)
        {

            cout << "\n\tCongratulations Adventurer, you've travelled through all of the Atlantis " << endl;
            cout << "\n\n\n\t\t\t\t\t   Press Enter to continue...";
            //cin >> spc;
            //cin.clear();
            cin.ignore();
            cin.ignore();
            clrscr();
        }

        //}
    }

    //cout << endl;
    //cout << endl;
    clrscr();
    system("Color 0F");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t FAREWELL" << endl;
    cout << "\t\t\t\t\t\t     Young Adventurer\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    //cout << "Location of Crystal is: " << location << endl;
    return 0;
}