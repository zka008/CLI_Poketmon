#include "Item.h"

Item::Item() {}
Item::Item(const char* name, const char* info, int effect, int price) {
	this->name = name;
	this->info = info;
	this->effect = effect;
	this->price = price;
}

string& Item::getName() {
	return name;
}
string& Item::getInfo() {
	return info;
}
int Item::getPrice() {
	return price;
}
int Item::getEffect() {
	return effect;
}

void Item::setName(string& name) {
	this->name = name;
}
void Item::setInfo(string& effect) {
	this->info = effect;
}
void Item::setPrice(int price) {
	this->price = price;
}
//상점에 판매하는 아이템에 대한 정보를 담은 리스트 반환
vector<Item> Item::LoadAllItem() {
	vector<Item> itemlist;
	itemlist.push_back(Item("상처약", "HP", 200, 200));
	itemlist.push_back(Item("좋은상처약", "HP", 500, 600));
	itemlist.push_back(Item("고급상처약", "HP", 800, 1200));
	itemlist.push_back(Item("맛있는물", "MP", 200, 200));
	itemlist.push_back(Item("튼튼밀크", "MP", 500, 600));
	itemlist.push_back(Item("후르츠밀크", "MP", 500, 1200));
	return itemlist;
}
//리스트에 있는 아이템 정보 출력
void Item::printItemList(vector<Item> list)
{
	int i = 1;

	for (Item item : list)
	{   //setw를 활용하여 문자열들을 보기좋게 정렬
		cout << i << "." << setw(10) << item.getName() << setw(2) << " 효과:" << item.getInfo() << " 회복 " << item.getEffect() << " 가격:" << item.getPrice() << endl;
		i++;
	}
}
//리스트에 있는 아이템 정보 출력
void Item::printItemListb(vector<Item> list)
{
	int i = 1;

	for (Item item : list)
	{   //setw를 활용하여 문자열들을 보기좋게 정렬
		cout << i << "." << setw(10) << item.getName() << setw(2) << "  효과:" << item.getInfo() << "  회복 " << item.getEffect() << endl;
		i++;
	}
}