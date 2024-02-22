#ifndef WEATHERBACKGROUND_H
#define WEATHERBACKGROUND_H
#include <QString>
#include <QMap>
class WeatherBackground
{
public:
    WeatherBackground();
    QString getBackgroundPath(const QString &description) const;
private:
    QMap<QString, QString> BackgroundMap;
};

#endif // WEATHERBACKGROUND_H
