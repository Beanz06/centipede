#ifndef BOMB_H
#define BOMB_H
#include <SFML/Graphics.hpp>
#include "Bug_Blaster.h"
#include <vector>
#include <string>
#include <fstream>
#include<time.h>

class Bomb
{
    public:
        Bomb();
        virtual ~Bomb();
        /**
        * @brief The init function is responsible for intitalizing the bomb sprite and position.
        *This is a detailed desciption of the init function
        *@param textureName This if the file location of the texture
        *@param position This is the initial position of the bullet
        */
        void init(std::string textureName, sf::Vector2f position);

        /**
        * @brief The getSprite function returns the sprite
        *This is a detailed desciption of the checkCollision function
        *@return Returns sprite
        */
        sf::Sprite getSprite();
        /**
        * @brief The spawnBomb function returns four bombs placed in random positions
        *This is a detailed desciption of the checkCollision function
        *@return This returns a vector of type Bomb
        */
        std::vector<Bomb*>  spawnBomb(sf::RenderWindow & window);
        void Bomb_reset();


    protected:

    private:
        float window_x = 900;
        float window_y = 668;
        bool file_found = false;
        sf::Texture Bomb_texture;
        sf::Sprite Bomb_sprite;
        sf::Vector2f Bomb_position;
        sf::Vector2i Bomb_spriteSize;
        std::vector<Bomb*> Bombs;
        float Sprite_left=0;
};

#endif // BOMB_H
