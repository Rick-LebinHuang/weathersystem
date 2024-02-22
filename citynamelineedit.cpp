#include "citynamelineedit.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

CityNameLineEdit::CityNameLineEdit(QWidget *parent) : QLineEdit(parent) {
    networkManager = new QNetworkAccessManager(this);
    completerModel = new QStringListModel(this);
    completer = new QCompleter(completerModel, this);
    this->setCompleter(completer);

    connect(this, &QLineEdit::textChanged, this, &CityNameLineEdit::handleTextChange);
    connect(networkManager, &QNetworkAccessManager::finished, this, &CityNameLineEdit::handleNetworkReply);
}

CityNameLineEdit::~CityNameLineEdit() {
    delete completer;
    delete networkManager;
    delete completerModel;
}

void CityNameLineEdit::handleTextChange(const QString &text) {
    if (text.length() < 3) { // Limit the request frequency
        completerModel->setStringList(QStringList());
        return;
    }


    QString apiKey = "e964abeddad09c81d604c72f514285d6";
    QString requestUrl = QString("http://api.openweathermap.org/geo/1.0/direct?q=%1&limit=5&appid=%2")
                             .arg(text, apiKey);
    networkManager->get(QNetworkRequest(QUrl(requestUrl)));
}

void CityNameLineEdit::handleNetworkReply(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        QJsonArray jsonArray = jsonDoc.array();

        QStringList cityList;
        for (const QJsonValue &value : jsonArray) {
            QJsonObject obj = value.toObject();
            QString cityName = obj["name"].toString();
            if (!cityList.contains(cityName)) {
                cityList << cityName;
            }
        }
        completerModel->setStringList(cityList);
    } else {
        qDebug() << "Network error:" << reply->errorString();
    }
    reply->deleteLater();
}
