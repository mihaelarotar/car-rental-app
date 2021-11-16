#ifndef CLIENT_H
#define CLIENT_H
#pragma once
#include <string>
#include <vector>
#include "car.h"
using namespace std;

class Client {
private:
    string fullName;
    vector<Car> favouritesList;
public:
    // constructor
    Client(string _fullName) : fullName{ _fullName } {}
    // getters
    string getName() const { return fullName; }
    void addFavourite(Car car) { this->favouritesList.push_back(car); }
    //vector<Car> getFavourites() const { return favouritesList; }
    const vector<Car>& getFavourites() { return favouritesList; }

    bool operator==(const Client& other) { return this->fullName == other.fullName; }

    Client& operator=(const Client& client) {
        if (this == &client)
            return *this;
        this->fullName = client.fullName;
        this->favouritesList = client.favouritesList;
        return *this;
    }
};
#endif // CLIENT_H

