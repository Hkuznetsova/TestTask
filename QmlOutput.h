#ifndef QMLOUTPUT_H
#define QMLOUTPUT_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "TableModel.h"


class QmlOutput
{
public:
    QmlOutput(QList<QPair<QString, QString>> JSONInfo, QQmlApplicationEngine &engine, TableModel &myModel);
};

#endif // QMLOUTPUT_H
