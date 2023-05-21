#include "Snake.h"


Snake::Snake()
{
    m_body.resize(4);
    m_head = --m_body.end();
    m_tail = m_body.begin();
}

Snake::~Snake()
{
    //dtor
}
void Snake::init(std::string  textureName, sf::Vector2f position){

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
	Centipede_sprite.setOrigin(Centipede_texture.getSize().x / 2, Centipede_texture.getSize().y / 2);


}

/*
std::vector<sf::Sprite>  Snake::spawn_centipede(){
    for(int i = 1; i<=Centipede_length; i++){
            body.push_back(Centipede_body_sprite);
    }
    body.push_back(Centipede_sprite);
    return body;
}
*/



