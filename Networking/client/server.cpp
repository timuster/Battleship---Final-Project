#include "server.h"


server::server(QObject *parent) : QObject(parent)
{
    Server = new QTcpServer(this);

    if (!Server->listen(QHostAddress::Any,4200))
    {
        qDebug() << "Server couldn't start...";
    }

    else
    {
        qDebug() << "Server started...";
    }

    //Server->nextPendingConnection()
}

void server::write(QString value)
{
    QTcpSocket *client = Server->nextPendingConnection();

    if (client->waitForConnected(3000))
    {
        qDebug() << "Client Connected: ...";

        client->write("The connection is sucessfull");

        client->waitForBytesWritten(1000);
        client->waitForReadyRead(3000);

        qDebug() << "Reading" << client->bytesAvailable();

        qDebug() << client->readAll();

        client->close();
    }

    else
    {
        qDebug() << "Connection Failed...";
    }
}

quint16 server::port()
{
    return Server->serverPort();
}

QHostAddress server::ip()
{
    return Server->serverAddress();
}
