#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {
public:
    string name;
    Player(string name) { this->name = name; }
};

class GamblingGame {
    Player* players[2];
public:
    GamblingGame() {
        players[0] = new Player("������");
        players[1] = new Player("������");
    }

    void play() {
        srand((unsigned)time(0));
        cout << "***** ���� ������ �����մϴ� *****" << endl;
        cout << "ù��° ���� �̸�>>" << players[0]->name << endl;
        cout << "�ι�° ���� �̸�>>" << players[1]->name << endl;

        int turn = 0;
        while (true) {
            cout << players[turn % 2]->name << ": <Enter> ";
            cin.ignore();

            int num1 = rand() % 3;
            int num2 = rand() % 3;
            int num3 = rand() % 3;

            cout << num1 << " " << num2 << " " << num3 << endl;

            if (num1 == num2 && num2 == num3) {
                cout << players[turn % 2]->name << " �¸�!" << endl;
                break;
            }
            else {
                cout << "�ƽ�����!" << endl;
            }

            turn++;
        }
    }
};

int main() {
    GamblingGame game;
    game.play();

    return 0;
}
