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
        players[0] = new Player("수연이");
        players[1] = new Player("제갈이");
    }

    void play() {
        srand((unsigned)time(0));
        cout << "***** 갬블링 게임을 시작합니다 *****" << endl;
        cout << "첫번째 선수 이름>>" << players[0]->name << endl;
        cout << "두번째 선수 이름>>" << players[1]->name << endl;

        int turn = 0;
        while (true) {
            cout << players[turn % 2]->name << ": <Enter> ";
            cin.ignore();

            int num1 = rand() % 3;
            int num2 = rand() % 3;
            int num3 = rand() % 3;

            cout << num1 << " " << num2 << " " << num3 << endl;

            if (num1 == num2 && num2 == num3) {
                cout << players[turn % 2]->name << " 승리!" << endl;
                break;
            }
            else {
                cout << "아쉽군요!" << endl;
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
