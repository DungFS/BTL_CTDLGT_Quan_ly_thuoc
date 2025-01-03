//
// Created by vudan on 1/2/2025.
//

#include "OrderManager.h"
#include "ClientManager.h"
#include "MedicineManager.h"
#include "iostream"
#include "Data.h"

using namespace std;


OrderManager *OrderManager::instance = nullptr;

OrderManager::OrderManager() {
    for(int i=0;i<50;i++){
        orders.append(Data::orders[i]);
    }
}

OrderManager *OrderManager::getInstance() {
    if (instance == nullptr) {
        instance = new OrderManager();
    }
    return instance;
}

int OrderManager::addOrder() {
    int i_id;
    cout << "Enter Id: ";
    cin >> i_id;
    string s_phone;
    cout << "Enter phone: ";
    cin >> s_phone;
    Client client = ClientManager::getInstance()->findByPhone(s_phone);
    if (client.phone != s_phone) {
        cout<<"Client not exists"<<endl;
        return 0;
    }
    int size;
    cout<<"Enter quantity of medicine: ";
    cin>>size;
    Item* items = new Item[size];
    for(int i=0;i<size;i++){
        int id_med;
        cout<<"Enter id medicine: ";
        cin>>id_med;
        int q;
        cout<<"Enter quantity: ";
        cin>>q;
        Medicine medicine = MedicineManager::getInstance()->findById(id_med);
        if(medicine.id != id_med){
            cout<<"Medicine not found"<<endl;
            return 0;
        }
        if(!MedicineManager::getInstance()->updateQuantity(q,medicine)){
            return 0;
        }
        items[i].medicine = medicine;
        items[i].quantity = q;
    }
    if (orders.append(Order(i_id,client,items,size))) {
        cout << "Orders added successfully!" << endl;
        return 1;
    } else {
        cout << "Unknown error" << endl;
        return 0;
    }
}


void OrderManager::displayOrder() {
    orders.display();
}

void OrderManager::findOrderByClient() {
    string s_phone;
    cout<<"Enter phone: ";
    cin>>s_phone;
    Node<Order> *tmp = orders.head;
    while (tmp!= nullptr){
        if(tmp->data.client.phone == s_phone){
            cout<<tmp->data<<endl;
        }
        tmp = tmp->next;
    }
}

void OrderManager::statistics() {
    string s_date;
    cout<<"Nhập tháng, năm: ";
    cin>>s_date;
    double total = 0;
    Node<Order> *tmp = orders.head;
    while (tmp!= nullptr){
        if(tmp->data.date.compare(0,7,s_date)==0){
            total+=tmp->data.total;
        }
        tmp = tmp->next;
    }
    cout<<"Tổng tiền bán ra trong "<<s_date<<" là: "<<total<<"$"<<endl;
}


