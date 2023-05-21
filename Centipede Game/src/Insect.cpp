#include "Insect.h"

Insect::Insect()
{
    //ctor
}

Insect::~Insect()
{
    //dtor
}
void Insect::init(std::string textureName, sf::Vector2f position){

	Insect_position = position;

	if(Insect_texture.loadFromFile(textureName.c_str())==1){
        Insect_texture.loadFromFile(textureName.c_str());
        file_found = true;
	}

	//if file not found throw an exception
	else{
	    file_found = false;
        throw FileCannotBeOpened();
	}


	// Create Sprite and Attach a Texture
	Insect_spriteSize = sf::Vector2i(32, 16);
	Insect_sprite.setTexture(Insect_texture);
	Insect_sprite.setTextureRect(sf::IntRect(0, 0, Insect_spriteSize.x, Insect_spriteSize.y));
	Insect_sprite.setPosition(Insect_position);
	Insect_sprite.setOrigin(Insect_texture.getSize().x / 2, Insect_texture.getSize().y / 2);

}
sf::Vector2f Insect::get_position(){
    return Insect_position;
}
bool Insect::is_file_found(){
    return file_found;
}
void Insect::diagonally_left(){
    Insect_temp.y = -Insect_speed;
	Insect_temp.x = -Insect_speed;
	//Insect_sprite.setPosition(Insect_position);

}
void Insect::diagonally_right(){
    Insect_temp.y = Insect_speed;
	Insect_temp.x = -Insect_speed;

}
void Insect::update(float dt){

    if(Insect_position.y + Insect_temp.y<window_y*0.8){
            diagonally_right();
    }

	else if(Insect_position.y + Insect_temp.y>=window_y*0.9){
        diagonally_left();
	}
	Insect_position.x += Insect_temp.x;
	Insect_position.y += Insect_temp.y;
	Insect_sprite.setPosition(Insect_position);



}


sf::Sprite Insect::getSprite() {

	return Insect_sprite;
}
/*
std::vector<Insect*> Insect::insect_reset(){
     for (Insect* insect : insects) {

		delete(insect);
	}
	insects.clear();
	return insects;
}
*/



