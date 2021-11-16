#ifndef MAINWINDOW_LOGIN_H
#define MAINWINDOW_LOGIN_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class MainWindow_Login;
}

class MainWindow_Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_Login(QWidget *parent = nullptr);
    ~MainWindow_Login();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::MainWindow_Login *ui;
    MainWindow* w;
};

#endif // MAINWINDOW_LOGIN_H
