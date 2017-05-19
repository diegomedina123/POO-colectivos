#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    db = new AdminDB;
    db->conectar("C:/Users/Medina/Desktop/base");
    query = new QSqlQuery(db->getDB());


    file = new QFile("C:/Users/Medina/Desktop/horarios.txt");
    if ( !file->open(QIODevice::ReadOnly) )     return;
    while ( !file->atEnd() )
    {
        QByteArray linea = file->readLine();
        //qDebug() << linea;
        //query->exec("INSERT INTO paradas (paradas) VALUES ('" + linea +"')");

        for (int i = 0; i < linea.count(); ++i)
        {
            if(linea.at(i) != ' ')
            {
                hora.append(linea.at(i));
            }
            else
            {
                if(!hora.isEmpty()) {query->exec("INSERT INTO horarios (horarios) VALUES ('"+ hora +"')");}
                hora.clear();
                break;
            }
        }
    }
}

Widget::~Widget()
{
    delete ui;
}
