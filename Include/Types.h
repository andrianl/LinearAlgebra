#pragma once

#include <concepts>

/**
 * @brief Concept to check if a type is a floating-point type.
 *
 * @tparam T The type to check.
 */
template <typename T>
concept FloatingPoint = std::is_floating_point_v<T>;

#ifdef DOUBLE_PRECISION
typedef double Real;
#else
typedef float Real;
#endif // DOUBLE_PRECISION