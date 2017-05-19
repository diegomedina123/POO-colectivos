#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include <QDebug>
#include <QSqlError>
#include <QVariant>
#include "admindb.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    QString hora;
    QFile * file;
    AdminDB* db;
    QSqlQuery* query;
};

#endif // WIDGET_H
