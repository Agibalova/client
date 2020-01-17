#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->Table,SIGNAL(triggered()),this,SLOT(clicTable()));
    connect(ui->Graphic_2,SIGNAL(triggered()),this,SLOT(clicGraphic()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::clicGraphic()
{
   qDebug() <<"test clickGraphic";
   m_graphics.show();
   connect(this,SIGNAL(transferNewData(int,int,int,int,int)),
           &m_graphics,SLOT(reciveTransferData(int,int,int,int,int)));
   return true;
}

bool MainWindow::clicTable()
{
    m_table.show();
    qDebug()<<"test clickTable";
    connect(this,SIGNAL(transferNewData(int,int,int,int,int)),
            &m_table,SLOT(reciveTransferData(int,int,int,int,int)));
    return true;
}

bool MainWindow::reciveNewData(int id, int x,int y,int z,int time)
{
    transferNewData(id,x,y,z,time);
    return true;
}
