﻿#pragma once

/**
 * @file CShape.h
 * @brief Declares the CShape class used to represent 2D shapes as components in the ECS system.
 */

#include "Prerequisites.h"
#include "ECS/Component.h"

class Window;

/**
 * @class CShape
 * @brief A component that represents a drawable 2D shape using SFML.
 *
 * Supports circle, rectangle, triangle, and polygon shapes.
 */
class CShape : public Component {
public:
  /**
   * @brief Default constructor.
   */
  CShape();

  CShape(ShapeType shapeType);

  /**
   * @brief Destructor.
   */
  virtual ~CShape() = default;

  // M�todos de ciclo de vida
  void start() override;
  void update(float deltaTime) override;
  void render(const EngineUtilities::TSharedPointer<Window>& window) override;
  void destroy() override;

  // Creaci�n y manipulaci�n de forma
  void createShape(ShapeType shapeType);
  void setPosition(float x, float y);
  void setPosition(const sf::Vector2f& position);
  void setFillColor(const sf::Color& color);
  void SetRotation(float angle);
  void setScale(const sf::Vector2f& scl);

private:
  EngineUtilities::TSharedPointer<sf::Shape> m_shapePtr; ///< Smart pointer a la forma SFML.
  ShapeType m_shapeType = ShapeType::EMPTY;              ///< Tipo de forma actual.
  sf::VertexArray* m_line = nullptr;                     ///< (opcional) l�nea si decides usar v�rtices.
};