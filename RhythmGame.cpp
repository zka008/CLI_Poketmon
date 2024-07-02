#include "RhythmGame.h"
#include "GameInfo.h"

// ������ ����
RhythmGame::RhythmGame() {

    srand(time(nullptr));
}

void RhythmGame::Game()
{
    // ���� ��� ����
    string num;
    cout << "\n<==================================Ÿ�� ����==================================>\n" << endl;
    cout << "Ÿ�ڰ���" << endl;
    cout << "1. �ʱ� ���" << endl;
    cout << "2. �߱� ���" << endl;
    cout << "3. ��� ���" << endl;
    cout << "4. ���� ����" << endl;
    cout << "�������ּ��� :";
    cin >> num;

    if (num == "1")
    {
        PlayGame(1000); // ���� ���� ���: Ű �Է� ������ 1��
    }
    else if (num == "2")
    {
        PlayGame(1400); // ���ڿ� ���: Ű �Է� ������ 0.8��
    }
    else if (num == "3")
    {
        PlayGame(750); // �����ư��� ���: Ű �Է� ������ 0.75��
    }
}

void RhythmGame::PlayGame(int keyDelay)
{
    cout << "Ÿ�ڰ����� �����մϴ�!" << endl;
    cout << "�� ������ " << DURATION << "�� ���� ����˴ϴ�." << endl;
    cout << "Ű �Է� �����̴� " << keyDelay / 1000.0 << "���Դϴ�." << endl;

    int startTime = time(nullptr);
    int time1;

    int count = 0;
    while (true)
    {
        time1 = time(nullptr);
        if (time1 - startTime >= DURATION)
        {
            cout << "���� ����! �ð� �ʰ�!" << endl;
            break;
        }

        string key;
        if (keyDelay == 1000)
            key = RandomKey();
        else
            key = RandomStringKey();

        cout << "Ű�� �Է��ϼ���: " << key << endl;

        clock_t inputtime = clock();
        string userInput;

        while ((clock() - inputtime) / (CLOCKS_PER_SEC / 1000.0) < keyDelay)
        {
            if (_kbhit())
            {
                char ch = _getch();
                if (ch == '\r') // Enter Ű�� ������ ����
                    break;
                userInput += ch;
                cout << ch; // �Էµ� ���� ǥ��
            }
        }

        if (userInput != key)
        {
            cout << endl << "�߸��� �Է�! ���� ����!" << endl;
            break;
        }
        else {
            count++;
            cout << endl << "����!" << endl;
        }
    }
    cout << count * 10 << " ����Ʈ�� ȹ���Ͽ����ϴ�.\n";
    GameInfo::Instance.player.setMoney(GameInfo::Instance.player.getMoney() + count * 10);
    cout << "���� ����! ������ �Է� Ƚ��: " << count << endl;
    cout << "\n<==================================Ÿ�� ����==================================>\n" << endl;
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