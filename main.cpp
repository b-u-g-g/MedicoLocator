#include <iostream>
#include <Retailer.h>
#include <string>
#include <Customer.h>
#include <HashTable.h>

using namespace std;

int main(){
    HashTable H;
    H.readFile();
    Retailer R;
    Customer C;
    cout <<"WELCOME TO MEDICATION TRACKER"<<endl;
    int choice;
    cout<<"Enter your choice :\n\n1 - Login as Retailer \n2 - Login as Customer\n\nYOUR CHOICE : ";
    cin>>choice ;
    cout<<"-------------------------"<<endl;
    switch (choice){
        case 1 :cout <<"1 - Create Account\n2 - Sign in\n\nENTER CHOICE : ";
                cin>>choice;
                cout<<endl;
                switch(choice){
                    case 1:
                    R.Register();
                    cout<<endl;
                    while(1){
                        cout << "\n\nChoose operation :\n\n1 - Add Stock \n2 - Update Stock\n3 - Update Shop Open or Close Status\n4 - Exit\n\nYour Choice : ";
                        cin>>choice;
                        cout<<endl;
                        switch(choice){
                            case 1:
                            R.addNew();
                            break;

                            case 2:
                            R.updateStock();
                            break;

                            case 3:
                            R.updateStatus();
                            break;

                            case 4:
                            exit(0);
                            break;
                        }
                    }
                    break;
                    case 2:
                    R.Login();
                    while(1){
                        cout << "\n\nChoose operation :\n\n1 - Add Stock \n2 - Update Stock\n3 - Update Shop Open or Close Status\n4 - Exit\n\nYour Choice : ";
                        cin>>choice;
                        cout<<endl;
                        switch(choice){
                            case 1:
                            R.addNew();
                            break;

                            case 2:
                            R.updateStock();
                            break;

                            case 3:
                            R.updateStatus();
                            break;

                            case 4:
                            exit(0);
                            break;
                        }
                  }
            }
                break;

        case 2 :cout<<"1 - Create Account\n2 - Sign in\n\nEnter choice : ";
                cin>>choice;
                cout<<endl;
                switch(choice){
                    case 1:
                    C.Register();
                    while(1){
                        cout<<"\n\nChoose operation :\n\n1 - View Retailers\n2- Connect to retailer\n3 - View Retailer StockSheet \n"
                        <<"4 - Add item to cart\n5 - Update cart item \n"
                        <<"6 - Remove item from cart\n7 - View cart\n8 - Checkout\n9 - Exit"
                        <<"\n\nYour Choice : ";
                        cin>>choice;
                        cout<<endl;
                        switch(choice){
                            case 1:
                            H.printList();
                            break;

                            case 2:
                            C.connect_retailer();
                            break;

                            case 3:
                            C.getStocksheet();
                            break;

                            case 4:
                            C.addToCart();
                            break;

                            case 5:
                            C.editCart();
                            break;

                            case 6:
                            C.removefromCart();
                            break;

                            case 7:
                            C.viewCart();
                            break;

                            case 8:
                            C.CheckOut();
                            break;

                            case 9:
                            exit(0);
                            break;
                        }
                    }

                    break;

                    case 2:
                    C.Login();
                    while(1){
                        cout<<"\n\nChoose operation :\n\n1 - View Retailers\n2- Connect to retailer\n3 - View Retailer StockSheet \n"
                        <<"4 - Add item to cart\n5 - Update cart item \n"
                        <<"6 - Remove item from cart\n7 - View cart\n8 - Checkout\n9 - Exit"
                        <<"\n\nYour Choice : ";
                        cin>>choice;
                        cout<<endl;
                        switch(choice){
                            case 1:
                            H.printList();
                            break;

                            case 2:
                            C.connect_retailer();
                            break;

                            case 3:
                            C.getStocksheet();
                            break;

                            case 4:
                            C.addToCart();
                            break;

                            case 5:
                            C.editCart();
                            break;

                            case 6:
                            C.removefromCart();
                            break;

                            case 7:
                            C.viewCart();
                            break;

                            case 8:
                            C.CheckOut();
                            break;

                            case 9:
                            exit(0);
                            break;
                        }
                    }

                    break;
                }

    }
}
