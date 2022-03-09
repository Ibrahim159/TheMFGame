#include "Monster.h"

Monster::Monster(){

}

Monster::Monster(int _type, int _hp, int _max_strenght){
    this->type = _type;
    this->hp = _hp;
    this->max_strength = _max_strenght;
}

int Monster::getType(){
    return this->type;
}

int Monster::getHp(){
    return this->hp;
}

int Monster::getMax_strength(){
    return this->max_strength;
}

void Monster::setHp(int _hp){
    this->hp = _hp;
}

void Monster::setType(int _type){
    this->type = _type;
}

void Monster::setMax_strenght(int _max_strength){
    this->max_strength = _max_strength;
}

void Monster::attack(Entity *entity){
    Player *player = (Player *)entity;
    srand(time(NULL));
    int attack = 1+rand()%(this->max_strength-1);
    int player_hp = player->getHp() - attack;
    std::cout << "You have a suffered " << attack << " points of damage" << std::endl;
    player->setHp(player_hp);
}