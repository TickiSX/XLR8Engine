#include "../include/Prerequisites.h"
#include "../include/BaseApp.h"

/// Destructor de BaseApp
BaseApp::~BaseApp() {
    // Liberar recursos si aún no fueron liberados explícitamente
    SAFE_PTR_RELEASE(m_circle);
    if (m_window) {
        m_window->destroy();
        SAFE_PTR_RELEASE(m_window);
    }
}

/**
 * @brief Método principal de ejecución.
 * Inicializa la aplicación y entra en el bucle principal hasta que la ventana se cierre.
 *
 * @return Código de salida (0 si se ejecuta correctamente).
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
 * @brief Inicializa recursos de la aplicación.
 * Crea la ventana y un círculo verde con radio 100.
 *
 * @return true si la inicialización fue exitosa.
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
 * @brief Lógica de actualización por frame.
 * Se puede extender en clases derivadas.
 */
void BaseApp::update() {
    // Lógica por frame (por ahora vacía)
}

/**
 * @brief Dibuja los elementos del frame actual.
 * Limpia la ventana, dibuja el círculo y muestra el frame.
 */
void BaseApp::render() {
    m_window->clear();
    m_window->draw(*m_circle);
    m_window->display();
}

/**
 * @brief Libera los recursos utilizados por la aplicación.
 */
void BaseApp::destroy() {
    SAFE_PTR_RELEASE(m_circle);
    if (m_window) {
        m_window->destroy();
        SAFE_PTR_RELEASE(m_window);
    }

    MESSAGE("BaseApp", "destroy", "Resources successfully released");
}
