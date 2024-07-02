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

    //상점에 판매하는 아이템에 대한 정보를 담은 리스트 반환
    static vector<Item> LoadAllItem();

    //리스트에 있는 아이템 정보 출력
    static void printItemList(vector<Item> item);
    static void printItemListb(vector<Item> item);
};