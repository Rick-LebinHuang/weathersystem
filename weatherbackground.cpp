#include "weatherbackground.h"

WeatherBackground::WeatherBackground() {
    // 初始化映射
    BackgroundMap["clear sky"] = ":/images/background/Clear.png";

    BackgroundMap["thunderstorm with light rain"] = ":/images/background/Thunderstorm.png";
    BackgroundMap["thunderstorm with rain"] = ":/images/background/Thunderstorm.png";
    BackgroundMap["thunderstorm with heavy rain"] = ":/images/background/Thunderstorm.png";
    BackgroundMap["light thunderstorm"] = ":/images/background/Thunderstorm.png";
    BackgroundMap["thunderstorm"] = ":/images/background/Thunderstorm.png";
    BackgroundMap["heavy thunderstorm"] = ":/images/background/Thunderstorm.png";
    BackgroundMap["ragged thunderstorm"] = ":/images/background/Thunderstorm.png";
    BackgroundMap["thunderstorm with light drizzle"] = ":/images/background/Thunderstorm.png";
    BackgroundMap["thunderstorm with drizzle"] = ":/images/background/Thunderstorm.png";
    BackgroundMap["thunderstorm with heavy drizzle"] = ":/images/background/Thunderstorm.png";

    BackgroundMap["light intensity drizzle"] = ":/images/background/Drizzle.png";
    BackgroundMap["drizzle"] = ":/images/background/Drizzle.png";
    BackgroundMap["heavy intensity drizzle"] = ":/images/background/Drizzle.png";
    BackgroundMap["light intensity drizzle rain"] = ":/images/background/Drizzle.png";
    BackgroundMap["drizzle rain"] = ":/images/background/Drizzle.png";
    BackgroundMap["heavy intensity drizzle rain"] = ":/images/background/Drizzle.png";
    BackgroundMap["shower rain and drizzle"] = ":/images/background/Drizzle.png";
    BackgroundMap["heavy shower rain and drizzle"] = ":/images/background/Drizzle.png";
    BackgroundMap["shower drizzle"] = ":/images/background/Drizzle.png";

    BackgroundMap["light rain"] = ":/images/background/Drizzle.png";
    BackgroundMap["moderate rain"] = ":/images/background/Drizzle.png";
    BackgroundMap["heavy intensity rain"] = ":/images/background/Drizzle.png";
    BackgroundMap["very heavy rain"] = ":/images/background/Drizzle.png";
    BackgroundMap["extreme rain"] = ":/images/background/Drizzle.png";
    BackgroundMap["freezing rain"] = ":/images/background/Drizzle.png";
    BackgroundMap["light intensity shower rain"] = ":/images/background/Drizzle.png";
    BackgroundMap["shower rain"] = ":/images/background/Drizzle.png";
    BackgroundMap["heavy intensity shower rain"] = ":/images/background/Drizzle.png";
    BackgroundMap["ragged shower rain"] = ":/images/background/Drizzle.png";

    BackgroundMap["light snow"] = ":/images/background/snow.png";
    BackgroundMap["snow"] = ":/images/background/snow.png";
    BackgroundMap["heavy snow"] = ":/images/background/snow.png";
    BackgroundMap["sleet"] = ":/images/background/snow.png";
    BackgroundMap["light shower sleet"] = ":/images/background/snow.png";
    BackgroundMap["shower sleet"] = ":/images/background/snow.png";
    BackgroundMap["light rain and snow"] = ":/images/background/snow.png";
    BackgroundMap["rain and snow"] = ":/images/background/snow.png";
    BackgroundMap["light shower snow"] = ":/images/background/snow.png";
    BackgroundMap["shower snow"] = ":/images/background/snow.png";
    BackgroundMap["heavy shower snow"] = ":/images/background/snow.png";

    BackgroundMap["mist"] = ":/images/background/Mist.png";
    BackgroundMap["smoke"] = ":/images/background/Mist.png";
    BackgroundMap["haze"] = ":/images/background/Mist.png";
    BackgroundMap["sand"] = ":/images/background/Mist.png";
    BackgroundMap["fog"] = ":/images/background/Mist.png";
    BackgroundMap["dust"] = ":/images/background/Mist.png";
    BackgroundMap["volcanic ash"] = ":/images/background/Mist.png";
    BackgroundMap["squalls"] = ":/images/background/Wind.png";
    BackgroundMap["tornado"] = ":/images/background/Wind.png";

    BackgroundMap["few clouds"] = ":/images/background/Cloudy.png";
    BackgroundMap["scattered clouds"] = ":/images/background/Cloudy.png";
    BackgroundMap["broken clouds"] = ":/images/background/Cloudy.png";
    BackgroundMap["overcast clouds"] = ":/images/background/Cloudy.png";
}

QString WeatherBackground::getBackgroundPath(const QString &description) const {
    return BackgroundMap.value(description, ":/images/background/default.png");
}
