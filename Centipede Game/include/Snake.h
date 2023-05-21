#ifndef SNAKE_H
#define SNAKE_H


#include "Bug_Blaster.h"
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <SFML/Graphics.hpp>

class Snake
{
    public:
        Snake();
        virtual ~Snake();
        void init(std::string textureName, sf::Vector2f position);
        void Move(const sf::Vector2f &direction);
        std::vector<sf::Sprite>  spawn_centipede();
        void update(float dt);
        sf::Sprite getSprite() {
            return Centipede_sprite;
            }


    protected:

    private:

        std::vector<sf::Sprite> body;
        std::vector<Snake*> Centipede_body;
        std::vector<sf::Sprite> m_body;

        std::vector<sf::Sprite>::iterator m_head;
        std::vector<sf::Sprite>::iterator m_tail;
        //head
        sf::Texture Centipede_texture;
        sf::Sprite Centipede_sprite;
        sf::Vector2f Centipede_position;
        sf::Vector2f Centipede_temp;
        sf::Vector2i Centipede_spriteSize;

         float Centipede_speed = 0.8;
        bool file_found = false;
        int Centipede_length = 7;
        float x;
        float y;
        int i = 6;
        float window_x = 900;
        float window_y = 668;
};

#endif // CENTIPEDE_H


