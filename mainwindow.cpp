#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Room.h"
#include "Lux.h"
#include <iostream>
#include <string>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{   //ui->spinBox->value()
    oop4::Lux a( ui->spinBox->value(),2);

 ui->label->setText(QString::fromStdString(std::to_string(a.Get_number())));
}
