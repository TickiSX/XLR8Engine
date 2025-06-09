#include "Window.h"
#include "../include/CShape.h"

/**
 * @brief Crea una nueva forma basada en el tipo especificado.
 *
 * @param shapeType Tipo de forma a crear.
 * @return Puntero a la forma SFML recién creada.
 */
sf::Shape* CShape::createShape(ShapeType shapeType) {
    m_shapeType = shapeType;

    switch (shapeType) {
    case ShapeType::CIRCLE:
    {
        sf::CircleShape* circle = new sf::CircleShape(10.f); // Radio de ejemplo
        circle->setFillColor(sf::Color::White);
        m_shape = circle;
        return circle;
    }
    case ShapeType::RECTANGLE:
    {
        sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(100.f, 50.f)); // Tamaño de ejemplo
        rectangle->setFillColor(sf::Color::White);
        m_shape = rectangle;
        return rectangle;
    }
    case ShapeType::TRIANGLE:
    {
        sf::ConvexShape* triangle = new sf::ConvexShape(3);
        triangle->setPoint(0, sf::Vector2f(0.f, 0.f));
        triangle->setPoint(1, sf::Vector2f(50.f, 100.f));
        triangle->setPoint(2, sf::Vector2f(100.f, 0.f));
        triangle->setFillColor(sf::Color::White);
        m_shape = triangle;
        return triangle;
    }
    case ShapeType::POLYGON:
    {
        sf::ConvexShape* polygon = new sf::ConvexShape(5); // Polígono con 5 puntos
        polygon->setPoint(0, sf::Vector2f(0.f, 0.f));
        polygon->setPoint(1, sf::Vector2f(50.f, 100.f));
        polygon->setPoint(2, sf::Vector2f(100.f, 0.f));
        polygon->setPoint(3, sf::Vector2f(75.f, -50.f));
        polygon->setPoint(4, sf::Vector2f(-25.f, -50.f));
        polygon->setFillColor(sf::Color::White);
        m_shape = polygon;
        return polygon;
    }
    default:
        ERROR("CShape", "createShape", "Unknown ShapeType");
        return nullptr;
    }
}

/**
 * @brief Establece la posición de la forma.
 *
 * @param x Coordenada X.
 * @param y Coordenada Y.
 */
void CShape::setPosition(float x, float y) {
    if (m_shape) {
        m_shape->setPosition(x, y);
    }
    else {
        ERROR("CShape", "setPosition", "Shape is not initialized");
    }
}

/**
 * @brief Establece la posición de la forma.
 *
 * @param position Vector de posición.
 */
void CShape::setPosition(const sf::Vector2f& position) {
    if (m_shape) {
        m_shape->setPosition(position);
    }
    else {
        ERROR("CShape", "setPosition", "Shape is not initialized");
    }
}

/**
 * @brief Establece el color de relleno de la forma.
 *
 * @param color Color de relleno.
 */
void CShape::setFillColor(const sf::Color& color) {
    if (m_shape) {
        m_shape->setFillColor(color);
    }
    else {
        ERROR("CShape", "setFillColor", "Shape is not initialized");
    }
}

/**
 * @brief Rota la forma un número de grados.
 *
 * @param angle Ángulo en grados.
 */
void CShape::setRotation(float angle) {
    if (m_shape) {
        m_shape->setRotation(angle);
    }
    else {
        ERROR("CShape", "setRotation", "Shape is not initialized");
    }
}

/**
 * @brief Escala la forma por los factores dados.
 *
 * @param scl Vector de escala.
 */
void CShape::setScale(const sf::Vector2f& scl) {
    if (m_shape) {
        m_shape->setScale(scl);
    }
    else {
        ERROR("CShape", "setScale", "Shape is not initialized");
    }
}
