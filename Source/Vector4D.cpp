#include "Vector4D.h"
#include "REMath.h"

namespace Ratchet
{
	template <FloatingPoint T>
	FVector4D<T>::FVector4D()
		: X(0), Y(0), Z(0), W(0) {}

	template <FloatingPoint T>
	FVector4D<T>::FVector4D(const T InX, const T InY, const T InZ, const T InW)
		: X(InX), Y(InY), Z(InZ), W(InW) {}

	template <FloatingPoint T>
	FVector4D<T>::FVector4D(const FVector4D &Other)
		: X(Other.X), Y(Other.Y), Z(Other.Z), W(Other.W) {}

	template <FloatingPoint T>
	bool FVector4D<T>::operator==(const FVector4D &Other) const
	{
	}

	template <FloatingPoint T>
	T &FVector4D<T>::operator[](const int8 i)
	{
		return (&X)[i];
	}

	template <FloatingPoint T>
	const T &FVector4D<T>::operator[](const int8 i) const
	{
		return (&X)[i];
	}

	template <FloatingPoint T>
	T FVector4D<T>::GetX() const
	{
		return X;
	}
	template <FloatingPoint T>
	T FVector4D<T>::GetY() const
	{
		return Y;
	}
	template <FloatingPoint T>
	T FVector4D<T>::GetZ() const
	{
		return Z;
	}
	template <FloatingPoint T>
	T FVector4D<T>::GetW() const
	{
		return W;
	}
	template <FloatingPoint T>
	void FVector4D<T>::SetX(const T InX)
	{
		X = InX;
	}
	template <FloatingPoint T>
	void FVector4D<T>::SetY(const T InY)
	{
		Y = InY;
	}
	template <FloatingPoint T>
	void FVector4D<T>::SetZ(const T InZ)
	{
		Z = InZ;
	}
	template <FloatingPoint T>
	void FVector4D<T>::SetW(const T InW)
	{
		W = InW;
	}
	template <FloatingPoint T>
	T FVector4D<T>::Magnitude() const
	{
		return Ratchet::Math::Sqrt<T>(X * X + Y * Y + Z * Z + W * W);
	}
	template <FloatingPoint T>
	FVector4D<T> &FVector4D<T>::Normalize()
	{
		const T magnitude = Magnitude();
		*this /= magnitude;
		return *this;
	}
	template <FloatingPoint T>
	T FVector4D<T>::DistanceTo(const FVector4D &Other) const
	{
		FVector4D<T> DifferenceVector = *this - Other;
		return DifferenceVector.Magnitude();
	}
	template <FloatingPoint T>
	FVector4D<T> &FVector4D<T>::operator+=(const FVector4D &Other)
	{
		X += Other.X;
		Y += Other.Y;
		Z += Other.Z;
		W += Other.W;
		return *this;
	}
	template <FloatingPoint T>
	FVector4D<T> &FVector4D<T>::operator-=(const FVector4D &Other)
	{
		X -= Other.X;
		Y -= Other.Y;
		Z -= Other.Z;
		W -= Other.W;
		return *this;
	}
	template <FloatingPoint T>
	FVector4D<T> &FVector4D<T>::operator*=(const T Scalar)
	{
		X *= Scalar;
		Y *= Scalar;
		Z *= Scalar;
		W *= Scalar;
		return *this;
	}
	template <FloatingPoint T>
	FVector4D<T> &FVector4D<T>::operator/=(const T Scalar)
	{
		const T Delimeter = static_cast<T>(1) / Scalar;
		X *= Delimeter;
		Y *= Delimeter;
		Z *= Delimeter;
		W *= Delimeter;
		return *this;
	}

	/* //////////////////////////////////////////////////////////////////////////////////////////////////////// */

	template <FloatingPoint T>
	FVector4D<T> operator*(const FVector4D<T> &LHS, const T Scalar)
	{
		return {LHS.GetX() * Scalar, LHS.GetY() * Scalar, LHS.GetZ() * Scalar, LHS.GetW() * Scalar};
	}

	template <FloatingPoint T>
	FVector4D<T> operator/(const FVector4D<T> &LHS, const T Scalar)
	{
		const T Delimeter = static_cast<T>(1) / Scalar;
		return {LHS.GetX() * Delimeter, LHS.GetY() * Delimeter, LHS.GetZ() * Delimeter, LHS.GetW() * Delimeter};
	}

	template <FloatingPoint T>
	FVector4D<T> operator+(const FVector4D<T> &A, const FVector4D<T> &B)
	{
		return {A.GetX() + B.GetX(), A.GetY() + B.GetY(), A.GetZ() + B.GetZ(), A.GetW() + B.GetW()};
	}

	template <FloatingPoint T>
	FVector4D<T> operator-(const FVector4D<T> &A, const FVector4D<T> &B)
	{
		return {A.GetX() - B.GetX(), A.GetY() - B.GetY(), A.GetZ() - B.GetZ(), A.GetW() - B.GetW()};
	}

	template <FloatingPoint T>
	FVector4D<T> operator-(const FVector4D<T> &Vector)
	{
		return {-Vector.GetX(), -Vector.GetY(), -Vector.GetZ(), -Vector.GetW()};
	}

	template <FloatingPoint T>
	T Magnitude(const FVector4D<T> &Vector)
	{
		return Vector.Magnitude();
	}

	template <FloatingPoint T>
	FVector4D<T> GetNormalized(const FVector4D<T> &Vector)
	{
		const T magnitude = Magnitude(Vector);
		FVector4D<T> NormalizedVector = Vector / magnitude;

		return NormalizedVector;
	}

	template <FloatingPoint T>
	T Dot(const FVector4D<T> &A, const FVector4D<T> &B)
	{
		return A.GetX() * B.GetX() + A.GetY() * B.GetY() + A.GetZ() * B.GetZ() + A.GetW() * B.GetW();
	}

	template <FloatingPoint T>
	T Distance(const FVector4D<T> &A, const FVector4D<T> &B)
	{
		return Magnitude(A - B);
	}

	template <FloatingPoint T>
	T DistanceSquared(const FVector4D<T> &A, const FVector4D<T> &B)
	{
		const FVector4D<T> Difference = A - B;
		return Dot(Difference, Difference);
	}

	// Explicit instantiation for float
	template class FVector4D<float>;

	// Explicit instantiation for double
	template class FVector4D<double>;

	// Explicit instantiation for long double
	template class FVector4D<long double>;

	// You can add more instantiations for other types if needed

	// Explicit instantiation for binary operators with float
	template FVector4D<float> operator*(const FVector4D<float> &LHS, const float Scalar);
	template FVector4D<float> operator/(const FVector4D<float> &LHS, const float Scalar);
	template FVector4D<float> operator+(const FVector4D<float> &A, const FVector4D<float> &B);
	template FVector4D<float> operator-(const FVector4D<float> &A, const FVector4D<float> &B);

	// Explicit instantiation for binary operators with double
	template FVector4D<double> operator*(const FVector4D<double> &LHS, const double Scalar);
	template FVector4D<double> operator/(const FVector4D<double> &LHS, const double Scalar);
	template FVector4D<double> operator+(const FVector4D<double> &A, const FVector4D<double> &B);
	template FVector4D<double> operator-(const FVector4D<double> &A, const FVector4D<double> &B);

	// Explicit instantiation for binary operators with long double
	template FVector4D<long double> operator*(const FVector4D<long double> &LHS, const long double Scalar);
	template FVector4D<long double> operator/(const FVector4D<long double> &LHS, const long double Scalar);
	template FVector4D<long double> operator+(const FVector4D<long double> &A, const FVector4D<long double> &B);
	template FVector4D<long double> operator-(const FVector4D<long double> &A, const FVector4D<long double> &B);

	// Explicit instantiation for other functions
	template float Magnitude(const FVector4D<float> &Vector);
	template double Magnitude(const FVector4D<double> &Vector);
	template long double Magnitude(const FVector4D<long double> &Vector);

	template FVector4D<float> GetNormalized(const FVector4D<float> &Vector);
	template FVector4D<double> GetNormalized(const FVector4D<double> &Vector);
	template FVector4D<long double> GetNormalized(const FVector4D<long double> &Vector);

	template float Dot(const FVector4D<float> &A, const FVector4D<float> &B);
	template double Dot(const FVector4D<double> &A, const FVector4D<double> &B);
	template long double Dot(const FVector4D<long double> &A, const FVector4D<long double> &B);

	template float Distance(const FVector4D<float> &A, const FVector4D<float> &B);
	template double Distance(const FVector4D<double> &A, const FVector4D<double> &B);
	template long double Distance(const FVector4D<long double> &A, const FVector4D<long double> &B);

	template float DistanceSquared(const FVector4D<float> &A, const FVector4D<float> &B);
	template double DistanceSquared(const FVector4D<double> &A, const FVector4D<double> &B);
	template long double DistanceSquared(const FVector4D<long double> &A, const FVector4D<long double> &B);

}
