#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "settings.h"
#include "testjudge.h"

using namespace std::chrono;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_timeoutTimer.setSingleShot(true);
    m_updateTimer.start(10);
    connect(&m_updateTimer, SIGNAL(timeout()), this, SLOT(updateClock()));
    connect(&m_timeoutTimer, SIGNAL(timeout()), this, SLOT(timesUp()));

    Settings settings;
    m_prevTime = settings.roundTime();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playButton_clicked()
{
    m_playTime.start();
    m_timeoutTimer.start(timeLeft());
}

void MainWindow::on_pauseButton_clicked()
{
    if (!m_playTime.isValid())
        return;

    m_prevTime -= milliseconds(m_playTime.elapsed());
    m_playTime.invalidate();
    m_timeoutTimer.stop();
}

void MainWindow::updateClock()
{
    int m = timeLeft().count();
    auto str = QString("%1:%2")
        .arg(m/1000/60)
        .arg(m/1000%60, 2, 10, QChar('0'));
    ui->clock->setText(str);
}

void MainWindow::timesUp()
{
    m_updateTimer.stop();
}

void MainWindow::setPoints(Player player, int points)
{
    QLabel* label;
    switch (player)
    {
    case Player::hong:  label = ui->hong_score;  break;
    case Player::chung: label = ui->chung_score; break;
    }
    label->setText(QString().setNum(points));
}

milliseconds MainWindow::timeLeft()
{
    return m_prevTime - milliseconds(m_playTime.isValid() ? m_playTime.elapsed() : 0);
}

bool MainWindow::activeMatch()
{
    return m_playTime.isValid();
}
