cmake_minimum_required(VERSION 3.31.3)
project(ctdl)

set(CMAKE_CXX_STANDARD 17)

add_executable(ctdl main.cpp Client.cpp Client.h Medicine.cpp Medicine.h Order.cpp Order.h LinkedList.cpp LinkedList.h MedicineManager.cpp MedicineManager.h ClientManager.cpp ClientManager.h OrderManager.cpp OrderManager.h Data.cpp Data.h)
