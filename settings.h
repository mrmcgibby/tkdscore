#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>

#include <chrono>

class Settings : public QSettings
{
public:
    explicit Settings(QObject *parent = nullptr);

    std::chrono::seconds roundTime();
};

#endif // SETTINGS_H
