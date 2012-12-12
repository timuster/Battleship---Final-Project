#ifndef SOCKETTEST_H
#define SOCKETTEST_H

#include<QObject>
#include<QTcpSocket>
#include<QDebug>

class sockettest: public QObject
{
    Q_OBJECT
public:
    sockettest(QObject *parent = 0);

    void Connect(QString name, QString ip);

    void Write (QString value);
    void close();

private slots:
    void readyRead();
    void connected();

private:
    QTcpSocket *socket;
    QString userName;
};

#endif // SOCKETTEST_H
