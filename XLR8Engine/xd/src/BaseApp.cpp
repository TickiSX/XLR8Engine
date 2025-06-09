#include "../include/Prerequisites.h"
#include "../include/BaseApp.h"

/// Destructor de BaseApp
BaseApp::~BaseApp() {
    // Liberar recursos si a�n no fueron liberados expl�citamente
    SAFE_PTR_RELEASE(m_circle);
    if (m_window) {
        m_window->destroy();
        SAFE_PTR_RELEASE(m_window);
    }
}

/**
 * @brief M�todo principal de ejecuci�n.
 * Inicializa la aplicaci�n y entra en el bucle principal hasta que la ventana se cierre.
 *
 * @return C�digo de salida (0 si se ejecuta correctamente).
 */
int BaseApp::run() {
    if (!init()) {
        ERROR("BaseApp", "run", "Initialization failed; check method validations");
    }

    while (m_window->isOpen()) {
        m_window->handleEvents();
        update();
        render();
    }

    destroy();
    return 0;
}

/**
 * @brief Inicializa recursos de la aplicaci�n.
 * Crea la ventana y un c�rculo verde con radio 100.
 *
 * @return true si la inicializaci�n fue exitosa.
 */
bool BaseApp::init() {
    m_window = new Window(1920, 1080, "Graphos");
    m_circle = new sf::CircleShape(100.0f);
    m_circle->setFillColor(sf::Color::Green);
    m_circle->setPosition(200.f, 150.f);

    MESSAGE("BaseApp", "init", "Window and CircleShape created successfully");
    return true;
}

/**
 * @brief L�gica de actualizaci�n por frame.
 * Se puede extender en clases derivadas.
 */
void BaseApp::update() {
    // L�gica por frame (por ahora vac�a)
}

/**
 * @brief Dibuja los elementos del frame actual.
 * Limpia la ventana, dibuja el c�rculo y muestra el frame.
 */
void BaseApp::render() {
    m_window->clear();
    m_window->draw(*m_circle);
    m_window->display();
}

/**
 * @brief Libera los recursos utilizados por la aplicaci�n.
 */
void BaseApp::destroy() {
    SAFE_PTR_RELEASE(m_circle);
    if (m_window) {
        m_window->destroy();
        SAFE_PTR_RELEASE(m_window);
    }

    MESSAGE("BaseApp", "destroy", "Resources successfully released");
}
