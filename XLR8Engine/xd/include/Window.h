#pragma once
#include "Prerequisites.h"

/**
 * @class Window
 * @brief Encapsula una ventana renderizable usando SFML.
 *
 * La clase Window abstrae una ventana de SFML y proporciona
 * funciones para manejo de eventos, dibujo y administraci�n del ciclo de vida.
 *
 * Uso t�pico:
 *  - Crear una instancia con el constructor parametrizado.
 *  - Llamar a handleEvents() cada frame para procesar eventos.
 *  - Llamar a draw(), clear() y display() durante el render loop.
 *  - Llamar a destroy() antes de cerrar la aplicaci�n.
 */
class Window
{
public:
    /**
     * @brief Constructor por defecto.
     * Crea una instancia sin inicializar la ventana.
     */
    Window() = default;

    /**
     * @brief Constructor con par�metros.
     * Inicializa la ventana con el tama�o y t�tulo especificados.
     *
     * @param width Ancho de la ventana.
     * @param height Alto de la ventana.
     * @param title T�tulo de la ventana.
     */
    Window(int width, int height, const std::string& title);

    /**
     * @brief Destructor.
     * Libera recursos utilizados por la ventana.
     */
    ~Window();

    /**
     * @brief Procesa los eventos de la ventana.
     * Llama internamente a pollEvent() de SFML.
     */
    void handleEvents();

    /**
     * @brief Verifica si la ventana sigue abierta.
     *
     * @return true si la ventana est� abierta, false si fue cerrada.
     */
    bool isOpen() const;

    /**
     * @brief Limpia el contenido actual del buffer.
     *
     * @param color Color de limpieza, por defecto negro opaco.
     */
    void clear(const sf::Color& color = sf::Color(0, 0, 0, 255));

    /**
     * @brief Dibuja un objeto drawable en la ventana.
     *
     * @param drawable Referencia al objeto drawable (ej. sf::Shape, sf::Sprite, etc).
     * @param states Estados de render opcionales.
     */
    void draw(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);

    /**
     * @brief Muestra en pantalla el contenido del buffer.
     * Llame a esto despu�s de dibujar todos los elementos del frame.
     */
    void display();

    /**
     * @brief Libera todos los recursos asociados con la ventana.
     */
    void destroy();

private:
    /**
     * @brief Puntero a la ventana SFML.
     */
    sf::RenderWindow* m_window;
};
