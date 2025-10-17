#include "RestaurantManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

RestaurantManager::RestaurantManager()
{
    head = nullptr;
    orderCounter = 1;
    loadFromFile();
}

RestaurantManager::~RestaurantManager()
{
    saveToFile();
    Order* temp;
    while (head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void RestaurantManager::showMenu()
{
    cout << endl <<"----- Menu -----" <<endl ;
    cout << "1.Pizza (200000)" << endl;
    cout << "2.Hamburger (150000)" << endl;
    cout << "3.Salad (80000)" << endl;
    cout << "4.Water (30000)" << endl;
    cout << "-------------------------" << endl;
}

void RestaurantManager::newOrder()
{
    string name, lastName, id;
    cout << "Name: "; cin >> name;
    cout << "Family_Name: "; cin >> lastName;
    cout << "Student_Id: "; cin >> id;

    Order* newOrder = new Order(name, lastName, id, orderCounter++);

    int choice;

    while (true)
    {
        showMenu();

        cout << "Input Number For Food (0 For Cancalation): ";
        cin >> choice;

        if (choice == 0)
        {
            break;
        }
        switch (choice)
        {

        case 1:
            
            newOrder->addItem("Pizza", 200000); break;

        case 2:
            
            newOrder->addItem("Hambergur", 150000); break;
        case 3:
            
            newOrder->addItem("Salad", 80000); break;
        case 4:
            
            newOrder->addItem("Water", 30000); break;
        default:
            
            cout << "Inavalid Choice" << endl ;
        }
    }

    if (!head)
    {
        head = newOrder;
    }
    else
    {
        Order* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newOrder;
    }

    cout << "Order With Number  " << newOrder->orderNumber << " Noted." << endl;
    saveToFile();
}

void RestaurantManager::markDelivered()
{
    int num;
    cout << "Order Number: "; cin >> num;

    for (Order* temp = head; temp; temp = temp->next) 
    {
        if (temp->orderNumber == num)
        {
            temp->status = "Delivered";
            cout << "Order Delivered." << endl;
            saveToFile();
            return;
        }
    }
    cout << "Order Not Found" << endl ;
}

void RestaurantManager::cancelOrder()
{
    int num;
    cout << "Oder Number: "; cin >> num;

    for (Order* temp = head; temp; temp = temp->next)
    {
        if (temp->orderNumber == num)
        {
            if (temp->status == "In Progress")
            {
                temp->status = "Canceled";
                cout << "Order Canceled.\n";
                saveToFile();
            }
            else cout << "Cancalation Is Not Possible.\n";
            return;
        }
    }
    cout << "Order Not Found" << endl;
}

void RestaurantManager::changeOrder() {
    int num;
    cout << "Order Number: ";
    cin >> num;

    for (Order* temp = head; temp; temp = temp->next)
    {
        if (temp->orderNumber == num && temp->status == "In Progress")
        {
            int choice;
            cout << "1.Add_Food" << endl << "2.Remove_Food" << endl << "Choice: ";
            cin >> choice;

            if (choice == 1)
            {
                showMenu();
                cout << "New_Item_Number: ";

                int item;
                cin >> item;

                if (item == 1)
                {
                    temp->addItem("Pizza", 200000);
                }
                else if (item == 2)
                {
                    temp->addItem("Hamburger", 150000);

                }
                else if (item == 3)
                {
                    temp->addItem("Salad", 80000);
                }
                else if (item == 4)
                {
                    temp->addItem("Water", 30000);
                }
            }
            else if (choice == 2) 
            {
                string item;
                cout << "Food_Name_For_Removing: ";

                cin >> item;
                temp->removeItem(item);
            }

            saveToFile();
            cout << "Order Updated." << endl;
            return;
        }
    }
    cout << "In_Progress_Order_Not_Found" << endl;
}

void RestaurantManager::reviewAll()
{
    for (Order* temp = head; temp; temp = temp->next)
        temp->displayOrder();
}

void RestaurantManager::saveToFile()
{
    ofstream out("orders.txt");
    for (Order* temp = head; temp; temp = temp->next)
        temp->saveToFile(out);
    out.close();
}

void RestaurantManager::loadFromFile()
{
    ifstream in("orders.txt");
    if (!in.is_open()) return;

    string line;
    while (getline(in, line))
    {
        stringstream ss(line);
        string name, last, id, numStr, status;
        getline(ss, name, ',');
        getline(ss, last, ',');
        getline(ss, id, ',');
        getline(ss, numStr, ',');
        getline(ss, status, ',');

        int num = stoi(numStr);
        Order* o = new Order(name, last, id, num);
        o->status = status;
        orderCounter = max(orderCounter, num + 1);

        string item;
        while (getline(ss, item, ','))
        {
            size_t pos = item.find(':');
            if (pos != string::npos)
            {
                string n = item.substr(0, pos);
                double p = stod(item.substr(pos + 1));
                o->addItem(n, p);
            }
        }

        if (!head)
        {
            head = o;
        }
        else 
        {
            Order* temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = o;
        }
    }

    in.close();
}
