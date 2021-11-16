#include "car.h"

bool Car::operator==(const Car& c) {
    return this->carID == c.getID();
}

Car& Car::operator=(const Car& car) {
    if (this == &car)
        return *this;
    this->carID = car.carID;
    this->brand = car.brand;
    this->model = car.model;
    this->year = car.year;
    this->km = car.km;
    this->price = car.price;
    this->performance = car.performance;
    this->fuel = car.fuel;
    return *this;
}

bool cmpPrice(const Car& c, const Car& other) {
    return c.getPrice() < other.getPrice();
}
