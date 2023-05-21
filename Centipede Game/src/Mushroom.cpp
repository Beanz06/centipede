#include "Mushroom.h"

Mushroom::Mushroom()
{
    //ctor
}

Mushroom::~Mushroom()
{
    //dtor
}
void Mushroom::init(std::string textureName, sf::Vector2f position) {

	mushroom_position = position;

	// Load a Texture
	if(mushroom_texture.loadFromFile(textureName.c_str())==1){
        mushroom_texture.loadFromFile(textureName.c_str());
        file_found = true;
	}

	//if file not found throw an exception
	else{
	    file_found = false;
        throw FileCannotBeOpened();
	}


	// Create Sprite and Attach a Texture
	mushroom_spriteSize = sf::Vector2i(16, 16);
	mushroom_sprite.setTexture(mushroom_texture);
	mushroom_sprite.setTextureRect(sf::IntRect(Sprite_left, 0, mushroom_spriteSize.x, mushroom_spriteSize.y));
	mushroom_sprite.setPosition(mushroom_position);
	mushroom_sprite.setOrigin(mushroom_texture.getSize().x / 2, mushroom_texture.getSize().y / 2);

}
void Mushroom::poison_init(std::string textureName, sf::Vector2f position) {

	mushroom_position = position;

	// Load a Texture
	if(mushroom_texture.loadFromFile(textureName.c_str())==1){
        mushroom_texture.loadFromFile(textureName.c_str());
        file_found = true;
	}

	//if file not found throw an exception
	else{
	    file_found = false;
        throw FileCannotBeOpened();
	}


	// Create Sprite and Attach a Texture
	mushroom_spriteSize = sf::Vector2i(16, 16);
	mushroom_sprite.setTexture(mushroom_texture);
	mushroom_sprite.setTextureRect(sf::IntRect(Sprite_left, 16, mushroom_spriteSize.x, mushroom_spriteSize.y));
	mushroom_sprite.setPosition(mushroom_position);
	mushroom_sprite.setOrigin(mushroom_texture.getSize().x / 2, mushroom_texture.getSize().y / 2);

}
std::vector<Mushroom*> Mushroom::spawnMushroom(sf::RenderWindow & window) {
    srand((unsigned) time(0));
    float pos_x =0;
    float pos_y =0;
	sf::Vector2f mushroomPos;
	for ( int i = 0; i<25 ; i++){
        //sets random mushroom position
        pos_x = (float)rand() / (float)RAND_MAX;
        pos_y = (float)rand() / (float)RAND_MAX;
        //clamps the mushroom yx position within the screen
        while(pos_x>0.9 || pos_x<0.1 || pos_x==0.5){
            pos_x = (float)rand() / (float)RAND_MAX;
        }
        //clamps the mushroom y position within the screen
        while(pos_y>0.9 || pos_y<0.1 || pos_y==0.85){
            pos_y = (float)rand() / (float)RAND_MAX;
        }
        mushroomPos = sf::Vector2f(window_x * pos_x, window_y * pos_y);
        Mushroom* mushroom = new Mushroom();
        mushroom->init("Resources/mushroom.png", mushroomPos);

        //store the mushrooms in a vector
        mushrooms.push_back(mushroom);
	}
	return mushrooms;


}


sf::Sprite Mushroom::getSprite() {

	return mushroom_sprite;
}
void Mushroom::mushroom_reset(){

	mushrooms.clear();
	//return Centipede_body;

}
void Mushroom::poisnous_mushroom(){
    is_poisnous = true;
}
bool Mushroom::get_poisnous(){
    return is_poisnous;
}
void Mushroom::incr_points(){
    mushroom_points+=50;
}
void Mushroom::animate_sprite(){
    Sprite_left+=16;
}
void Mushroom::animate_reset(){
    Sprite_left = 0;
}
int Mushroom::get_Sprite_left(){
    return Sprite_left;
}
bool Mushroom::get_file(){
    return file_found;
}
float Mushroom::get_mushroom_size(){
    return mushrooms.size();
}

void Mushroom::Draw(sf::RenderWindow & window){
    for (Mushroom *mushroom : mushrooms) {

		window.draw(mushroom->getSprite());
	}
}
