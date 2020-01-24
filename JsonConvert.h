#ifndef JSONCONVERT_H
#define JSONCONVERT_H

#include <QtCore/QDebug>
#include <QtCore/QJsonDocument>
#include <QtCore/QCoreApplication>
#include <QJsonArray>
#include <QJsonObject>

class JsonConvert
{
public:
    QList<QPair<QString, QString>> getJsonInfo(QByteArray responseData);
};

#endif // JSONCONVERT_H
