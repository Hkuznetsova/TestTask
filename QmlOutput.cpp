#include "QmlOutput.h"

QmlOutput::QmlOutput(QList<QPair<QString, QString>> jsonInfo, QQmlApplicationEngine &engine)
{
    QObjectList tableModel;
    for (QList<QPair<QString, QString>>::iterator i = jsonInfo.begin(); i != jsonInfo.end(); ++i)
        tableModel.append(new TableModel((*i).first, (*i).second));

    engine.rootContext()->setContextProperty("tableModel", QVariant::fromValue(tableModel));
}
