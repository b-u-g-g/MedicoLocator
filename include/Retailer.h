#ifndef RETAILER_H
#define RETAILER_H
#include <string>

using namespace std;

class Retailer
{
    public:
        Retailer();
        void Register();
        void Login();
        void addNew();
        void updateStock();
        void updateStatus();
    private:
        string name;
        string email;
        string username;
        string password;
        string address;
        string dir = ".\\Retailers\\";
        int pincode;
        bool status;
};

#endif // RETAILER_H
