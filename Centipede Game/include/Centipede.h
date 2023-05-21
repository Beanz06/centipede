#ifndef CENTIPEDE_H
#define CENTIPEDE_H
#include "Bug_Blaster.h"
#include "Mushroom.h"
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <SFML/Graphics.hpp>
class Mushroom;
class Centipede
{
    public:
        Centipede();
        virtual ~Centipede();
        /**
        * @brief The init() function is responsible for intitalizing the centipede sprite and position.
        *This is a detailed desciption of the init function
        *@param textureName This if the file location of the texture
        *@param position This is the initial position of the bullet
        */
        void init(std::string textureName, sf::Vector2f position);
        /**
        * @brief The checkCollision checks the collision between two sprites and returns true if they collide and false if they don't collide
        *This is a detailed desciption of the checkCollision function
        *@param sprite1 This if the first sprite
        *@param sprite2 This is the second sprite
        *@return true if the sprites collide and false if they don't collide
        */
        bool checkCollision(sf::Sprite sprite1, sf::Sprite sprite2);
        /**
        * @brief The Mushroom_collision function checks whether any of the head segments of the centipede have collided with a mushroom or aa poisonous mushroom. If a head segment collides a normal mushroom, the mushroom_centipede_collision value of that segment is set to true. Otherwise, if the centipede head segment collides with a poisonous mushroom the poison value for that segment is set to true.
        *@param mushrooms This a vector of the mushrooms on the screen
        */
        void Mushroom_collision(std::vector<Mushroom*> mushrooms);
        /**
        *@brief The Draw function draws the centipede on the screen
        *@param window thie is the rendered window
        *@param centipede_body this is a vector of the centipede
        */
        void Draw(sf::RenderWindow & window, std::vector<Centipede*> centipede_body);
        /**
        *@brief The is_file_found function returns true if the texture file is found and false if it is not
        *@return This returns a bool
        */
        bool is_file_found();
        /**
        *@brief The centipede_reset function resets the centipede back to its original form
        */
        void centipede_reset();
        /**
        *@brief set_head function sets the specified centipede segment as a head
        */
        void set_head();
        /**
        *@brief The get_head function returns true if the centipede segment is a head and false otherwise
        */
        bool get_head();
        /**
        * @brief The update function makes the centipede change direction when the head segment has collided with a mushroom and when the head segment has collided with a poisonous mushroom, that segment and the following segments go straight down into the player area.
        * @param dt This is the change in time of the system
        */
        void update(float dt);
        /**
        * @brief The getSprite function returns the sprite
        *This is a detailed desciption of the checkCollision function
        *@return Returns sprite
        */
        sf::Sprite getSprite();
        /**
        * @brief The set_temp function sets a temporary direction for the centipede
        *This is a detailed desciption of the checkCollision function
        *@param previous dir direction of the centipede
        */
        sf::Vector2f set_temp(sf::Vector2f dir){
            Centipede_temp = dir;
        }
        sf::Vector2f get_temp(){
            return Centipede_temp;
        }
        sf::Vector2f get_position(){
            return Centipede_position;
        }
        /**
        * @brief The set_collision function sets the collision to true if the centipede collides with a mushroom and false if it does not
        *This is a detailed desciption of the checkCollision function
        *@param collision This is true if there is a collision between the centipede and the mushroom and false otherwise.
        */
        void set_collision(bool collision){
            mushroom_centipede_collision = collision;
        }

        bool get_collision(){
            return mushroom_centipede_collision;
        }
        /**
        * @brief The spawnCentipede function returns a centipede vector
        *This is a detailed desciption of the checkCollision function
        *@param initial_pos This is the initial position of the centipede
        *@return This returns a vector of type Scorpions
        */
        std::vector<Centipede*> spawnCentipede( sf::Vector2f initial_pos);
        std::vector<Centipede*> get_centipede(){
            return Centipede_body;
        }
        bool get_file(){
            return file_found;
        }
        /**
        * @brief The left function moves the centipede left
        */
        void left();
        /**
        * @brief The right function moves the centipede right
        */
        void right();
        /**
        * @brief The down function moves the centipede down
        */
        void down();
        /**
        * @brief The up function moves the centipede up
        */
        void up();


    protected:

    private:
        float Centipede_speed = 16.f;
        bool file_found = false;
        int Centipede_length = 9;
        float x;
        float y;
        int i = 6;
        float window_x = 900;
        float window_y = 668;
        float prev_move = 0;
        bool mushroom_centipede_collision = false;
        bool poison = false;
        bool is_head = false;
        std::vector<sf::Sprite> body;
        std::vector<Centipede*> Centipede_body;
        //head
        sf::Texture Centipede_texture;
        sf::Sprite Centipede_sprite;
        sf::Vector2f Centipede_position;
        sf::Vector2f Centipede_temp = sf::Vector2f(-Centipede_speed, 0);
        //Centipede_temp.x = -Centipede_speed;
     //Centipede_temp.y = 0;
        sf::Vector2f Centipede_t;
        sf::Vector2i Centipede_spriteSize;

};

#endif // CENTIPEDE_H

