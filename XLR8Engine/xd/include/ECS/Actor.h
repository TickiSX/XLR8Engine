#pragma once

#include <memory> ///< Para std::shared_ptr
#include <string> ///< Para std::string
#include "Transform.h" ///< Aseg�rate de tener tu clase Transform aqu�

/**
 * @class Actor
 * @brief Clase base para todos los objetos que pueden ser colocados en la escena.
 */
class Actor
{
public:
    Actor();
    virtual ~Actor();

    /**
     * @brief Actualiza el actor.
     * @param deltaTime Tiempo transcurrido desde el �ltimo frame.
     */
    virtual void Update(float deltaTime) = 0;

    /**
     * @brief Devuelve el nombre del actor.
     * @return Nombre como std::string.
     */
    virtual std::string GetName() const = 0;

    /**
     * @brief Devuelve el transform del actor.
     * @return std::shared_ptr<Transform>.
     */
    std::shared_ptr<Transform> GetTransform() const { return transform_; }

protected:
    std::shared_ptr<Transform> transform_; ///< Transformaci�n del actor.
};