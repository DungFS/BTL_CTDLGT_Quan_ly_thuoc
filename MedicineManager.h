//
// Created by vudan on 1/1/2025.
//

#ifndef CTDL_MEDICINEMANAGER_H
#define CTDL_MEDICINEMANAGER_H
#include "LinkedList.h"
#include "Medicine.h"

class MedicineManager {
private:
    LinkedList<Medicine> medicines;
    MedicineManager();
    static MedicineManager* instance;
public:
    static MedicineManager* getInstance();
    int addMedicine();
    int removeMedicine();
    int updateMedicine();
    int updateQuantity(int q,Medicine medicine);
    Medicine findById(int id);
    void displayMedicines();

    void findMedicine();
};


#endif //CTDL_MEDICINEMANAGER_H
