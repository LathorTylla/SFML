#include "BaseApp.h"

int
BaseApp::run() {
	if (!initialize()) {
		ERROR("BaseApp", "run", "Initializes result on a false statemente, check method validations");
	}
	while (m_window->isOpen()) {
		m_window->handleEvents();
		update();
		render();
	}

	cleanUp();
	return 0;
}

bool
BaseApp::initialize() {
	m_window = new Window(800, 600, "Galvan Engine");
	shape = new sf::CircleShape(100.0f);
	shape->setFillColor(sf::Color::Green);
	if (!m_window) {
		ERROR("BaseApp", "initialize", "Error on window creation, var is null");
		return false;
	}
	shape = new sf::CircleShape(10.0f);

	if (!shape) {
		ERROR("BaseApp", "initialize", "Error on shape creation, var is null");
		return false;
	}

	shape->setFillColor(sf::Color::Blue);
	shape->setPosition(200.0f, 200.0f);
	Triangulo = m_shapeFactory.createShape(ShapeType::TRIANGLE);
	if (!Triangulo) {
		ERROR("BaseApp", "initialize", "Error on triangulo creation, var is null");
		return false;
	}
	return true;
}

void
BaseApp::update() {
}

void
BaseApp::render() {
	m_window->clear();
	m_window->draw(*shape);
	m_window->draw(*Triangulo);
	m_window->display();
}

void
BaseApp::cleanUp() {
	m_window->destroy();
	delete m_window;
	delete shape;
	delete Triangulo;
}