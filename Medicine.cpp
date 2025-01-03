//
// Created by vudan on 1/1/2025.
//

#include "Medicine.h"
#include "iostream"

Medicine::Medicine(int i_id, string s_name, double d_price, string s_dateExpire, int i_quantity) {
    id = i_id;
    name = s_name;
    price = d_price;
    dateExpire = s_dateExpire;
    quantity = i_quantity;
}

ostream &operator<<(ostream &os, const Medicine &medicine) {
    os << "ID: " << medicine.id << ", "
       << "Name: " << medicine.name << ", "
       << "Price: " << medicine.price << ", "
       << "Expiration Date: " << medicine.dateExpire << ", "
       << "Quantity: " << medicine.quantity;
    return os;
}

bool Medicine::operator==(const Medicine &other) const {
    return id == other.id;
}
Medicine::Medicine() : id(0), name(""), price(0.0), dateExpire(""), quantity(0) {}