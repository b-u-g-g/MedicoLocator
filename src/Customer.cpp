#include "Customer.h"
#include <string>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

Customer::Customer()
{
    //ctor
}

void Customer::Register(){
    cout<<"Enter Full Name : ";
    cin.ignore();
    getline(cin, name);
    cout<<"Enter Email ID : ";
    cin>>email;
    cout<<"Enter Username : ";
    cin>>username;
    cout<<"Enter Password : ";
    cin>>password;
    cout<<"Enter Address : ";
    cin.ignore();
    getline(cin, address);
    fstream fout;
    fout.open("customers.csv", ios::out | ios::app);
    fout<<name<<":"
        <<email<<":"
        <<username<<":"
        <<password<<":"
        <<address<<endl;
    cout<<"\nRegistration Successful!\n"<<endl;
}

void Customer::Login(){
    fstream fin;
    int check = 0;
    string uname, pass;
    cout<<"Enter username : ";
    cin>>uname;
    cout<<"Enter password : ";
    cin>>pass;
    fin.open("customers.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    while(getline(fin, line)){
        row.clear();
        stringstream s(line);
        while(getline(s, word, ':')){
            row.push_back(word);
        }
        if(uname==row[2] && pass==row[3]){
            check = 1;
            name = row[0];
            email = row[1];
            username = row[2];
            password = row[3];
            address = row[4];
            cout<<"\nLogin Successful!\n"<<endl;
            break;
        }
    }
    if(check==0){
        cout<<"ERROR : User not found!\n"<<endl;
    }
}

void Customer::connect_retailer(){
    cout<<"\nEnter retailer username to connect : ";
    cin>>r_uname;
    cout<<"Connection Successful!"<<endl;
    cout<<endl;
    return;
}

void Customer::getStocksheet(){
    fstream fin;
    if(r_uname == ""){
        cout<<"Please connect to a retailer to view stocksheet."<<endl;
        return;
    }
    fin.open(".//Retailers//"+r_uname+".csv", ios::in);
    if(!fin.is_open()){
        cout<<"File does not exist!"<<endl;
        return;
    }
    vector<string> row;
    string line, word, temp;
    cout << left << setw(10) << setfill(' ') << "ItemID";
    cout << left << setw(30) << setfill(' ') << "Item Name";
    cout << left << setw(15) << setfill(' ') << "Price";
    cout << left << setw(15) << setfill(' ') << "Quantity";
    cout<<endl;
    while(getline(fin, line)){
        row.clear();
        stringstream s(line);
        while(getline(s, word, ',')){
            row.push_back(word);
        }
        cout << left << setw(10) << setfill(' ') << row[0];
        cout << left << setw(30) << setfill(' ') << row[1];
        cout << left << setw(15) << setfill(' ') << row[2];
        cout << left << setw(15) << setfill(' ') << row[3];
        cout<<endl;
    }
    fin.close();
}


void Customer::addToCart(){
    if(r_uname == ""){
        cout<<"Please connect to a retailer first."<<endl;
        return;
    }
    string itemid, itemname;
    float price;
    int availquant;
    fstream fin;
    fin.open(".//Retailers//"+r_uname+".csv", ios::in);
    int quant;
    cout<<"Enter ItemID to add : ";
    cin>>itemid;
    vector<string> row;
    string line, word, temp;
    while(getline(fin, line)){
        row.clear();
        stringstream s(line);
        while(getline(s, word, ',')){
            row.push_back(word);
        }
        if(row[0] == itemid){
            itemname = row[1];
            price = stoi(row[2]);
            availquant = stoi(row[3]);
            break;
        }
    }
    fin.close();
    while(1){
        cout<<"Enter quantity : ";
        cin>>quant;
        if(quant > availquant){
            cout<<"Quantity exceeds availability! Please enter a lesser value."<<endl;
            continue;
        }
        else
            break;
    }
    Cart.push_back({itemid, itemname, price, quant});
    cout<<"\nItem added to cart."<<endl;
}


void Customer::editCart(){
    if(r_uname == ""){
        cout<<"Please connect to a retailer first."<<endl;
        return;
    }
    string itemid;
    int quant, check = 0;
    if(Cart.empty()){
        cout<<"ERROR : Cart is empty!"<<endl;
        return;
    }
    cout<<"Enter ItemID to edit : ";
    cin>>itemid;
    cout<<"Enter new quantity : ";
    cin>>quant;
    for(int i=0; i<(int)Cart.size(); i++){
        if(Cart[i].itemID == itemid){
            check = 1;
            Cart[i].quantity = quant;
        }
    }
    if(check){
        cout<<"Cart updated successfully!"<<endl;
    }
    else{
        cout<<"ERROR : Item does not exist!"<<endl;
    }
}

void Customer::removefromCart(){
    if(r_uname == ""){
        cout<<"Please connect to a retailer first."<<endl;
        return;
    }
    string itemid;
    int check = 0;
    if(Cart.empty()){
        cout<<"ERROR : Cart is empty!"<<endl;
        return;
    }
    cout<<"Enter ItemID to remove : ";
    cin>>itemid;
    for(int i=0; i<(int)Cart.size(); i++){
        if(Cart[i].itemID == itemid){
            Cart.erase(Cart.begin() + i);
        }
    }
    if(check){
        cout<<"Cart updated successfully!"<<endl;
    }
    else{
        cout<<"ERROR : Item does not exist!"<<endl;
    }
}



void Customer::viewCart(){
    if(r_uname == ""){
        cout<<"Please connect to a retailer first."<<endl;
        return;
    }
    if(Cart.empty()){
        cout<<"Cart is Empty!"<<endl;
        return;
    }
    cout << left << setw(15) << setfill(' ') << "ItemID";
    cout << left << setw(30) << setfill(' ') << "Name";
    cout << left << setw(15) << setfill(' ') << "Price";
    cout << left << setw(10) << setfill(' ') << "Quantity";
    cout<<endl;
    for(int i=0; i<(int)Cart.size(); i++){
        cout << left << setw(15) << setfill(' ') << Cart[i].itemID;
        cout << left << setw(30) << setfill(' ') << Cart[i].itemname;
        cout << left << setw(15) << setfill(' ') << Cart[i].price;
        cout << left << setw(10) << setfill(' ') << Cart[i].quantity;
        cout<<endl;
    }
}


void Customer::CheckOut(){
    if(r_uname == ""){
        cout<<"Please connect to a retailer first."<<endl;
        return;
    }
    if(Cart.empty()){
        cout<<"You have no items in your cart!"<<endl;
        return;
    }
    fstream fout, fin;
    fin.open(".//Retailers//" + r_uname + ".csv", ios::in);
    fout.open(".//Retailers//" + r_uname + "new.csv", ios::out);
    string line, word;
    vector<string> row;
    while(getline(fin, line)){
        row.clear();
        stringstream s(line);
        while(getline(s, word, ',')){
            row.push_back(word);
        }
        int index = -1;
        for(int i=0; i<(int)Cart.size(); i++){
            if(Cart[i].itemID == row[0]){
                index = i;
            }
        }
        if(index != -1){
            int quantity = stoi(row[3]) - Cart[index].quantity;
            fout<<row[0]<<","
                <<row[1]<<","
                <<row[2]<<","
                <<quantity<<"\n";
        }
        else{
            fout<<row[0]<<","
                <<row[1]<<","
                <<row[2]<<","
                <<row[3]<<"\n";
        }
    }
    fin.close();
    fout.close();
    string soldfile = ".//Retailers//" + r_uname + ".csv";
    string snewfile = ".//Retailers//" + r_uname + "new.csv";
    char* oldfile = &soldfile[0];
    char* newfile = &snewfile[0];
    remove(oldfile);
    rename(newfile, oldfile);
    Cart.clear();
    cout<<"Checkout Successful!"<<endl;
}


