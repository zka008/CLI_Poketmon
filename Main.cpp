#include "header.h"
#include "Poketmon.h"
#include "GameInfo.h"
#include "Player.h"
#include "Item.h"
#include "Skill.h"
#include "Rhythmgame.h"

//미니 게임 실행
void RhythmGame1()
{
	RhythmGame game;
	game.Game(); // 게임 실행
}

//로비 선택지 출력
void printMenu()
{
	cout << "\n<===================================로비 창===================================>" << endl;
	cout << "1. 전투" << endl;
	cout << "2. 보유 포켓몬" << endl;
	cout << "3. 상점" << endl;
	cout << "4. 포켓몬 도감" << endl;
	cout << "5. 미니게임" << endl;
	cout << "6. 종료" << endl;
	cout << "<===================================로비 창===================================>" << endl;
	cout << "항목 선택 : ";
}

//전투 화면 출력
void printBattle(Poketmon computerPoketmon, Poketmon playerPoketmon)
{
	cout << endl;
	cout << "   (\\__/) 플레이어 포켓몬: " << playerPoketmon.getName() << endl;
	cout << "   (pㅅp) 희귀도: " << playerPoketmon.getLevel() << endl;
	cout << "   / 　 づHP: " << playerPoketmon.getHP() << endl;
	cout << "          MP: " << playerPoketmon.getMP() << endl;

	cout << endl;
	cout << "          vs" << endl;
	cout << endl << endl;

	cout << "  (\\__/)  야생의 포켓몬: " << computerPoketmon.getName() << endl;
	cout << "  (●ㅅ●)  희귀도: " << computerPoketmon.getLevel() << endl;
	cout << "  /   づ  HP: " << computerPoketmon.getHP() << endl;
	cout << "          MP: " << computerPoketmon.getMP() << endl << endl;
	cout << "\n<==================================전투 시작==================================>\n" << endl;
}

//전투 선택지 출력
int printSelection()
{
	int select;
	cout << "<-------------->" << endl;
	cout << " | 1. 공격    |" << endl;
	cout << " | 2. 스킬    |" << endl;
	cout << " | 3. 아이템  |" << endl;
	cout << " | 4. 도망    |" << endl;
	cout << "<-------------->" << endl;
	cout << "항목 선택 : ";
	cin >> select;

	return select;
}

//스킬 사용 공격 로직
void skillLogic(Poketmon& attack, Poketmon& target, const Skill& skill) {
	target.setHP(target.getHP() - skill.getDamage());
	attack.setMP(attack.getMP() - skill.getMp());
	cout << "\n<=============================================================================>\n" << endl;
	cout << "[" << attack.getName() << "이(가) " << skill.getName() << "을(를) 사용을 하였다.]" << endl;
	cout << "[" << skill.getDamage() << "만큼 데미지를 주었습니다.]" << endl;
	cout << "\n<=============================================================================>\n" << endl;
}

//컴퓨터 공격 로직
void comAttack(Poketmon& com, Poketmon& player) {
	//시드값을 얻기 위한 random_device 생성.
	random_device rd;
	//random_device 를 통해 난수 생성 엔진을 초기화 한다.
	mt19937 gen(rd());
	//0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	uniform_int_distribution<int> dis(0, 50);
	int rand = dis(gen);
	while (true) {
		if (rand < 25) {
			// 컴퓨터 일반공격 : 컴퓨터 포켓몬의 HP를 공격력만큼 감소시킴
			cout << "[" << com.getName() << "이(가) 공격합니다.]" << endl;
			cout << "[" << com.getdm() << "만큼 데미지를 주었습니다.]" << endl;
			player.setHP(player.getHP() - com.getdm());
			break;
		}
		else {
			if (com.getMP() < 30) {
				rand = 1;
				continue;
			}
			if (rand < 15) {
				skillLogic(com, player, com.getSkill1());
				break;
			}
			else if (rand < 31) {
				skillLogic(com, player, com.getSkill2());
				break;
			}
			else {
				skillLogic(com, player, com.getSkill3());
				break;
			}
		}
	}
}

//처음 실행 시 또는 로비로 돌아왔을 때 양식(플레이어 정보, 메뉴 정보 등) 출력
void catchPoketmon(Poketmon target)
{
	int select;
	cout << "\n===============================" << endl;
	cout << "1. " << target.getName() << "잡기" << endl;
	cout << "2. " << target.getName() << "풀어주기" << endl;
	cout << "===============================" << endl;
	cout << "[선택하기] : ";
	cin >> select;

	switch (select)
	{
	case 1:
		/*if (rand() % 2 == 0)*/
		{
			GameInfo::Instance.player.addMyPoketmons(target);
			cout << target.getName() << "을(를) 포획했습니다." << endl;
			return;
		}
		/*else
		{
			cout << "\n포켓몬을 잡지 못했습니다.\n" << endl;*/
			//return;
		//}
	case 2:
		cout << "\n" << target.getName() << "을(를) 풀어주었습니다." << endl;
		break;
	}
	cout << "\n" << target.getName() << "이(가) 야생으로 돌아갔습니다." << endl << endl;
	Sleep(1300);
	return;
}

//전투 메뉴 기능
void funcBattle()
{
	if (GameInfo::Instance.poketmon.getName() == "")
	{
		cout << "\n";
		cout << " !!선택한 포켓몬이 존재하지 않아 전투에 참여할 수 없습니다.!!\n" << endl;
		return;
	}
	cout << "<==================================전투 시작==================================>" << endl;

	//모든 포켓몬 리스트를 poketmon에 넣어준거고
	vector<Poketmon> poketmon = Poketmon::LoadAllPoketmon();

	//포켓몬 카드 랜덤 입력
	//시드값을 얻기 위한 random_device 생성.
	random_device rd;
	//random_device 를 통해 난수 생성 엔진을 초기화 한다.
	mt19937 gen(rd());
	//0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
	uniform_int_distribution<int> dis(0, 50);
	int random = dis(gen);

	Poketmon playerPoketmon = GameInfo::Instance.poketmon; //플레이어 첫번째 포켓몬 소환
	Poketmon computerPoketmon = poketmon[random]; //컴퓨터 포켓몬 랜덤으로 소환


	Poketmon::Poketmon();

	//플레이어 포켓몬 스킬 정보
	Skill skill1 = playerPoketmon.getSkill1();
	Skill skill2 = playerPoketmon.getSkill2();
	Skill skill3 = playerPoketmon.getSkill3();

	//컴퓨터 포켓몬 스킬 정보
	Skill cskill1 = computerPoketmon.getSkill1();
	Skill cskill2 = computerPoketmon.getSkill2();
	Skill cskill3 = computerPoketmon.getSkill3();
battle:
	//선택한 포켓몬의 이름과 기본 정보 출력
	printBattle(computerPoketmon, playerPoketmon);

	while (true)
	{
		int select = printSelection();

		cout << "<=============================================================================>\n" << endl;

		switch (select)
		{
		case 1:
			// 플레이어 일반공격 : 컴퓨터 포켓몬의 HP를 공격력만큼 감소시킴
			cout << "[" << playerPoketmon.getName() << "이(가) 공격합니다.]" << endl;
			cout << "[" << playerPoketmon.getdm() << "만큼 데미지를 주었습니다.]" << endl;
			computerPoketmon.setHP(computerPoketmon.getHP() - playerPoketmon.getdm());

			break;
		case 2:
			//플레이어 포켓몬 스킬 목록 출력
			cout << "\n<-----------------스킬 사용----------------->" << endl;
			cout << "[1]" << setw(11) << skill1.getName() << "[데미지]" << setw(5) << skill1.getDamage() << "[MP]" << setw(5) << skill1.getMp() << endl;
			cout << "[2]" << setw(11) << skill2.getName() << "[데미지]" << setw(5) << skill2.getDamage() << "[MP]" << setw(5) << skill2.getMp() << endl;
			cout << "[3]" << setw(11) << skill3.getName() << "[데미지]" << setw(5) << skill3.getDamage() << "[MP]" << setw(5) << skill3.getMp() << endl;
			cout << "[4]" << "뒤로 돌아가기" << endl;
			cout << "<-----------------스킬 취소[4]---------------->\n" << endl;
			cout << "[스킬 선택] : ";

			//사용할 스킬 선택
			int choicskill;
			cin >> choicskill;

			//남은 mp가 스킬의 최소 수치보다 많으면 스킬 사용
			if (playerPoketmon.getMP() >= 30)
			{
				switch (choicskill)
				{
				case 1:
					skillLogic(playerPoketmon, computerPoketmon, skill1);
					break;
				case 2:
					skillLogic(playerPoketmon, computerPoketmon, skill2);
					break;
				case 3:
					skillLogic(playerPoketmon, computerPoketmon, skill3);
					break;
				case 4:
					goto battle;
				}
				Sleep(1300);
			}
			//mp가 부족하면 메시지와 함께 전투 화면으로 전환
			else
			{
				cout << "[MP]가 부족합니다" << endl;
				goto battle;
			}
			break;
		
		//아이템 사용
		case 3:
			item:
			cout << "-> 아이템을 선택하세요" << endl;
			Item::printItemListb(GameInfo::Instance.player.getMyItems());
			cout << "사용할 아이템을 입력하세요 (q로 종료): ";
			char input;
			cin >> input;

			if (input == 'q') {
				cout << "아이템 사용을 취소했습니다.\n";
				cout << "<=============================================================================>" << endl;
				goto battle;
			}

			if (input - '0' > GameInfo::Instance.player.getMyItems().size() || input - '0' < 1) {
				cout << "올바른 선택지를 입력하세요.\n";
				goto item;
			}

			if (GameInfo::Instance.player.getMyItems().at(input - '0' - 1).getInfo() == "HP") {
				playerPoketmon.setHP(playerPoketmon.getHP() + GameInfo::Instance.player.getMyItems().at(input - '0' - 1).getEffect());
				//GameInfo::Instance.player.getMyItems().erase(GameInfo::Instance.player.getMyItems().begin() + (idx-1));
				cout << "[" << playerPoketmon.getName() << "의 HP가 " << GameInfo::Instance.player.getMyItems().at(input - '0' - 1).getEffect() << "만큼 회복되었다]" << endl;
				cout << "\n<=============================================================================>" << endl;
			}
			else {
				playerPoketmon.setMP(playerPoketmon.getMP() + GameInfo::Instance.player.getMyItems().at(input - '0' - 1).getEffect());
				cout << "[" << playerPoketmon.getName() << "의 MP가 " << GameInfo::Instance.player.getMyItems().at(input - '0' - 1).getEffect() << "만큼 회복되었다]" << endl;
				cout << "\n<=============================================================================>" << endl;
				//GameInfo::Instance.player.getMyItems().erase(GameInfo::Instance.player.getMyItems().begin() + (idx-1));
			}
			goto skipCatch;
			break;

		//도망 : 성공 시 로비로 복귀, 실패 시 컴퓨터가 공격함
		case 4:
			cout << "-> 도망가기" << endl;
			if (dis(gen) < 25)
			{
				cout << "도망 성공" << endl;
				GameInfo::Instance.player.clearItem();
				return;
			}
			cout << "도망 실패" << endl;
			goto skipCatch;
			break;
		
		//목록에 없는 번호를 입력했을 경우
		default:
			cout << "잘못 누르셨습니다." << endl;
			goto battle;
		}
		Sleep(1300);
		//컴퓨터 포켓몬 체력 0 -> 포획 혹은 풀어주기
		if (computerPoketmon.getHP() < 1) {
			catchPoketmon(poketmon[random]);
			GameInfo::Instance.player.setMoney(GameInfo::Instance.player.getMoney() + 500);
			GameInfo::Instance.player.clearItem();
			return;
		}
		skipCatch:
		//컴퓨터 공격
		comAttack(computerPoketmon, playerPoketmon);

		//플레이어 hp 0이하면 패배
		if (playerPoketmon.getHP() <= 0)
		{
			cout << "\n" << playerPoketmon.getName() << "이(가) 전투불가능 상태가 되었습니다." << endl << endl;
			Sleep(1300);
			return;
		}
		// 0이 아니면 플레이어의 남은 HP 출력
		else {
			cout << "<=============================================================================>" << endl;
		}

		printBattle(computerPoketmon, playerPoketmon);
	}
}

//상점 메뉴 기능
void funcShop()
{
shop:
	cout << "보유 금액 : "<<GameInfo::Instance.player.getMoney() << endl;
	vector<Item> itemList = Item::LoadAllItem();
	cout << "{Tip}" << "모든 아이템은 하나만 구매하면 전투 1회에 제한없이 사용할 수 있습니다." << endl;
	cout << "--------------아이템 목록--------------" << endl;
	Item::printItemList(itemList);
	cout << "-------------상점 종료 [q]-------------" << endl;
	cout << "\n구매할 아이템의 번호를 입력하세요 :";
	char index;
	cin >> index;

	if (index == 'q'){
		return;
	}
	if (index < '1' || index > '6') {
		cout << "\n올바른 선택지를 입력하세요.\n";
		goto shop;
	}
	Item select = itemList.at(index - '0' - 1); //인덱스를 입력하여 구매하고자 하는 아이템에 접근해서 select에 통째로 넣어버림, 그래서 select가 아이템의 정보가 담긴 객체가 되는 것
	if (select.getPrice() > GameInfo::Instance.player.getMoney()) {
		cout << "\n아이템 구매에 필요한 금액이 부족합니다. 소지금액을 확인해 주세요.\n\n";
		goto shop;
	}
	else{
		cout << "구매에 성공하였습니다.\n\n";
		GameInfo::Instance.player.addMyItems(select);
		GameInfo::Instance.player.setMoney(GameInfo::Instance.player.getMoney() - select.getPrice());
		goto shop;
	}
}

//보유 포켓몬 메뉴 기능
void funcMyPoketmon()
{
mypoketmon:
	vector<Poketmon> myPoketmonList = GameInfo::Instance.player.getMyPoketmons();
	cout << "<=================================보유 포켓몬 ==================================>" << endl << endl;
	Poketmon::printPocketmonList(myPoketmonList);
	cout << "\n<=================================종료 버튼 [q]=================================>\n" << endl << endl;
	cout << "전투에 내보낼 포켓몬을 선택해 주세요 : ";
	char index;
	cin >> index;
	if (index == 'q')
	{
		return;
	}
	if (index - '0' > myPoketmonList.size() || index - '0' < 1)
	{
		cout << "\n올바른 선택지를 입력하세요.\n" << endl;
		goto mypoketmon;
	}
	Poketmon select = myPoketmonList.at(index - '0' - 1);

	GameInfo::Instance.poketmon = select;
	cout << "전투에 내보낼 포켓몬을 성공적으로 선택하였습니다." << endl;

}

//전체 포켓몬 도감
void funcPoketmonDictionary() {
dictionary:
	vector<Poketmon> poketmon = Poketmon::LoadAllPoketmon();
	cout << "<=================================보유 포켓몬 ==================================>" << endl << endl;
	Poketmon::printPocketmonList(poketmon);
	cout << "\n<=================================종료 버튼 [q]=================================>\n" << endl;
	char index;
	cin >> index;
	if (index == 'q') return;
	else {
		cout << "올바른 문자를 입력해주세요" << endl;
		goto dictionary;
	}
}


int main()
{
	//초기 플레이어 정보 설정
	GameInfo::Instance.player.addMyPoketmons(Poketmon::LoadAllPoketmon().at(0));
	GameInfo::Instance.player.addMyPoketmons(Poketmon::LoadAllPoketmon().at(1));
	GameInfo::Instance.player.setMoney(3000);
	while (true)
	{
		char select;
		printMenu();
		cin >> select;
		if (select > '6' || select < '0') {
			cout << "올바른 선택지를 입력하세요." << endl;
			continue;
		}
		switch (select-'0')
		{
		case 1:
			system("cls");
			funcBattle();
			break;
		case 2:
			system("cls");
			funcMyPoketmon();
			break;
		case 3:
			system("cls");
			funcShop();
			break;
		case 4:
			system("cls");
			funcPoketmonDictionary();
			break;
		case 5:
			system("cls");
			RhythmGame1();
			break;
		case 6:
			cout << "종료합니다";
			return 0;
		default:
			cout << "올바른 선택지를 입력하세요." << endl;
			break;
		}
	}
}