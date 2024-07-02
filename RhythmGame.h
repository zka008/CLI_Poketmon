#pragma once
#include "header.h"

class RhythmGame
{
public:

    RhythmGame();
    void Game();
    void PlayGame(int keyDelay);
    char RandomKey();
    std::string RandomStringKey();

private:
    static const int DURATION = 60; // 게임 지속 시간
};
