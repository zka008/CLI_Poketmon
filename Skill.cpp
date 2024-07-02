#include "Skill.h"

Skill::Skill() {}
Skill::Skill(string name, int damage, int mp) :name(name), damage(damage), mp(mp) {}

string Skill::getName() const {
	return this->name;
}
int Skill::getDamage() const {
	return this->damage;
}
int Skill::getMp() const {
	return this->mp;
}