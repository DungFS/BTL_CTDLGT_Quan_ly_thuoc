//
// Created by vudan on 1/1/2025.
//

#include "Order.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
using namespace std;
string getDateNow(){
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm* tm_now = localtime(&now_time);

    // Lưu ngày vào một biến string
    ostringstream oss;
    oss << std::put_time(tm_now, "%Y-%m-%d");
    return oss.str();
}


Order::Order(int i_id,Client c_client, Item *i_items,int i_size) {
    id = i_id;
    client = c_client;
    date = getDateNow();
    size = i_size;
    items = i_items;
    total = 0;
    for(int i=0;i<size;i++){
        total += items[i].quantity*items[i].medicine.price;
    }
}
Order::Order(int i_id,Client c_client,string s_date, Item *i_items,int i_size) {
    id = i_id;
    client = c_client;
    date = s_date;
    size = i_size;
    items = i_items;
    total = 0;
    for(int i=0;i<size;i++){
        total += items[i].quantity*items[i].medicine.price;
    }
}

ostream &operator<<(ostream &os, const Order &order) {
    os <<"id: "<< order.id<<", "
       << "name: "<< order.client.name<<", "
       << "phone: "<<order.client.phone<<", "
       << "date: "<<order.date<<", "
       << "total: "<<order.total<<", "
       <<" details: { ";
    for(int i=0;i<order.size;i++){
        os <<"["<< order.items[i].medicine.name << ", "<<order.items[i].quantity<<"] ";
    }
    os << "}";
    return os;
}

bool Order::operator==(const Order &other) const {
    return id == other.id;
}

Order::Order() {
    id = 0;
    date = "";
    items = nullptr;
    total = 0;
}
