#include "QmlOutput.h"

QmlOutput::QmlOutput(QList<QPair<QString, QString>> jsonInfo, QQmlApplicationEngine &engine, TableModel &myModel)
{
    for (QList<QPair<QString, QString>>::iterator i = jsonInfo.begin(); i != jsonInfo.end(); ++i)
            myModel.add(*i);
    //engine.rootContext()->setContextProperty("myModel", &myModel);
}
