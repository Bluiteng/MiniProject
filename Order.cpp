#include "Order.h"
#include <iostream>
#include <fstream>
using namespace std;

Order::Order(string name, string lastName, string id, int number)
{
    studentName = name;
    studentLastName = lastName;
    studentID = id;
    orderNumber = number;
    status = "In Progress";
    itemsHead = nullptr;
    next = nullptr;
}

Order::~Order()
{
    OrderItem* temp;
    while (itemsHead)
    {
        temp = itemsHead;
        itemsHead = itemsHead->next;
        delete temp;
    }
}

void Order::addItem(string name, double price)
{
    OrderItem* newItem = new OrderItem(name, price);
    if (!itemsHead)
    {
        itemsHead = newItem;
    }
    else 
    {
        OrderItem* temp = itemsHead;
        while (temp->next)
        {
            temp = temp->next;
            temp->next = newItem;
        }
    }
}

void Order::removeItem(string name)
{
    if (!itemsHead)
    {
        return;
    }

    if (itemsHead->name == name)
    {
        OrderItem* temp = itemsHead;
        itemsHead = itemsHead->next;
        delete temp;
        return;
    }

    OrderItem* temp = itemsHead;
    while (temp->next && temp->next->name != name)
    {
        temp = temp->next;
    }

    if (temp->next)
    {
        OrderItem* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
}

void Order::displayOrder()
{
    cout << endl << "Order_Number: " << orderNumber
        << endl << "Name: " << studentName << " " << studentLastName
        << endl << "Student Id: " << studentID
        << endl <<"Status: " << status << endl <<"Items: \n";

    OrderItem* temp = itemsHead;
    double total = 0;
    while (temp)
    {
        cout << " - " << temp->name << " (" << temp->price << " Rials)" << endl;
        total += temp->price;
        temp = temp->next;
    }
    cout << " Total Price: " << total << " Rials" << endl;
}

void Order::saveToFile(ofstream& out)
{
    out << studentName << "," << studentLastName << "," << studentID << ","
        << orderNumber << "," << status;

    OrderItem* temp = itemsHead;
    while (temp)
    {
        out << "," << temp->name << ":" << temp->price;
        temp = temp->next;
    }
    out << endl;
}
