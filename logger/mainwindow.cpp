#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logger.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_debugButton_clicked()
{
    qDebug(logDebug()) << "Debug Button";
}

void MainWindow::on_infoButton_clicked()
{
    qInfo(logInfo()) << "Info Button";
}

void MainWindow::on_warningButton_clicked()
{
    qWarning(logWarning()) << "Warning Button";
}

void MainWindow::on_criticalButton_clicked()
{
    qCritical(logCritical()) << "Critical Button";
}
