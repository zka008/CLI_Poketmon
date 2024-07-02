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

    // ���� �� �ε� ����� ���� �Լ�
    void saveGameToFile(string filename);
    void loadGameFromFile(string filename);
};

