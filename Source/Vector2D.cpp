#include "Vector2D.h"
#include "REMath.h"

namespace Ratchet
{
	template <FloatingPoint T>
	FVector2D<T>::FVector2D()
		: X(0), Y(0) {}

	template <FloatingPoint T>
	FVector2D<T>::FVector2D(const T InX, const T InY)
		: X(InX), Y(InY) {}

	template <FloatingPoint T>
	FVector2D<T>::FVector2D(const FVector2D &Other)
		: X(Other.X), Y(Other.Y) {}

	template <FloatingPoint T>
	bool FVector2D<T>::operator==(const FVector2D &other) const
	{
	}

	template <FloatingPoint T>
	T &FVector2D<T>::operator[](const int8 i)
	{
		return (&X)[i];
	}

	template <FloatingPoint T>
	const T &FVector2D<T>::operator[](const int8 i) const
	{
		return (&X)[i];
	}

	template <FloatingPoint T>
	T FVector2D<T>::GetX() const
	{
		return X;
	}

	template <FloatingPoint T>
	T FVector2D<T>::GetY() const
	{
		return Y;
	}

	template <FloatingPoint T>
	void FVector2D<T>::SetX(const T InX)
	{
		X = InX;
	}

	template <FloatingPoint T>
	void FVector2D<T>::SetY(const T InY)
	{
		Y = InY;
	}

	template <FloatingPoint T>
	T FVector2D<T>::Magnitude() const
	{
		return Ratchet::Math::Sqrt<T>(X * X + Y * Y);
	}

	template <FloatingPoint T>
	FVector2D<T> &FVector2D<T>::Normalize()
	{
		const T magnitude = Magnitude();
		*this /= magnitude;
		return *this;
	}

	template <FloatingPoint T>
	T FVector2D<T>::DistanceTo(const FVector2D &Other) const
	{
		FVector2D<T> DifferenceVector = *this - Other;
		return DifferenceVector.Magnitude();
	}

	template <FloatingPoint T>
	FVector2D<T> &FVector2D<T>::operator+=(const FVector2D<T> &Other)
	{
		X += Other.X;
		Y += Other.Y;
		return *this;
	}

	template <FloatingPoint T>
	FVector2D<T> &FVector2D<T>::operator-=(const FVector2D<T> &Other)
	{
		X -= Other.X;
		Y -= Other.Y;
		return *this;
	}

	template <FloatingPoint T>
	FVector2D<T> &FVector2D<T>::operator*=(const T Scalar)
	{
		X *= Scalar;
		Y *= Scalar;
		return *this;
	}

	template <FloatingPoint T>
	FVector2D<T> &FVector2D<T>::operator/=(const T Scalar)
	{
		const T Delimeter = static_cast<T>(1) / Scalar;
		X *= Delimeter;
		Y *= Delimeter;
		return *this;
	}

	template <FloatingPoint T>
	FVector2D<T> operator*(const FVector2D<T> &LHS, const T Scalar)
	{
		return {LHS.GetX() * Scalar, LHS.GetY() * Scalar};
	}

	template <FloatingPoint T>
	FVector2D<T> operator/(const FVector2D<T> &LHS, const T Scalar)
	{
		const T Delimeter = static_cast<T>(1) / Scalar;
		return {LHS.GetX() * Delimeter, LHS.GetY() * Delimeter};
	}

	template <FloatingPoint T>
	FVector2D<T> operator+(const FVector2D<T> &A, const FVector2D<T> &B)
	{
		return {A.GetX() + B.GetX(), A.GetY() + B.GetY()};
	}

	template <FloatingPoint T>
	FVector2D<T> operator-(const FVector2D<T> &A, const FVector2D<T> &B)
	{
		return {A.GetX() - B.GetX(), A.GetY() - B.GetY()};
	}

	template <FloatingPoint T>
	FVector2D<T> operator-(const FVector2D<T> &Vector)
	{
		return {-Vector.GetX(), -Vector.GetY()};
	}

	template <FloatingPoint T>
	T Magnitude(const FVector2D<T> &Vector)
	{
		return Vector.Magnitude();
	}

	template <FloatingPoint T>
	FVector2D<T> GetNormalized(const FVector2D<T> &Vector)
	{
		const T magnitude = Magnitude(Vector);
		FVector2D<T> NormalizedVector = Vector / magnitude;

		return NormalizedVector;
	}

	template <FloatingPoint T>
	T Dot(const FVector2D<T> &A, const FVector2D<T> &B)
	{
		return A.GetX() * B.GetX() + A.GetY() * B.GetY();
	}

	template <FloatingPoint T>
	T Distance(const FVector2D<T> &A, const FVector2D<T> &B)
	{
		return Magnitude(A - B);
	}

	template <FloatingPoint T>
	T DistanceSquared(const FVector2D<T> &A, const FVector2D<T> &B)
	{
		const FVector2D<T> Difference = A - B;
		return Dot(Difference, Difference);
	}

	// Explicit instantiation for float
	template class FVector2D<float>;

	// Explicit instantiation for double
	template class FVector2D<double>;

	// Explicit instantiation for long double
	template class FVector2D<long double>;

	// You can add more instantiations for other types if needed

	// Explicit instantiation for binary operators with float
	template FVector2D<float> operator*(const FVector2D<float> &LHS, const float Scalar);
	template FVector2D<float> operator/(const FVector2D<float> &LHS, const float Scalar);
	template FVector2D<float> operator+(const FVector2D<float> &A, const FVector2D<float> &B);
	template FVector2D<float> operator-(const FVector2D<float> &A, const FVector2D<float> &B);

	// Explicit instantiation for binary operators with double
	template FVector2D<double> operator*(const FVector2D<double> &LHS, const double Scalar);
	template FVector2D<double> operator/(const FVector2D<double> &LHS, const double Scalar);
	template FVector2D<double> operator+(const FVector2D<double> &A, const FVector2D<double> &B);
	template FVector2D<double> operator-(const FVector2D<double> &A, const FVector2D<double> &B);

	// Explicit instantiation for binary operators with long double
	template FVector2D<long double> operator*(const FVector2D<long double> &LHS, const long double Scalar);
	template FVector2D<long double> operator/(const FVector2D<long double> &LHS, const long double Scalar);
	template FVector2D<long double> operator+(const FVector2D<long double> &A, const FVector2D<long double> &B);
	template FVector2D<long double> operator-(const FVector2D<long double> &A, const FVector2D<long double> &B);

	// Explicit instantiation for other functions
	template float Magnitude(const FVector2D<float> &Vector);
	template double Magnitude(const FVector2D<double> &Vector);
	template long double Magnitude(const FVector2D<long double> &Vector);

	template FVector2D<float> GetNormalized(const FVector2D<float> &Vector);
	template FVector2D<double> GetNormalized(const FVector2D<double> &Vector);
	template FVector2D<long double> GetNormalized(const FVector2D<long double> &Vector);

	template float Dot(const FVector2D<float> &A, const FVector2D<float> &B);
	template double Dot(const FVector2D<double> &A, const FVector2D<double> &B);
	template long double Dot(const FVector2D<long double> &A, const FVector2D<long double> &B);

	template float Distance(const FVector2D<float> &A, const FVector2D<float> &B);
	template double Distance(const FVector2D<double> &A, const FVector2D<double> &B);
	template long double Distance(const FVector2D<long double> &A, const FVector2D<long double> &B);

	template float DistanceSquared(const FVector2D<float> &A, const FVector2D<float> &B);
	template double DistanceSquared(const FVector2D<double> &A, const FVector2D<double> &B);
	template long double DistanceSquared(const FVector2D<long double> &A, const FVector2D<long double> &B);

}