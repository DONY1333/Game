#define _HAS_STD_BYTE 0// 為了避免 C++17 中 std::byte 與 Windows.h 的衝突，先定義這個宏來禁用 std::byte
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Jobs.h"
#include "UI.h"
#include <windows.h>

using namespace std;

int main() {
	SetConsoleOutputCP(65001); //固定使用 UTF-8 編碼輸出，確保中文顯示正常
    SetConsoleCP(65001);

	srand(static_cast<unsigned int>(time(NULL)));// 初始化隨機種子(使用當前時間)

    Character* player = nullptr;
    Character* monster = new Character("魔王受試者", "BOSS", 500, 100, 10, 15, 10, 15);
	int pChoice, aChoice;//pChoice:職業選擇 aChoice:行動選擇

    cout << "1. 鬥士 | 2. 法師 | 3. 刺客\n請選擇職業: ";
    cin >> pChoice;
    
    if (pChoice == 1) player = new Fighter("玩家 1 號");//用指標選職業
    else if (pChoice == 2) player = new Mage("玩家 1 號");
	else player = new Assassin("玩家 1 號");//為了方便以後擴充自訂名字，不在構造函數內直接寫死


    bool running = true;
	while (running && player->isAlive() && monster->isAlive()) {//遊戲主迴圈，當玩家和怪物都還活著時持續運行
		player->resetDefense();//每回合開始重置玩家防禦狀態為非防禦
		displayStatus(player, monster);//呼叫UI函數，顯示玩家和怪物的狀態
        
        cout << "【1】輕攻 [5MP] 【2】重攻 [15MP] 【3】大招 [45MP] 【4】防禦 【0】退出\n>> 指令: ";
        cin >> aChoice;
        
		if (aChoice == 0) { running = false; break; }//如果玩家選擇退出(0)，結束遊戲

        cout << "\n[ 戰鬥日誌 ]" << endl;
		if (aChoice == 4) player->startDefense();//如果玩家選擇防禦(4)，進入防禦狀態
		else player->performAttack(aChoice, monster);//否則執行攻擊，aChoice對應攻擊類型
        
        if (monster->isAlive()) {
            cout << "\n[ 對手回合 ]" << endl;
			monster->resetDefense();//每回合怪物回合開始重置怪物防禦狀態為非防禦
			int mAction = (rand() % 4) + 1;//怪物隨機選擇行動，有25%的機率選擇防禦(4)，75%的機率選擇攻擊(1-3)
			if (mAction == 4) monster->startDefense();//如果boss防禦，它的防禦狀態會在下一回合玩家攻擊結束後重置
			else monster->performAttack((rand() % 2) + 1, player);//怪物攻擊類型隨機選擇輕攻(1)或重攻(2)，不使用大招(3)以保持遊戲平衡
            
			player->recoverEnergy();//每回合結束後玩家恢復能量，讓玩家在下一回合有更多選擇的空間
			monster->recoverEnergy();//每回合結束後怪物也恢復能量，讓怪物在下一回合有更多選擇的空間
        }
    }
    cout << "\n遊戲結束！" << endl;
    if (running == true) {
        cout << (player->isAlive() ? "恭喜！你擊敗了魔王！" : "很遺憾，你被魔王打敗了...") << endl;
    }
    delete player;
    delete monster;
    system("pause");
    return 0;
}