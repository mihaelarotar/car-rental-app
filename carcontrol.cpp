#include "carcontrol.h"
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;

vector<Car> CarControl::generalFilter(function<bool(const Car&)> fct) {
    vector<Car> newList;
    for (const Car& car : repo.getAll()) {
        if (fct(car))
            newList.push_back(car);
    }
    return newList;
}

vector<Car> CarControl::getBrand(string brand) {
    return generalFilter([brand](const Car& c) ->bool {
        return c.getBrand() == brand; });
}

vector<Car> CarControl::getModel(string model) {
    return generalFilter([model](const Car& c) {
        return c.getModel() == model; });
}

vector<Car> CarControl::filterByKm(int km) {
    return generalFilter([km](const Car& c) {
        return c.getKm() <= km; });
}

vector<Car> CarControl::filterOlderYear(int year) {
    return generalFilter([year](const Car& c) {
        return c.getYear() < year; });
}

vector<Car> CarControl::filterNewerYear(int year) {
    return generalFilter([year](const Car& c) {
        return c.getYear() >= year; });
}

vector<Car> CarControl::sortByPrice() {
    auto copyAll = repo.getAll();
    sort(copyAll.begin(), copyAll.end(), cmpPrice);
    return copyAll;
}
