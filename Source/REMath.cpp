#include "REMath.h"

#include <type_traits>

#include "Platform.h"

namespace Ratchet
{
	namespace Math
	{
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

		// Explicit instantiations for the required floating-point types
		template float Abs<float>(float value);
		template double Abs<double>(double value);
		template long double Abs<long double>(long double value);

		template float Sqrt<float>(float value);
		template double Sqrt<double>(double value);
		template long double Sqrt<long double>(long double value);
	}
}