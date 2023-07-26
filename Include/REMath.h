#pragma once

#include <concepts>
#include <limits>

template <typename T>
concept FloatingPoint = std::is_floating_point_v<T>;

namespace Ratchet
{
	namespace Math
	{
		template <FloatingPoint T>
		T Epsilon = std::numeric_limits<T>::epsilon();

		template <typename T>
		T Abs(T value);

		template <FloatingPoint T>
		T Sqrt(T value);
	}
}