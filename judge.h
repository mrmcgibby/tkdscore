#ifndef JUDGE_H
#define JUDGE_H

#include "common.h"

#include <QObject>

class Judge : public QObject
{
    Q_OBJECT
public:
    explicit Judge(QObject *parent = nullptr);

signals:
    void score(Player player, ScoreType type);
};

#endif // JUDGE_H
