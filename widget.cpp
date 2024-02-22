#include "widget.h"
#include "ui_widget.h"
#include <QNetworkRequest>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include "filehelper.h"
#include "weathericonmapper.h"
#include "weatherbackground.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , networkManager(new QNetworkAccessManager(this))
    , iconMapper(new WeatherIconMapper())
    , backgroundMapper(new WeatherBackground())
{
    ui->setupUi(this);
    // set the background in the welcome page.
    Welcomebackground = new QLabel(ui->WelcomePage);
    Welcomebackground->setPixmap(QPixmap(":/images/background/WelcomePageBackground.png"));
    Welcomebackground->resize(ui->WelcomePage->size());
    Welcomebackground->lower(); // keep background in lowest level.
    Welcomebackground->setScaledContents(true);

    // set the background in the main page.
    backgroundLabel = new QLabel(ui->MainPage);
    backgroundLabel->setPixmap(QPixmap(":/images/background/Clear.png"));
    backgroundLabel->resize(ui->MainPage->size());
    backgroundLabel->lower(); // keep background in lowest level.
    backgroundLabel->setScaledContents(true);

    // set the initial page is welcome page.
    ui->StackedWidget->setCurrentWidget(ui->WelcomePage);

    // set the place_holder_text.
    QPalette pal = ui->lineEdit_cityName->palette();
    pal.setColor(QPalette::PlaceholderText, QColor("#888888")); // 灰色的占位符文本
    ui->lineEdit_cityName->setPalette(pal);

    connect(networkManager, &QNetworkAccessManager::finished, this, &Widget::onNetworkReply);
}


Widget::~Widget()
{
    delete ui;
}

// rewrite the resizeEvent to make the background image full of the screen.
void Widget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    backgroundLabel->resize(this->size());
    Welcomebackground->resize(ui->WelcomePage->size());
}

void Widget::on_btnStart_clicked()
{
    ui->StackedWidget->setCurrentWidget(ui->MainPage);

}

void Widget::on_btnSearch_clicked()
{
    QString input = ui->lineEdit_cityName->text();
    if (!input.isEmpty()) {
        QString apiKey = "e964abeddad09c81d604c72f514285d6"; // API key
        QString requestUrl;
            bool isPostalCode = true;
        for (const QChar &ch : input) {
            if (!ch.isDigit()) {
                isPostalCode = false;
                break;
            }
        }

        if (isPostalCode) {
            // 假设为美国邮政编码，需要根据实际情况调整
            requestUrl = QString("http://api.openweathermap.org/data/2.5/weather?zip=%1,au&appid=%2").arg(input, apiKey);
        } else {
            requestUrl = QString("http://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2").arg(input, apiKey);
        }
        QUrl url(requestUrl);
        QNetworkRequest request(url);
        networkManager->get(request);
    }
}

void Widget::onNetworkReply(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseBytes = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseBytes);
        if (!jsonDoc.isNull()) {
            if (jsonDoc.isObject()) {
                QJsonObject jsonObj = jsonDoc.object();
                QJsonObject main = jsonObj["main"].toObject();
                double tempK = main["temp"].toDouble(); // temperature(Default is Kelvin temperature)
                int tempC = qRound(tempK - 273.15); // Convert to Celsius
                double humidity = main["humidity"].toDouble(); // humidity
                QJsonObject windObject = jsonObj["wind"].toObject();
                int windSpeed = windObject["speed"].toInt();
                // Create an array of weather descriptions.
                QJsonArray weatherArray = jsonObj["weather"].toArray();
                QJsonObject weather = weatherArray.first().toObject();
                QString description = weather["description"].toString(); // description of weather

                // Update UI components.
                ui->temperatureLabel->setText(QString::number(tempC)+QString::fromLocal8Bit("°C"));
                ui->humidityLabel->setText(QString::number(humidity) + " %");
                ui->descriptionLabel->setText(description);
                ui->labelWindSpeed->setText(QString::number(windSpeed) + " m/s ");

                QString iconPath = iconMapper->getIconPath(description);
                QPixmap pixmap(iconPath);
                QPixmap scaledPixmap = pixmap.scaled(ui->weatherIconLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                ui->weatherIconLabel->setPixmap(scaledPixmap);

                QString backgroundPath = backgroundMapper->getBackgroundPath(description); //Create and initialize backgroundMapper
                QPixmap pixmap1(backgroundPath);
                if (!pixmap.isNull()) {
                    QPixmap scaledPixmap1 = pixmap1.scaled(ui->MainPage->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                    backgroundLabel->setPixmap(scaledPixmap1);
                } else {
                    qDebug() << "Failed to load pixmap from path:" << backgroundPath;
                }

                // According to the weather, update the style.
                QString stylesheetPath;
                if (description.contains("snow") || description.contains("clear")) {
                    stylesheetPath = ":/images/qss/BrightTheme.qss";
                } else {
                    stylesheetPath = ":/images/qss/DarkTheme.qss";
                }

                // Using FileHelper to load the style sheet
                QString qssContent = FileHelper::readAllTxt(stylesheetPath);
                if (!qssContent.isEmpty()) {
                    this->setStyleSheet(qssContent);
                } else {
                    qDebug() << "Failed to load stylesheet:" << stylesheetPath;
                }

            }
        }
    } else {
        // debug
        qDebug() << "There is a problem with the program";
    }
    reply->deleteLater();
}




