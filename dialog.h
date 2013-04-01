#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QDebug>
#include <QDataStream>
#include <QByteArray>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_verticalSlider_valueChanged(int value);

private:
    Ui::Dialog *ui;
    QTcpSocket *tcp;
   // QDataStream *sendout;
};

#endif // DIALOG_H
