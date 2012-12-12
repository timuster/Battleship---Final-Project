#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class server: public QObject
{
    Q_OBJECT

public:
    server(QObject *parent = 0);

    quint16 port();
    QHostAddress ip();

    void write(QString value);

private:
    QTcpServer *Server;
};

#endif // SERVER_H
