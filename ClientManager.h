//
// Created by vudan on 1/2/2025.
//

#ifndef CTDL_CLIENTMANAGER_H
#define CTDL_CLIENTMANAGER_H


#include "Client.h"
#include "LinkedList.h"

class ClientManager {
private:
    LinkedList<Client> clients;
    ClientManager();
    static ClientManager* instance;
public:
    static ClientManager* getInstance();
    int addClient();
    int removeClient();
    void displayClient();
    void findClient();
    Client findByPhone(string phone);
};


#endif //CTDL_CLIENTMANAGER_H
