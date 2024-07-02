#include "RhythmGame.h"
#include "GameInfo.h"

// 생성자 정의
RhythmGame::RhythmGame() {

    srand(time(nullptr));
}

void RhythmGame::Game()
{
    // 게임 모드 선택
    string num;
    cout << "\n<==================================타자 게임==================================>\n" << endl;
    cout << "타자게임" << endl;
    cout << "1. 초급 모드" << endl;
    cout << "2. 중급 모드" << endl;
    cout << "3. 고급 모드" << endl;
    cout << "4. 게임 종료" << endl;
    cout << "선택해주세요 :";
    cin >> num;

    if (num == "1")
    {
        PlayGame(1000); // 단일 문자 모드: 키 입력 딜레이 1초
    }
    else if (num == "2")
    {
        PlayGame(1400); // 문자열 모드: 키 입력 딜레이 0.8초
    }
    else if (num == "3")
    {
        PlayGame(750); // 번갈아가며 모드: 키 입력 딜레이 0.75초
    }
}

void RhythmGame::PlayGame(int keyDelay)
{
    cout << "타자게임을 시작합니다!" << endl;
    cout << "이 게임은 " << DURATION << "초 동안 진행됩니다." << endl;
    cout << "키 입력 딜레이는 " << keyDelay / 1000.0 << "초입니다." << endl;

    int startTime = time(nullptr);
    int time1;

    int count = 0;
    while (true)
    {
        time1 = time(nullptr);
        if (time1 - startTime >= DURATION)
        {
            cout << "게임 종료! 시간 초과!" << endl;
            break;
        }

        string key;
        if (keyDelay == 1000)
            key = RandomKey();
        else
            key = RandomStringKey();

        cout << "키를 입력하세요: " << key << endl;

        clock_t inputtime = clock();
        string userInput;

        while ((clock() - inputtime) / (CLOCKS_PER_SEC / 1000.0) < keyDelay)
        {
            if (_kbhit())
            {
                char ch = _getch();
                if (ch == '\r') // Enter 키가 눌리면 종료
                    break;
                userInput += ch;
                cout << ch; // 입력된 문자 표시
            }
        }

        if (userInput != key)
        {
            cout << endl << "잘못된 입력! 게임 종료!" << endl;
            break;
        }
        else {
            count++;
            cout << endl << "성공!" << endl;
        }
    }
    cout << count * 10 << " 포인트를 획득하였습니다.\n";
    GameInfo::Instance.player.setMoney(GameInfo::Instance.player.getMoney() + count * 10);
    cout << "게임 종료! 성공한 입력 횟수: " << count << endl;
    cout << "\n<==================================타자 종료==================================>\n" << endl;
}

char RhythmGame::RandomKey()
{
    const char keys[] = { 'w', 'a', 's', 'd' };
    int randomIndex = rand() % 4;
    return keys[randomIndex];
}

string RhythmGame::RandomStringKey()
{
    const string keys[] = { "that", "what", "int", "you" };
    int randomIndex = rand() % 4;
    return keys[randomIndex];
}