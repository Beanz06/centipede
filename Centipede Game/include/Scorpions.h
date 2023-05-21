#ifndef SCORPIONS_H
#define SCORPIONS_H
#include <SFML/Graphics.hpp>
#include "Bug_Blaster.h"
#include <vector>
#include <string>
#include <fstream>
#include <time.h>

class Scorpions
{
    public:
        Scorpions();
        virtual ~Scorpions();
        /**
        * @brief The init function is responsible for intitalizing the scorpion sprite and position.
        *This is a detailed desciption of the init function
        *@param textureName This if the file location of the texture
        *@param position This is the initial position of the bullet
        */
        void init(std::string textureName, sf::Vector2f position);
        std::vector<Scorpions*> scorpion_reset();
        /**
        * @brief The spawnScorpion function returns a scorpion placed in a random y position
        *This is a detailed desciption of the checkCollision function
        *@return This returns a vector of type Scorpions
        */
        std::vector<Scorpions*> spawnScorpion();
        void Draw(sf::RenderWindow & window, std::vector<Scorpions*> scorpions);
        /**
        * @brief The checkCollision checks the collision between two sprites and returns true if they collide and false if they don't collide
        *This is a detailed desciption of the checkCollision function
        *@param sprite1 This if the first sprite
        *@param sprite2 This is the second sprite
        *@return true if the sprites collide and false if they don't collide
        */
        bool checkCollision(sf::Sprite sprite1, sf::Sprite sprite2);

        std::vector<Mushroom*> Mushroom_collision(std::vector<Mushroom*> mushrooms);
        /**
        * @brief The update function moves the scorpion across the screen and when the scorpion is out of the screen bounds, the scorpion is deleted..
        * @param dt This is the change in time of the system.
        * @return This returns a vector of the scorpions.
        */
        std::vector<Scorpions*>update(float dt);
        //void scorpion_reset();
        bool is_file_found();
        bool is_out_of_Bounds();
        bool is_mushroom_collision();
        //This manually adds a scorpion to the screen, used for testing only.
        void add_scorpion(Scorpions* scorpion);
        sf::Sprite getSprite();
        void left();
        void right();

    protected:

    private:
        float Scorpion_speed = 3;
        float x;
        float y;
        float window_x = 900;
        float window_y = 668;
        bool file_found = false;
        bool out_of_Bounds = false;
        bool mushroom_collision = false;
        //ifstream infile_;

        std::vector<Scorpions*> scorpions;
        sf::Texture Scorpion_texture;
        sf::Sprite Scorpion_sprite;
        sf::Vector2f Scorpion_position;
        sf::Vector2f Scorpion_temp;
        sf::Vector2i Scorpion_spriteSize;
};

#endif // SCORPIONS_H
