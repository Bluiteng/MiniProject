#include <iostream>
#include "RestaurantManager.h"
using namespace std;

int main()
{
    RestaurantManager manager;
    int choice;

    while (true)
    {

        cout << endl <<"----- Restaurant Managment system -----" << endl;
        cout << "1. Menu" << endl;
        cout << "2. New Order" << endl;
        cout << "3. Order_Delivered" << endl;
        cout << "4. Cancel_Order" << endl;
        cout << "5. Change_Order" << endl;
        cout << "6. Review" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
        case 1: 

            manager.showMenu();
            break;

        case 2:

            manager.newOrder();
            break;

        case 3:
            
            manager.markDelivered();
            break;

        case 4:

            manager.cancelOrder();
            break;

        case 5:
            
            manager.changeOrder();
            break;

        case 6:
            
            manager.reviewAll();
            break;

        case 0:

            return 0;

        default: 

            cout << "Invaild Choice" << endl;
        }
    }
}
