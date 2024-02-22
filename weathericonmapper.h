#ifndef WEATHERICONMAPPER_H
#define WEATHERICONMAPPER_H
#include <QString>
#include <QMap>

// the header of WeatherIconMapper
class WeatherIconMapper
{
public:
    WeatherIconMapper();
    QString getIconPath(const QString &description) const;
private:
    QMap<QString, QString> iconMap;
};

#endif // WEATHERICONMAPPER_H
