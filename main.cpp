#include "widget.h"
#include <QTextCodec>
#include <QApplication>
#include <Qfile>
#include <filehelper.h>
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Widget w;
    QString qssStr = FileHelper::readAllTxt(":/images/qss/DarkTheme.qss");
    //Load QSS content in QAapplication

    a.setStyleSheet(qssStr);
    w.showMaximized();
    return a.exec();
}
