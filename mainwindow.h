#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractTableModel>
#include "carcontrol.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MyModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    MyModel(QObject *parent = nullptr);

    void setMyData(const QVector<Car>& cars);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

private:
    QVector<Car> cars;

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(CarControl& _control, QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    CarControl& control;
};
#endif // MAINWINDOW_H
