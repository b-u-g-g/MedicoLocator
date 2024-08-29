#ifndef NODE_H
#define NODE_H
#include "HashTable.h"
#include <bits/stdc++.h>

using namespace std;

class HashTable;

class Node
{
public:
    Node();
private:
    string name;
    string email;
    string address;
    string username;
    bool status;
    int pincode;
    Node* next;
    friend class HashTable;
};

#endif // NODE_H
