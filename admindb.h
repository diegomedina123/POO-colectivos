#ifndef ADMINDB_H
#define ADMINDB_H
#include <QObject>
#include <QString>
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QDebug>

class AdminDB: public QObject
{
    Q_OBJECT
public:
    AdminDB();
    ~AdminDB();
    bool conectar(QString nombreBase);
    QSqlDatabase getDB();
    QVector <QString> select(QString comando);

private:
    QSqlDatabase db;

};

#endif // ADMINDB_H
