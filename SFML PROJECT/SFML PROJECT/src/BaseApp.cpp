#include "BaseApp.h"

int BaseApp::run(){
  initialize();  // Inicializa la ventana y la forma
  while (m_window->isOpen())
  {
    m_window->handleEvents();  // Maneja eventos
    update();        // Actualiza la lógica
    render();        // Dibuja en la pantalla
  }

  cleanUp();  
  return 0; 
}

// Implementación de initialize 
void 
BaseApp::initialize(){
  m_window = new Window(800, 600, "LathorEngine");
  shape = new sf::CircleShape(100.0f);
  shape->setFillColor(sf::Color::Magenta);
}

// Implementación de update
void BaseApp::update()
{
}

// Implementación de render 
void BaseApp::render()
{
  m_window->clear();
  m_window->draw(*shape);
  m_window->display();
}

// Implementación de cleanUp
void BaseApp::cleanUp()
{
  m_window->destroy();
  delete m_window;
  delete shape;
}
