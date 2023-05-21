#include "Scorpions.h"

Scorpions::Scorpions()
{
    //ctor
}

Scorpions::~Scorpions()
{
    //dtor
}

void Scorpions::init(std::string textureName, sf::Vector2f position){

	Scorpion_position = position;
	// Load a Texture
	if(Scorpion_texture.loadFromFile(textureName.c_str())==1){
        Scorpion_texture.loadFromFile(textureName.c_str());
        file_found = true;
	}

	//if file not found throw an exception
	else{
	    file_found = false;
        throw FileCannotBeOpened();
	}


	// Create Sprite and Attach a Texture
	Scorpion_spriteSize = sf::Vector2i(32, 16);
	Scorpion_sprite.setTexture(Scorpion_texture);
	Scorpion_sprite.setTextureRect(sf::IntRect(0, 0, Scorpion_spriteSize.x, Scorpion_spriteSize.y));
	Scorpion_sprite.setPosition(Scorpion_position);
	Scorpion_sprite.setOrigin(Scorpion_texture.getSize().x / 2, Scorpion_texture.getSize().y / 2);
	//left();

}
bool Scorpions::is_file_found(){
    return file_found;
}
bool Scorpions::is_out_of_Bounds(){
    return out_of_Bounds;
}
void Scorpions::add_scorpion(Scorpions* scorpion){
            scorpions.push_back(scorpion);
}
bool Scorpions::is_mushroom_collision(){
    return mushroom_collision;
}
std::vector<Scorpions*> Scorpions::scorpion_reset(){
    for (Scorpions* scorpion : scorpions) {

		delete(scorpion);
	}
	scorpions.clear();
	return scorpions;
}
void Scorpions::left(){
    Scorpion_temp.y = 0;
	Scorpion_temp.x = -Scorpion_speed;
	//Insect_sprite.setPosition(Insect_position);

}
void Scorpions::right(){
    Scorpion_temp.y = 0;
	Scorpion_temp.x = -Scorpion_speed;

}
std::vector<Scorpions*> Scorpions::update(float dt){

    for (int i = 0; i < scorpions.size(); i++) {

		Scorpions* scorpion = scorpions[i];
        scorpion->Scorpion_sprite.setPosition(scorpion->Scorpion_sprite.getPosition()+Scorpion_temp);
        out_of_Bounds = false;
		if (scorpion->getSprite().getPosition().x <= 0 || scorpion->getSprite().getPosition().x >= window_x) {
            out_of_Bounds = true;
			scorpions.erase(scorpions.begin() + i);
			delete(scorpion);


		}
	}
	return scorpions;




}
std::vector<Scorpions*> Scorpions::spawnScorpion( ) {
    srand((unsigned) time(0));
    float pos_x =0;
    float pos_y =0;
	sf::Vector2f scorpionPos;
	//pos_y = 0.2;
	pos_y = (float)rand() / (float)RAND_MAX;
	while(pos_y>0.75 || pos_y<0.1){
            pos_y = (float)rand() / (float)RAND_MAX;
        }
	scorpionPos = sf::Vector2f(window_x , window_y * pos_y);
    Scorpions* scorpion = new Scorpions();
    scorpion->init("Resources/scorpion.png", scorpionPos);

    //store the centipede's head in a vector
    scorpions.push_back(scorpion);
	left();
	return scorpions;


}
bool Scorpions::checkCollision(sf::Sprite sprite1, sf::Sprite sprite2) {

	sf::FloatRect shape1 = sprite1.getGlobalBounds();
	sf::FloatRect shape2 = sprite2.getGlobalBounds();

	if (shape1.intersects(shape2)) {

		return true;

	}
	else {

		return false;

	}

}
std::vector<Mushroom*> Scorpions::Mushroom_collision(std::vector<Mushroom*> mushrooms){
    for (int i = 0; i < scorpions.size(); i++) {
            for (int j = 0; j < mushrooms.size(); j++) {

                Scorpions* scorpion = scorpions[i];
                Mushroom* mushroom = mushrooms[j];
                mushroom_collision = false;
                if (checkCollision(scorpion->getSprite(), mushroom->getSprite())) {
                    mushroom_collision = true;
                    mushroom->poison_init("Resources/mushroom.png", mushroom->getSprite().getPosition());
                    mushroom->poisnous_mushroom();



                }


            }
        }
        return mushrooms;
}
void Scorpions::Draw(sf::RenderWindow & window,std::vector<Scorpions*> scorpions){
    for (int i = 0; i < scorpions.size(); i++) {
		window.draw(scorpions[i]->getSprite());
	}
	//window.draw(centipede_body[0]->getSprite());

}

sf::Sprite Scorpions::getSprite() {

	return Scorpion_sprite;
}
