#include "header.h"
#include "Poketmon.h"

Poketmon::Poketmon() {}
Poketmon::Poketmon(string name, int level, int hp, int mp, string info, int dm, Skill skill1, Skill skill2, Skill skill3)
	: name(name), level(level), hp(hp), mp(mp), info(info), dm(dm), skill1(skill1), skill2(skill2), skill3(skill3) {}
string Poketmon::getName() const
{
	return name;
}

int Poketmon::getLevel() const
{
	return level;
}

int Poketmon::getHP() const
{
	return hp;
}

int Poketmon::getMP() const
{
	return mp;
}
void Poketmon::setHP(int reduceHP)
{
	hp = reduceHP;
}
void Poketmon::setMP(int reduceMP)
{
	mp = reduceMP;
}
string Poketmon::getInfo() const 
{
	return info;
}
int Poketmon::getdm() const 
{
	return dm;
}
Skill Poketmon::getSkill1() const 
{
	return this->skill1;
}

Skill Poketmon::getSkill2() const 
{
	return this->skill2;
} 

Skill Poketmon::getSkill3() const 
{
	return this->skill3;
}

void Poketmon::printPocketmonList(vector<Poketmon> v) 
{
	int i = 1;

	for (const Poketmon& card : v)
	{
		cout << " ������ȣ" << i << " �̸�: " << card.getName() << ", Level: " << card.getLevel()
			<< ", HP: " << card.getHP() << ", MP: " << card.getMP() << ", Ư��: " << card.getInfo() << endl;	 
		i++;
	}
}

vector<Poketmon> Poketmon::LoadAllPoketmon()
{
    vector<Poketmon> cardList;

    //1�� ���� ������
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(50, 100);

    int Damage = dis(gen);

    //2�� ���� ������
    random_device rd1;
    mt19937 gen1(rd1());
    uniform_int_distribution<> dis1(100, 200);

    int Damage1 = dis1(gen1);

    //3�� ���� ������
    random_device rd2;
    mt19937 gen2(rd2());
    uniform_int_distribution<> dis2(200, 300);

    int Damage2 = dis2(gen2);

    //1��
    cardList.push_back(Poketmon("ġ�ڸ�Ÿ", 1, 500, 300, "[�ٻ��]������ ��û ������ �� �����̻� �ɸ��� �ʴ´�.", Damage,
        Skill("������ ����", 100, 30),
        Skill("������ ��", 150, 50),
        Skill("�ʸ���Ʈ", 200, 100)));
    cardList.push_back(Poketmon("��������", 1, 550, 300, "[�������ϸ�]Ÿ������ �Ҳ�", Damage,
        Skill("ȸ�����Ҳ�", 100, 30),
        Skill("�Ҳɼ���", 150, 50),
        Skill("ȭ�����", 200, 100)));
    cardList.push_back(Poketmon("�ް��Ͽ�", 1, 600, 300, "[��� ���ϸ�]������ ��û ������ �� �����̻� �ɸ��� �ʴ´�.", Damage,
        Skill("�ֶ��", 100, 30),
        Skill("�ź�����", 150, 50),
        Skill("�Ŀ���", 200, 100)));
    cardList.push_back(Poketmon("���̸���", 1, 550, 300, "[�ٻ�� ���ϸ�]������ ��û ������ �� �����̻� �ɸ��� �ʴ´�.", Damage,
        Skill("���Ѹ���", 100, 30),
        Skill("����Ѹ���", 150, 50),
        Skill("��������", 200, 100)));
    cardList.push_back(Poketmon("������", 1, 500, 300, "[�������ϸ�]Ÿ������ �Ҳ�", Damage,
        Skill("����", 100, 30),
        Skill("ȸ�����Ҳ�", 150, 50),
        Skill("�Ҳ���ġ", 200, 100)));
    cardList.push_back(Poketmon("��������", 1, 550, 400, "[ū��]��ݴ���", Damage,
        Skill("������", 100, 30),
        Skill("�ĵ�Ÿ��", 150, 50),
        Skill("���̵������", 200, 100)));
    cardList.push_back(Poketmon("���̹�", 1, 600, 400, "[����]Ÿ������ �Ҳ�", Damage,
        Skill("ũ�ν���", 100, 30),
        Skill("���", 150, 50),
        Skill("ȭ���ڵ���", 200, 100)));
    cardList.push_back(Poketmon("������", 1, 500, 400, "[������]��ī�ο� ���� ���� ����, ����", Damage,
        Skill("������", 100, 30),
        Skill("�������Ʈ", 150, 50),
        Skill("���̵������", 200, 100)));
    cardList.push_back(Poketmon("������", 1, 500, 400, "[ū��]��ݴ���", Damage,
        Skill("��ö����", 100, 30),
        Skill("���ǵ彺Ÿ", 150, 50),
        Skill("�ֱ��θ���", 200, 100)));

    //2��
    cardList.push_back(Poketmon("���ġ", 2, 700, 900, "[�븻]�߻� ���ϸ󿡰Լ� �ݵ�� ����ĥ �� �ִ�.", Damage1,
        Skill("�ӵ��", 200, 30),
        Skill("������ǳ", 250, 50),
        Skill("��������", 300, 100)));
    cardList.push_back(Poketmon("�ο��", 2, 700, 600, "[�븻����]�Ҹ�, ��ī�ο� ��", Damage1,
        Skill("�ʸ���Ʈ", 200, 30),
        Skill("�����ũ", 250, 50),
        Skill("����", 300, 100)));
    cardList.push_back(Poketmon("�ٲ���", 2, 800, 600, "[������]�� ���ϸ��� ���߷��� ����߸� �� ����.������ ȸ������ �����Ѵ�, ����� ������ �� �� �ִ�.", Damage1,
        Skill("������ ������", 200, 30),
        Skill("�͵�", 250, 50),
        Skill("��ǳ", 300, 100)));
    cardList.push_back(Poketmon("�����", 2, 700, 600, "[��������]���� ���", Damage1,
        Skill("�Ҳɼ���", 200, 30),
        Skill("�����", 250, 50),
        Skill("��ǳ", 300, 100)));
    cardList.push_back(Poketmon("�����", 2, 800, 600, "[����]���� ���°� ���� �ʴ´�.", Damage1,
        Skill("�ذ�", 200, 30),
        Skill("�Ҳɼ���", 250, 50),
        Skill("�Ҵ빮��", 300, 100)));
    cardList.push_back(Poketmon("��ũ�δ���", 2, 850, 400, "[ū��]��ݴ���", Damage1,
        Skill("��ö����", 200, 30),
        Skill("��¦����", 250, 50),
        Skill("ȸ���θ�", 300, 100)));
    cardList.push_back(Poketmon("�Ѿ�", 2, 700, 400, "[��]�ǿ�, ��������, ��������", Damage1,
        Skill("�˼���ġ", 200, 30),
        Skill("�ºα�����", 250, 50),
        Skill("�̻��Ѻ�", 300, 100)));
    cardList.push_back(Poketmon("��Ÿ��", 2, 800, 300, "[��]����, ����, ���Ǻ���", Damage1,
        Skill("������", 200, 30),
        Skill("��ġ��", 250, 50),
        Skill("�ֱ��θ���", 300, 100)));
    cardList.push_back(Poketmon("��������", 2, 750, 500, "[��]������ �Թ��� �ۺ״´�.", Damage1,
        Skill("ȸ�����Ҳ�", 200, 30),
        Skill("�Ҳɼ���", 250, 50),
        Skill("ȭ�����", 300, 100)));


    //3��
    cardList.push_back(Poketmon("���츶", 3, 900, 400, "[��Ʈ]�� Ÿ�� ����� ��ȿȭ�Ѵ�.", Damage2,
        Skill("�͵�", 300, 30),
        Skill("��Ư�Ѻ��", 350, 50),
        Skill("����ƺ극��ũ", 400, 100)));
    cardList.push_back(Poketmon("������", 3, 900, 900, "[Ǯ]���ϼ� �������� ƴ������", Damage2,
        Skill("������", 300, 30),
        Skill("������", 350, 50),
        Skill("����", 400, 100)));
    cardList.push_back(Poketmon("����", 3, 1000, 1300, "[��������]����, ����, ����", Damage2,
        Skill("������ġ", 300, 30),
        Skill("������", 350, 50),
        Skill("����â", 400, 100)));
    cardList.push_back(Poketmon("����", 3, 1000, 900, "[Ǯ]���ϼ� �������� ƴ������", Damage2,
        Skill("�ΰ��ֱ�", 300, 30),
        Skill("����", 350, 50),
        Skill("������", 400, 100)));
    cardList.push_back(Poketmon("�ؼ���", 3, 1100, 1000, "[Ǯ ����]��û�� �� ���ǵ尡 2��� ������.", Damage2,
        Skill("����Ʈ�ǵ�", 300, 30),
        Skill("���濡��", 350, 50),
        Skill("������", 400, 100)));
    cardList.push_back(Poketmon("�Ϸο�", 3, 900, 400, "[��, ����]�� ���ϸ��� �޼Ҹ� ������ Ȯ���� ����.", Damage2,
        Skill("��ö����", 300, 30),
        Skill("�ڸ���ġ", 350, 50),
        Skill("�һ�", 400, 100)));
    cardList.push_back(Poketmon("����", 3, 1000, 1000, "[����]������ ���� ���� ƨ�ܳ��� ������ ���� ���� ���� ���� �ִ�.", Damage2,
        Skill("����", 300, 30),
        Skill("����", 350, 50),
        Skill("������", 400, 100)));
    cardList.push_back(Poketmon("������", 3, 1100, 1000, "[����]������ ���� ���� ƨ�ܳ��� ������ ���� ���� ���� ���� �ִ�.", Damage2,
        Skill("�������Ʈ", 300, 30),
        Skill("��������", 350, 50),
        Skill("���̵������", 400, 100)));
    cardList.push_back(Poketmon("������", 3, 1000, 500, "[����]�˰���, ���Ӹ�, �ִ��ϰݱ⸦ ��ȿȭ�ϸ� ü���� ����á�� �� �ϰݿ� �������� �ʴ´�.", Damage2,
        Skill("������ġ��", 300, 30),
        Skill("�����ġ��", 350, 50),
        Skill("������", 400, 100)));
    cardList.push_back(Poketmon("�ձ���", 3, 1100, 800, "[��]������ ������ 5�ϰ� �� ������ �ȴ�.", Damage2,
        Skill("������ġ", 300, 30),
        Skill("������μ���", 350, 50),
        Skill("�ֱ��θ���", 400, 100)));
    cardList.push_back(Poketmon("��������", 3, 1000, 800, "[����]���� ���°� ���� �ʴ´�.", Damage2,
        Skill("������ġ", 300, 30),
        Skill("�����뷡", 350, 50),
        Skill("������", 400, 100)));
    cardList.push_back(Poketmon("���ڸ�", 3, 1100, 1500, "[�Ҳ�]��û�� �Ҳ��� �ۺ״´�. �������� �ʴ� ���� �����ϴ�.", Damage2,
        Skill("�Ҳɼ���", 300, 30),
        Skill("�Ҳ���ġ", 350, 50),
        Skill("����", 400, 100)));
    cardList.push_back(Poketmon("���ڿ�", 3, 950, 1200, "[������]���� �׸��ڹ�� Ư���� ��� ȿ���� ���ȴ�.", Damage2,
        Skill("�巡��ũ��", 300, 30),
        Skill("���Ǽ���", 350, 50),
        Skill("�����ĵ�", 400, 100)));
    cardList.push_back(Poketmon("������", 3, 950, 800, "[��ö]���߷��� �������� ������ ����� ȸ���� ������ �����Ѵ�.", Damage2,
        Skill("��主��", 300, 30),
        Skill("���ǵ彺Ÿ", 350, 50),
        Skill("���뿵��", 400, 100)));
    cardList.push_back(Poketmon("��Ű", 3, 1000, 800, "[��]Ǯ������ ������ ���� �ʴ´�.", Damage2,
        Skill("�����Ŀ�", 300, 30),
        Skill("�ֱ��θ���", 350, 50),
        Skill("�߽�", 400, 100)));
    cardList.push_back(Poketmon("����", 3, 1000, 1900, "[����]�ϰݱⰡ ������ ������ ü���� ������ ���¿��� �ϰݿ� �������� �ʴ´�.", Damage2,
        Skill("�����Ǽ���", 300, 30),
        Skill("�õ���ġ", 350, 50),
        Skill("����", 400, 100)));
    cardList.push_back(Poketmon("�Ƹ��Ƶ���", 3, 1000, 700, "[������]�Ҹ�, ������ �˸�, ��������", Damage2,
        Skill("��主��", 300, 30),
        Skill("�ź��Ǻ���", 350, 50),
        Skill("�ֱ��θ���", 400, 100)));
    cardList.push_back(Poketmon("�ȳ�", 3, 950, 800, "[������]�� Ÿ�� ����� ���� �ʴ´�.", Damage2,
        Skill("��������", 300, 30),
        Skill("�̷�����", 350, 50),
        Skill("����������", 400, 100)));
    cardList.push_back(Poketmon("�ߵ�ŷ", 3, 1100, 1300, "[��, ������]ȥ�� ���¿� ������ �ʴ´�.", Damage2,
        Skill("������", 300, 30),
        Skill("ȯ���", 350, 50),
        Skill("������Ű�׽ý�", 400, 100)));

    cardList.push_back(Poketmon("�ߺξ�", 2, 1000, 600, "[�븻����]�Ҹ�, ��ī�ο� ��", Damage2,
        Skill("��¦����", 300, 30),
        Skill("����ġ��", 350, 50),
        Skill("�ӿ�������", 400, 100)));
    cardList.push_back(Poketmon("������", 3, 1000, 500, "[������]��ũ��, �����̷�", Damage2,
        Skill("�������̺�", 300, 30),
        Skill("���ǵ彺Ÿ", 350, 50),
        Skill("��Ʈü����", 400, 100)));
    cardList.push_back(Poketmon("������", 3, 900, 700, "[�븻]�Ⱦ�, ����, ��ų��ũ", Damage2,
        Skill("����", 300, 30),
        Skill("��ö�ָ�", 350, 50),
        Skill("ȭ�����", 400, 100)));
    cardList.push_back(Poketmon("���ڸ�", 3, 900, 500, "[��������]����, ����, ����", Damage2,
        Skill("ī����", 300, 30),
        Skill("Į��ġ��", 350, 50),
        Skill("�ºα�����", 400, 100)));
    cardList.push_back(Poketmon("����", 3, 900, 1100, "[��������]����, ����, ����", Damage2,
        Skill("�ް�����ġ", 300, 30),
        Skill("�ֱ��θ���", 350, 50),
        Skill("���̷κ�", 400, 100)));
    cardList.push_back(Poketmon("�Ḹ��", 3, 1100, 2000, "[Ǫ��]��, �͵� ���°� ���� �ʴ´�.", Damage2,
        Skill("�����û���", 300, 30),
        Skill("���ɺ�", 350, 50),
        Skill("�帲��ũ", 400, 100)));
    cardList.push_back(Poketmon("�ڻ�ȣ", 3, 900, 1500, "[��]�Ϳ����� �����ϱ� �ηƴ�.", Damage2,
        Skill("�͵�", 300, 30),
        Skill("����̱�", 350, 50),
        Skill("���Ǹͼ�", 400, 100)));
    cardList.push_back(Poketmon("Ű��Ű", 3, 950, 1500, "[�븻, ������]Ǯ���� �ʴ´�.", Damage2,
        Skill("��ũ�γ�����", 300, 30),
        Skill("���ǵ彺Ÿ", 350, 50),
        Skill("���̾�����", 400, 100)));

    cardList.push_back(Poketmon("���ƽ", 3, 1000, 800, "[������]�ǿ�, �ϴ�������, ���", Damage2,
        Skill("õ����Ű��", 300, 30),
        Skill("�ź��Ǻ���", 350, 50),
        Skill("����", 400, 100)));

    cardList.push_back(Poketmon("���̰�", 3, 900, 700, "[������]�Ҹ�, �����Ǿ˸�, ��������", Damage2,
        Skill("����Ʈ", 300, 30),
        Skill("���뿵��", 350, 50),
        Skill("�������", 400, 100)));
    cardList.push_back(Poketmon("����", 3, 900, 1800, "[����]�˰���, ����", Damage2,
        Skill("��ö����", 300, 30),
        Skill("������", 350, 50),
        Skill("�ֱ��θ���", 400, 100)));
    cardList.push_back(Poketmon("�س���", 3, 900, 1200, "[Ǯ]���ϼ�, ���Ŀ�, ������", Damage2,
        Skill("�ٶ�����Ű��", 300, 30),
        Skill("���°ſ�", 350, 50),
        Skill("��������", 400, 100)));
    cardList.push_back(Poketmon("�ط��", 3, 1000, 1300, "[Ǯ]��� ���°� �Ǿ��� ��, ���� ���� �������� �پ���.", Damage2,
        Skill("�ݼ���", 300, 30),
        Skill("�ݼӺм�", 350, 50),
        Skill("��ħ", 400, 100)));

    return cardList;
}

