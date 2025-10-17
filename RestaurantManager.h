#pragma once
#ifndef RESTAURANTMANAGER_H
#define RESTAURANTMANAGER_H

#include "Order.h"
#include <string>
using namespace std;

class RestaurantManager
{
private:
    Order* head;
    int orderCounter;

public:
    RestaurantManager();
    ~RestaurantManager();

    void loadFromFile();
    void saveToFile();

    void showMenu();
    void newOrder();
    void markDelivered();
    void cancelOrder();
    void changeOrder();
    void reviewAll();
};

#endif
