#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Node.h"
#include <bits/stdc++.h>

using namespace std;

class Node;

class HashTable
{
    public:
        HashTable();
        int hashFunc(int);
        void Insert(int pin, string name, string email, string address, string uname, bool);
        void readFile();
        void printList();
        bool searchItem(string, string);
    private:
        int T_S;
        void print();
        Node* createNode(int pin, string name, string email, string address, string uname, bool);
        Node** HashArray;
};

#endif // HASHTABLE_H
