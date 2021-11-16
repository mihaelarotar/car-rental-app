#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTableView>
MainWindow::MainWindow(CarControl& _control, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , control(_control)
{
    ui->setupUi(this);
    QVector<Car> carList;
    for (const Car& c : control.getAll()) {
        carList.append(c);
    }
    MyModel *CarModel = new MyModel(this);
    CarModel->setMyData(carList);
    ui->tableView->setModel(CarModel);
    //ui->tableView->horizontalHeader()->setVisible(false);
    //ui->tableView->verticalHeader()->setVisible(false);
    ui->tableView->setStyleSheet("QHeaderView::section { background-color:gray }");
    ui->tableView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

MyModel::MyModel(QObject *parent) : QAbstractTableModel(parent) {}

void MyModel::setMyData(const QVector<Car>& carList)
{
    //cars.clear();
    cars = carList;
}

int MyModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return cars.length();
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 8;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    if (index.column() == 0) {
        return cars[index.row()].getID();
    }
    else if (index.column() == 1) {
        return QString::fromStdString(cars[index.row()].getBrand());
    }
    else if (index.column() == 2) {
        return QString::fromStdString(cars[index.row()].getModel());
    }
    else if (index.column() == 3) {
        return cars[index.row()].getYear();
    }
    else if (index.column() == 4) {
        return cars[index.row()].getKm();
    }
    else if (index.column() == 5) {
        return cars[index.row()].getPrice();
    }
    else if (index.column() == 6) {
        return cars[index.row()].getPerformance();
    }
    else if (index.column() == 7) {
        return QString::fromStdString(cars[index.row()].getFuel());
    }
    return QVariant();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("ID");
        }
        else if (section == 1) {
            return QString("Brand");
        }
        else if (section == 2) {
            return QString("Model");
        }
        else if (section == 3) {
            return QString("Year");
        }
        else if (section == 4) {
            return QString("Km");
        }
        else if (section == 5) {
            return QString("Price");
        }
        else if (section == 6) {
            return QString("Performance(HP)");
        }
        else if (section == 7) {
            return QString("Fuel");
        }
    }
    if (role == Qt::DisplayRole && orientation == Qt::Vertical) {
        return section + 1;
    }
    return QVariant();
}


