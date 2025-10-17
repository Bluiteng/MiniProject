#pragma once
#ifndef ORDER_H
#define ORDER_H

#include <string>
#include "OrderItem.h"
using namespace std;

class Order 
{

public:
    string studentName;
    string studentLastName;
    string studentID;
    int orderNumber;
    string status;

    OrderItem* itemsHead;
    Order* next;

    Order(string name, string lastName, string id, int number);
    ~Order();

    void addItem(string name, double price);
    void removeItem(string name);
    void displayOrder();
    void saveToFile(ofstream& out);
};

#endif
