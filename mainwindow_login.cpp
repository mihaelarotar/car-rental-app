#include "mainwindow_login.h"
#include "ui_mainwindow_login.h"
#include "mainwindow.h"
#include <QMessageBox>

MainWindow_Login::MainWindow_Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_Login)
{
    ui->setupUi(this);
}

MainWindow_Login::~MainWindow_Login()
{
    delete ui;
}

void MainWindow_Login::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_user->text();
    QString password = ui->lineEdit_pass->text();
    if (username == "manager" && password == "s3cr3t") {
        QMessageBox::information(this, "OK", "ok");
        hide();
        //table = new Table(this)
        CarRepo repo;
        CarControl control(repo);
        w = new MainWindow (control, this);
        w->setWindowTitle("Car App");
        w->show();

    }
    else {
        QMessageBox::warning(this, "Error", "error");
    }

}


