#pragma once
#include "header.h"
#include "Skill.h"

//포켓몬 리스트 클래스
class Poketmon {
private:
    string name;
    int level;
    int hp;
    int mp;
    string info;
    int dm;
    Skill skill1;
    Skill skill2;
    Skill skill3;

public:
    Poketmon();
    Poketmon(string name, int level, int hp, int mp, string info, int dm, Skill(skill1), Skill(skill2), Skill(skill3));

    string getName() const;
    int getLevel() const;
    int getHP() const;
    int getMP() const;
    int getdm() const;
    void setHP(int reduceHP);
    void setMP(int reduceMP);
    string getInfo() const;
    Skill getSkill1() const;
    Skill getSkill2() const;
    Skill getSkill3() const;

    //리스트에 있는 정보 출력
    static void printPocketmonList(vector<Poketmon> v);
    //모든 포켓몬에 대한 정보를 담은 리스트 반환
    static vector<Poketmon> LoadAllPoketmon();
};