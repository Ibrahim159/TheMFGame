#pragma once
#include <iostream>
#include "Player.h"
#include "entity.h"

class Monster:public Entity {
    private:
        int type;
        int hp;
        int max_strength;

    public:
        Monster();
        Monster(int, int, int);
        int getHp();
        int getType();
        int getMax_strength();
        void setType(int);
        void setHp(int);
        void setMax_strenght(int);
        virtual void attack(Entity *entity)override;
};