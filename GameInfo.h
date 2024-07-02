#pragma once
#include "header.h"
#include "Player.h"
#include "Poketmon.h"
#include "Item.h"
class GameInfo {
public:
    static GameInfo Instance;
    GameInfo();
    Player player;
    Poketmon poketmon;

    // 저장 및 로드 기능을 위한 함수
    void saveGameToFile(string filename);
    void loadGameFromFile(string filename);
};

