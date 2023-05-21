#include "Bomb.h"

Bomb::Bomb()
{
    //ctor
}

Bomb::~Bomb()
{
    //dtor
}
void Bomb::init(std::string textureName, sf::Vector2f position) {

	Bomb_position = position;

	// Load a Texture
	if(Bomb_texture.loadFromFile(textureName.c_str())==1){
        Bomb_texture.loadFromFile(textureName.c_str());
        file_found = true;
	}

	//if file not found throw an exception
	else{
	    file_found = false;
        throw FileCannotBeOpened();
	}


	// Create Sprite and Attach a Texture
	Bomb_spriteSize = sf::Vector2i(16, 16);
	Bomb_sprite.setTexture(Bomb_texture);
	Bomb_sprite.setTextureRect(sf::IntRect(Sprite_left, 0, Bomb_spriteSize.x, Bomb_spriteSize.y));
	Bomb_sprite.setPosition(Bomb_position);
	Bomb_sprite.setOrigin(Bomb_texture.getSize().x / 2, Bomb_texture.getSize().y / 2);

}

std::vector<Bomb*> Bomb::spawnBomb(sf::RenderWindow & window) {
    srand((unsigned) time(0));
    float pos_x =0;
    float pos_y =0;
	sf::Vector2f BombPos;
	for ( int i = 0; i<4 ; i++){
        //sets random bomb position
        pos_x = (float)rand() / (float)RAND_MAX;
        pos_y = (float)rand() / (float)RAND_MAX;
        //clamps the bombs x position within the screen
        while(pos_x>0.9 || pos_x<0.1 || pos_x==0.5){
            pos_x = (float)rand() / (float)RAND_MAX;
        }
        //clamps the bombs y position within the screen
        while(pos_y>0.9 || pos_y<0.1 || pos_y==0.85){
            pos_y = (float)rand() / (float)RAND_MAX;
        }
        BombPos = sf::Vector2f(window_x * pos_x, window_y * pos_y);
        Bomb* bomb = new Bomb();
        bomb->init("Resources/Bomb.png", BombPos);

        //store the mushrooms in a vector
        Bombs.push_back(bomb);
	}
	return Bombs;


}

sf::Sprite Bomb::getSprite() {

	return Bomb_sprite;
}

void Bomb::Bomb_reset(){

	Bombs.clear();


}



