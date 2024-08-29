#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <bits/stdc++.h>

using namespace std;

struct cartItem{
    string itemID;
    string itemname;
    float price;
    int quantity;
};

class Customer
{
    public:
        Customer();
        void Register();
        void Login();
        void getStocksheet();
        void addToCart();
        void removefromCart();
        void editCart();
        void viewCart();
        void connect_retailer();
        void CheckOut();
    private:
        string name;
        string email;
        string username;
        string password;
        string address;
        string r_uname;
        vector<cartItem> Cart;
};

#endif // CUSTOMER_H
