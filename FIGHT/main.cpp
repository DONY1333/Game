#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Jobs.h"
#include "UI.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    Character* player = nullptr;
    Character* monster = new Character("魔王受試者", "BOSS", 500, 100, 10, 15, 10, 15);
    int pChoice, aChoice;

    cout << "1. 鬥士 | 2. 法師 | 3. 刺客\n請選擇職業: ";
    cin >> pChoice;
    
    if (pChoice == 1) player = new Fighter("玩家 1 號");
    else if (pChoice == 2) player = new Mage("玩家 1 號");
    else player = new Assassin("玩家 1 號");

    bool running = true;
    while (running && player->isAlive() && monster->isAlive()) {
        player->resetDefense();
        displayStatus(player, monster);
        
        cout << "【1】輕攻 [5MP] 【2】重攻 [15MP] 【3】大招 [45MP] 【4】防禦 【0】退出\n>> 指令: ";
        cin >> aChoice;
        
        if (aChoice == 0) { running = false; break; }

        cout << "\n[ 戰鬥日誌 ]" << endl;
        if (aChoice == 4) player->startDefense();
        else player->performAttack(aChoice, monster);
        
        if (monster->isAlive()) {
            cout << "\n[ 對手回合 ]" << endl;
            monster->resetDefense();
            int mAction = (rand() % 4) + 1;
            if (mAction == 4) monster->startDefense();
            else monster->performAttack((rand() % 2) + 1, player);
            
            player->recoverEnergy();
            monster->recoverEnergy();
        }
    }

    cout << "\n遊戲結束！" << endl;
    delete player;
    delete monster;
    return 0;
}