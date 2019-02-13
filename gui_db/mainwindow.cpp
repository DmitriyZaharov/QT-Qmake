#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    db.setDatabaseName("/home/vitamin/db_test/db/rzhd.db");

    if(!db.open())
    {
        qFatal("Can't open file");
    }

    ui->setupUi(this);

    int cw = coutSwitch(1);
    qDebug() << cw;

    cw = coutSwitch(2);
    qDebug() << cw;

    QString cout_type1;
    cout_type1 = "Type1 = " + QString::number(coutSwitch(1));

    QString cout_type2;
    cout_type2 = "Type2 = " + QString::number(coutSwitch(2));

    ui->label_2->setText(cout_type1);
    ui->label_3->setText(cout_type2);

//    ui->spinBox->setMaximum(2784);
//    ui->spinBox->setMinimum(400);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::coutSwitch(int type)
{
    int res = -1;
    QSqlQuery qu;
    qu.prepare("select count(*) from RAILWAY_OBJ_SINGLE_SWITCH where TURN_TYPE = :type");


    qu.bindValue(":type", type);
    qu.exec();

    if(qu.next())
    {
        res = qu.value(0).toInt();
    }

    return res;

}

int MainWindow::coutPoint(int line_id)
{
    int res = -1;
    QSqlQuery qu;

    qu.prepare("select count(*) from GEO_LINE_ADDITIONAL_POINTS where ID_GEO_LINE = :id");


    qu.bindValue(":id", line_id);
    qu.exec();

    if(qu.next())
    {
        res = qu.value(0).toInt();
    }

    return res;

}

void MainWindow::on_spinBox_editingFinished()
{

//    qDebug() << ui->spinBox->value();
    int point_count = coutPoint(ui->spinBox->value());
    ui->lineEdit->setText(QString::number(point_count + 2));



}
