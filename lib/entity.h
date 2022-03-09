#pragma once

class Entity {
    public:
    Entity(){}
    ~Entity(){}
    int getHp();
    virtual void attack(Entity *entity);
    void setHp(int);

    private:
    int hp;
};