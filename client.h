#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QUdpSocket>
class client : public QObject
{
    Q_OBJECT
public:
    explicit client(QObject *parent = nullptr);

signals:
    bool newData(int id, int x, int y, int z, int time);
public slots:

    void readPendingDatagram();

private :
    QUdpSocket m_socket;
};

#endif // CLIENT_H
