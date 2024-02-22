#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "weathericonmapper.h"
#include "weatherbackground.h"
#include "citynamelineedit.h"
#include <QLabel>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_btnStart_clicked();
    void onNetworkReply(QNetworkReply *reply); //add the slot function for network reply
    void on_btnSearch_clicked();

private:
    Ui::Widget *ui;
    QStackedWidget *stackedWidget;
    QNetworkAccessManager *networkManager; // add a network manager
    WeatherIconMapper *iconMapper;
    WeatherBackground *backgroundMapper;
    QLabel *backgroundLabel;
    QLabel *Welcomebackground;
    CityNameLineEdit *cityNameLineEdit;
};
#endif // WIDGET_H
