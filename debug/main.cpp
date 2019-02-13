#include <QCoreApplication>
#include <QDebug>
#include <QDate>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Date:" << QDate::currentDate();

    qWarning() << "Warning";
    qCritical() << "Critical";
    qFatal("Fatal");

    return a.exec();
}
