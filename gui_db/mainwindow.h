#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
//#include <QSqlDatabase>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_spinBox_editingFinished();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    int coutSwitch(int type);
    int coutPoint(int line_id);

};

#endif // MAINWINDOW_H
