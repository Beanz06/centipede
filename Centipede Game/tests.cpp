#include "Bug_Blaster.h"
#include "Bullets.h"
#include "Mushroom.h"
#include "Insect.h"
#include "Centipede.h"
#include "Scorpions.h"

#include "SFML\Graphics.hpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
//float window_x = 900;
// bool out_of_bounds = false;
//float window_y = 668;
sf::Vector2f viewSize(900, 668);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "Hello SFML Game !!!", sf::Style::Default);
TEST_CASE("Check if blaster moves up") {
    sf::Vector2f curr ;
    sf::Vector2f prev ;
    Bug_Blaster blaster;
    blaster.init("Resources/blaster.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f));
    prev = blaster.get_position();
    //move the blaster up twice
    for (int i = 0; i<=2; i++)
    {
        blaster.Up();
        curr =blaster.get_position();
    }
    CHECK(prev.y>curr.y);
}

TEST_CASE("Check if blaster moves down") {
    sf::Vector2f curr ;
    sf::Vector2f prev ;
    Bug_Blaster blaster;
    blaster.init("Resources/blaster.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f));
    prev = blaster.get_position();
    //move the blaster down twice
    for (int i = 0; i<=2; i++)
    {
        blaster.Down();
        curr =blaster.get_position();
    }
    CHECK(prev.y<curr.y);
}
TEST_CASE("Check if blaster moves left") {
    sf::Vector2f curr ;
    sf::Vector2f prev ;
    Bug_Blaster blaster;
    blaster.init("Resources/blaster.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f));
    prev = blaster.get_position();
    //move the blaster left twice
    for (int i = 0; i<=2; i++)
    {
        blaster.Left();
        curr =blaster.get_position();
    }
    CHECK(prev.x>curr.x);
}
TEST_CASE("Check if blaster moves right") {
    sf::Vector2f curr ;
    sf::Vector2f prev ;
    Bug_Blaster blaster;
    blaster.init("Resources/blaster.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f));
    prev = blaster.get_position();
    //move the blaster right twice
    for (int i = 0; i<=2; i++)
    {
        blaster.Right();
        curr =blaster.get_position();
    }
    CHECK(prev.x<curr.x);
}

TEST_CASE("Bug Blaster position out of bounds at the right") {
    Bug_Blaster blaster;
    float dt;
    blaster.init("Resources/blaster.png", sf::Vector2f(viewSize.x * 0.95f, viewSize.y * 0.8f));
    blaster.update(dt);
    CHECK(blaster.get_bounds() == true);
}
TEST_CASE("Bug Blaster position out of bounds at the left") {
    Bug_Blaster blaster;
    float dt;
    blaster.init("Resources/blaster.png", sf::Vector2f(viewSize.x*0.05f, viewSize.y * 0.95f));
    blaster.update(dt);
    CHECK(blaster.get_bounds() == true);
}
TEST_CASE("Bug Blaster position out of bounds at the top") {
    Bug_Blaster blaster;
    float dt;
    blaster.init("Resources/blaster.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.65f));
    blaster.update(dt);
    CHECK(blaster.get_bounds() == true);
}
TEST_CASE("Bug Blaster position out of bounds at the bottom") {
    Bug_Blaster blaster;
    float dt;
    blaster.init("Resources/blaster.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.95f));
    blaster.update(dt);
    CHECK(blaster.get_bounds() == true);
}
TEST_CASE("Bug Blaster texture file path valid") {
    Bug_Blaster blaster;
    blaster.init("Resources/blaster.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.85f));
    CHECK(blaster.get_file() == true);
}
TEST_CASE("Bug Blaster texture file path cannot be  invalid") {
    Bug_Blaster blaster;
    CHECK_THROWS_AS(blaster.init("Rjhesources/blaster.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f)), FileCannotBeOpened);

}

//Bullets test cases
TEST_CASE("Bullets texture file path valid") {
    Bullets bullet;
    bullet.init("Resources/bullet.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f), 400.0f);
    CHECK(bullet.get_file() == true);
}
TEST_CASE("Bullets texture file path cannot be  invalid") {
    Bullets bullet;
    CHECK_THROWS_AS(bullet.init("Rjhesources/bullet.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f), 400.0f), FileCannotBeOpened);

}

TEST_CASE("Check if bullet moves up") {
    sf::Vector2f curr ;
    sf::Vector2f prev ;
    float dt;
    std::vector<Bullets*> bullets;
    Bullets bullet;
    bullet.init("Resources/bullet.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f), 900.f);
    prev = sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f);
    bullet.Move();
    bullets = bullet.get_bullets();
    curr = bullet.get_position();
    CHECK(prev.y>curr.y);
}
TEST_CASE("Check bullet gets deleted when out of bounds") {
    float dt;
    std::vector<Bullets*> bullets;
    Bullets bullet;
    bullet.init("Resources/bullet.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y), 1.f);
    bullet.update(dt);
    bullets = bullet.get_bullets();
    CHECK(bullets.size()==0);
}

//Centipede tests
TEST_CASE("Centipede texture file path valid") {
    Centipede centipede;
    centipede.init("Resources/insect.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f));
    CHECK(centipede.is_file_found() == true);
}
TEST_CASE("Centipede texture file path cannot be  invalid") {
    Centipede centipede;
    CHECK_THROWS_AS(centipede.init("Rjhesources/insect.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f)), FileCannotBeOpened);

}
TEST_CASE("Check centipede moves left by default") {
    sf::Vector2f head_curr_pos ;
    sf::Vector2f head_initial_pos ;
    float dt;
    head_initial_pos = sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.2f);
    Centipede centipede;
    std::vector<Centipede*> centipede_body=centipede.spawnCentipede(head_initial_pos);
    centipede.update(dt);
    head_curr_pos = centipede_body[0]->getSprite().getPosition();
    CHECK(head_initial_pos.x>head_curr_pos.x);
}
TEST_CASE("Check centipede body follows centipede head") {
    sf::Vector2f tail_curr_pos ;
    sf::Vector2f tail_inital_pos ;
    float dt;
    Centipede centipede;
    std::vector<Centipede*> centipede_body=centipede.spawnCentipede( sf::Vector2f(viewSize.x * 0.8, viewSize.y * 0.2));
    int tail = centipede_body.size()-1;
    tail_inital_pos = centipede_body[tail]->getSprite().getPosition();
    centipede.update(dt);
    tail_curr_pos = centipede_body[tail]->getSprite().getPosition();
    CHECK(tail_inital_pos.x>tail_curr_pos.x);
}
TEST_CASE("Check centipede head moves down, when it reaches the left end of the boundary") {
    sf::Vector2f head_curr_pos ;
    sf::Vector2f head_initial_pos = sf::Vector2f(viewSize.x * 0.f, viewSize.y * 0.2f);
    float dt;
    Centipede centipede;
    std::vector<Centipede*> centipede_body=centipede.spawnCentipede(head_initial_pos);
    centipede.update(dt);
    head_curr_pos = centipede_body[0]->getSprite().getPosition();
    CHECK(head_initial_pos.y<head_curr_pos.y);
}

TEST_CASE("Check centipede head moves down, when it reaches the right end of the boundary") {
    sf::Vector2f head_curr_pos ;
    sf::Vector2f head_initial_pos = sf::Vector2f(viewSize.x , viewSize.y * 0.2f);
    float dt;
    Centipede centipede;
    std::vector<Centipede*> centipede_body=centipede.spawnCentipede(head_initial_pos);
    centipede.update(dt);
    head_curr_pos = centipede_body[0]->getSprite().getPosition();
    CHECK(head_initial_pos.y<head_curr_pos.y);
}
TEST_CASE("Check centipede head moves down then right, when it reaches the left end of the boundary") {
    sf::Vector2f head_curr_pos ;
    sf::Vector2f head_initial_pos = sf::Vector2f(viewSize.x*0 , viewSize.y * 0.2f);
    float dt;
    Centipede centipede;
    std::vector<Centipede*> centipede_body=centipede.spawnCentipede(head_initial_pos);
    centipede.update(dt);
    centipede.update(dt);
    head_curr_pos = centipede_body[0]->getSprite().getPosition();
    CHECK(head_initial_pos.y<head_curr_pos.y);
    CHECK(head_initial_pos.x<head_curr_pos.x);
}
TEST_CASE("Check centipede head moves down then left, when it reaches the right end of the boundary") {
    sf::Vector2f head_curr_pos ;
    sf::Vector2f head_initial_pos = sf::Vector2f(viewSize.x , viewSize.y * 0.2f);
    float dt;
    Centipede centipede;
    std::vector<Centipede*> centipede_body=centipede.spawnCentipede(head_initial_pos);
    centipede.update(dt);
    centipede.update(dt);
    head_curr_pos = centipede_body[0]->getSprite().getPosition();
    CHECK(head_initial_pos.y<head_curr_pos.y);
    CHECK(head_initial_pos.x>head_curr_pos.x);
}


//Mushrooms test cases
TEST_CASE("Mushroom texture file path valid") {
    Mushroom mushroom;
    mushroom.init("Resources/mushroom.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f));
    CHECK(mushroom.get_file() == true);
}
TEST_CASE("Mushroom texture file path cannot be  invalid") {
    Mushroom mushroom;
    CHECK_THROWS_AS(mushroom.init("Rjhesources/mushroom.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f)), FileCannotBeOpened);

}
TEST_CASE("25 Mushrooms must be displayed") {
    Mushroom mushroom;
    mushroom.spawnMushroom(window);
    mushroom.init("Resources/mushroom.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f));
    CHECK(mushroom.get_mushroom_size() == 25);
}

//Insect test cases
TEST_CASE("Insect texture file path valid") {
    Insect insect;
    insect.init("Resources/insect.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f));
    CHECK(insect.is_file_found() == true);
}
TEST_CASE("Insect texture file path cannot be  invalid") {
    Insect insect;
    CHECK_THROWS_AS(insect.init("Rjhesources/insect.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f)), FileCannotBeOpened);

}
TEST_CASE("Check if insect moves diagonally left") {
    sf::Vector2f curr_pos ;
    sf::Vector2f initial_pos = sf::Vector2f(viewSize.x , viewSize.y * 0.9f);;
    float dt;
    Insect insect;
    insect.init("Resources/insect.png", initial_pos);
    insect.update(dt);
    curr_pos = insect.get_position();
    CHECK(initial_pos.x>curr_pos.x);
    CHECK(initial_pos.y>curr_pos.y);
}
TEST_CASE("Check if insect moves diagonally right") {
    sf::Vector2f curr_pos ;
    sf::Vector2f initial_pos = sf::Vector2f(viewSize.x , viewSize.y * 0.75f);
    float dt;
    Insect insect;
    insect.init("Resources/insect.png", initial_pos);
    insect.update(dt);
    curr_pos = insect.get_position();
    CHECK(initial_pos.x>curr_pos.x);
    CHECK(initial_pos.y<curr_pos.y);
}

//Scorpions test cases
TEST_CASE("Scorpion texture file path valid") {
    Scorpions scorpion;
    scorpion.init("Resources/scorpion.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f));
    CHECK(scorpion.is_file_found() == true);
}
TEST_CASE("Scorpion texture file path cannot be  invalid") {
    Scorpions scorpion;
    CHECK_THROWS_AS(scorpion.init("Rjhesources/scorpion.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.8f)), FileCannotBeOpened);

}
TEST_CASE("Scorpion moves left") {
    sf::Vector2f curr_pos ;
    sf::Vector2f initial_pos = sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.95f);
    Scorpions Scorpion;
    float dt;
    Scorpions* scorpion = new Scorpions();
    scorpion->init("Resources/scorpion.png", initial_pos);
    Scorpion.add_scorpion(scorpion);
    Scorpion.update(dt);
    curr_pos = Scorpion.getSprite().getPosition();
    CHECK(initial_pos.x>curr_pos.x);
}
TEST_CASE("Scorpion position inbounds") {
    Scorpions Scorpion;
    float dt;
    Scorpions* scorpion = new Scorpions();
    scorpion->init("Resources/scorpion.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.95f));
    Scorpion.add_scorpion(scorpion);
    Scorpion.update(dt);
    CHECK(Scorpion.is_out_of_Bounds() == false);
}
TEST_CASE("Scorpion position out of bounds") {
    Scorpions Scorpion;
    float dt;
    Scorpions* scorpion = new Scorpions();
    scorpion->init("Resources/scorpion.png", sf::Vector2f(0, viewSize.y * 0.95f));
    Scorpion.add_scorpion(scorpion);
    Scorpion.update(dt);
    CHECK(Scorpion.is_out_of_Bounds() == true);
}
TEST_CASE("Scorpion is deleted when position out of bounds") {
    Scorpions Scorpion;
    std::vector<Scorpions*> scorpions;
    float dt;
    Scorpions* scorpion = new Scorpions();
    scorpion->init("Resources/scorpion.png", sf::Vector2f(0, viewSize.y * 0.95f));
    Scorpion.add_scorpion(scorpion);
    scorpions = Scorpion.update(dt);
    CHECK(scorpions.size() == 0);
}
TEST_CASE("Scorpion collides with mushroom boundaries") {
    Scorpions Scorpion;
    std::vector<Scorpions*> scorpions;
    std::vector<Mushroom*> mushrooms;
    Mushroom* mushroom = new Mushroom();
    mushroom->init("Resources/mushroom.png", sf::Vector2f(viewSize.x * 0.8f, viewSize.y * 0.95f));
    float dt;
    Scorpions* scorpion = new Scorpions();
    scorpion->init("Resources/scorpion.png", sf::Vector2f(viewSize.x * 0.81f, viewSize.y * 0.95f));

    CHECK(Scorpion.checkCollision(scorpion->getSprite(), mushroom->getSprite())==true);

}


