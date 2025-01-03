#include <iostream>
#include "MedicineManager.h"
#include "ClientManager.h"
#include "OrderManager.h"
using namespace std;

void menu1(){
    cout << "======== Quản lý khách hàng ========" << endl;
    cout << "1. Thêm" << endl;
    cout << "2. Xóa" << endl;
    cout << "3. Tìm kiếm" << endl;
    cout << "0. Thoát" << endl;
    cout << "====================================" << endl;
    cout << "Chọn một tùy chọn: ";
}
void menu2(){
    cout << "======== Quản lý thuốc ========" << endl;
    cout << "1. Thêm" << endl;
    cout << "2. Xóa" << endl;
    cout << "3. Chỉnh sửa" << endl;
    cout << "4. Tìm kiếm" << endl;
    cout << "0. Thoát" << endl;
    cout << "================================" << endl;
    cout << "Chọn một tùy chọn: ";
}
void menu3(){
    cout << "======== Giao dịch và thống kê ========" << endl;
    cout << "1. Tạo mới giao dịch" << endl;
    cout << "2. Thông kê theo tháng" << endl;
    cout << "3. Tìm kiếm" << endl;
    cout << "0. Thoát" << endl;
    cout << "================================" << endl;
    cout << "Chọn một tùy chọn: ";
}





int main(){

    MedicineManager* medicineManager = MedicineManager::getInstance();
    ClientManager* clientManager = ClientManager::getInstance();
    OrderManager* orderManager = OrderManager::getInstance();
    int choice;
    do{
        menu:
        cout << "======== MENU ========" << endl;
        cout << "1. Quản lý người dùng" << endl;
        cout << "2. Quản lý thuốc" << endl;
        cout << "3. Giao dịch và thống kê" << endl;
        cout << "0. Thoát" << endl;
        cout << "======================" << endl;
        cout << "Chọn một tùy chọn: ";

        cin >> choice;

        switch (choice) {
            case 1:
                int choice1;
                do{
                    cout << "====================================================" << endl;
                    clientManager->displayClient();
                    cout << "====================================================" << endl;
                    menu1();
                    cin >> choice1;
                    switch (choice1) {
                        case 1:
                            clientManager->addClient();
                            break;
                        case 2:
                            clientManager->removeClient();
                            break;
                        case 3:
                            clientManager->findClient();
                            break;
                        case 0:
                            goto menu;
                        default: break;
                    }
                }while(choice!=0);
                break;
            case 2:
                int choice2;
                do{
                    cout << "====================================================" << endl;
                    medicineManager->displayMedicines();
                    cout << "====================================================" << endl;
                    menu2();
                    cin >> choice2;
                    switch (choice2) {
                        case 1:
                            medicineManager->addMedicine();
                            break;
                        case 2:
                            medicineManager->removeMedicine();
                            break;
                        case 3:
                            medicineManager->updateMedicine();
                            break;
                        case 4:
                            medicineManager->findMedicine();
                            break;
                        case 0:
                            goto menu;
                        default: break;
                    }
                }while(choice!=0);
                break;
            case 3:
                int choice3;
                do{
                    cout << "====================================================" << endl;
                    orderManager->displayOrder();
                    cout << "====================================================" << endl;
                    menu3();
                    cin >> choice3;
                    switch (choice3) {
                        case 1:
                            orderManager->addOrder();
                            break;
                        case 2:
                            orderManager->statistics();
                            break;
                        case 3:
                            orderManager->findOrderByClient();
                            break;
                        case 0:
                            goto menu;
                        default: break;
                    }
                }while(choice!=0);
                break;
            case 0:
                cout << "Thoát chương trình." << endl;
                break;
            default:
                cout << "Lựa chọn không hợp lệ, vui lòng chọn lại!" << endl;
        }
        cout << endl;
    }while(choice != 0);

    return 0;
}

