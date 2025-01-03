//
// Created by vudan on 1/2/2025.
//

#ifndef CTDL_ORDERMANAGER_H
#define CTDL_ORDERMANAGER_H
#include "LinkedList.h"
#include "Order.h"

class OrderManager {
private:
    LinkedList<Order> orders;
    OrderManager();
    static OrderManager* instance;
public:
    static OrderManager* getInstance();
    int addOrder();
    void displayOrder();
    void findOrderByClient();
    void statistics();
};


#endif //CTDL_ORDERMANAGER_H
