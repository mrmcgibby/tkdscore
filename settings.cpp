#include "settings.h"

using namespace std::chrono;

Settings::Settings(QObject *parent)
    : QSettings(parent)
{
}

seconds Settings::roundTime()
{
    return seconds(value("round_time", 60).toInt());
}
