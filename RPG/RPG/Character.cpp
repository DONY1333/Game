#include "Character.h"

Character::Character(string n, string j, int h, int m, int c, int r, int e, int d) //初始化列表來設置角色屬性
    : name(n), job(j), hp(h), maxHp(h), mp(m), maxMp(m), 
      critChance(c), baseRecover(r), evasionRate(e), defenseValue(d), isDefending(false) {}

void Character::recoverEnergy() {
    mp += baseRecover;
    if (mp > maxMp) mp = maxMp;
    cout << "[恢復] " << name << " 獲得 " << baseRecover << " MP" << endl;
}

void Character::startDefense() {
    isDefending = true;
    cout << ">>> " << name << " 進入防禦架勢！" << endl;
}

void Character::resetDefense() { isDefending = false; }

void Character::performAttack(int type, Character* target) {//設定攻擊參數(攻擊種類，被攻擊的目標)
	if (!target) return;//如果被攻擊的目標為空指針，直接返回
    int baseDmg = 0, cost = 0;
    string move;
    if (type == 1) { move = "輕攻擊"; baseDmg = 25; cost = 5; }
    else if (type == 2) { move = "重攻擊"; baseDmg = 45; cost = 15; }
    else if (type == 3) { move = "【必殺技】"; baseDmg = 105; cost = 45; }
	else return;//如果攻擊類型不是1、2或3，直接返回

    if (mp >= cost) {//如果當前魔力足夠執行攻擊
        mp -= cost;
        int roll = rand() % 100;
        int finalDmg = (roll < critChance) ? baseDmg * 2 : baseDmg;
        cout << ">> " << name << " 施展 " << move << (roll < critChance ? " (💥 爆擊！)" : "") << endl;
        target->receiveDamage(finalDmg);
    } else {
        cout << "!! 能量不足 !! (剩餘 " << mp << " MP)" << endl;
    }
}

void Character::receiveDamage(int d) {
    if ((rand() % 100) < evasionRate) {
        cout << "   💨 閃避！ " << name << " 躲開了攻擊。" << endl;
        return;
    }
    int finalDmg = isDefending ? max(0, d - defenseValue) : d;
    if (isDefending) cout << "   🛡️  防禦減免了 " << defenseValue << " 點傷害。" << endl;
    hp = max(0, hp - finalDmg);
    cout << "   " << name << " 受到 " << finalDmg << " 點傷害，血量剩餘: " << hp << endl;
}

bool Character::isAlive() { return hp > 0; }
string Character::getName() { return name; }
string Character::getJob() { return job; }
int Character::getHp() { return hp; }
int Character::getMaxHp() { return maxHp; }
int Character::getMp() { return mp; }
int Character::getMaxMp() { return maxMp; }