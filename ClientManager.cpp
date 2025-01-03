//
// Created by vudan on 1/2/2025.
//

#include "ClientManager.h"
#include "iostream"
#include "Data.h"
using namespace std;

ClientManager::ClientManager() {
    for(int i=0;i<21;i++){
        clients.append(Data::clients[i]);
    }
}
ClientManager* ClientManager::instance = nullptr;
ClientManager* ClientManager::getInstance() {
    if (instance == nullptr) {
        instance = new ClientManager();  // Tạo đối tượng duy nhất khi chưa có
    }
    return instance;
}

int ClientManager::addClient() {
    Client client = Client();
    cin.ignore();
    cout<<"Enter name: ";
    getline(cin,client.name);
    cout<<"Enter phone: ";
    cin>>client.phone;
    cin.ignore();
    cout<<"Enter address: ";
    getline(cin,client.address);
    if(findByPhone(client.phone).phone == client.phone){
        cout<<"Phone already exists"<<endl;
        return 0;
    }
    if (clients.append(client)) {
        cout << "Client added successfully!" << endl;
        return 1;
    } else {
        cout << "Unknown error" << endl;
        return 0;
    }
    return 0;
}

int ClientManager::removeClient() {
    Client client = Client();
    cout<<"Enter phone: ";
    cin>>client.phone;
    if (clients.remove(client)) {
        cout << "Client removed successfully!" << endl;
        return 1;
    } else {
        cout << "Unknown error" << endl;
        return 0;
    }
}

void ClientManager::displayClient() {
    clients.display();
}

Client ClientManager::findByPhone(string phone) {
    Node<Client> *current = clients.head;
    while (current != nullptr) {
        if (current->data.phone == phone) {
            return current->data;
        }
        current = current->next;
    }
    return Client();
}

void ClientManager::findClient() {
    string s_phone;
    cout<<"Enter phone: ";
    cin>>s_phone;
    Client client = findByPhone(s_phone);
    if (client.phone == "") {
        cout << "Client not found" << endl;
    } else {
        cout << client << endl;
    }
}


