#pragma once

// =======================================================
// Standard Library Headers
// =======================================================
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <thread>
#include <map>
#include <fstream>
#include <unordered_map>

// =======================================================
// Third-Party Libraries
// =======================================================
#include <SFML/Graphics.hpp>

// =======================================================
// Macros
// =======================================================

/**
 * @brief Safely deletes a pointer and sets it to nullptr.
 *
 * @param x Pointer to release.
 */
#define SAFE_PTR_RELEASE(x) \
    if (x != nullptr) { delete x; x = nullptr; }

 /**
  * @brief Logs a message indicating the creation state of a resource.
  *
  * @param classObj Name of the class.
  * @param method Name of the method.
  * @param state Description of the resource state.
  */
#define MESSAGE(classObj, method, state)                         \
{                                                                \
    std::ostringstream os_;                                      \
    os_ << classObj << "::" << method << " : "                   \
        << "[CREATION OF RESOURCE: " << state << "]\n";          \
    std::cerr << os_.str();                                      \
}

  /**
   * @brief Logs an error message and terminates the application.
   *
   * @param classObj Name of the class.
   * @param method Name of the method.
   * @param errorMSG Error details.
   */
#define ERROR(classObj, method, errorMSG)                        \
{                                                                \
    std::ostringstream os_;                                      \
    os_ << "ERROR : " << classObj << "::" << method << " : "     \
        << "Error in data from params [" << errorMSG << "]\n";   \
    std::cerr << os_.str();                                      \
    exit(1);                                                     \
}

   // =======================================================
   // Enumerations
   // =======================================================

   /**
    * @enum ShapeType
    * @brief Represents the different types of shapes supported in the application.
    */
enum ShapeType {
    EMPTY = 0,  ///< No shape selected or initialized.
    CIRCLE = 1,  ///< Circle shape.
    RECTANGLE = 2,  ///< Rectangle shape.
    TRIANGLE = 3,  ///< Triangle shape.
    POLYGON = 4   ///< Polygon shape.
};
