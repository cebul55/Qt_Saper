#include "saper.h"
#include "saperboard.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Saper w;
    w.show();

    return a.exec();
}
