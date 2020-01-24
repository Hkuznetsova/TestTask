#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QQmlContext>


#include "TableModel.h"
#include "JsonConvert.h"
#include "QmlOutput.h"
#include "ConsoleOutput.h"
#include "TcpClient.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    TcpClient client(&engine);
    client.tcpClientConnect("jsonplaceholder.typicode.com", 80);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
