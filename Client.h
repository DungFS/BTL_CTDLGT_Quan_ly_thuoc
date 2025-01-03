//
// Created by vudan on 1/1/2025.
//

#ifndef CTDL_CLIENT_H
#define CTDL_CLIENT_H
#include "string"
using namespace std;

class Client {
public:
    string name;
    string phone;
    string address;
    Client();
    Client(string s_name,string s_phone,string s_address);
    // Toán tử in (<<)
    friend ostream& operator<<(ostream& os, const Client& client);

    // Toán tử so sánh (==)
    bool operator==(const Client& other) const;
};


#endif //CTDL_CLIENT_H
