#include "JsonConvert.h"


QList<QPair<QString, QString>> JsonConvert::getJsonInfo (QByteArray responseData)
{
    QJsonParseError error;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(responseData, &error);
    if (error.error != QJsonParseError::NoError) {
        throw "JSON Error : Invalid JSON format!\n";
    }

    QJsonArray jsonArray = jsonDocument.array();
    QList<QPair<QString, QString>> jsonInfoList;


    for (const QJsonValue& value : jsonArray) {
        if (!value.isObject()
            || !value.toObject().contains("name")
            || !value.toObject().contains("address")
            || !value.toObject()["address"].toObject().contains("geo")
            || !value.toObject()["address"].toObject()["geo"].toObject().contains("lat")
        ) {
            throw "JSON Error : The document does not contains all neccesary attributes!\n";
        }

        QString name = value.toObject()["name"].toString();
        QString color;
        double d = value.toObject()["address"].toObject()["geo"].toObject()["lat"].toString().toDouble();
        if (d < 0) {
            color = "Red";
        } else {
            color = "Green";
        }
        QPair<QString, QString> pair;
        pair.first = name;
        pair.second = color;
        jsonInfoList << pair;
     }

    return jsonInfoList;
}
