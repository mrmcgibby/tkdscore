#include "testjudge.h"

TestJudge::TestJudge(QObject *parent)
    : Judge(parent)
{
    m_timer.start(1000);

    connect(&m_timer, SIGNAL(timeout()), this, SLOT(genHit()));
}

void TestJudge::genHit()
{
    emit score(Player::hong, ScoreType::punch);
}
