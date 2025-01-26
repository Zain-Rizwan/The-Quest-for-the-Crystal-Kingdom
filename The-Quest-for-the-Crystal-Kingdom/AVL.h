#pragma once
#include <iostream>
#include <random>


using namespace std;

int getRand() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 400);

    // Generate a random number between 0 and 400
    int randomNumber = dis(gen);

    // Print the random number
    std:: cout << "Random Number: " << randomNumber << endl;
    return randomNumber;
}

class Node {
public:
    int data;
    int count;
    int reward;
    Node* left;
    Node* right;
    int height;
    Node() {
        data = 100;
        count = 0;
        reward = 0;
        right = left = NULL;
        height = 1;
    }
    Node(int d,int r) {
        data = d;
        count = 0;
        reward = r;
        right = left = NULL;
        height = 1;
    }

};
class AVLTree {
public:
    Node* root;
    int height(Node* N) {
        if (N == NULL)
            return 0;
        return N->height;
    }
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
    int getBalance(Node* N) {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }
    Node* insert(Node* node, int data) {
        if (node == NULL) {
            int r = getRand();
            std::cout << "Random Number: " << r << endl;
            return (new Node(data, r));
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        }
        else if (data > node->data)
            node->right = insert(node->right, data);
        else
            return node;
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);
        if (balance > 1 && data < node->left->data)
            return rightRotate(node);

        if (balance < -1 && data > node->right->data)
            return leftRotate(node);

        if (balance > 1 && data > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && data < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
    bool search(Node* node, int data) {
        if (node == NULL)
            return false;
        if (node->data == data)
            return true;
        if (node->data > data)
            return search(node->left, data);
        return search(node->right, data);
    }
    Node* delete_node(Node* node, int key) {
        if (node == NULL)
            return node;
        if (key < node->data)
            node->left = delete_node(node->left, key);
        else if (key > node->data)
            node->right = delete_node(node->right, key);
        else {
            if ((node->left == NULL) || (node->right == NULL)) {
                Node* temp = node->left ? node->left : node->right;

                if (temp == NULL) {
                    temp = node;
                    node = NULL;
                }
                else
                    *node = *temp;
                delete temp;
            }
            else {
                Node* temp = node->right;
                while (temp->left != NULL)
                    temp = temp->left;
                node->data = temp->data;
                node->right = delete_node(node->right, temp->data);
            }
        }
        if (node == NULL)
            return node;
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);
        if (balance > 1 && getBalance(node->left) >= 0)
            return rightRotate(node);
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && getBalance(node->right) <= 0)
            return leftRotate(node);
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    int size(Node* node) {
        if (node == NULL)
            return 0;
        else
            return size(node->left) + size(node->right) + 1;
    }
public:
    AVLTree() {
        root = NULL;
    }
};