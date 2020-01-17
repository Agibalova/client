#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>
#include "client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    client cl;
    QObject::connect(&cl,SIGNAL(newData(int,int,int,int,int)),
                     &w,SLOT(reciveNewData(int,int,int,int,int)));
    qDebug()<<"start program";

    return a.exec();
}
