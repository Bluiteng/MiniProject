#include "OrderItem.h"

OrderItem::OrderItem(string name, double price)
{
    this->name = name;
    this->price = price;
    this->next = nullptr;
}
