#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QObject>
#include <QAbstractListModel>

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum Roles {
        NameRole = Qt::UserRole + 1,
        ColorRole
    };

    TableModel(QObject *parent = 0);
    TableModel(QList<QPair<QString, QString>> data,QObject *parent = 0);

    virtual int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QHash<int, QByteArray> roleNames() const;


private:
    QList<QPair<QString, QString>> m_data;
};

#endif // TABLEMODEL_H
