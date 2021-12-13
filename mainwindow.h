#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "common.h"

#include <QMainWindow>
#include <QTimer>
#include <QElapsedTimer>
#include <QLabel>

#include <chrono>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setPoints(Player, int points);

private slots:
    void on_playButton_clicked();
    void on_pauseButton_clicked();
    void updateClock();
    void timesUp();

private:
    std::chrono::milliseconds timeLeft();
    bool activeMatch();

    Ui::MainWindow *ui;

    QTimer m_updateTimer;
    QTimer m_timeoutTimer;
    QElapsedTimer m_playTime;
    std::chrono::milliseconds m_prevTime;
    int m_round = 1;
};
#endif // MAINWINDOW_H
