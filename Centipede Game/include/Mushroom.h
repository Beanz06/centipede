#ifndef MUSHROOM_H
#define MUSHROOM_H
#include <SFML/Graphics.hpp>
#include "Bug_Blaster.h"
#include <vector>
#include <string>
#include <fstream>
#include<time.h>

class Mushroom
{
    public:
        Mushroom();
        virtual ~Mushroom();
        /**
        * @brief The init() function is responsible for intitalizing the mushroom sprite and position.
        *This is a detailed desciption of the init function
        *@param textureName This if the file location of the texture
        *@param position This is the initial position of the bullet
        */
        void init(std::string textureName, sf::Vector2f position);
        /**
        * @brief The poison_init() function is responsible for intitalizing the poisonous mushroom sprite and position.
        *This is a detailed description of the poison_init function
        *@param textureName This if the file location of the texture
        *@param position This is the initial position of the bullet
        */
        void poison_init(std::string textureName, sf::Vector2f position);
        /**
        * @brief The getSprite function returns the sprite
        *This is a detailed desciption of the checkCollision function
        *@return Returns sprite
        */
        sf::Sprite getSprite();
        /**
        * @brief The spawnMushroom function returns 25 mushrooms placed in random positions
        *This is a detailed desciption of the checkCollision function
        *@return This returns a vector of type Mushroom
        */
        std::vector<Mushroom*> spawnMushroom(sf::RenderWindow & window);

        void mushroom_reset();
        void poisnous_mushroom();
        bool get_poisnous();
        void incr_points();
        void animate_sprite();
        void animate_reset();

        int get_Sprite_left();
        bool get_file();
        float get_mushroom_size();
        void Draw(sf::RenderWindow & window);


    protected:

    private:
        bool file_found = false;
        int mushroom_points = 0;
        float window_x = 900;
        float window_y = 668;
        bool is_poisnous = false;
        std::vector<Mushroom*> mushrooms;
        sf::Texture mushroom_texture;
        sf::Sprite mushroom_sprite;
        sf::Vector2f mushroom_position;
        sf::Vector2i mushroom_spriteSize;
        float Sprite_left=0;

};

#endif // MUSHROOM_H

