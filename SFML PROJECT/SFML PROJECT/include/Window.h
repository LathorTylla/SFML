#pragma once
#include <SFML/Graphics.hpp>

class 
Window
{
public:
  Window() = default;
  Window(int width, int height, const std::string& tittle);
  ~Window();
 
  //Funcion de manejo de datos
  void
  handleEvents();

  void
  clear();

  void
  display();

  bool
  isOpen() const;

  void
  draw(const sf::Drawable & drawable);

  sf::RenderWindow*
  getWindow();

  void 
  init();

  void
  update();

  void
  render();

  void
  destroy(); 
  
private:
  sf::RenderWindow* m_window;
};