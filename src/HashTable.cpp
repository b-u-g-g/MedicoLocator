#include "HashTable.h"
#include <iostream>
#include <Node.h>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

HashTable::HashTable()
{
    T_S = 100;
    HashArray = (Node**)malloc(sizeof(Node*)*T_S);
    for(int i=0; i<T_S; i++){
        HashArray[i] = NULL;
    }
}

Node* HashTable::createNode(int pin, string name, string email, string address, string uname, bool status){
    Node* ptr = new Node;
    ptr->pincode = pin;
    ptr->name = name;
    ptr->email = email;
    ptr->address = address;
    ptr->username = uname;
    ptr->status = status;
    ptr->next = NULL;
    return ptr;
}

int HashTable::hashFunc(int key){
    return (key%T_S);
}

void HashTable::Insert(int pin, string name, string email, string address, string uname, bool status){
    int index = hashFunc(pin);
    if(HashArray[index] == NULL){
        HashArray[index] = createNode(pin, name, email, address, uname, status);
        return;
    }
    Node* temp = HashArray[index];
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = createNode(pin, name, email, address, uname, status);
    return;
}


void HashTable::readFile(){
    fstream fin;
    fin.open("retailers.csv", ios::in);
    vector<string> row;
    string line, word;
    while(getline(fin, line)){
        row.clear();
        stringstream s(line);
        while(getline(s, word, ':')){
            row.push_back(word);
        }
        Insert(stoi(row[5]), row[0], row[1], row[4], row[2], stoi(row[6]));
    }
    fin.close();
}

void HashTable::print(){
    for(int i=0; i<T_S; i++){
        Node* temp = HashArray[i];
        if(temp == NULL){
            cout<<"------------------";
        }
        while(temp!=NULL){
            cout<<temp->pincode<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}



void HashTable::printList(){
    int pin;
    string itemname;
    cout<<"Enter pincode to get retailers in your area: ";
    cin>>pin;
    cout<<"Enter item name (Enter 0 to get all shops at your pincode): ";
    cin>>itemname;
    int index = hashFunc(pin);
    Node* temp = HashArray[index];
    if(temp == NULL){
        cout<<"\nNo shops available at entered pincode!"<<endl;
        return;
    }
    cout<<endl;
    cout << left << setw(25) << setfill(' ') << "Name";
    cout << left << setw(60) << setfill(' ') << "Address";
    cout << left << setw(15) << setfill(' ') << "Username";
    cout << left << setw(5) << setfill(' ') << "Status";
    cout<<endl;
    while(temp != NULL){
        if(temp->pincode != pin){
            temp = temp->next;
            continue;
        }
        if(itemname == "0"){
            cout << left << setw(25) << setfill(' ') << temp->name;
            cout << left << setw(60) << setfill(' ') << temp->address;
            cout << left << setw(15) << setfill(' ') << temp->username;
            cout << left << setw(5) << setfill(' ') << (temp->status ? "Open" : "Closed");
            cout<<endl;
        }
        else if(searchItem(temp->username, itemname)){
            cout << left << setw(25) << setfill(' ') << temp->name;
            cout << left << setw(60) << setfill(' ') << temp->address;
            cout << left << setw(15) << setfill(' ') << temp->username;
            cout << left << setw(5) << setfill(' ') << (temp->status ? "Open" : "Closed");
            cout<<endl;
        }
        temp = temp->next;
    }
}


bool HashTable::searchItem(string uname, string itemname){
    bool check = false;
    fstream fin;
    fin.open(".//Retailers//" + uname + ".csv", ios::in);
    vector<string> row;
    string line, word;
    while(getline(fin, line)){
        row.clear();
        stringstream s(line);
        while(getline(s, word, ',')){
            row.push_back(word);
        }
        if(itemname == row[1] && stoi(row[3]) != 0){
            check = true;
            break;
        }
    }
    return check;
}
