#pragma once
#include "header.h"
class Item {
private:
    string name;
    string info;
    int effect;
    int price;
public:
    Item();
    Item(const char* name, const char* info, int effect, int price);

    string& getName();
    string& getInfo();
    int getPrice();
    int getEffect();

    void setName(string& name);
    void setInfo(string& info);
    void setPrice(int price);

    //������ �Ǹ��ϴ� �����ۿ� ���� ������ ���� ����Ʈ ��ȯ
    static vector<Item> LoadAllItem();

    //����Ʈ�� �ִ� ������ ���� ���
    static void printItemList(vector<Item> item);
    static void printItemListb(vector<Item> item);
};