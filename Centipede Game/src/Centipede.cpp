#include "Centipede.h"

Centipede::Centipede()
{

    //ctor
}

Centipede::~Centipede()
{
    //dtor
}
void Centipede::init(std::string  textureName, sf::Vector2f position){

	Centipede_position = position;

	// Load a Texture
	if(Centipede_texture.loadFromFile(textureName.c_str())==1){
        Centipede_texture.loadFromFile(textureName.c_str());
        file_found = true;
	}

	//if file not found throw an exception
	else{
	    file_found = false;
        throw FileCannotBeOpened();
	}

	// Create Sprite and Attach a Texture
	Centipede_spriteSize = sf::Vector2i(16, 16);
	Centipede_sprite.setTexture(Centipede_texture);
	Centipede_sprite.setTextureRect(sf::IntRect(0, 0, Centipede_spriteSize.x, Centipede_spriteSize.y));
	Centipede_sprite.setPosition(Centipede_position);
	Centipede_sprite.setOrigin(8, 8);

}

std::vector<Centipede*> Centipede::spawnCentipede( sf::Vector2f initial_pos) {
    srand((unsigned) time(0));
    float pos_x =0;
    float pos_y =0;
	sf::Vector2f centipedePos;
	centipedePos = initial_pos;
    Centipede* centipede = new Centipede();
    centipede->init("Resources/Centipede_head.png", centipedePos);
    centipede->set_head();

    //store the centipede's head in a vector

    Centipede_body.push_back(centipede);
	for ( int i = 1; i<Centipede_length ; i++){
        sf::FloatRect new_location = Centipede_body[i - 1]->getSprite().getGlobalBounds();
        sf::Vector2f new_location2 = Centipede_body[i - 1]->getSprite().getPosition();
        centipedePos = sf::Vector2f(new_location2.x + 16.f, new_location.top + new_location.height/2);
        //centipedePos = sf::Vector2f(new_location.left + new_location.width, new_location.top + new_location.height/2);
        Centipede* centipede = new Centipede();
        centipede->init("Resources/Centipede_body.png", centipedePos);

            //store the centipede's body in a vector
        Centipede_body.push_back(centipede);
	}
	left();
	return Centipede_body;


}
void Centipede::left(){
    Centipede_temp.x = -Centipede_speed;
     Centipede_temp.y = 0;
}
void Centipede::right(){
    Centipede_temp.x = Centipede_speed;
     Centipede_temp.y = 0;
}
void Centipede::down(){
    Centipede_temp.x = 0;
    Centipede_temp.y = Centipede_speed;
}
void Centipede::up(){
    Centipede_temp.x = 0;
    Centipede_temp.y = -Centipede_speed;
}
void Centipede::set_head(){
    is_head = true;
}
bool Centipede::get_head(){
    return is_head;
}
bool Centipede::is_file_found(){
    return file_found;
}

void Centipede::update(float dt){
    sf::Vector2f new_pos;

    /*
    if (Centipede_body[0]->getSprite().getPosition().x > window_x*0.8){
            left(dt);

    }
    */
    if(Centipede_temp.x!=0){
        prev_move = Centipede_temp.x;
        }

    for(int j = Centipede_length-1;j>=0; j--){
        Centipede* centipede = Centipede_body[j];
        if(centipede->get_head()==true){
            if(poison == true){
                down();
                Centipede_body[j]->Centipede_sprite.setRotation(270);
            }
             if (Centipede_body[j]->getSprite().getPosition().x < window_x*0.05 || Centipede_body[j]->getSprite().getPosition().x > window_x*0.95 || centipede->get_collision() == true ){

                down();
                centipede->set_temp(Centipede_temp);
                //prev_move = Centipede_temp.x;
                Centipede_body[j]->Centipede_sprite.setRotation(270);
                if (Centipede_body[j]->getSprite().getPosition().y == Centipede_body[j+1]->Centipede_sprite.getPosition().y + 16.f && Centipede_body[j]->getSprite().getPosition().x < window_x*0.1  ||  Centipede_body[j]->getSprite().getPosition().y == Centipede_body[j+1]->Centipede_sprite.getPosition().y + 16.f && centipede->get_collision() == true && prev_move<0 && poison == false){
                right();
                centipede->set_temp(Centipede_temp);
                Centipede_body[j]->Centipede_sprite.setRotation(180);
                //mushroom_centipede_collision =false;
                centipede->set_collision(false);

                }
                else if (Centipede_body[j]->getSprite().getPosition().y == Centipede_body[j+1]->Centipede_sprite.getPosition().y + 16.f && Centipede_body[j]->getSprite().getPosition().x > window_x*0.9  || Centipede_body[j]->getSprite().getPosition().y == Centipede_body[j+1]->Centipede_sprite.getPosition().y + 16.f && centipede->get_collision()== true && prev_move>0 && poison == false){
                    left();
                    centipede->set_temp(Centipede_temp);
                    Centipede_body[j]->Centipede_sprite.setRotation(359);

                    //mushroom_centipede_collision =false;
                    centipede->set_collision(false);
                }
            }
            //Centipede_body[j]->Centipede_sprite.setPosition(Centipede_body[j]->Centipede_sprite.getPosition()+ Centipede_temp);
        }
    }
    /*
    else if (Centipede_body[0]->getSprite().getPosition().y >= window_y*0.99&&poison == true){
        centipede_reset();
        spawnCentipede(sf::Vector2f(window_x * 0.8,window_y* 0.2));

    }
    */

   for(int j = Centipede_length-1;j>=0; j--){
        Centipede* centipede = Centipede_body[j];

        if(centipede->get_head()==true){
           Centipede_body[j]->Centipede_sprite.setPosition(Centipede_body[j]->Centipede_sprite.getPosition()+ centipede->get_temp());
        }
        else{
            //if the previous sprite rotated
            if(Centipede_body[j-1]->Centipede_sprite.getRotation()==270){
                Centipede_body[j]->Centipede_sprite.setRotation(270);
            }
            else if(Centipede_body[j-1]->Centipede_sprite.getRotation()==359){
                Centipede_body[j]->Centipede_sprite.setRotation(359);
            }
            else if(Centipede_body[j-1]->Centipede_sprite.getRotation()==180){
                Centipede_body[j]->Centipede_sprite.setRotation(180);
            }

            Centipede_body[j]->Centipede_sprite.setPosition(Centipede_body[j-1]->Centipede_sprite.getPosition());
        }
   }


}
void Centipede::Draw(sf::RenderWindow & window,std::vector<Centipede*> centipede_body){
    for (int i = 1; i < centipede_body.size(); ++i) {
		window.draw(centipede_body[i]->getSprite());
	}
	window.draw(centipede_body[0]->getSprite());

}
bool Centipede::checkCollision(sf::Sprite sprite1, sf::Sprite sprite2){
    sf::FloatRect shape1 = sprite1.getGlobalBounds();
	sf::FloatRect shape2 = sprite2.getGlobalBounds();

	if (shape1.intersects(shape2)) {

		return true;

	}
	else {

		return false;

	}

}
void Centipede::Mushroom_collision(std::vector<Mushroom*> mushrooms){
    for(int i = Centipede_length-1;i>=0; i--){
    for (int j = 0; j < mushrooms.size(); j++) {

                Mushroom* mushroom = mushrooms[j];
                Centipede* centipede = Centipede_body[i];
                if (centipede->get_head()==true){
                if (checkCollision(centipede->getSprite(), mushroom->getSprite())) {
                    //mushroom_centipede_collision = true;
                    centipede->set_collision(true);
                    if(mushroom->get_poisnous()==true){
                        poison = mushroom->get_poisnous();
                    }

                    //return true;


                }



            }
    }
    }
            /*
            else{
                    mushroom_centipede_collision =false;
                }
                */

}
void Centipede::centipede_reset(){
    for (Centipede* centipede : Centipede_body) {

		delete(centipede);
	}
	Centipede_body.clear();
	poison = false;
	//return Centipede_body;

}
sf::Sprite Centipede::getSprite() {

	return Centipede_sprite;
}

