#pragma once
#ifndef ORDERITEM_H
#define ORDERITEM_H

#include <string>
using namespace std;

class OrderItem
{

public:

    string name;
    double price;
    OrderItem* next;

    OrderItem(string name, double price);
};

#endif
