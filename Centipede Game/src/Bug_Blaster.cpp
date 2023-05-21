#include "Bug_Blaster.h"


void Bug_Blaster::init(const string textureName, sf::Vector2f position){

	blaster_position = position;

	// Load a Texture
	if(blaster_texture.loadFromFile(textureName.c_str())==1){
        blaster_texture.loadFromFile(textureName.c_str());
        file_found = true;
	}

	//if file not found throw an exception
	else{
	    file_found = false;
        throw FileCannotBeOpened();
	}

	// Create Sprite and Attach a Texture
	blaster_sprite.setTexture(blaster_texture);
	blaster_sprite.setPosition(blaster_position);
	blaster_sprite.setOrigin(blaster_texture.getSize().x / 2, blaster_texture.getSize().y / 2);

}
void Bug_Blaster::update(float dt){
    // if statements, clamp blaster in bounds

    if (blaster_position.x >= window_x * 0.9f) {
		blaster_position.x = window_x * 0.9f;
		out_of_bounds = true;

	}
	else if (blaster_position.x <= window_x*0.1f) {

		blaster_position.x = window_x*0.1f;
		out_of_bounds = true;
	}
	else if (blaster_position.y >= window_y * 0.9f) {

		blaster_position.y = window_y * 0.9f;
		out_of_bounds = true;
	}
	else if (blaster_position.y <= window_y*0.8f) {

		blaster_position.y = window_y*0.8f;
		out_of_bounds = true;
	}
	else{
        out_of_bounds = false;
	}
}
sf::Sprite Bug_Blaster::getSprite(){
    //return the Blater's sprite
	return blaster_sprite;
}

//moves blaster Up
void Bug_Blaster::Up()
{
    //update blaster's y position
    blaster_prev_position = blaster_position;
	blaster_position.y -= blaster_SPEED;
	blaster_sprite.setPosition(blaster_position);
}

//moves blaster Down
void Bug_Blaster::Down()
{
    //update blaster's y position
    blaster_prev_position = blaster_position;
	blaster_position.y += blaster_SPEED;
	blaster_sprite.setPosition(blaster_position);
}

//moves blaster Left
void Bug_Blaster::Left()
{
    //update blaster's x position
    blaster_prev_position = blaster_position;
	blaster_position.x -= blaster_SPEED;
	blaster_sprite.setPosition(blaster_position);
}

//moves blaster Right
void Bug_Blaster::Right()
{
	//update blaster's x position
	blaster_prev_position = blaster_position;
	blaster_position.x += blaster_SPEED;
	blaster_sprite.setPosition(blaster_position);
}

bool Bug_Blaster::checkCollision(sf::Sprite sprite1, sf::Sprite sprite2) {

	sf::FloatRect shape1 = sprite1.getGlobalBounds();
	sf::FloatRect shape2 = sprite2.getGlobalBounds();

	if (shape1.intersects(shape2)) {

		return true;

	}
	else {

		return false;

	}

}
std::vector<Insect*>  Bug_Blaster::Insect_collision(std::vector<Insect*> insects){
    for (int j = 0; j < insects.size(); j++) {

                Insect* insect = insects[j];

                if (checkCollision(getSprite(), insect->getSprite())) {

                --life;
                    //bullets.erase(bullets.begin() + i);
                    insects.erase(insects.begin() + j);

                    //delete(bullet);
                    delete(insect);

                    //printf(" rocket intersects enemy \n");

                }

            }
            return insects;

}

void Bug_Blaster::Centipede_collision(std::vector<Centipede*> Centipede_body){
        for (int j = 0; j < Centipede_body.size(); j++) {


                Centipede* centipede = Centipede_body[j];

                if (checkCollision(getSprite(), centipede->getSprite())) {
                        --life;
                        //Centipede_body.clear();
                       // centipede_reset();

                }
        }
            //return Centipede_body;

}

void Bug_Blaster::Mushroom_collision(std::vector<Mushroom*> mushrooms){
    for (int j = 0; j < mushrooms.size(); j++) {

                Mushroom* mushroom = mushrooms[j];

                if (checkCollision(getSprite(), mushroom->getSprite())) {
                    blaster_position = blaster_prev_position;


                }


            }

}
void Bug_Blaster::Blaster_reset(){
    life = 3;
    //init("Resources/blaster.png", sf::Vector2f(window_x * 0.5f, window_y * 0.85f));

}
