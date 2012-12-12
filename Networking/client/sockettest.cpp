#include "sockettest.h"
#include <QRegExp>

sockettest::sockettest(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
}

void sockettest::Connect(QString name, QString ip)
{
    this->userName = name;
    socket->connectToHost(ip, 4200);

    if (socket->waitForConnected(3000))
    {
        qDebug() << "Connected: ...";
    }

    else
    {
        qDebug() << "Connection Failed...Try plugging the ip address instead of hostname";
    }
}

void sockettest::Write(QString value)
{
    if(!value.isEmpty())
    {
        value = value.trimmed();

        if (socket->isWritable())
        {
            socket->write(QString(value + "\n").toUtf8());

            socket->waitForBytesWritten(1000);
        }

        else
        {
            qDebug() << "Can not write " << value << " because socket was not connected";
        }
    }

    else
    {
        qDebug() << "You passed an empty value...";
    }
}

void sockettest::close()
{
    socket->close();
}

void sockettest::readyRead()
{
    // We'll loop over every (complete) line of text that the server has sent us:
    while(socket->canReadLine())
    {
        // Here's the line the of text the server sent us (we use UTF-8 so
        // that non-English speakers can chat in their native language)
        QString line = QString::fromUtf8(socket->readLine()).trimmed();

        // These two regular expressions describe the kinds of messages
        // the server can send us:

        //  Normal messges look like this: "username:The message"
        QRegExp messageRegex("^([^:]+):(.*)$");

        // Any message that starts with "/users:" is the server sending us a
        // list of users so we can show that list in our GUI:
        QRegExp usersRegex("^/users:(.*)$");

        // Is this a users message:
        if(usersRegex.indexIn(line) != -1)
        {
            //qDebug() << "I am here";
        }
        // Is this a normal chat message:
        else if(messageRegex.indexIn(line) != -1)
        {
            // If so, append this message to our chat box:
            QString user = messageRegex.cap(1);
            QString message = messageRegex.cap(2);

            if(user != this->userName && user!= "Server")
                qDebug() << "User: " << user << endl << "Message: " << message << endl;
        }

        else
            qDebug() << "Came to else..";
    }

}

void sockettest::connected()
{
    // And send our username to the chat server.
    QString value = "/me:" + this->userName + "\n";
    this->Write(value);

    qDebug() << "Connection Sucessfull";
}

