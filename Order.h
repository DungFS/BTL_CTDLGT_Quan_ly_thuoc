//
// Created by vudan on 1/1/2025.
//

#ifndef CTDL_ORDER_H
#define CTDL_ORDER_H
#include "string"
#include "medicine.h"
#include "Client.h"

using namespace std;

struct Item{
    Medicine medicine;
    int quantity;
    Item(Medicine m_medicine,int i_quantity){
        medicine = m_medicine;
        quantity = i_quantity;
    }
    Item(){
        quantity = 0;
    };
};
class Order {
public:
    int id;
    Client client;
    string date;
    int size;
    Item* items;
    double total;
    Order(int i_id,Client c_client,Item* i_items,int i_size);
    Order(int i_id,Client c_client,string s_date,Item* i_items,int i_size);
    Order();
    // Toán tử in (<<)
    friend ostream& operator<<(ostream& os, const Order& order);

    // Toán tử so sánh (==)
    bool operator==(const Order& other) const;
};


#endif //CTDL_ORDER_H
