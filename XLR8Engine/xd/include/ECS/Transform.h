﻿#pragma once

/**
 * @file Transform.h
 * @brief Declares the Transform component used for managing position, rotation, and scale in entities.
 */

#include <SFML/System/Vector2.hpp>
#include "ECS/Component.h"

class Window;

/**
 * @class Transform
 * @brief Component that holds position, rotation, and scale for an entity.
 */
class Transform : public Component {
public:
    /**
     * @brief Default constructor.
     */
    Transform()
        : Component(ComponentType::TRANFORM),
        m_position(0.f, 0.f),
        m_rotation(0.f, 0.f),
        m_scale(1.f, 1.f) {
    }

    /**
     * @brief Destructor.
     */
    virtual
        ~Transform() = default;

    // M�todos override del sistema ECS

    //Quitar deltaTime al START
    void
        start() override {}


    void
        update(float deltaTime) override {}


    void
        render(const EngineUtilities::TSharedPointer<Window>& window) override {}

    void
        destroy() override {
    }

    // Setters
    void
        setPosition(const sf::Vector2f& pos) {
        m_position = pos;
    }   //Se supone que es para que actualice el valo de la clase 

    void
        setRotation(const sf::Vector2f& rot) {
        m_rotation = rot;
    }

    void
        setScale(const sf::Vector2f& scl) {
        m_scale = scl;
    }

    // Getters
    sf::Vector2f
        getPosition() const { return m_position; }

    sf::Vector2f
        getRotation() const { return m_rotation; }

    sf::Vector2f
        getScale()    const { return m_scale; }

private:
    sf::Vector2f m_position;
    sf::Vector2f m_rotation;
    sf::Vector2f m_scale;
};