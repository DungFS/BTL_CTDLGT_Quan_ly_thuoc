//
// Created by vudan on 1/1/2025.
//

#ifndef CTDL_MEDICINE_H
#define CTDL_MEDICINE_H
#include "string"
using namespace std;

class Medicine {
public:
    int id;
    string name;
    double price;
    string dateExpire;
    int quantity;
    Medicine();
    Medicine(int i_id,string s_name,double d_price,string s_dateExpire,int i_quantity);
    // Toán tử in (<<)
    friend ostream& operator<<(ostream& os, const Medicine& medicine);

    // Toán tử so sánh (==)
    bool operator==(const Medicine& other) const;
};


#endif //CTDL_MEDICINE_H
