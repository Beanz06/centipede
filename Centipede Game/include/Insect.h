#ifndef INSECT_H
#define INSECT_H
#include <SFML/Graphics.hpp>
#include "Bug_Blaster.h"
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

class Insect
{
    public:
        Insect();
        virtual ~Insect();
        /**
        * @brief The init function is responsible for intitalizing the insect sprite and position.
        *This is a detailed desciption of the init function
        *@param textureName This if the file location of the texture
        *@param position This is the initial position of the bullet
        */
        void init(std::string textureName, sf::Vector2f position);
        std::vector<Insect*> insect_reset();
        /**
        * @brief The update function moves the insect/spider diagonally left and right across the screen within the player’s area. This function changes the insect’s movement direction when it reaches a certain y-position
        * @param dt This is the change in time of the system
        */
        void update(float dt);
        bool is_file_found();
        /**
        * @brief The getSprite function returns the sprite
        *This is a detailed description of the checkCollision function
        *@return Returns sprite
        */
        sf::Sprite getSprite();
        sf::Vector2f get_position();
        void diagonally_left();
        void diagonally_right();

    protected:

    private:
        float Insect_speed = 1.5;
        float x;
        float y;
        float window_x = 900;
        float window_y = 668;
        //ifstream infile_;
        bool insect_bound = true;
        bool file_found = false;
        sf::Texture Insect_texture;
        sf::Sprite Insect_sprite;
        sf::Vector2f Insect_position;
        sf::Vector2f Insect_temp;
        sf::Vector2i Insect_spriteSize;
};

#endif // INSECT_H
