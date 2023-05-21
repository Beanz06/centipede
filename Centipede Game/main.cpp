#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

#include "Bug_Blaster.h"
#include "Bullets.h"
#include "Mushroom.h"
#include "Insect.h"
#include "Centipede.h"
#include "Scorpions.h"
#include "Bomb.h"

//mushrooms ;
sf::Vector2f viewSize(900, 668);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello SFML Game !!!", sf::Style::Default);
sf::Vector2f playerPosition;
Bug_Blaster blaster;
Bullets bullet;
Mushroom mushroom;
Centipede centipede;
Scorpions scorpion;
Insect insect;
Bomb bomb;
std::vector<Scorpions*> scorpions ;
std::vector<Mushroom*> mushrooms = mushroom.spawnMushroom(window);
std::vector<Bomb*> Bombs ;
std::vector<Bullets*> bullets;
std::vector<Insect*> insects;
std::vector<Centipede*>  centipede_body = centipede.spawnCentipede( sf::Vector2f(viewSize.x * 0.92, viewSize.y * 0.2));
float currentTime;
float prevTime = 0.0f;
float prevTime2 = 0.0f;
float prevTime3 = 0.0f;
float prevTime4 = 0.0f;
bool gameover = true;
bool gamepause = true;
int temp_life = 3;
int games_played = 0;
sf::Font headingFont;
sf::Font scoreFont;

sf::Text headingText;
sf::Text scoreText;
sf::Text lifeText;
sf::Text tutorialText;

int score  = 0;
std::string finalScore = "Score: " + std::to_string(score);
std::string life = "Life: " + std::to_string(blaster.get_life());


void init() {


	blaster.init("Resources/blaster.png", sf::Vector2f(viewSize.x * 0.5f, viewSize.y * 0.85f));
	srand((int)time(0));
	// Load font

	headingFont.loadFromFile("Resources/fonts/OpenSans-Bold.ttf");

	scoreFont.loadFromFile("Resources/fonts/OpenSans-LightItalic.ttf");

	// Set Heading Text

	headingText.setFont(headingFont);
	headingText.setString("Centipede Game");
	headingText.setCharacterSize(84);
	headingText.setFillColor(sf::Color::Red);

	sf::FloatRect headingbounds = headingText.getLocalBounds();
	headingText.setOrigin(headingbounds.width / 2, headingbounds.height / 2);
	headingText.setPosition(sf::Vector2f(viewSize.x * 0.5f, viewSize.y * 0.10f));

	// Set Score Text

	scoreText.setFont(scoreFont);
	scoreText.setString("Score: 0");
	scoreText.setCharacterSize(45);
	scoreText.setFillColor(sf::Color::Red);

	sf::FloatRect scorebounds = scoreText.getLocalBounds();
	scoreText.setOrigin(scorebounds.width / 2, scorebounds.height / 2);
	scoreText.setPosition(sf::Vector2f(viewSize.x * 0.5f, viewSize.y * 0.10f));

	// Set life Text

	lifeText.setFont(scoreFont);
	lifeText.setString("life: 3");
	lifeText.setCharacterSize(45);
	lifeText.setFillColor(sf::Color::Red);

	sf::FloatRect lifebounds = lifeText.getLocalBounds();
	lifeText.setOrigin(lifebounds.width / 2, lifebounds.height / 2);
	lifeText.setPosition(sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.10f));

	// Tutorial Text

	tutorialText.setFont(scoreFont);
	tutorialText.setString("Press Space bar to Fire and Start Game,\n Up Arrow to move up,\n Down Arrow to move down,\n Left Arrow to move left,\n Right Arrow to move right");
	tutorialText.setCharacterSize(35);
	tutorialText.setFillColor(sf::Color::Red);

	sf::FloatRect tutorialbounds = tutorialText.getLocalBounds();
	tutorialText.setOrigin(tutorialbounds.width / 2, tutorialbounds.height / 2);
	tutorialText.setPosition(sf::Vector2f(viewSize.x * 0.5f, viewSize.y * 0.50f));


}
void spawnInsect() {

	float pos_x =0;
    float pos_y =0;
	int randLoc = 1;

	sf::Vector2f InsectPos;

	InsectPos = sf::Vector2f(viewSize.x, viewSize.y*0.9 );

	Insect* insect = new Insect();
	insect->init("Resources/spider.png", InsectPos);
	insects.push_back(insect);
}
void insect_reset(){
     for (Insect* insect : insects) {

		delete(insect);
	}
	insects.clear();
	//return insects;
}




void updateInput() {

	sf::Event event;

	// while there are pending events...
	while (window.pollEvent(event)) {

        if (event.type == sf::Event::KeyPressed) {

			if (event.key.code == sf::Keyboard::Up) {

				blaster.Up();
			}

			if (event.key.code == sf::Keyboard::Down) {

				blaster.Down();
			}
			if (event.key.code == sf::Keyboard::Left) {

				blaster.Left();
			}

			if (event.key.code == sf::Keyboard::Right) {

				blaster.Right();
			}
			if (event.key.code == sf::Keyboard::Space) {
                if (gameover) {
					gameover = false;
					score = 0;
                    bullet.reset_points();
					//reset();
				}
				else{
                 bullet.shoot(blaster.getSprite().getPosition());
				}

			}

		}
		if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed){
            games_played = 0;
            window.close();
		}


	}

}


void update(float dt) {

    bullet.update(dt);
	blaster.update(dt);
	blaster.Mushroom_collision(mushrooms);
    insects = blaster.Insect_collision(insects);
    blaster.Centipede_collision(centipede_body);
    mushrooms = scorpion.Mushroom_collision(mushrooms);
	bullet.Bomb_collision(Bombs, mushrooms);
	bullet.Centipede_collision(centipede_body, mushrooms);
	bullet.Mushroom_collision(mushrooms, blaster.get_life(), temp_life);
	if(blaster.get_life() <= 0 || centipede_body.size()==0){
        float prevTime = 0.0f;
        float prevTime2 = 0.0f;
        float prevTime3 = 0.0f;
        float prevTime4 = 0.0f;
        gameover = true;
        mushrooms.clear();
        mushroom.mushroom_reset();
        centipede_body.clear();
	    centipede.centipede_reset();
	    insect_reset();
	    scorpions = scorpion.scorpion_reset();
        centipede_body = centipede.spawnCentipede(sf::Vector2f(viewSize.x * 0.8, viewSize.y * 0.2));
        blaster.Blaster_reset();
        temp_life = 3;
        blaster.init("Resources/blaster.png", sf::Vector2f(viewSize.x * 0.5f, viewSize.y * 0.85f));
        mushrooms = mushroom.spawnMushroom(window);
        games_played++;

	}
	else if(temp_life > blaster.get_life()){
        float prevTime = 0.0f;
        float prevTime2 = 0.0f;
        float prevTime3 = 0.0f;
        float prevTime4 = 0.0f;
	    centipede_body.clear();
	    centipede.centipede_reset();
	    insect_reset();
        centipede_body = centipede.spawnCentipede(sf::Vector2f(viewSize.x * 0.8, viewSize.y * 0.2));
        //blaster.Blaster_reset();
        blaster.init("Resources/blaster.png", sf::Vector2f(viewSize.x * 0.5f, viewSize.y * 0.85f));
        //gamepause = true;
        temp_life = blaster.get_life();
	}

    bullet.Insect_collision(insects);
	currentTime += dt;
	//update bullets

    //if there are 10 mushrooms on the screen respawn new mushrooms
	if(mushrooms.size()==10 ){
        mushrooms.clear();
        mushroom.mushroom_reset();
        mushrooms = mushroom.spawnMushroom(window);
	}

	//update centipede
	if (currentTime >= (prevTime + 0.1f) && gameover == false ) {
        centipede.update(dt);
        centipede.Mushroom_collision(mushrooms);
        //centipede_body = centipede.get_centipede();
        for(int j = centipede_body.size()-1;j>=0; j--){
        Centipede* centi = centipede_body[j];
        if(centi->get_head()==true){
            if(centi->getSprite().getPosition().y > viewSize.y*0.99){
                centipede_body.clear();
                centipede.centipede_reset();
                centipede_body = centipede.spawnCentipede(sf::Vector2f(viewSize.x * 0.92, viewSize.y * 0.8));
            }
        }
        }

		//centipede.update(dt);

		prevTime = currentTime;

	}





	// Update Insect

	for (int i = 0; i < insects.size(); i++) {

		Insect* insect = insects[i];
		insect->update(dt);

		if (insect->getSprite().getPosition().x < 0 || insect->getSprite().getPosition().x > viewSize.x) {

			insects.erase(insects.begin() + i);
			delete(insect);

		}
	}

	if(insects.size()==0 && gameover == false && currentTime >= (prevTime2 + 15.f) ){
        spawnInsect();
        prevTime2 = currentTime;
	}

	else if(Bombs.size()==0 && gameover == false && currentTime >= (prevTime4 + 10.f) ){
        Bombs = bomb.spawnBomb(window);;
        prevTime4 = currentTime;
	}
	else if(scorpions.size()==0 && gameover == false && currentTime >= (prevTime3 + 25.f) ){
        //scorpions.clear();
        scorpions = scorpion.spawnScorpion();
        prevTime3 = currentTime;
	}
	scorpions = scorpion.update(dt);


	score  = bullet.get_points();
	finalScore = "Score: " + std::to_string(score);
	scoreText.setString(finalScore);
	sf::FloatRect scorebounds = scoreText.getLocalBounds();
	scoreText.setOrigin(scorebounds.width / 2, scorebounds.height / 2);
	scoreText.setPosition(sf::Vector2f(viewSize.x * 0.5f, viewSize.y * 0.10f));

	life = "Life: " + std::to_string(blaster.get_life());
	lifeText.setString(life);
	sf::FloatRect lifebounds = lifeText.getLocalBounds();
	lifeText.setOrigin(lifebounds.width / 2, lifebounds.height / 2);
	lifeText.setPosition(sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.10f));


}

void draw() {

	window.draw(blaster.getSprite());

	//draw bullets
	bullet.Draw(window);
	//draw the mushrooms
    //mushroom.Draw(window);
    for (Mushroom *mushroom : mushrooms) {

		window.draw(mushroom->getSprite());
	}
	for (Bomb *bomb : Bombs) {

		window.draw(bomb->getSprite());
	}
	centipede.Draw(window, centipede_body);
	scorpion.Draw(window, scorpions);
	for (Insect *insect : insects) {

		window.draw(insect->getSprite());
	}

	if (gameover == true && games_played==0) {
		window.draw(headingText);
		window.draw(tutorialText);
	}

	else if (gameover == true && games_played>0) {
	    headingText.setString("Game Over");
	    scoreText.setPosition(sf::Vector2f(viewSize.x * 0.5f, viewSize.y * 0.80f));
		window.draw(headingText);
		window.draw(tutorialText);
		window.draw(scoreText);

	}

	 else {
		window.draw(scoreText);
		window.draw(lifeText);
	}


}



int main() {

	sf::Clock clock;
	window.setFramerateLimit(60);

	init();
	while (window.isOpen()) {
		updateInput();

		sf::Time dt = clock.restart();
		//if (!gameover)
        update(dt.asSeconds());
		//update(dt.asSeconds());


		window.clear(sf::Color::Black);

		draw();

		window.display();

	}

	return 0;
}
