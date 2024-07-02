#pragma once
#include "header.h"

class Skill {
private:
    string name;
    int damage;
    int mp;

public:
    Skill();
    Skill(string name, int damage, int mp);

    string getName() const;
    int getDamage() const;
    int getMp() const;
};