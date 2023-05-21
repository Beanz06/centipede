#ifndef BULLETS_H
#define BULLETS_H
#include <SFML/Graphics.hpp>
#include "Bug_Blaster.h"
#include "Mushroom.h"
#include "Insect.h"
#include "Centipede.h"
#include "Scorpions.h"
#include "Bomb.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Bullets: public Mushroom, public Insect, public Centipede, public Scorpions, public Bomb
{
    public:
        Bullets();
        virtual ~Bullets();
        /**
        * @brief The init() function is responsible for intitalizing the bullets sprite and position.
        *This is a detailed desciption of the init function
        *@param textureName This if the file location of the texture
        *@param position This is the initial position of the bullet
        *@param _speed This is the speed of the bullet

        */
        void init(std::string textureName, sf::Vector2f position, float _speed);
        /**
        * @brief The update function moves the bullet upwards and when the bullet is out of the screen bounds the bullet is deleted.
        * @param dt This is the change in time of the system
        */
        void update(float dt);
        /**
        * @brief The checkCollision checks the collision between two sprites and returns true if they collide and false if they don't collide
        *This is a detailed desciption of the checkCollision function
        *@param sprite1 This if the first sprite
        *@param sprite2 This is the second sprite
        *@return true if the sprites collide and false if they don't collide
        */
        bool checkCollision(sf::Sprite sprite1, sf::Sprite sprite2);
        /**
        * @brief The checkCollisionBomb checks the collision between the bomb and other sprites,it returns true if they collide and false if they don't collide
        *This is a detailed desciption of the checkCollision function
        *@param sprite1 This if the first sprite
        *@param sprite2 This is the second sprite
        *@return true if the sprites collide and false if they don't collide
        */
        bool checkCollisionBomb(sf::Sprite sprite1, sf::Sprite sprite2);
        /**
        * @brief The Mushroom_collision function checks whether the bullets have collided with a mushroom or a poisonous mushroom.
        * @brief changes the mushroom’s texture. After the mushroom is shot four times, the mushroom is deleted and the points of the player increase.
        * @brief But if the player loses a life before the mushroom is shot four times and deleted, the mushroom sprite returns to its original form.
        *@param mushrooms This a vector of the mushrooms on the screen
        *@param life This is the life of the bug blaster
        *@param prev_life This is the previous life of the bug blaster
        */
        void Mushroom_collision(std::vector<Mushroom*> & mushrooms, int life, int prev_life);
        /**
        * @brief The Insect_collision function checks whether the bullets have collided with an insect.
        * @brief When the bullet collides with the insect, the Insect_collision() function deletes the insect and the bullet, while also increasing the players points.
        *@param insects This a vector of the insects on the screen
        */
        void Insect_collision(std::vector<Insect*> & insects);
        /**
        * @brief The Bomb_collision function checks whether the bullets have collided with a bomb.
        * @brief When the bullet collides with a bomb, the Bomb_collision() function deletes the bullets and the bomb, it also deletes all the mushrooms within the bombs radius
        *@param Bombs This a vector of the bombs on the screen
        *@param mushrooms This a vector of the mushrooms on the screen
        */
        void Bomb_collision(std::vector<Bomb*> & Bombs, std::vector<Mushroom*> & mushrooms);
        void Scorpion_collision(std::vector<Scorpions*> & scorpions);
        /**
        * @brief The Centipede_collision function checks whether the bullets have collided with any centipede segment.
        * @brief When the bullet collides with a centipede segment, the function changes the centipede segments which are shot turn into mushrooms therefore when an interior segment is shot
        * @brief , the new centipede which is formed from the rear piece will immediately collide with the mushroom resulting from the shot segment and reverse direction.
        *@brief The points the player gets vary depending on whether the head or the body was shot.
        *@param Bombs This a vector of the bombs on the screen
        *@param mushrooms This a vector of the mushrooms on the screen
        */
        void Centipede_collision(std::vector<Centipede*> & centipede_body, std::vector<Mushroom*> & mushrooms);
        void Centipede_to_Mushroom(std::vector<Centipede*> & centipede_body, std::vector<Mushroom*> & mushrooms);
        /**
        * @brief The shoot function creates a new bullet and stores it in a vector of the Bullet type
        *This is a detailed description of the checkCollision function
        *@param blaster_position This is the position of the blaster
        */
        void shoot(sf::Vector2f blaster_position);
        /**
        * @brief The Move function moves the bullet upwards
        */
        void Move();
        void Draw(sf::RenderWindow & window);
        //Bug_Blaster blaster;
        /**
        * @brief The getSprite function returns the sprite
        *This is a detailed desciption of the checkCollision function
        *@return Returns sprite
        */
        sf::Sprite getSprite();
        std::vector<Bullets*> get_bullets();
        sf::Vector2f get_position();
        bool is_mushroom_collision(){
            return mushroom_collision;
        }
        bool get_file(){
            return file_found;
        }
        void reset_points(){
            mushroom_points =0;
            insect_points = 0;
            centipede_points=0;

        }
        void incr_mushroom_points(){
            mushroom_points+=1;
        }
        void incr_insect_points(){
            insect_points+=300;
        }
        void incr_centipede_points(){
            centipede_points+=10;
        }
        void incr_centipede_head_points(){
            centipede_points+=100;
        }
        void incr_scorpion_points();
        int get_points(){
            points = mushroom_points + insect_points + centipede_points + scorpion_points;
            return points;
        }


    protected:

    private:
        std::vector<Bullets*> bullets;
        float dt;
        float speed = 5;
        //Mushroom mushroom;
        bool file_found = false;
        bool mushroom_collision = false;
        int mushroom_points = 0;
        int insect_points = 0;
        int centipede_points = 0;
        int scorpion_points = 0;
        int rad = 16.f;
        int points = mushroom_points + insect_points + centipede_points + scorpion_points;
        sf::Texture bullets_texture;
        sf::Sprite bullets_sprite;
        sf::Vector2f bullets_position;
        float bullets_speed;
};

#endif // BULLETS_H
