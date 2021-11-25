#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_timeoutTimer.setSingleShot(true);
    m_updateTimer.start(10);
    connect(&m_updateTimer, SIGNAL(timeout()), this, SLOT(updateClock()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playButton_clicked()
{
    m_playTime.start();
    m_timeoutTimer.start(msecLeft());
}

void MainWindow::on_pauseButton_clicked()
{
    m_prevmsec -= m_playTime.elapsed();
    m_playTime.invalidate();
    m_timeoutTimer.stop();
}

void MainWindow::updateClock()
{
    auto m = msecLeft();
    auto str = QString("%1:%2")
        .arg(m/1000/60)
        .arg(m/1000%60, 2, 10, QChar('0'));
    ui->clock->setText(str);
}

qint64 MainWindow::msecLeft()
{
    return m_prevmsec - (m_playTime.isValid() ? m_playTime.elapsed() : 0);
}
