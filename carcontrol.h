#ifndef CARCONTROL_H
#define CARCONTROL_H
#pragma once
#include "carrepo.cpp"
#include <string>
#include <vector>
#include <functional>
#include <iostream>
using namespace std;

class CarControl {
private:
    CarRepo& repo;
public:
    // constructor
    CarControl(CarRepo& _repo) : repo(_repo) {}
    // cannot copy objects of type CarControl
    CarControl(const CarControl& control) = delete;

    void addClient(const Client& client) {
        //cout << "Client added\n";
        repo.addClient(client);
    }
    // adds car to favourites
    void addToFavourites(int id, string clientName) {
        repo.addToFavourites(id, clientName);
    }
    // shows all cars
    const vector<Car>& getAll() { return repo.getAll(); }
    // shows favourites
    vector<Car> getFavourites(string clientName) {
        return repo.getFavouritesList(clientName);
    }
    // adds car to list
    void addCar(Car c) { repo.save(c); }
    // removes car from list
    void removeCar(int id) { repo.del(id); }
    // updates car in list
    void updateCar(Car c) { repo.update(c); }
    // shows all cars of this brand
    vector<Car> getBrand(string brand);
    // shows all cars of this model
    vector<Car> getModel(string model);
    /* general filter function
    the function ist bool, gets a car as parameter and returns true if car has given property
    otherwise false*/
    vector<Car> generalFilter(function <bool(const Car&)> fct);
    // shows all cars with registration year older than the given year
    vector<Car> filterOlderYear(int year);
    // shows all cars with registration year newer than the given year
    vector<Car> filterNewerYear(int year);
    // shows all cars with number of km smaller than the given number
    vector<Car> filterByKm(int km);
    // sorts cars by price (ascending order)
    vector<Car> sortByPrice();
};




#endif // CARCONTROL_H
