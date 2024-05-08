#include "car.h"

Car::Car(std::string b, std::string m, int y) : brand(b), model(m), year(y) {}

void Car::display() const {
    std::cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << std::endl;
}
