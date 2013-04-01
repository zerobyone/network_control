#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    tcp=new QTcpSocket(this);
    tcp->connectToHost("127.0.0.1",8001);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_clicked()
{
    QString push("X2100E");
    qDebug()<<push;
   // X_buf=push;
    buf=Y_buf+X_buf+P_buf;
    qDebug()<<buf;
    tcp->write(buf.toAscii());
}

void Dialog::on_pushButton_4_clicked()
{
    QString down("X0800E");
   // qDebug()<<down;
    X_buf=Y_buf+X_buf+P_buf;
    buf=Y_buf+X_buf+P_buf;
    qDebug()<<buf;
    tcp->write(buf.toAscii());
}

void Dialog::on_pushButton_2_clicked()
{
    QString left("Y0800E");
   // qDebug()<<left;
    Y_buf=left;
    buf=Y_buf+X_buf+P_buf;
    qDebug()<<buf;
    tcp->write(buf.toAscii());
}


void Dialog::on_pushButton_3_clicked()
{
    QString right("Y2100E");
   // qDebug()<<right;
    Y_buf=right;
    buf=Y_buf+X_buf+P_buf;
    qDebug()<<buf;
    tcp->write(buf.toAscii());
}

void Dialog::on_verticalSlider_valueChanged(int value)
{
    QString power;
    power.setNum(value);
    if(value<1000)
        power.insert(0,"P0");
    else
        power.insert(0,"P");
    power.append("E");
    //qDebug()<<power;
    buf=Y_buf+X_buf+P_buf;
    qDebug()<<buf;
    tcp->write(buf.toAscii());
}
