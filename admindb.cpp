#include "admindb.h"


AdminDB::AdminDB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

AdminDB::~AdminDB()
{

}

bool AdminDB::conectar(QString nombreBase)
{
    db.setDatabaseName(nombreBase);
    if(db.open())
    {
        return true;
    }
    return false;
}

QSqlDatabase AdminDB::getDB()
{
    return db;
}

QVector <QString> AdminDB::select(QString comando)
{
    QVector<QString> registros;

    QStringList v= db.tables();

    QSqlRecord rec= db.record(v.at(0));

    QString sel="select * from "+ v.at(0);

    QSqlQuery query= db.exec(sel);
    while(query.next())
    {
        QString campos;
        for (int i = 0; i < rec.count(); ++i)
        {
            campos.append(query.value(i).toString()+" ");
        }
        registros.append( campos );

    }
    return registros;
}
