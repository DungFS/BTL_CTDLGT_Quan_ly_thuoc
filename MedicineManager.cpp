//
// Created by vudan on 1/1/2025.
//

#include "MedicineManager.h"
#include "iostream"
#include "Data.h"


using namespace std;
// Khởi tạo instance là nullptr
MedicineManager* MedicineManager::instance = nullptr;
MedicineManager *MedicineManager::getInstance() {
    if (instance == nullptr) {
        instance = new MedicineManager();  // Tạo đối tượng duy nhất khi chưa có
    }
    return instance;
}
MedicineManager::MedicineManager() {
    for(int i=0;i<20;i++){
        medicines.append(Data::medicines[i]);
    }
};

int MedicineManager::addMedicine() {
    Medicine medicine = Medicine();
    cout << "Enter id: ";
    cin >> medicine.id;
    while (findById(medicine.id).id == medicine.id) {
        cout << "Id already exists" << endl;
        cout << "Enter id: ";
        cin >> medicine.id;
    }
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, medicine.name);
    cout << "Enter date expire: ";
    cin >> medicine.dateExpire;
    cout << "Enter price: ";
    cin >> medicine.price;
    cout << "Enter quantity: ";
    cin >> medicine.quantity;

    if (medicines.append(medicine)) {
        cout << "Medicine added successfully!" << endl;
        return 1;
    } else {
        cout << "Unknown error" << endl;
        return 0;
    }
}

int MedicineManager::removeMedicine() {
    Medicine medicine = Medicine();
    cout << "Enter id: ";
    cin >> medicine.id;
    if (medicines.remove(medicine)) {
        cout << "Medicine removed successfully!" << endl;
        return 1;
    } else {
        cout << "Unknown error" << endl;
        return 0;
    }
}

int MedicineManager::updateMedicine() {
    int i_id;
    cout << "Enter id: ";
    cin >> i_id;

    Medicine medicine = findById(i_id);
    while (medicine.id != i_id){
        cout <<"Id not found"<<endl;
        cout << "Enter id: ";
        cin >> i_id;
        medicine = findById(i_id);
    }
    Medicine newMedicine = Medicine();
    newMedicine.id = i_id;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, newMedicine.name);
    cout << "Enter date expire: ";
    cin >> newMedicine.dateExpire;
    cout << "Enter price: ";
    cin >> newMedicine.price;
    cout << "Enter quantity: ";
    cin >> newMedicine.quantity;
    if (medicines.update(medicine, newMedicine)) {
        cout << "Medicine updated successfully!" << endl;
        return 1;
    } else {
        cout << "Unknown error" << endl;
        return 0;
    }
}

int MedicineManager::updateQuantity(int q,Medicine medicine) {
    Medicine new_medicine = medicine;
    new_medicine.quantity -= q;
    if(new_medicine.quantity<0){
        cout<<"not enough"<<endl;
        return 0;
    }
    medicines.update(medicine,new_medicine);
    return 1;
}

Medicine MedicineManager::findById(int id) {
    Node<Medicine> *current = medicines.head;
    while (current != nullptr) {
        if (current->data.id == id) {
            return current->data;
        }
        current = current->next;
    }
    return Medicine();
}

void MedicineManager::displayMedicines() {
    medicines.display();
}

void MedicineManager::findMedicine() {
    int i_id;
    cout << "Enter id: ";
    cin >> i_id;
    Medicine medicine = findById(i_id);
    if(medicine.id == i_id){
        cout<<medicine<<endl;
    } else{
        cout<<"Medicine not found"<<endl;
    }
}


