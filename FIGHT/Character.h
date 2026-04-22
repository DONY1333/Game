#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Character {
protected:
    string name, job;
    int hp, maxHp, mp, maxMp;
    int critChance, baseRecover, evasionRate, defenseValue;
    bool isDefending;

public:
    Character(string n, string j, int h, int m, int c, int r, int e, int d);
    virtual ~Character() {}
    virtual void recoverEnergy();
    void startDefense();
    void resetDefense();
    void performAttack(int type, Character* target);
    void receiveDamage(int d);
    bool isAlive();
    string getName();
    string getJob();
    int getHp();
    int getMaxHp();
    int getMp();
    int getMaxMp();
};
#endif