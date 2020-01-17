#include "table.h"
#include "ui_table.h"
#include <QDebug>

Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    QStringList horizontalHeader;
    horizontalHeader.append("Time");
    horizontalHeader.append("ID");
    horizontalHeader.append("x");
    horizontalHeader.append("y");
    horizontalHeader.append("z");


    m_model = new QStandardItemModel;

    m_model ->setHorizontalHeaderLabels(horizontalHeader);

    ui->tableView->setModel( m_model);
}

Table::~Table()
{
    delete ui;
}

bool Table::reciveTransferData(int id, int x, int y, int z,int time)
{
    qDebug()<<"reciveTransferData" <<"id= "<<id<<"x = "<<x<<" y = "<<y <<"z = "<<z <<" ttime = "<<time;
    if (z > 0) {
        QStandardItem *item = new QStandardItem(QVariant(id).toString());
        item->setTextAlignment(Qt::AlignCenter);

        int row = m_model->rowCount();
        m_model->setItem(row, 1, item);

        item = new QStandardItem(QVariant(x).toString());
        item->setTextAlignment(Qt::AlignCenter);
        m_model->setItem(row, 2, item);

        item = new QStandardItem(QVariant(y).toString());
        item->setTextAlignment(Qt::AlignCenter);
        m_model->setItem(row, 3, item);
        item = new QStandardItem(QVariant(z).toString());
        item->setTextAlignment(Qt::AlignCenter);
        m_model->setItem(row, 4, item);


        int totalNumberOfmSeconds = time; // nr of seconds more than 1 day.
        int mseconds = totalNumberOfmSeconds % 1000;
        int seconds = (totalNumberOfmSeconds / 1000) % 60;
        int minutes = (totalNumberOfmSeconds / 60 / 1000) % 60;
        int hours = (totalNumberOfmSeconds / 60 / 60 / 1000);

        QString timeString = QString("%1:%2:%3:%4")
          .arg(hours, 2, 10, QChar('0'))
          .arg(minutes, 2, 10, QChar('0'))
          .arg(seconds, 2, 10, QChar('0'))
          .arg(mseconds, 3, 10, QChar('0'));

        item = new QStandardItem(QVariant(timeString).toString());
        item->setTextAlignment(Qt::AlignCenter);
        m_model->setItem(row, 0, item);

    }
    return true;
}
