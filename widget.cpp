#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setButtonStatus();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pb10_clicked()
{
    calc(10);
}

void Widget::on_pushButton_2_clicked()
{
    calc(50);
}

void Widget::on_pushButton_3_clicked()
{
    calc(100);
}

void Widget::on_pushButton_4_clicked()
{
    calc(500);
}

void Widget::on_pushButton_5_clicked()
{
    calc(-100);
}

void Widget::on_pushButton_6_clicked()
{
    calc(-150);
}

void Widget::on_pushButton_7_clicked()
{
    calc(-200);
}

void Widget::on_pushButton_8_clicked()
{
    int n500 = money / 500;
    int n100 = (money % 500) / 100;
    int n50 = (money % 100) / 50;
    int n10 = (money % 50) / 10;
    QString change = QString("500:\t%1\n100:\t%2\n50:\t%3\n10:\t%4").arg(n500).arg(n100).arg(n50).arg(n10);
    calc(-money);
    QMessageBox::information(this, "Change", change);
}

void Widget::calc(int num)
{
    int sum = money + num;
    money = sum < 0 ? money : sum;
    ui->lcdNumber->display(money);
    setButtonStatus();
}

void Widget::setButtonStatus()
{
    ui->pushButton_5->setEnabled(money >= 100);
    ui->pushButton_6->setEnabled(money >= 150);
    ui->pushButton_7->setEnabled(money >= 200);
}
