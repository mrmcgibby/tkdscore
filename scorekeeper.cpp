#include "scorekeeper.h"

#include "testjudge.h"

ScoreKeeper::ScoreKeeper(QObject *parent)
    : QObject(parent)
{
}

void ScoreKeeper::addJudge(Judge* judge)
{
    judge->setParent(this);
    m_judges.push_back(judge);
    int i = m_judges.size() - 1;
    connect(m_judges[i], &Judge::score, this, [this, i](Player player, ScoreType type) {
        judgeScore(i, player, type);
    });
}

void ScoreKeeper::enableScoring(bool enable)
{
    m_scoringEnabled = enable;
}

void ScoreKeeper::judgeScore(int judge, Player player, ScoreType type)
{
    if (!m_scoringEnabled)
        return;

    int points;
    switch (type)
    {
    case ScoreType::punch:    points = 1; break;
    case ScoreType::body:     points = 2; break;
    case ScoreType::head:     points = 3; break;
    case ScoreType::spinbody: points = 4; break;
    case ScoreType::spinhead: points = 5; break;
    }

    m_score[player] += points;

    emit scoreChanged(player, m_score[player]);
}
