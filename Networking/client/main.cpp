#include <iostream>
#include <sockettest.h>
#include <server.h>
#include <QTcpServer>
#include <QObject>
#include <string>

/*
 * This is your main() function. Very simple.
 */
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string line;
    string playerName;
    string ip;

    cout << "Enter player name: " << endl;

    cin >> playerName;

    cout << "Enter ip address or host address: " << endl;
    cin >> ip;

    sockettest cTest;

    cTest.Connect(QString::fromStdString(playerName), QString::fromStdString(ip));

    while(cin)
    {
        cin >> line;

        cTest.Write(QString::fromStdString(line));
    }

    cTest.close();

    return 0;
}

/*
    QTcpSocket *socket;
    socket = new QTcpSocket();
    int port = 4200;

    socket->connectToHost("192.168.1.103", port);

    QString message = "This is a message 1";

    socket->write(QString(message).toUtf8());
  */
