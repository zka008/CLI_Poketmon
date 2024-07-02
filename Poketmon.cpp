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
		cout << " 도감번호" << i << " 이름: " << card.getName() << ", Level: " << card.getLevel()
			<< ", HP: " << card.getHP() << ", MP: " << card.getMP() << ", 특성: " << card.getInfo() << endl;	 
		i++;
	}
}

vector<Poketmon> Poketmon::LoadAllPoketmon()
{
    vector<Poketmon> cardList;

    //1성 랜덤 데미지
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(50, 100);

    int Damage = dis(gen);

    //2성 랜덤 데미지
    random_device rd1;
    mt19937 gen1(rd1());
    uniform_int_distribution<> dis1(100, 200);

    int Damage1 = dis1(gen1);

    //3성 랜덤 데미지
    random_device rd2;
    mt19937 gen2(rd2());
    uniform_int_distribution<> dis2(200, 300);

    int Damage2 = dis2(gen2);

    //1성
    cardList.push_back(Poketmon("치코리타", 1, 500, 300, "[잎사귀]날씨가 쾌청 상태일 때 상태이상에 걸리지 않는다.", Damage,
        Skill("나뭇잎 공격", 100, 30),
        Skill("마음의 눈", 150, 50),
        Skill("십만볼트", 200, 100)));
    cardList.push_back(Poketmon("마그케인", 1, 550, 300, "[불쥐포켓몬]타오르는 불꽃", Damage,
        Skill("회오리불꽃", 100, 30),
        Skill("불꽃세례", 150, 50),
        Skill("화염방사", 200, 100)));
    cardList.push_back(Poketmon("메가니움", 1, 600, 300, "[허브 포켓몬]날씨가 쾌청 상태일 때 상태이상에 걸리지 않는다.", Damage,
        Skill("솔라빔", 100, 30),
        Skill("신비의힘", 150, 50),
        Skill("파워휩", 200, 100)));
    cardList.push_back(Poketmon("베이리프", 1, 550, 300, "[잎사귀 포켓몬]날씨가 쾌청 상태일 때 상태이상에 걸리지 않는다.", Damage,
        Skill("씨뿌리기", 100, 30),
        Skill("진흙뿌리기", 150, 50),
        Skill("대지의힘", 200, 100)));
    cardList.push_back(Poketmon("브케인", 1, 500, 300, "[불쥐포켓몬]타오르는 불꽃", Damage,
        Skill("연옥", 100, 30),
        Skill("회오리불꽃", 150, 50),
        Skill("불꽃펀치", 200, 100)));
    cardList.push_back(Poketmon("엘리게이", 1, 550, 400, "[큰턱]우격다짐", Damage,
        Skill("물대포", 100, 30),
        Skill("파도타기", 150, 50),
        Skill("하이드로펌프", 200, 100)));
    cardList.push_back(Poketmon("블레이범", 1, 600, 400, "[불쥐]타오르는 불꽃", Damage,
        Skill("크로스촙", 100, 30),
        Skill("방어", 150, 50),
        Skill("화염자동차", 200, 100)));
    cardList.push_back(Poketmon("꼬리선", 1, 500, 400, "[망보기]날카로운 눈을 통한 통찰, 도주", Damage,
        Skill("물대포", 100, 30),
        Skill("아쿠아제트", 150, 50),
        Skill("하이드로펌프", 200, 100)));
    cardList.push_back(Poketmon("리아코", 1, 500, 400, "[큰턱]우격다짐", Damage,
        Skill("강철날개", 100, 30),
        Skill("스피드스타", 150, 50),
        Skill("애교부리기", 200, 100)));

    //2성
    cardList.push_back(Poketmon("노고치", 2, 700, 900, "[노말]야생 포켓몬에게서 반드시 도망칠 수 있다.", Damage1,
        Skill("머드숏", 200, 30),
        Skill("진흙폭풍", 250, 50),
        Skill("진흙폭발", 300, 100)));
    cardList.push_back(Poketmon("부우부", 2, 700, 600, "[노말비행]불면, 날카로운 눈", Damage1,
        Skill("십만볼트", 200, 30),
        Skill("전기쇼크", 250, 50),
        Skill("번개", 300, 100)));
    cardList.push_back(Poketmon("다꼬리", 2, 800, 600, "[망보기]이 포켓몬의 명중률을 떨어뜨릴 수 없다.상대방의 회피율을 무시한다, 상대의 도구를 알 수 있다.", Damage1,
        Skill("나뭇잎 날리기", 200, 30),
        Skill("맹독", 250, 50),
        Skill("폭풍", 300, 100)));
    cardList.push_back(Poketmon("레디바", 2, 700, 600, "[벌레비행]일찍 기상", Damage1,
        Skill("불꽃세례", 200, 30),
        Skill("심장부", 250, 50),
        Skill("열풍", 300, 100)));
    cardList.push_back(Poketmon("레디안", 2, 800, 600, "[얼음]수면 상태가 되지 않는다.", Damage1,
        Skill("해감", 200, 30),
        Skill("불꽃세례", 250, 50),
        Skill("불대문자", 300, 100)));
    cardList.push_back(Poketmon("장크로다일", 2, 850, 400, "[큰턱]우격다짐", Damage1,
        Skill("강철날개", 200, 30),
        Skill("깜짝베기", 250, 50),
        Skill("회전부리", 300, 100)));
    cardList.push_back(Poketmon("총어", 2, 700, 400, "[물]의욕, 스나이퍼, 벽던쟁이", Damage1,
        Skill("촉수강치", 200, 30),
        Skill("승부굳히기", 250, 50),
        Skill("이상한빛", 300, 100)));
    cardList.push_back(Poketmon("만타인", 2, 800, 300, "[물]저수, 쓱쓱, 수의베일", Damage1,
        Skill("더블윙", 200, 30),
        Skill("박치기", 250, 50),
        Skill("애교부리기", 300, 100)));
    cardList.push_back(Poketmon("대포무노", 2, 750, 500, "[물]적에게 먹물을 퍼붓는다.", Damage1,
        Skill("회오리불꽃", 200, 30),
        Skill("불꽃세례", 250, 50),
        Skill("화염방사", 300, 100)));


    //3성
    cardList.push_back(Poketmon("무우마", 3, 900, 400, "[고스트]땅 타입 기술을 무효화한다.", Damage2,
        Skill("맹독", 300, 30),
        Skill("독특한비늘", 350, 50),
        Skill("아쿠아브레이크", 400, 100)));
    cardList.push_back(Poketmon("퉁퉁코", 3, 900, 900, "[풀]엽록소 리프가드 틈새포착", Damage2,
        Skill("전자포", 300, 30),
        Skill("전격파", 350, 50),
        Skill("번개", 400, 100)));
    cardList.push_back(Poketmon("누오", 3, 1000, 1300, "[벌레비행]가속, 복안, 통찰", Damage2,
        Skill("얼음뭉치", 300, 30),
        Skill("눈보라", 350, 50),
        Skill("얼음창", 400, 100)));
    cardList.push_back(Poketmon("두코", 3, 1000, 900, "[풀]엽록소 리프가드 틈새포착", Damage2,
        Skill("두개애교", 300, 30),
        Skill("폭포", 350, 50),
        Skill("물대포", 400, 100)));
    cardList.push_back(Poketmon("솜솜코", 3, 1100, 1000, "[풀 비행]쾌청일 때 스피드가 2배로 오른다.", Damage2,
        Skill("소프트실드", 300, 30),
        Skill("스톤에지", 350, 50),
        Skill("대지진", 400, 100)));
    cardList.push_back(Poketmon("니로우", 3, 900, 400, "[악, 비행]이 포켓몬이 급소를 공격할 확률이 높다.", Damage2,
        Skill("강철날개", 300, 30),
        Skill("코멧펀치", 350, 50),
        Skill("불새", 400, 100)));
    cardList.push_back(Poketmon("마릴", 3, 1000, 1000, "[물페어리]전신의 털은 물을 튕겨내는 성질을 지녀 물을 끼얹어도 말라 있다.", Damage2,
        Skill("참기", 300, 30),
        Skill("방전", 350, 50),
        Skill("물대포", 400, 100)));
    cardList.push_back(Poketmon("마릴리", 3, 1100, 1000, "[물페어리]전신의 털은 물을 튕겨내는 성질을 지녀 물을 끼얹어도 말라 있다.", Damage2,
        Skill("아쿠아제트", 300, 30),
        Skill("바위깨기", 350, 50),
        Skill("하이드로펌프", 400, 100)));
    cardList.push_back(Poketmon("꼬지모", 3, 1000, 500, "[바위]옹골참, 돌머리, 주눅일격기를 무효화하며 체력이 가득찼을 때 일격에 쓰러지지 않는다.", Damage2,
        Skill("번개박치기", 300, 30),
        Skill("몸통박치기", 350, 50),
        Skill("전자포", 400, 100)));
    cardList.push_back(Poketmon("왕구리", 3, 1100, 800, "[물]전투에 나오면 5턴간 비가 내리게 된다.", Damage2,
        Skill("마하펀치", 300, 30),
        Skill("깨물어부수기", 350, 50),
        Skill("애교부리기", 400, 100)));
    cardList.push_back(Poketmon("딜리버드", 3, 1000, 800, "[얼음]수면 상태가 되지 않는다.", Damage2,
        Skill("얼음뭉치", 300, 30),
        Skill("돌림노래", 350, 50),
        Skill("눈사태", 400, 100)));
    cardList.push_back(Poketmon("리자몽", 3, 1100, 1500, "[불꽃]엄청난 불꽃을 퍼붓는다. 접근하지 않는 것이 현명하다.", Damage2,
        Skill("불꽃세례", 300, 30),
        Skill("불꽃펀치", 350, 50),
        Skill("연옥", 400, 100)));
    cardList.push_back(Poketmon("마자용", 3, 950, 1200, "[에스퍼]서로 그림자밟기 특성일 경우 효과가 상쇄된다.", Damage2,
        Skill("드래곤크루", 300, 30),
        Skill("용의숨결", 350, 50),
        Skill("용의파동", 400, 100)));
    cardList.push_back(Poketmon("무장조", 3, 950, 800, "[강철]명중률이 내려가지 않으며 상대의 회피율 증가를 무시한다.", Damage2,
        Skill("김밥말이", 300, 30),
        Skill("스피드스타", 350, 50),
        Skill("절대영도", 400, 100)));
    cardList.push_back(Poketmon("블래키", 3, 1000, 800, "[악]풀죽음에 영향을 받지 않는다.", Damage2,
        Skill("잠재파워", 300, 30),
        Skill("애교부리기", 350, 50),
        Skill("야습", 400, 100)));
    cardList.push_back(Poketmon("쏘콘", 3, 1000, 1900, "[벌레]일격기가 통하지 않으며 체력이 가득찬 상태에서 일격에 쓰러지지 않는다.", Damage2,
        Skill("얼음의숨결", 300, 30),
        Skill("냉동펀치", 350, 50),
        Skill("격투", 400, 100)));
    cardList.push_back(Poketmon("아리아도스", 3, 1000, 700, "[벌레독]불면, 벌레의 알림, 스나이퍼", Damage2,
        Skill("김밥말이", 300, 30),
        Skill("신비의부적", 350, 50),
        Skill("애교부리기", 400, 100)));
    cardList.push_back(Poketmon("안농", 3, 950, 800, "[에스퍼]땅 타입 기술에 맞지 않는다.", Damage2,
        Skill("바위깨기", 300, 30),
        Skill("미래예지", 350, 50),
        Skill("프리즈드라이", 400, 100)));
    cardList.push_back(Poketmon("야도킹", 3, 1100, 1300, "[물, 에스퍼]혼란 상태에 빠지지 않는다.", Damage2,
        Skill("염동력", 300, 30),
        Skill("환상빔", 350, 50),
        Skill("사이코키네시스", 400, 100)));

    cardList.push_back(Poketmon("야부엉", 2, 1000, 600, "[노말비행]불면, 날카로운 눈", Damage2,
        Skill("깜짝베기", 300, 30),
        Skill("날개치기", 350, 50),
        Skill("속여때리기", 400, 100)));
    cardList.push_back(Poketmon("에브이", 3, 1000, 500, "[에스퍼]싱크로, 매직미러", Damage2,
        Skill("심쿵라이브", 300, 30),
        Skill("스피드스타", 350, 50),
        Skill("볼트체인지", 400, 100)));
    cardList.push_back(Poketmon("에이팜", 3, 900, 700, "[노말]픽업, 도주, 스킬링크", Damage2,
        Skill("분함", 300, 30),
        Skill("강철주먹", 350, 50),
        Skill("화염방사", 400, 100)));
    cardList.push_back(Poketmon("왕자리", 3, 900, 500, "[벌레비행]가속, 복안, 통찰", Damage2,
        Skill("카운터", 300, 30),
        Skill("칼등치기", 350, 50),
        Skill("승부굳히기", 400, 100)));
    cardList.push_back(Poketmon("우파", 3, 900, 1100, "[벌레비행]가속, 복안, 통찰", Damage2,
        Skill("메가톤펀치", 300, 30),
        Skill("애교부리기", 350, 50),
        Skill("자이로볼", 400, 100)));
    cardList.push_back(Poketmon("잠만보", 3, 1100, 2000, "[푸근]독, 맹독 상태가 되지 않는다.", Damage2,
        Skill("매지컬샤인", 300, 30),
        Skill("유령불", 350, 50),
        Skill("드림이크", 400, 100)));
    cardList.push_back(Poketmon("코산호", 3, 900, 1500, "[물]귀여워서 공격하기 두렵다.", Damage2,
        Skill("맹독", 300, 30),
        Skill("길들이기", 350, 50),
        Skill("물의맹세", 400, 100)));
    cardList.push_back(Poketmon("키링키", 3, 950, 1500, "[노말, 에스퍼]풀죽지 않는다.", Damage2,
        Skill("싱크로노이즈", 300, 30),
        Skill("스피드스타", 350, 50),
        Skill("아이언테일", 400, 100)));

    cardList.push_back(Poketmon("토게틱", 3, 1000, 800, "[페어리비행]의욕, 하늘의은총, 대운", Damage2,
        Skill("천사의키스", 300, 30),
        Skill("신비의부적", 350, 50),
        Skill("도발", 400, 100)));

    cardList.push_back(Poketmon("페이검", 3, 900, 700, "[벌레독]불면, 벌레의알림, 스나이퍼", Damage2,
        Skill("페인트", 300, 30),
        Skill("절대영도", 350, 50),
        Skill("베어가르기", 400, 100)));
    cardList.push_back(Poketmon("피콘", 3, 900, 1800, "[벌레]옹골참, 방진", Damage2,
        Skill("강철날개", 300, 30),
        Skill("진공파", 350, 50),
        Skill("애교부리기", 400, 100)));
    cardList.push_back(Poketmon("해너츠", 3, 900, 1200, "[풀]엽록소, 선파워, 일찍기상", Damage2,
        Skill("바람일으키기", 300, 30),
        Skill("마력거울", 350, 50),
        Skill("에어컷터", 400, 100)));
    cardList.push_back(Poketmon("해루미", 3, 1000, 1300, "[풀]잠듦 상태가 되었을 때, 잠드는 턴이 절반으로 줄어든다.", Damage2,
        Skill("금속음", 300, 30),
        Skill("금속분쇄", 350, 50),
        Skill("독침", 400, 100)));

    return cardList;
}

