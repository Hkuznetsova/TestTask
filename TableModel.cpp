#include "TableModel.h"
#include <QDebug>

TableModel::TableModel(QObject *parent):
    QAbstractTableModel(parent)
{
}

TableModel::TableModel(QList<QPair<QString, QString>> data,  QObject *parent):
    QAbstractTableModel(parent)
{
    m_data = data;

}

int TableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }

    return m_data.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return 2;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{


    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case ColorRole:
        return m_data.at(index.row()).second;
    case NameRole:
        return m_data.at(index.row()).first;
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> TableModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractTableModel::roleNames();
    roles[ColorRole] = "color";
    roles[NameRole] = "name";

    return roles;
}

void TableModel::add(QPair<QString, QString> data)
{
    beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
    m_data << data;
    endInsertRows();

    QModelIndex index = createIndex(0, 0, static_cast<void *>(0));
    emit dataChanged(index, index);
}

