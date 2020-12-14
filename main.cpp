#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include "Table.h"
#include "Lux.h"
#include "Standart.h"
#include "Multiseat.h"
using namespace oop4;


int main(int argc, char *argv[])
  {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
  }
