#include <iostream>
#include <cstdlib>
#include <ctime>
#include "lib/entity.h"
#include "lib/Player.h"
#include "lib/Monster.h"


void gameMotor();
void middleGame(Player *);
bool playerOptions(Player *, Monster *);
Monster *generateMonster();

int main(int argc, char const *argv[]){
    srand(time(NULL));
    

    gameMotor();
}

void gameMotor(){
    int opt;
    std::string name;
    Player *player;

    do
    {
        system("clear");
        std::cout << "[1] New Game" << std::endl;
        std::cout << "[2] Continue" << std::endl;
        std::cout << "[3] Exit" << std::endl;
        std::cin >> opt;
        switch(opt)
        {
        case 1:
            std::cout << "Hi new traveler" << std::endl;
            std::cout << "Whats is your name?: " << std::endl;
            std::cin >> name;
            
            player = new Player(name, 0, 100, 15);

            std::cout << "Nice to meet you " << player->getName() << std::endl;
            middleGame(player);
            break;
        case 2:
            std::cout << "The option is blocked" << std::endl;
            break;

        case 3:
            std::cout << "See you later" << std::endl;
            break;
        
        default:
            std::cout << "Wrong Option!" << std::endl;
            break;
        }
        
    } while (opt != 3);
}

Monster *generateMonster(){
    int monster_type = 1+rand()%(3-1);
    int monster_hp = 31+rand()%(51-31);
    int monster_max_strength;

    if(monster_type == 2){
        monster_max_strength = 25+rand()%(80-25);
    }else{
        monster_max_strength = 1+rand()%(25-1);
    }

    Monster *monster = new Monster(monster_type, monster_hp, monster_max_strength);
    std::cout << "A monster type " << monster->getType() <<" has appared" << std::endl;

    return monster;
}

bool playerOptions(Player *player, Monster *monster){
    int opt, c;
    bool match_over = false;
    player->profile();
    std::cout << std::endl;
    std::cout << "[1] ATK" << std::endl;
    std::cout << "[2] RUN" << std::endl;
    std::cout << "[3] SUICIDE" << std::endl;
    std::cout << "What do you want to do?: " << std::endl;
    std::cin >> opt;

    switch (opt){
        case 1:
            player->attack(monster);
            break;

        case 2:
            match_over = player->playerRun();
            break;

        case 3:
            std::cout << "Bye cruel world..." << std::endl;
            player->setHp(0);
            getchar();
            break;

        default:
            std::cout << "Error during the player options" << std::endl;
            break;
    }

    return match_over;
}

void middleGame(Player *player){
    bool game_over = false;
    int match_over = false;
    Monster *monster = generateMonster();
    int monster_todo;

    while (player->getHp() > 0){
            monster_todo = 1+rand()%(3-1);
            if(monster->getHp() > 0){
                std::cout << "The HP of the monster is: " << monster->getHp() << std::endl;
                if(monster_todo == 1){
                    std::cout << "The monster attack!!!" << std::endl;
                    monster->attack(player);
                }else{
                    std::cout << "The monster is watching" << std::endl;
                }

                match_over = playerOptions(player, monster);
                
                if(match_over == true){
                    middleGame(player);
                }
            }else {
                int player_xp = player->getXp() + 10;
                int player_hp = player->getHp() + 10;
                int player_atk = player->getAtk() + 10;

                std::cout << "You have won " << player_xp << " XP" << std::endl;
                std::cout << "You have won " << player_hp << " HP" << std::endl;
                std::cout << "You have won " << player_atk << " ATK" << std::endl;
                player->setXp(player_xp);
                player->setHp(player_hp);
                player->setAtk(player_atk);
                middleGame(player);
            }
    }
}