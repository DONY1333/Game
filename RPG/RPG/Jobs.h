#ifndef JOBS_H
#define JOBS_H
#include "Character.h"

class Fighter : public Character {
public:
    Fighter(string n) : Character(n, "鬥士", 250, 50, 15, 15, 20, 20) {}
};

class Mage : public Character {
public:
    Mage(string n) : Character(n, "法師", 150, 65, 10, 25, 10, 10) {}
};

class Assassin : public Character {
public:
    Assassin(string n) : Character(n, "刺客", 120, 50, 45, 10, 50, 5) {}
};
#endif
// 這個檔案定義了三個職業類別：鬥士、法師和刺客，分別繼承自 Character 類別，並在構造函數中設置了各自的屬性值。
//使用子類別原因:如果職業新增太多複雜不同內容可以放到不同檔案內