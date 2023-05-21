#ifndef BUG_BLASTER_H
#define BUG_BLASTER_H
#include <SFML/Graphics.hpp>
#include "Insect.h"
#include "Mushroom.h"
#include "Centipede.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class FileCannotBeOpened{};
class Centipede;
class Insect;
class Mushroom;
class Bug_Blaster
{
    public:
        /**
        * @brief The init function is responsible for intitalizing the bug blaster sprite and position.
        *This is a detailed desciption of the init function
        *@param textureName This if the file location of the texture
        *@param position This is the initial position of the bullet
        */
        void init(const string textureName, sf::Vector2f position);
        /**
        * @brief The checkCollision checks the collision between two sprites and returns true if they collide and false if they don't collide
        *This is a detailed desciption of the checkCollision function
        *@param sprite1 This if the first sprite
        *@param sprite2 This is the second sprite
        *@return true if the sprites collide and false if they don't collide
        */
        bool checkCollision(sf::Sprite sprite1, sf::Sprite sprite2);
        /**
        * @brief The Centipede_collision function checks when the bug blaster collides with the centipede and decreases the bug blasters life
        *@param mushrooms This a vector of the mushrooms on the screen
        */
        void Centipede_collision(std::vector<Centipede*> Centipede_body);
        /**
        * @brief The Insect_collision When the bug blaster collides with the insect, the insect_collision() function decreases the bug blasters life and deletes the  insect
        *This is a detailed desciption of the checkCollision function
        *@param sprite1 This if the first sprite
        *@param sprite2 This is the second sprite
        *@return true if the sprites collide and false if they don't collide
        */
        std::vector<Insect*> Insect_collision(std::vector<Insect*> insects);
        /**
        * @brief The Mushroom_collision checks when the bug blaster collides with a mushroom, the Mushroom_collision() function simply prevents the bug blaster from moving in the direction of the mushroom.
        *@param mushrooms This a vector of the mushrooms on the screen
        */
        void Mushroom_collision(std::vector<Mushroom*> mushrooms);
        /**
        * @brief The Blaster_reset function resets the bug blasters life
        */
        void Blaster_reset();
        /**
        * @brief The Up function moves the bug blaster up
        */
        void Up();
        /**
        * @brief The Down function moves the bug blaster down
        */
        void Down();
        /**
        * @brief The Left function moves the bug blaster left
        */
        void Left();
        /**
        * @brief The Right function moves the bug blaster right
        */
        void Right();
        /**
        * @brief The update function contains the bug blaster within an area.
        * @param dt This is the change in time of the system
        */
        void update(float dt);
        /**
        * @brief The getSprite function returns the sprite
        *This is a detailed description of the checkCollision function
        *@return Returns sprite
        */
        sf::Sprite getSprite();
        sf::Vector2f get_position(){
            return blaster_position;
        }
        /**
        * @brief The get_bounds function returns true if the bug blaster if out of bounds and false otherwise
        *This is a detailed description of the checkCollision function
        *@return Returns boolena
        */
        bool get_bounds(){
            return out_of_bounds;
        }
        bool get_file(){
            return file_found;
        }
        /**
        * @brief The get_life function returns the life of the bug blaster
        *This is a detailed description of the checkCollision function
        *@return Returns life integer
        */
        int get_life(){
            return life;
        }

    protected:

    private:
        bool out_of_bounds = false;
        int life = 3;
        bool file_found = false;
        float window_x = 900;
        float window_y = 668;
        float blaster_SPEED = 5;
        sf::Texture blaster_texture;
        sf::Sprite blaster_sprite;
        sf::Vector2f blaster_position;
        sf::Vector2f blaster_prev_position;
};

#endif // BUG_BLASTER_H
