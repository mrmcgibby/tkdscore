#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QElapsedTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_playButton_clicked();
    void on_pauseButton_clicked();
    void updateClock();

private:
    qint64 msecLeft();

    Ui::MainWindow *ui;

    QTimer m_updateTimer;
    QTimer m_timeoutTimer;
    QElapsedTimer m_playTime;
    qint64 m_prevmsec = 60*1000;
    int m_round = 1;
};
#endif // MAINWINDOW_H
