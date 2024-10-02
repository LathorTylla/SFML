#include "BaseApp.h"

/*
 * @brief Método que ejecuta el bucle principal de la aplicación.
 *
 * Inicializa la aplicación, maneja los eventos de la ventana, actualiza y renderiza los actores,
 * y finalmente limpia los recursos al terminar.
 *
 * @return int Código de retorno de la aplicación.
*/

int
BaseApp::run() {
	if (!initialize()) {
		ERROR("BaseApp", "run", "Initializes result on a false statemente, check method validations");
	}
	while (m_window->isOpen()) {
		m_window->handleEvents();
		deltaTime = clock.restart();
		update();
		render();
	}

	cleanUp();
	return 0;
}

/*
 * @brief Inicializa la ventana y los actores para la aplicación.
 *
 * Crea una ventana y actores como el círculo y el triángulo, configurando sus componentes y atributos.
 *
 * @return bool Verdadero si la inicialización fue exitosa, falso si hubo algún error.
*/
bool
BaseApp::initialize() {
	m_window = new Window(800, 600, "LathorEngine");
	if (!m_window) {
		ERROR("BaseApp", "initialize", "Error on window creation, var is null");
		return false;
	}

		// Triangle Actor
		Circle = EngineUtilities::MakeShared<Actor>("Circle");
		if (!Circle.isNull()) {
			Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);
			Circle->getComponent<ShapeFactory>()->setPosition(200.0f, 200.0f);
			Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Blue);
		}

		
		// Triangle Actor
		Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
		if (!Triangle.isNull()) {
			Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
		}

		return true;
	}

/*
 * @brief Actualiza el estado de los actores en cada cuadro.
 *
 * Actualiza la posición del círculo para que siga el ratón, y mueve el triángulo entre los waypoints.
*/
	void
	BaseApp::update() {
		// Mouse Position
		sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->getWindow());
		sf::Vector2f mousePosF(static_cast<float>(mousePosition.x),
			static_cast<float>(mousePosition.y));
		if (!Circle.isNull()) {
			Circle->getComponent<ShapeFactory>()->Seek(mousePosF,
				300.0f, //velocidad
				deltaTime.asSeconds(),
				10.0f);
		}
		// Mover el triángulo entre los waypoints
		MovimientoTriangulo(deltaTime.asSeconds(), Triangle);
	}

/*
 * @brief Mueve el actor Triángulo entre los waypoints.
 *
 * Utiliza la función Seek del componente ShapeFactory para mover el triángulo hacia el siguiente waypoint.
 *
 * @param deltaTime Tiempo transcurrido desde la última actualización.
 * @param Triangle Puntero compartido al actor triángulo.
*/

	void
		BaseApp::MovimientoTriangulo(float deltaTime, EngineUtilities::TSharedPointer<Actor> Triangle) {
		if (Triangle.isNull()) return;

		// Posición del siguiente waypoint
		sf::Vector2f targetPos = waypoints[ActualPosition];

		// Usar la función Seek del ShapeFactory para moverse hacia el waypoint
		Triangle->getComponent<ShapeFactory>()->Seek(targetPos, 200.0f, deltaTime, 10.0f);

		// Obtener la posición actual del triángulo
		sf::Vector2f currentPos = Triangle->getComponent<ShapeFactory>()->getShape()->getPosition();

		// Calcular la distancia al waypoint
		float distanceToTarget = std::sqrt(std::pow(targetPos.x - currentPos.x, 2) + std::pow(targetPos.y - currentPos.y, 2));

		// Si estamos cerca del waypoint, pasar al siguiente
		if (distanceToTarget < 10.0f) {
			ActualPosition = (ActualPosition + 1) % waypoints.size(); // Ciclar entre los waypoints
		}
	}

/*
 * @brief Renderiza los actores en la ventana.
 *
 * Limpia la ventana, renderiza los actores (círculo y triángulo), y muestra el contenido.
*/

	void
	BaseApp::render() {
		m_window->clear();
		Circle->render(*m_window);
		Triangle->render(*m_window);
		/*if (!Triangle.isNull()) {
			m_window->draw(*Triangle->getComponent<ShapeFactory>()->getShape());
		}*/
		m_window->display();
	}

/*
 * @brief Limpia los recursos utilizados por la aplicación.
 *
 * Destruye la ventana y libera la memoria asociada.
*/

	void
	BaseApp::cleanUp() {
		m_window->destroy();
		delete m_window;
	}