#include "Player.h"

Player::Player(){}

Player::Player(std::string _name, int _xp, int _hp, int _atk){
    this->name = _name;
    this->xp = _xp;
    this->hp = _hp;
    this->atk = _atk;
}

std::string Player::getName(){
    return this->name;
}

int Player::getXp(){
    return this->xp;
}

int Player::getHp(){
    return this->hp;
}

int Player::getAtk(){
    return this->atk;
}

void Player::setName(std::string _name){
    this->name = _name;
}

void Player::setXp(int _xp){
    this->xp = _xp;
}

void Player::setHp(int _hp){
    this->hp = _hp;
}

void Player::setAtk(int _atk){
    this->atk = _atk;
}

void Player::profile(){
    std::cout << "Name: " << this->getName() << std::endl;
    std::cout << "XP: " << this->getXp() << std::endl;
    std::cout << "HP: " << this->getHp() << std::endl;
    std::cout << "ATK: " << this->getAtk() << std::endl;
}

void Player::attack(Entity *entity){
    Monster *monster = (Monster *)entity;
    int monster_hp = 0;
    srand(time(NULL));
    int attack = 1+rand()%(this->atk-1);
    monster_hp = monster->getHp() - attack;
    std::cout << "The monster has suffered " << attack << " points of damage" << std::endl;
    monster->setHp(monster_hp);
}

bool Player::playerRun(){
    /*The player has a chance to run of 25%*/
    srand(time(NULL));
    int chance = rand()%(5-1);
    if(chance == 1){
        std::cout << "You scape" << std::endl;
        return true;
    }
    return false;
}