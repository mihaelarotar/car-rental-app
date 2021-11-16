#include "car.h"
#include "crud.h"
#include "client.h"
#include <vector>
#include <string>
#include <ctime>
#include <exception>
#include <iostream>
#include <fstream>
using namespace std;

#define NULL_Client Client("");

class CarRepo : public CrudRepository<Car> {
private:
    vector<Car> carList;
    vector<Client> clients;
public:
    // constructor
    CarRepo() { this->readFromFile(); }
    // cannot copy objects of type CarRepo
    CarRepo(const CarRepo&) = delete;
    // checks if data is valid
    void validate(const Car& c) {
        if (c.getBrand().size() == 0 || c.getModel().size() == 0 || c.getFuel().size() == 0)
            throw exception();
        if (c.getID() < 0)
            throw exception();
        if (c.getPrice() < 0)
            throw exception();
        if (c.getKm() < 0)
            throw exception();
        if (c.getPerformance() < 0)
            throw exception();
        struct tm newtime;
        time_t now = time(0);
        localtime_s(&newtime, &now);
        if (c.getYear() < 1900 || c.getYear() > newtime.tm_year + 1900)
            throw exception();
    }
    // returns the position of car in list or -1 if there is no such car in list
    int findOne(int id) {
        for (unsigned int i = 0; i < this->carList.size(); i++) {
            if (this->carList[i].getID() == id)
                return i;
        }
        return -1;
    }
    void save(const Car& c) {
        validate(c);
        if (findOne(c.getID()) != -1)
            throw exception();
        else
            this->carList.push_back(c);
        this->writeToFile();
    }
    void del(int id) {
        int i = findOne(id);
        if (i == -1)
            throw exception();
        else
            this->carList.erase(this->carList.begin() + i);
        this->writeToFile();
    }
    void update(const Car& c) {
        validate(c);
        int i = findOne(c.getID());
        if (i == -1)
            throw exception();
        else
            this->carList[i] = c;
        this->writeToFile();
    }
    const vector<Car>& getAll() { return carList; }

    void readFromFile() {
        fstream file;
        file.open("cars.csv", ios::in);
        string line;
        string delimiter = ",";
        while (getline(file, line)) {
            // first value is id
            string idString = line.substr(0, line.find(delimiter));
            int id = stoi(idString); // conversion string to int
            line.erase(0, line.find(delimiter) + delimiter.length());
            // second value is brand
            string brand = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            // third value is model
            string model = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());

            string yearString = line.substr(0, line.find(delimiter));
            int year = stoi(yearString); // conversion string to int
            line.erase(0, line.find(delimiter) + delimiter.length());

            string kmString = line.substr(0, line.find(delimiter));
            int km = stoi(kmString); // conversion string to int
            line.erase(0, line.find(delimiter) + delimiter.length());

            string priceString = line.substr(0, line.find(delimiter));
            int price = stoi(priceString); // conversion string to int
            line.erase(0, line.find(delimiter) + delimiter.length());

            string perfString = line.substr(0, line.find(delimiter));
            int perf = stoi(perfString); // conversion string to int
            line.erase(0, line.find(delimiter) + delimiter.length());

            string fuel = line.substr(0, line.find(delimiter));
            //line.erase(0, line.find(delimiter) + delimiter.length());

            Car car{ id, brand, model, year, km, price, perf, fuel };
            this->save(car);
            //this->carList.push_back(car);
        }
        file.close();
    }

    void writeToFile() {
        fstream file;
        file.open("cars.csv", ios::out);
        for (const Car& car : this->carList)
            file << car.getID() << "," << car.getBrand() << "," << car.getModel() << "," << car.getYear()
            << "," << car.getKm() << "," << car.getPrice() << "," <<
            car.getPerformance() << "," << car.getFuel() << endl;
        file.close();
    }

    int findClient(string name) {
        for (unsigned int i = 0; i < this->clients.size(); i++) {
            if (this->clients[i].getName() == name)
                return i;
        }
        return -1;
    }

    void addClient(const Client& client) {
        if (client.getName().size() == 0)
            throw exception();
        this->clients.push_back(client);
        this->writeToClients();
    }

    void writeToClients() {
        fstream file1;
        file1.open("clients.txt", ios::out);
        for (const Client& client : this->clients) {
            file1 << client.getName() << "\n\t";
            for (const Car& car : getFavouritesList(client.getName()))
                file1 << car.getID() << "," << car.getBrand() << "," << car.getModel() << "\n\t";
        }
        file1.close();
    }

    void updateClient(const Client& c) {
        int i = findClient(c.getName());
        this->clients[i] = c;
        this->writeToClients();
    }

    void addToFavourites(int id, string clientName) {
        if (findOne(id) == -1)
            throw exception();

        for (const Car& c : getFavouritesList(clientName)) {
            if (c.getID() == id)
                throw exception();
        }
        auto car = this->carList[findOne(id)];
        auto client = this->clients[findClient(clientName)];
        client.addFavourite(car);
        updateClient(client);
    }

    vector<Car> getFavouritesList(string clientName) {
        return this->clients[findClient(clientName)].getFavourites();
    }
};

