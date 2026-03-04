#ifndef ENEMY_H
#define ENEMY_H

#include "Unit.h"

class Enemy : public Unit {
public:
    Enemy(std::string n, int h, int m, int a,int i,std::string image);

    // ระบบ AI: ส่ง Player เข้ามาเพื่อให้ศัตรูตัดสินใจว่าจะโจมตีหรือทำอย่างอื่น
    void takeAction(Unit& target);
};

#endif