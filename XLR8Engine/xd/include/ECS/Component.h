#pragma once

#include <memory>  ///< Para std::shared_ptr
#include "Actor.h" ///< Asegúrate de tener la clase Actor declarada

/**
 * @class Component
 * @brief Clase base para todos los componentes del motor.
 */
class Component
{
public:
    Component() = default;
    virtual ~Component() = default;

    /**
     * @brief Actualiza el componente.
     * @param deltaTime Tiempo transcurrido desde el último frame.
     */
    virtual void Update(float deltaTime) = 0;

    /**
     * @brief Establece el actor al que pertenece este componente.
     * @param actor Puntero al actor.
     */
    void SetOwner(std::shared_ptr<Actor> actor) { owner_ = actor; }

    /**
     * @brief Devuelve el actor dueño del componente.
     * @return std::shared_ptr<Actor>
     */
    std::shared_ptr<Actor> GetOwner() const { return owner_; }

protected:
    std::shared_ptr<Actor> owner_; ///< Actor dueño del componente.
};