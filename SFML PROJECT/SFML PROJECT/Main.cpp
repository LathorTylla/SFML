#include <SFML/Graphics.hpp>
#include "BaseApp.h"

sf::RenderWindow* window;
sf::CircleShape* shape;

int 
main(){
  BaseApp app;
  return app.run();
}