#ifndef UI_H
#define UI_H

#include <iostream>
#include "Character.h"
using namespace std;

void displayStatus(Character* p, Character* m) {
    cout << "\n╔═══════════════════════════════════════╗" << endl;
    cout << "  玩家：" << p->getName() << " (" << p->getJob() << ")" << endl;
    cout << "  血量：" << p->getHp() << "/" << p->getMaxHp() 
         << "  魔力：" << p->getMp() << "/" << p->getMaxMp() << endl;
    cout << "╟───────────────────────────────────────╢" << endl;
    cout << "  對手：" << m->getName() << "  血量：" << m->getHp() << "/" << m->getMaxHp() << endl;
    cout << "╚═══════════════════════════════════════╝" << endl;
}
#endif