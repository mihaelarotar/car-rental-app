#ifndef CAR_H
#define CAR_H


#pragma once
#include <string>
using std::string;

class Car {
private:
    int carID;
    string brand;
    string model;
    int year;
    int km;
    int price;
    int performance;
    string fuel;
public:
    // constructor
    Car(int _carID, string _brand, string _model, int _year, int _km, int _price, int _performance, string _fuel) : carID{ _carID },
        brand{ _brand }, model{ _model }, year{ _year }, km{ _km }, price{ _price }, performance{ _performance }, fuel{ _fuel } {}
    // getters
    int getID() const { return carID; }
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    int getKm() const { return km; }
    int getPrice() const { return price; }
    int getPerformance() const { return performance; }
    string getFuel() const { return fuel; }
    // comparison operator
    bool operator==(const Car& c);
    // assignment operator
    Car& operator=(const Car& car);
};

// compares two object of class car by price
bool cmpPrice(const Car& c, const Car& other);
#endif // CAR_H
