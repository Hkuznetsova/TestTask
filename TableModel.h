#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QObject>
#include <QVariant>

class TableModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
public:
    TableModel(QObject *parent = nullptr);
    TableModel(const TableModel &other);
    TableModel(const QString &name, const QString &color, QObject *parent = nullptr);
    void setName(const QString &name);
    void setColor(const QString &color);
    QString name() const;
    QString color() const;
signals:
    void nameChanged();
    void colorChanged();
private:
    QString m_name;
    QString m_color;
};

Q_DECLARE_METATYPE(TableModel)

#endif // TABLEMODEL_H
