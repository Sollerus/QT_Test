#include "mainwindow.h"

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setToolTip("A tooltip");
    w.show();
    QPushButton b;
    b.setText("Hello world");
    b.setToolTip("A tooltip");
    b.show();
    return a.exec();
}
