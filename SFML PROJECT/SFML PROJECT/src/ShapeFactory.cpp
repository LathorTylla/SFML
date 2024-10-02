#include "ShapeFactory.h"

/*
 * @brief Crea una forma basada en el tipo especificado.
 *
 * Crea una forma de tipo c�rculo, rect�ngulo o tri�ngulo y la almacena en el miembro m_shape.
 *
 * @param shapeType Tipo de forma a crear, basado en la enumeraci�n ShapeType.
 * @return sf::Shape* Puntero a la forma creada, o nullptr si el tipo es EMPTY.
*/

sf::Shape*
ShapeFactory::createShape(ShapeType shapeType) {
	m_shapeType = shapeType;
	switch (shapeType) {
	case EMPTY: {
		return nullptr;
	}
	case CIRCLE: {
		sf::CircleShape* circle = new sf::CircleShape(10.0f);
		circle->setFillColor(sf::Color::White);
		m_shape = circle;
		return circle;
	}
	case RECTANGLE: {
		sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2(100.0f, 50.0f));
		rectangle->setFillColor(sf::Color::White);
		m_shape = rectangle;
		return rectangle;
	}
	case TRIANGLE: {
		sf::CircleShape* triangle = new sf::CircleShape(50.0f, 3);
		triangle->setFillColor(sf::Color::White);
		m_shape = triangle;
		return triangle;
	}
	default:
		return nullptr;
	}
}

/*
 * @brief Establece la posici�n de la forma.
 *
 * @param x Coordenada X de la posici�n.
 * @param y Coordenada Y de la posici�n.
*/
void
ShapeFactory::setPosition(float x, float y) {
	m_shape->setPosition(x, y);
}
/*
 * @brief Establece la posici�n de la forma utilizando un objeto sf::Vector2f.
 *
 * @param position Objeto sf::Vector2f que contiene las coordenadas de la posici�n.
*/
void
ShapeFactory::setPosition(const sf::Vector2f& position) {
	m_shape->setPosition(position);
}
/*
 * @brief Establece el color de relleno de la forma.
 *
 * @param color Color de relleno en formato sf::Color.
*/
void
ShapeFactory::setFillColor(const sf::Color& color) {
	m_shape->setFillColor(color);
}
/*
 * @brief Mueve la forma hacia una posici�n objetivo.
 *
 * La forma se mover� hacia la posici�n objetivo a una velocidad espec�fica y se detendr� si est� dentro del rango especificado.
 *
 * @param targetPosition Posici�n objetivo a la que se mover� la forma.
 * @param speed Velocidad del movimiento.
 * @param deltaTime Tiempo transcurrido desde la �ltima actualizaci�n.
 * @param range Distancia m�nima para detenerse cerca del objetivo.
*/
void
ShapeFactory::Seek(const sf::Vector2f& targetPosition,
									float speed,
									float deltaTime,
									float range) {
	// Obtener la posici�n actual de mi shape
	sf::Vector2f shapePosition = m_shape->getPosition();
	// Calcular la direcci�n desde el c�rculo hacia el objetivo
	sf::Vector2f direction = targetPosition - shapePosition;
	// Calcular la distancia al objetivo
	float lenght = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	// Si la distancia es mayor que el rango, mover la shape hacia el objetivo
	if (lenght > range) {
		direction /= lenght;
		m_shape->move(direction * speed * deltaTime);
	}
}