#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>

class Car {
private:
    std::string brand;
    std::string model;
    int year;

public:
    Car(std::string brand, std::string model, int year); // 构造函数
    void display() const; // 用于显示汽车信息的方法
};

#endif
