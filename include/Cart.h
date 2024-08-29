#ifndef CART_H
#define CART_H
#include <bits/stdc++.h>

using namespace std;

struct cartItem{
    string ItemID;
    string ItemName;
    float price;
};

class Cart
{
    public:
        Cart();
    private:
        vector<cartItem> cart;
};

#endif // CART_H
