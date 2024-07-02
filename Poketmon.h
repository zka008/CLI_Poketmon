#pragma once
#include "header.h"
#include "Skill.h"

//���ϸ� ����Ʈ Ŭ����
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

    //����Ʈ�� �ִ� ���� ���
    static void printPocketmonList(vector<Poketmon> v);
    //��� ���ϸ� ���� ������ ���� ����Ʈ ��ȯ
    static vector<Poketmon> LoadAllPoketmon();
};