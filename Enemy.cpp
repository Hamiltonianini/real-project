#include "Enemy.h"
#include <iostream>
#include <ctime>

Enemy::Enemy(std::string n, int h, int m, int a,int i ,std::string roob)
:Unit(n,h,m,a,0,roob){}

void Enemy::takeAction(Unit& target){
    int chance = rand()%100+1;

    if(chance < 70){
        std::cout << "enemy attack :" << atk <<std::endl;
        target.takeDamage(atk);
        std::cout << "///////////////////////////////////////////" << std::endl;

    }else{
        std::cout << "crit!"<< atk*1.25 <<std::endl;;
        target.takeDamage(1.25*atk);
        std::cout << "///////////////////////////////////////////" << std::endl;

    }
}