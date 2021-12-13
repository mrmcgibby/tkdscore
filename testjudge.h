#ifndef TESTJUDGE_H
#define TESTJUDGE_H

#include "judge.h"

#include <QTimer>

class TestJudge : public Judge
{
    Q_OBJECT
public:
    explicit TestJudge(QObject *parent = nullptr);

private slots:
    void genHit();

private:
    QTimer m_timer;
};

#endif // TESTJUDGE_H
