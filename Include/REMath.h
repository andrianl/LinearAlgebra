#pragma once
#include <type_traits>

#include "Platform.h"
#include <limits>



template <typename T>
concept FloatingPoint = std::is_floating_point_v<T>;

namespace Ratchet
{
	namespace Math
	{

		template<FloatingPoint T>
		T Epsilon = std::numeric_limits<T>::epsilon();

		template <typename T>
		T Abs(T value)
		{
			return (value < 0) ? -value : value;
		}

		template <FloatingPoint T>
		T Sqrt(T value)
		{
			if (value == 0 || value == 1)
				return value;


			T x = value;
			T y = (x + value / x) / 2;

			while (Abs<T>(x - y) > Epsilon<T>)
			{
				x = y;
				y = (x + value / x) / 2;
			}

			return y;
		}
	}
}