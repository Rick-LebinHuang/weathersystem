#include "weathericonmapper.h"

WeatherIconMapper::WeatherIconMapper()
{
    // initialize the mapping of the icon
    iconMap["clear sky"] = ":/images/picture/Clear.png";

    iconMap["thunderstorm with light rain"] = ":/images/picture/Thunderstorm.png";
    iconMap["thunderstorm with rain"] = ":/images/picture/Thunderstorm.png";
    iconMap["thunderstorm with heavy rain"] = ":/images/picture/Thunderstorm.png";
    iconMap["light thunderstorm"] = ":/images/picture/Thunderstorm.png";
    iconMap["thunderstorm"] = ":/images/picture/Thunderstorm.png";
    iconMap["heavy thunderstorm"] = ":/images/picture/Thunderstorm.png";
    iconMap["ragged thunderstorm"] = ":/images/picture/Thunderstorm.png";
    iconMap["thunderstorm with light drizzle"] = ":/images/picture/Thunderstorm.png";
    iconMap["thunderstorm with drizzle"] = ":/images/picture/Thunderstorm.png";
    iconMap["thunderstorm with heavy drizzle"] = ":/images/picture/Thunderstorm.png";

    iconMap["light intensity drizzle"] = ":/images/picture/Drizzle.png";
    iconMap["drizzle"] = ":/images/picture/Drizzle.png";
    iconMap["heavy intensity drizzle"] = ":/images/picture/Drizzle.png";
    iconMap["light intensity drizzle rain"] = ":/images/picture/Drizzle.png";
    iconMap["drizzle rain"] = ":/images/picture/Drizzle.png";
    iconMap["heavy intensity drizzle rain"] = ":/images/picture/Drizzle.png";
    iconMap["shower rain and drizzle"] = ":/images/picture/Drizzle.png";
    iconMap["heavy shower rain and drizzle"] = ":/images/picture/Drizzle.png";
    iconMap["shower drizzle"] = ":/images/picture/Drizzle.png";

    iconMap["light rain"] = ":/images/picture/Rain.png";
    iconMap["moderate rain"] = ":/images/picture/Rain.png";
    iconMap["heavy intensity rain"] = ":/images/picture/Rain.png";
    iconMap["very heavy rain"] = ":/images/picture/Rain.png";
    iconMap["extreme rain"] = ":/images/picture/Rain.png";
    iconMap["freezing rain"] = ":/images/picture/Rain.png";
    iconMap["light intensity shower rain"] = ":/images/picture/Rain.png";
    iconMap["shower rain"] = ":/images/picture/Rain.png";
    iconMap["heavy intensity shower rain"] = ":/images/picture/Rain.png";
    iconMap["ragged shower rain"] = ":/images/picture/Rain.png";

    iconMap["light snow"] = ":/images/picture/Snow.png";
    iconMap["snow"] = ":/images/picture/Snow.png";
    iconMap["heavy snow"] = ":/images/picture/Snow.png";
    iconMap["sleet"] = ":/images/picture/Snow.png";
    iconMap["light shower sleet"] = ":/images/picture/Snow.png";
    iconMap["shower sleet"] = ":/images/picture/Snow.png";
    iconMap["light rain and snow"] = ":/images/picture/Snow.png";
    iconMap["rain and snow"] = ":/images/picture/Snow.png";
    iconMap["light shower snow"] = ":/images/picture/Snow.png";
    iconMap["shower snow"] = ":/images/picture/Snow.png";
    iconMap["heavy shower snow"] = ":/images/picture/Snow.png";

    iconMap["mist"] = ":/images/picture/Mist.png";
    iconMap["smoke"] = ":/images/picture/Mist.png";
    iconMap["haze"] = ":/images/picture/Mist.png";
    iconMap["sand"] = ":/images/picture/Mist.png";
    iconMap["fog"] = ":/images/picture/Mist.png";
    iconMap["dust"] = ":/images/picture/Mist.png";
    iconMap["volcanic ash"] = ":/images/picture/picture/Mist.png";
    iconMap["squalls"] = ":/images/picture/Squalls.png";
    iconMap["tornado"] = ":/images/picture/Tornado.png";

    iconMap["few clouds"] = ":/images/picture/Cloudy.png";
    iconMap["scattered clouds"] = ":/images/picture/Cloudy.png";
    iconMap["broken clouds"] = ":/images/picture/Cloudy.png";
    iconMap["overcast clouds"] = ":/images/picture/Cloudy.png";
}

QString WeatherIconMapper::getIconPath(const QString &description) const {
    return iconMap.value(description, ":/images/picture/default.png");
}
