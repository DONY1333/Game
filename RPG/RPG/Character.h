#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Character {
protected:
	string name, job;//角色名稱和職業
	int hp, maxHp, mp, maxMp;//當前血量、最大血量、當前魔力和最大魔力
	int critChance, baseRecover, evasionRate, defenseValue;//暴擊率、基礎能量恢復量、閃避率和防禦值
	bool isDefending;//是否處於防禦狀態

public:
	Character(string n, string j, int h, int m, int c, int r, int e, int d);//構造函數，初始化角色屬性
	virtual ~Character() {}//虛擬析構函數，確保子類別能正確釋放資源
	virtual void recoverEnergy();//恢復能量
	void startDefense();//開始防禦
	void resetDefense();//重置防禦狀態
	void performAttack(int type, Character* target);//執行攻擊
	void receiveDamage(int d);//接收傷害
	bool isAlive();//檢查角色是否還活著
	string getName();//獲取角色名稱
	string getJob();//獲取職業名稱
	int getHp();//獲取當前血量
	int getMaxHp();//獲取最大血量
	int getMp();//獲取當前魔力
	int getMaxMp();//獲取最大魔力
};
#endif