#pragma once
#include <SFML/Graphics.hpp>
#include <Window.h>
#include "ShapeFactory.h"
#include <Actor.h>
#include "Prerequisites.h"


class BaseApp
{
public:
  BaseApp() = default;
  ~BaseApp() = default;

  //Funcion  encargada de ejecutar la funcion en main
  int 
  run();

  //Funcion de inicializacion
  bool
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
  sf::Clock clock;
  sf::Time deltaTime;

  Window * m_window;
  //sf::RenderWindow* window;
  //sf::CircleShape* shape;
  EngineUtilities::TSharedPointer<Actor>Triangle;
  EngineUtilities::TSharedPointer<Actor> Circle;
  //ShapeFactory m_shapeFactory;
  //sf::Shape* Triangulo;
};

