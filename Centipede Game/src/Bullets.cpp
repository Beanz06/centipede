#include "Bullets.h"

Bullets::Bullets()
{
    //ctor
}

Bullets::~Bullets()
{
    //dtor
}
void Bullets::init(std::string textureName, sf::Vector2f position, float _speed){

	bullets_speed = _speed;
	bullets_position = position;

	// Load a Texture

	if(bullets_texture.loadFromFile(textureName.c_str())==1){
        bullets_texture.loadFromFile(textureName.c_str());
        file_found = true;
	}

	//if file not found throw an exception
	else{
	    file_found = false;
        throw FileCannotBeOpened();
	}
	// Create Sprite and Attach a Texture
	bullets_sprite.setTexture(bullets_texture);
	bullets_sprite.setPosition(bullets_position);
	bullets_sprite.setOrigin(bullets_texture.getSize().x / 2, bullets_texture.getSize().y / 2);

}
std::vector<Bullets*> Bullets::get_bullets(){
    return bullets;
}
sf::Vector2f Bullets::get_position(){
    return bullets_position;
}
void Bullets::Move(){
    //update bullets y position
	bullets_position.y -= bullets_speed;
	bullets_sprite.setPosition(bullets_position);
}
void Bullets::incr_scorpion_points(){
    scorpion_points +=1000;
}

void Bullets::update(float dt){

    for (int i = 0; i < bullets.size(); i++) {

		Bullets* bullet = bullets[i];

		bullet->Move();

		//delete bullet once off screen
		if (bullet->getSprite().getPosition().y > 668) {

			bullets.erase(bullets.begin() + i);
			delete(bullet);

		}

	}

    //update bullets y position
	//bullets_position.y -= bullets_speed*dt;
	//bullets_sprite.setPosition(bullets_position);

}


sf::Sprite Bullets::getSprite() {

	return bullets_sprite;
}
void Bullets::shoot(sf::Vector2f blaster_position) {

	Bullets* bullet = new Bullets();

	bullet->init("Resources/bullet.png", blaster_position, speed);

	bullets.push_back(bullet);

}

bool Bullets::checkCollision(sf::Sprite sprite1, sf::Sprite sprite2) {

	sf::FloatRect shape1 = sprite1.getGlobalBounds();
	sf::FloatRect shape2 = sprite2.getGlobalBounds();

	if (shape1.intersects(shape2)) {

		return true;

	}
	else {

		return false;

	}

}
bool Bullets::checkCollisionBomb(sf::Sprite sprite1, sf::Sprite sprite2) {
    //sprite1.setPosition(sprite1.getPosition().x+16.f, sprite1.getPosition().y );
	sf::FloatRect shape1 = sprite1.getGlobalBounds();
	sf::FloatRect shape2 = sprite2.getGlobalBounds();


	float dx = (sprite1.getPosition().x ) - (sprite2.getPosition().x);
		float dy = (sprite1.getPosition().y) - (sprite2.getPosition().y );
		float distance = std::sqrt((dx * dx) + (dy * dy));

		if (distance <= (shape1.width / 2) + (shape2.width / 2) + rad)
		{
			return true;
		}
		else
		{
			return false;
		}


}
void Bullets::Draw(sf::RenderWindow & window){
    for (Bullets *bullet : bullets) {

		window.draw(bullet->getSprite());
	}
}

void Bullets::Mushroom_collision(std::vector<Mushroom*> &mushrooms, int life, int prev_life){
    for (int i = 0; i < bullets.size(); i++) {
            for (int j = 0; j < mushrooms.size(); j++) {

                Bullets* bullet = bullets[i];
                Mushroom* mushroom = mushrooms[j];
                mushroom_collision = false;
                if (checkCollision(bullet->getSprite(), mushroom->getSprite())) {
                    //if mushroom is shot the mushroom sprite changes
                    mushroom_collision = true;
                    mushroom->animate_sprite();
                    mushroom->init("Resources/mushroom.png", mushroom->getSprite().getPosition());
                    if(mushroom->get_poisnous()==true){
                        mushroom->poison_init("Resources/mushroom.png", mushroom->getSprite().getPosition());
                    }
                    bullets.erase(bullets.begin() + i);
                    delete(bullet);
                    //if the mushroom is shot 4 times it is deleted
                    if(mushroom->get_Sprite_left()==64){
                      mushrooms.erase(mushrooms.begin() + j);
                      delete(mushroom);
                      incr_mushroom_points();
                    }



                }
                else if(prev_life>life){
                    mushroom->animate_reset();
                    mushroom->init("Resources/mushroom.png", mushroom->getSprite().getPosition());

                }

            }
        }

}
void Bullets::Insect_collision(std::vector<Insect*> & insects){
    for (int i = 0; i < bullets.size(); i++) {
            for (int j = 0; j < insects.size(); j++) {

                Bullets* bullet = bullets[i];
                Insect* insect = insects[j];

                if (checkCollision(bullet->getSprite(), insect->getSprite())) {


                    bullets.erase(bullets.begin() + i);
                    insects.erase(insects.begin() + j);

                    delete(bullet);
                    delete(insect);
                    incr_insect_points();
                    //printf(" rocket intersects enemy \n");

                }

            }
        }

}
void Bullets::Scorpion_collision(std::vector<Scorpions*> &scorpions){
    for (int i = 0; i < bullets.size(); i++) {
            for (int j = 0; j < scorpions.size(); j++) {

                Bullets* bullet = bullets[i];
                Scorpions* scorpion = scorpions[j];
                if (checkCollision(bullet->getSprite(), scorpion->getSprite())) {


                    bullets.erase(bullets.begin() + i);
                    scorpions.erase(scorpions.begin() + j);

                    delete(bullet);
                    delete(scorpion);
                    incr_scorpion_points();


                }

            }
        }

}

void Bullets::Centipede_collision(std::vector<Centipede*> &centipede_body, std::vector<Mushroom*> &mushrooms){
    for (int i = 0; i < bullets.size(); i++) {
            for (int j = 0; j < centipede_body.size(); j++) {

                Bullets* bullet = bullets[i];
                Centipede* centipede = centipede_body[j];

                if (checkCollision(bullet->getSprite(), centipede->getSprite())) {


                    //delete centipede segment shot and convert segment to head
                    if(j == centipede_body.size()-1 ){
                        bullets.erase(bullets.begin() + i);
                        centipede_body.erase(centipede_body.begin() + j);

                        delete(bullet);
                        //delete(centipede);
                        incr_centipede_points();
                    }
                    else{
                    centipede_body[j+1]->init("Resources/Centipede_head.png", centipede_body[j+1]->getSprite().getPosition());
                    centipede_body[j+1]->set_head();
                    bullets.erase(bullets.begin() + i);
                    centipede_body.erase(centipede_body.begin() + j);

                    delete(bullet);
                    //change centipede to mushroom
                    sf::Vector2f mushroomPos = centipede->getSprite().getPosition();
                    Mushroom* mushroom = new Mushroom();
                    mushroom->init("Resources/mushroom.png", mushroomPos);

                    //store the mushrooms in a vector
                    mushrooms.push_back(mushroom);

                    //delete(centipede);

                        if(j==0){
                            incr_centipede_head_points();
                        }
                        else
                        incr_centipede_points();
                    }

                }

            }
        }



}
/*
void Bullets::Centipede_to_Mushroom(std::vector<Centipede*> &centipede_body, std::vector<Mushroom*> &mushrooms){
    for (int i = 0; i < bullets.size(); i++) {
            for (int j = 0; j < centipede_body.size(); j++) {

                Bullets* bullet = bullets[i];
                Centipede* centipede = centipede_body[j];

                if (checkCollision(bullet->getSprite(), centipede->getSprite())) {

                    sf::Vector2f mushroomPos = centipede->getSprite().getPosition();
                    Mushroom* mushroom = new Mushroom();
                    mushroom->init("Resources/mushroom.png", mushroomPos);

                    //store the mushrooms in a vector
                    mushrooms.push_back(mushroom);


                }

            }
        }



}
*/

void Bullets::Bomb_collision(std::vector<Bomb*> & Bombs, std::vector<Mushroom*> &mushrooms){
    for (int i = 0; i < bullets.size(); i++) {
            for (int j = 0; j < Bombs.size(); j++) {

                Bullets* bullet = bullets[i];
                Bomb* bomb = Bombs[j];

                if (checkCollision(bullet->getSprite(), bomb->getSprite())) {


                            for (int z = 0; z < mushrooms.size(); z++) {
                                Mushroom* mushroom = mushrooms[z];
                                if(checkCollisionBomb(bomb->getSprite(),mushroom->getSprite())){
                                 mushrooms.erase(mushrooms.begin() + z);
                                 //delete(mushroom);
                                }

                    }
                    bullets.erase(bullets.begin() + i);
                    delete(bullet);
                    Bombs.erase(Bombs.begin() + j);
                    //delete(bomb);

                }

            }
        }


}

