#include "TableModel.h"

TableModel::TableModel(QObject *parent)
    : QObject { parent }
    , m_name { "" }
    , m_color { "" }
{

}

TableModel::TableModel(const TableModel &other)
    : QObject { other.parent() }
    , m_name { other.m_name }
    , m_color { other.m_color }
{

}

TableModel::TableModel(const QString &name, const QString &color, QObject *parent)
    : QObject { parent }
    , m_name { name }
    , m_color { color }
{

}

void TableModel::setName(const QString &name)
{
    if(m_name != name) {
        m_name = name;
        emit nameChanged();
    }
}

void TableModel::setColor(const QString &color)
{
    if(m_color != color) {
        m_color = color;
        emit colorChanged();
    }
}

QString TableModel::name() const
{
    return m_name;
}

QString TableModel::color() const
{
    return m_color;
}

