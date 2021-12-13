#ifndef SCOREKEEPER_H
#define SCOREKEEPER_H

#include "judge.h"
#include "common.h"

#include <QObject>
#include <QMap>

class ScoreKeeper : public QObject
{
    Q_OBJECT
public:
    explicit ScoreKeeper(QObject *parent = nullptr);

    void addJudge(Judge* judge);

signals:
    void scoreChanged(Player player, int points);

public slots:
    void enableScoring(bool = true);

private slots:
    void judgeScore(int judge, Player player, ScoreType type);

private:
    QVector<Judge*> m_judges;
    QMap<Player, int> m_score;
    bool m_scoringEnabled;
};

#endif // SCOREKEEPER_H
