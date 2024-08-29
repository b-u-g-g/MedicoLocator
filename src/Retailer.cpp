#include "Retailer.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

Retailer::Retailer()
{

}

void Retailer::Register(){
    int pincode;
    cout<<"Enter Shop Name : ";
    cin.ignore();
    getline(std::cin, name);
    cout<<"Enter Email ID : ";
    cin>>email;
    cout<<"Enter Username : ";
    cin>>username;
    cout<<"Enter Password : ";
    cin>>password;
    cout<<"Enter Address : ";
    cin.ignore();
    getline(std::cin, address);
    cout<<"Enter Pincode : ";
    cin>>pincode;
    status = true;
    fstream fout;
    fstream f;
    f.open(dir + username + ".csv", ios::out);
    f.close();
    fout.open("retailers.csv", ios::out | ios::app);
    fout<<name<<":"
        <<email<<":"
        <<username<<":"
        <<password<<":"
        <<address<<":"
        <<pincode<<":"
        <<status<<"\n";
    fout.close();
}


void Retailer::Login(){
    fstream fin;
    int check = 0;
    string uname, pass;
    cout<<"Enter username : ";
    cin>>uname;
    cout<<"Enter password : ";
    cin>>pass;
    fin.open("retailers.csv", ios::in);
    vector<string> row;
    string line, word;
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
            pincode = stoi(row[5]);
            cout<<"\nLogin Successful!"<<endl;
            break;
        }
    }
    if(check==0){
        cout<<"\nERROR : User not found!"<<endl;
    }
    fin.close();
}



void Retailer::addNew(){
    string itemid;
    string itemname;
    float price;
    int availquantity;
    cout<<"\nEnter Item ID : ";
    cin>>itemid;
    cout<<"Enter Item Name : ";
    cin>>itemname;
    cout<<"Enter Price: ";
    cin>>price;
    cout<<"Enter Available Quantity : ";
    cin>>availquantity;
    fstream fout;
    fout.open(dir + username + ".csv", ios::out | ios::app);
    fout<<itemid<<","
        <<itemname<<","
        <<price<<","
        <<availquantity<<"\n";
    fout.close();
    cout<<"\nItem added Successfully!"<<endl;
}



void Retailer::updateStock(){
    string itemID;
    int check = 0;
    float price;
    int quantity;
    cout<<"\nEnter Item ID : ";
    cin>>itemID;
    cout<<"Enter updated Price : ";
    cin>>price;
    cout<<"Enter updated available quantity : ";
    cin>>quantity;
    fstream fout, fin;
    fin.open(dir + username + ".csv", ios::in);
    fout.open(dir + username + "new.csv", ios::out);
    string line, word;
    vector<string> row;
    while(getline(fin, line)){
        row.clear();
        stringstream s(line);
        while(getline(s, word, ',')){
            row.push_back(word);
        }
        if(itemID == row[0]){
            check = 1;
            fout<<row[0]<<","
                <<row[1]<<","
                <<price<<","
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
    string soldfile = dir + username + ".csv";
    string snewfile = dir + username + "new.csv";
    char* oldfile = &soldfile[0];
    char* newfile = &snewfile[0];
    remove(oldfile);
    rename(newfile, oldfile);
    cout<<"\nItem updated Successfully!"<<endl;
    if(check==0){
        cout<<"ERROR : Record does not exist!"<<endl;
    }
}

void Retailer::updateStatus(){
    int stat;
    cout<<"Enter Shop Status : ";
    cin>>stat;
    status = stat;
    fstream fout, fin;
    fin.open("retailers.csv", ios::in);
    fout.open("retailersnew.csv", ios::out);
    string line, word;
    vector<string> row;
    while(getline(fin, line)){
        row.clear();
        stringstream s(line);
        while(getline(s, word, ':')){
            row.push_back(word);
        }
        if(username == row[2]){
            fout<<row[0]<<":"
                <<row[1]<<":"
                <<row[2]<<":"
                <<row[3]<<":"
                <<row[4]<<":"
                <<row[5]<<":"
                <<status<<"\n";
        }
        else{
            fout<<row[0]<<":"
                <<row[1]<<":"
                <<row[2]<<":"
                <<row[3]<<":"
                <<row[4]<<":"
                <<row[5]<<":"
                <<row[6]<<"\n";
        }
    }
    fin.close();
    fout.close();
    string soldfile = "retailers.csv";
    string snewfile = "retailersnew.csv";
    char* oldfile = &soldfile[0];
    char* newfile = &snewfile[0];
    remove(oldfile);
    rename(newfile, oldfile);
    cout<<"\nStatus updated to : "<<(stat ? "Open":"Closed")<<endl;
}

