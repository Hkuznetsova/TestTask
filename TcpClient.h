#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QTcpSocket>
#include <QDataStream>
#include <iostream>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "JsonConvert.h"
#include "TableModel.h"

class TcpClient : public QObject
{
Q_OBJECT
private:
    QTcpSocket* m_pTcpSocket;
    quint16     m_nNextBlockSize;
    QQmlApplicationEngine* engine;
    TableModel* myModel;

public:
    TcpClient(QQmlApplicationEngine* engine, TableModel* myModel);
    void tcpClientConnect(const QString& strHost,  int nPort);

private slots:
    void slotReadyRead   (                            );
    void slotError       (QAbstractSocket::SocketError);
    void slotConnected   (                            );
};


#endif // TCPCLIENT_H
