#pragma once
#include <iostream>
#include "Monster.h"
#include "entity.h"

class Player:public Entity{
    private:
        std::string name;
        int xp;
        int hp;
        int atk;

    public:
        Player();
        Player(std::string , int, int, int);

        std::string getName();
        int getXp();
        int getHp();
        int getAtk();
        void setName(std::string);
        void setXp(int);
        void setHp(int);
        void setAtk(int);
        void profile();
        bool playerRun();
        virtual void attack(Entity *entity)override;
};