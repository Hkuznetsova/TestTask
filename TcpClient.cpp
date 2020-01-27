#include "TcpClient.h"
#include "QmlOutput.h"
#include "ConsoleOutput.h"

TcpClient::TcpClient(QQmlApplicationEngine* engine, TableModel* myModel)
{
    this->engine = engine;
    this->myModel = myModel;
}

void TcpClient::tcpClientConnect(const QString& strHost,  int nPort)
{
    m_pTcpSocket = new QTcpSocket(this);
    m_pTcpSocket->connectToHost(strHost, nPort);
    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(m_pTcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
    connect(m_pTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(slotError(QAbstractSocket::SocketError)));
}

void TcpClient::slotReadyRead()
{
    QByteArray unused;
    QByteArray responseData;

    do {
        unused = m_pTcpSocket->readLine();
    } while(unused != "\r\n" && m_pTcpSocket->bytesAvailable());

    while (!m_pTcpSocket->atEnd()) {
       QByteArray data = m_pTcpSocket->read(100);
       responseData += data;
    }
    QDataStream stream(&responseData, QIODevice::ReadOnly);

    JsonConvert jsonConvert;
    QList<QPair<QString, QString>> JsonInfo;
    try {
        JsonInfo = jsonConvert.getJsonInfo(responseData);
    } catch (char const* e) {
        qDebug() << e;
        return;
    }
    if (!JsonInfo.isEmpty()) {
        QmlOutput qmlOutput(JsonInfo, *engine,*myModel);
        ConsoleOutput consoleOutput(JsonInfo);
    }
}

void TcpClient::slotError(QAbstractSocket::SocketError err)
{
    QString strError =
                     (err == QAbstractSocket::HostNotFoundError ?
                     "Error: The host was not found.\n" :
                     err == QAbstractSocket::RemoteHostClosedError ?
                     "The remote host is closed.\n" :
                     err == QAbstractSocket::ConnectionRefusedError ?
                     "Error: The connection was refused.\n" :
                     QString(m_pTcpSocket->errorString())
                    );
    qDebug() << strError;
}

void TcpClient::slotConnected()
{
    m_pTcpSocket->write("GET /users HTTP/1.0\r\nHost: jsonplaceholder.typicode.com\r\n\r\n");
    std::cout << "Received the connected() signal \n";
}
