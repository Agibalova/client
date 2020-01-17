#include "client.h"
#include <QtDebug>
#include <QByteArray>
#include <QDataStream>
#include <QTime>

client::client(QObject *parent) : QObject(parent)
{

    qDebug()<<"client";
   QHostAddress addres("127.0.0.1");
    m_socket.bind(addres,36001);
    connect(&m_socket, SIGNAL(readyRead()),
            this,SLOT(readPendingDatagram()));
}

void client::readPendingDatagram()
{
    qDebug()<<"readPendingDatagram";
    while (m_socket.hasPendingDatagrams()) {
        QByteArray datagram;

        datagram.resize (m_socket.pendingDatagramSize());
        qDebug()<<"datagram size="<<datagram.size();
        QHostAddress sender;
        quint16 senderPort;

        m_socket.readDatagram(datagram.data(), datagram.size(),
                            &sender, &senderPort);
        QDataStream stream(datagram);
        stream.setVersion(QDataStream::Qt_4_8);
        qint64 size;
        int id;
        int time;
        int x;
        int y;
        int z;
        stream >> size >> id >> time >> x >> y >> z;
        emit newData(id,x,y,z,time);

    }
}
