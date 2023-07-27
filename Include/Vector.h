#pragma once

#include "Vector3D.h"
#include "Vector2D.h"
#include "Vector4D.h"

namespace Ratchet
{
#ifdef DOUBLE_PRECISION
	using Vector3D = FVector3D<double>;
	using Vector2D = FVector2D<double>;
	using Vector4D = FVector4D<double>;
#else
	using Vector3D = FVector3D<float>;
	using Vector2D = FVector2D<float>;
	using Vector4D = FVector4D<float>;
#endif

}

using Ratchet::Vector2D;
using Ratchet::Vector3D;
using Ratchet::Vector4D;