#pragma once
#include "header.h"
#include "Poketmon.h"
#include "Item.h"
class Player {
private:
    string name;
    int level;
    int exp;
    int money;
    vector<Poketmon> myPokemons;
    vector<Item> myItems;

public:
    Player();
    Player(int money, vector<Poketmon>& myPokemons, vector<Item>& myItems);

    int getMoney();
    vector<Poketmon> getMyPoketmons();
    vector<Item> getMyItems();

    void setMoney(int money);
    void addMyPoketmons(Poketmon poketmon);
    void addMyItems(Item& item);
    void delPoketmon(int idx);
    void delItem(int idx);
    void clearItem();
};