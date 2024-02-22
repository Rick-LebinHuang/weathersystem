#ifndef CITYNAMELINEEDIT_H
#define CITYNAMELINEEDIT_H

#include <QLineEdit>
#include <QCompleter>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QStringListModel>

class CityNameLineEdit : public QLineEdit {
    Q_OBJECT

public:
    explicit CityNameLineEdit(QWidget *parent = nullptr);
    ~CityNameLineEdit();

// set the slots function
private slots:
    void handleTextChange(const QString &text);
    void handleNetworkReply(QNetworkReply *reply);

private:
    QCompleter *completer;
    QNetworkAccessManager *networkManager;
    QStringListModel *completerModel;
};

#endif // CITYNAMELINEEDIT_H
