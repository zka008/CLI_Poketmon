#include "Player.h"

Player::Player() {}
Player::Player(int money, vector<Poketmon>& myPokemons, vector<Item>& myItems) {
	this->money = money;
	this->myPokemons = myPokemons;
	this->myItems = myItems;
}

int Player::getMoney() {
	return money;
}
vector<Poketmon> Player::getMyPoketmons() {
	return myPokemons;
}
vector<Item> Player::getMyItems() {
	return myItems;
}

void Player::setMoney(int money) {
	this->money = money;
}
void Player::addMyPoketmons(Poketmon poketmon) {
	myPokemons.push_back(poketmon);
}
void Player::addMyItems(Item& item) {
	myItems.push_back(item);
}
void Player::delPoketmon(int idx) {
	myPokemons.erase(myPokemons.begin() + idx);
}
void Player::delItem(int idx) {
	myItems.erase(myItems.begin() + idx);
}
void Player::clearItem() {
	myItems.clear();
}