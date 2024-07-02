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
//������ �Ǹ��ϴ� �����ۿ� ���� ������ ���� ����Ʈ ��ȯ
vector<Item> Item::LoadAllItem() {
	vector<Item> itemlist;
	itemlist.push_back(Item("��ó��", "HP", 200, 200));
	itemlist.push_back(Item("������ó��", "HP", 500, 600));
	itemlist.push_back(Item("��޻�ó��", "HP", 800, 1200));
	itemlist.push_back(Item("���ִ¹�", "MP", 200, 200));
	itemlist.push_back(Item("ưư��ũ", "MP", 500, 600));
	itemlist.push_back(Item("�ĸ�����ũ", "MP", 500, 1200));
	return itemlist;
}
//����Ʈ�� �ִ� ������ ���� ���
void Item::printItemList(vector<Item> list)
{
	int i = 1;

	for (Item item : list)
	{   //setw�� Ȱ���Ͽ� ���ڿ����� �������� ����
		cout << i << "." << setw(10) << item.getName() << setw(2) << " ȿ��:" << item.getInfo() << " ȸ�� " << item.getEffect() << " ����:" << item.getPrice() << endl;
		i++;
	}
}
//����Ʈ�� �ִ� ������ ���� ���
void Item::printItemListb(vector<Item> list)
{
	int i = 1;

	for (Item item : list)
	{   //setw�� Ȱ���Ͽ� ���ڿ����� �������� ����
		cout << i << "." << setw(10) << item.getName() << setw(2) << "  ȿ��:" << item.getInfo() << "  ȸ�� " << item.getEffect() << endl;
		i++;
	}
}