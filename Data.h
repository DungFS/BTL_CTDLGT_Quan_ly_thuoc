//
// Created by vudan on 1/2/2025.
//

#ifndef CTDL_DATA_H
#define CTDL_DATA_H
#include "Medicine.h"
#include "Client.h"
#include "Order.h"

class Data {
public:
    static Medicine* medicines;
    static Client* clients;
    static Order* orders;
};


#endif //CTDL_DATA_H
