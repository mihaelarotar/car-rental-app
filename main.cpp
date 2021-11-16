#include "mainwindow_login.h"
#include <QApplication>

void initialList(CarControl& control) {
    Car c1(1, "Dacia", "Logan", 1970, 25000, 1000, 20, "gas");
    Car c2(2, "Dacia", "Duster", 2000, 10000, 10000, 100, "electric");
    Car c3{ 3, "Audi", "A6",  2010, 2000, 3500, 270, "Gasoline" };
    Car c4{ 4, "Opel", "Corsa",  2009, 240, 2300, 90, "Diesel" };
    Car c5{ 5, "Opel", "Astra",  2004, 1000, 1300, 120, "Diesel" };
    Car c6{ 6, "Mercedes", "Benz",  2011, 2000, 4000, 300, "Gasoline" };
    Car c7{ 7, "Porsche", "Cayene",  2013, 100, 5100, 310, "Diesel" };
    Car c8{ 8, "Toyota", "Supra",  2020, 100, 5140, 400, "Hybrid" };
    Car c9{ 9, "VW", "Tiguan",  2018, 10, 5100, 405, "Hybrid" };
    Car c10{ 10, "VW", "Tiguan",  2008, 100, 5000, 350, "electric" };
    control.addCar(c1);
    control.addCar(c2);
    control.addCar(c3);
    control.addCar(c4);
    control.addCar(c5);
    control.addCar(c6);
    control.addCar(c7);
    control.addCar(c8);
    control.addCar(c9);
    control.addCar(c10);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow_Login log;
    log.show();
    //CarRepo repo;
    //CarControl control(repo);
    //initialList(control);
    //Login log;
    //log.show();
    //if (log.exec() != QDialog::Accepted) {
      //  a.quit();
    //}
    //else {
    /*CarRepo repo;
    CarControl control(repo);
    MainWindow w(control);
    w.setWindowTitle("Car App");
    w.show();*/
    //}
    return a.exec();
}
