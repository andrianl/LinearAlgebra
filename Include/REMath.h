#pragma once
#include <type_traits>

#include "Platform.h"
#include <limits>


// external includes
#include <concepts>
#include <limits>

// internal includes
#include "Types.h"

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
