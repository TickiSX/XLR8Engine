#include "../include/Window.h"

/**
 * @brief Constructor de la clase Window.
 * Inicializa una ventana SFML con los parámetros dados.
 *
 * @param width Ancho de la ventana.
 * @param height Alto de la ventana.
 * @param title Título de la ventana.
 */
Window::Window(int width, int height, const std::string& title) {
    m_window = new sf::RenderWindow(sf::VideoMode(width, height), title);

    if (m_window) {
        m_window->setFramerateLimit(60);
        MESSAGE("Window", "Window", "window created successfully");
    }
    else {
        ERROR("Window", "Window", "Failed to create window");
    }
}

/**
 * @brief Destructor. Libera la memoria de la ventana.
 */
Window::~Window() {
    SAFE_PTR_RELEASE(m_window);
}

/**
 * @brief Maneja los eventos de la ventana (por ahora solo el cierre).
 */
void Window::handleEvents() {
    sf::Event event;
    while (m_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window->close();
        }
    }
}

/**
 * @brief Verifica si la ventana sigue abierta.
 *
 * @return true si está abierta, false si no.
 */
bool Window::isOpen() const {
    if (m_window) {
        return m_window->isOpen();
    }
    else {
        ERROR("Window", "isOpen", "Window is null");
        return false;
    }
}

/**
 * @brief Limpia el buffer de color de la ventana.
 *
 * @param color Color a usar para limpiar.
 */
void Window::clear(const sf::Color& color) {
    if (m_window) {
        m_window->clear(color);
    }
    else {
        ERROR("Window", "clear", "Window is null");
    }
}

/**
 * @brief Dibuja un objeto SFML en la ventana.
 *
 * @param drawable Objeto SFML que se puede dibujar.
 * @param states Estados de renderizado (por defecto).
 */
void Window::draw(const sf::Drawable& drawable, const sf::RenderStates& states) {
    if (m_window) {
        m_window->draw(drawable, states);
    }
    else {
        ERROR("Window", "draw", "Window is null");
    }
}

/**
 * @brief Muestra el contenido de la ventana en pantalla.
 */
void Window::display() {
    if (m_window) {
        m_window->display();
    }
    else {
        ERROR("Window", "display", "Window is null");
    }
}

/**
 * @brief Destruye la ventana y libera recursos.
 */
void Window::destroy() {
    SAFE_PTR_RELEASE(m_window);
}
