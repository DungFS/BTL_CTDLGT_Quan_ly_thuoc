//
// Created by vudan on 1/1/2025.
//

#include "Client.h"
#include "iostream"

Client::Client(string s_name, string s_phone, string s_address) {
    name = s_name;
    phone = s_phone;
    address = s_address;
}

ostream &operator<<(ostream &os, const Client &client) {
    os << "Name: " << client.name << ", "
       << "Phone: " << client.phone << ", "
       << "Address: " << client.address;
    return os;
}

bool Client::operator==(const Client &other) const {
    return phone == other.phone;
}

Client::Client() {
    name = "";
    phone = "";
    address = "";
}
