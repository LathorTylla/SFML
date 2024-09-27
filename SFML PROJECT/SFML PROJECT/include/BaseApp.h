#pragma once
#include <SFML/Graphics.hpp>
#include <Window.h>

class BaseApp
{
public:
  BaseApp() = default;
  ~BaseApp() = default;

  //Funcion  encargada de ejecutar la funcion en main
  int 
  run();

  //Funcion de inicializacion
  void
  initialize();

  //Funcion que se actualiza por frames
  void
  update();

  //Funcion de renderizado
  void
  render();

  void
  cleanUp();

private:
  Window * m_window;
  //sf::RenderWindow* window;
  sf::CircleShape* shape;
};

