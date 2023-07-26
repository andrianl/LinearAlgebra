#include "Vector3D.h"
#include "REMath.h"


namespace Ratchet
{
	template <FloatingPoint T>
	Ratchet::FVector3D<T>::FVector3D() 
		: X(0), Y(0), Z(0) {}

	template <FloatingPoint T>
	Ratchet::FVector3D<T>::FVector3D(const T InX, const T InY, const T InZ) 
		: X(InX), Y(InY), Z(InZ){}

	template <FloatingPoint T>
	Ratchet::FVector3D<T>::FVector3D(const FVector3D& Other)
		: X(Other.X), Y(Other.Y), Z(Other.Z){}

	template <FloatingPoint T>
	bool Ratchet::FVector3D<T>::operator==(const FVector3D& other) const
	{

	}

	template <FloatingPoint T>
	T& Ratchet::FVector3D<T>::operator[](const int8 i)
	{
		return (&X)[i];
	}

	template <FloatingPoint T>
	const T& Ratchet::FVector3D<T>::operator[](const int8 i) const
	{
		return (&X)[i];
	}


	template <FloatingPoint T>
	T Ratchet::FVector3D<T>::GetX() const
	{
		return X;
	}


	template <FloatingPoint T>
	T Ratchet::FVector3D<T>::GetY() const
	{
		return Y;
	}

	template <FloatingPoint T>
	T Ratchet::FVector3D<T>::GetZ() const
	{
		return Z;
	}


	template <FloatingPoint T>
	void Ratchet::FVector3D<T>::SetX(const T InX)
	{
		X = InX;
	}


	template <FloatingPoint T>
	void Ratchet::FVector3D<T>::SetY(const T InY)
	{
		Y = InY;
	}


	template <FloatingPoint T>
	void Ratchet::FVector3D<T>::SetZ(const T InZ)
	{
		Z = InZ;
	}


	template <FloatingPoint T>
	T Ratchet::FVector3D<T>::Magnitude() const
	{
		return Ratchet::Math::Sqrt<T>(X * X + Y * Y + Z * Z);;
	}


	template <FloatingPoint T>
	FVector3D<T>& Ratchet::FVector3D<T>::Normalize()
	{
		const T magnitude = Magnitude();
		*this /= magnitude;
		return *this;
	}


	template <FloatingPoint T>
	T Ratchet::FVector3D<T>::DistanceTo(const FVector3D& Other) const
	{
		FVector3D<T> DiffernceVector = *this - Other;
		return DiffernceVector.Magnitude();
	}

	template <FloatingPoint T>
	FVector3D<T>& Ratchet::FVector3D<T>::operator+=(const FVector3D& Other)
	{
		X += Other.X;
		Y += Other.Y;
		Z += Other.Z;
		return *this;
	}


	template <FloatingPoint T>
	FVector3D<T>& Ratchet::FVector3D<T>::operator-=(const FVector3D& Other)
	{
		X -= Other.X;
		Y -= Other.Y;
		Z -= Other.Z;
		return *this;
	}


	template <FloatingPoint T>
	FVector3D<T>& Ratchet::FVector3D<T>::operator*=(const T Scalar)
	{
		X *= Scalar;
		Y *= Scalar;
		Z *= Scalar;
		return *this;
	}


	template <FloatingPoint T>
	FVector3D<T>& Ratchet::FVector3D<T>::operator/=(const T Scalar)
	{
		const T Delimeter = static_cast<T>(1) / Scalar;
		X *= Delimeter;
		Y *= Delimeter;
		Z *= Delimeter;
		return *this;
	}
	

	template <FloatingPoint T>
	FVector3D<T> operator*(const FVector3D<T>& LHS, const T& Scalar)
	{
		return { LHS.GetX() * Scalar, LHS.GetY() * Scalar, LHS.GetZ() * Scalar };
	}

	template <FloatingPoint T>
	FVector3D<T> operator/(const FVector3D<T>& LHS, const T& Scalar)
	{
		const T Delimeter = static_cast<T>(1) / Scalar;
		return { LHS.GetX() * Delimeter, LHS.GetY() * Delimeter, LHS.GetZ() * Delimeter };
	}

	template <FloatingPoint T>
	FVector3D<T> operator+(const FVector3D<T>& A, const FVector3D<T>& B)
	{
		return { A.GetX() + B.GetX(), A.GetY() + B.GetY(), A.GetZ() + B.GetZ() };
	}

	template <FloatingPoint T>
	FVector3D<T> operator-(const FVector3D<T>& A, const FVector3D<T>& B)
	{
		return { A.GetX() - B.GetX(), A.GetY() - B.GetY(), A.GetZ() - B.GetZ() };
	}

	template <FloatingPoint T>
	T Magnitude(const FVector3D<T>& Vector)
	{
		return Vector.Magnitude();
	}

	template <FloatingPoint T>
	FVector3D<T> GetNormalized(const FVector3D<T>& Vector)
	{
		const T magnitude = Magnitude(Vector);
		FVector3D<T> NormalizedVector = Vector / magnitude;

		return NormalizedVector;
	}

	template <FloatingPoint T>
	T Dot(const FVector3D<T>& A, const FVector3D<T>& B)
	{
		return A.GetX() * B.GetX() + A.GetY() * B.GetY() + A.GetZ() * B.GetZ();
	}

	template <FloatingPoint T>
	FVector3D<T> Cross(const FVector3D<T>& A, const FVector3D<T>& B)
	{
		return {
			A.GetY() * B.GetZ() - A.GetZ() * B.GetY(),
			A.GetZ() * B.GetX() - A.GetX() * B.GetZ(),
			A.GetX() * B.GetY() - A.GetY() * B.GetX()
		};
	}

	template <FloatingPoint T>
	T Distance(const FVector3D<T>& A, const FVector3D<T>& B)
	{
		return Magnitude(A - B);
	}

	template <FloatingPoint T>
	T DistanceSquared(const FVector3D<T>& A, const FVector3D<T>& B)
	{
		const FVector3D<T> Difference = A - B;
		return Dot(Difference, Difference);
	}

	template <FloatingPoint T>
	FVector3D<T> Project(const FVector3D<T>& A, const FVector3D<T>& B)
	{
		return { B * (Dot(A, B) / Dot(B, B)) };
	}


	template <FloatingPoint T>
	FVector3D<T>
		Reject(const FVector3D<T>& A, const FVector3D<T>& B)
	{
		return { A - B * (Dot(A, B) / Dot(B, B)) };
	}


	// Explicit instantiation for float
	template class FVector3D<float>;

	// Explicit instantiation for double
	template class FVector3D<double>;

	// Explicit instantiation for long double
	template class FVector3D<long double>;

	// You can add more instantiations for other types if needed

	// Explicit instantiation for binary operators with float
	template FVector3D<float> operator*(const FVector3D<float>& LHS, const float& Scalar);
	template FVector3D<float> operator/(const FVector3D<float>& LHS, const float& Scalar);
	template FVector3D<float> operator+(const FVector3D<float>& A, const FVector3D<float>& B);
	template FVector3D<float> operator-(const FVector3D<float>& A, const FVector3D<float>& B);

	// Explicit instantiation for binary operators with double
	template FVector3D<double> operator*(const FVector3D<double>& LHS, const double& Scalar);
	template FVector3D<double> operator/(const FVector3D<double>& LHS, const double& Scalar);
	template FVector3D<double> operator+(const FVector3D<double>& A, const FVector3D<double>& B);
	template FVector3D<double> operator-(const FVector3D<double>& A, const FVector3D<double>& B);

	// Explicit instantiation for binary operators with long double
	template FVector3D<long double> operator*(const FVector3D<long double>& LHS, const long double& Scalar);
	template FVector3D<long double> operator/(const FVector3D<long double>& LHS, const long double& Scalar);
	template FVector3D<long double> operator+(const FVector3D<long double>& A, const FVector3D<long double>& B);
	template FVector3D<long double> operator-(const FVector3D<long double>& A, const FVector3D<long double>& B);

	// Explicit instantiation for other functions
	template float Magnitude(const FVector3D<float>& Vector);
	template double Magnitude(const FVector3D<double>& Vector);
	template long double Magnitude(const FVector3D<long double>& Vector);

	template FVector3D<float> GetNormalized(const FVector3D<float>& Vector);
	template FVector3D<double> GetNormalized(const FVector3D<double>& Vector);
	template FVector3D<long double> GetNormalized(const FVector3D<long double>& Vector);

	template float Dot(const FVector3D<float>& A, const FVector3D<float>& B);
	template double Dot(const FVector3D<double>& A, const FVector3D<double>& B);
	template long double Dot(const FVector3D<long double>& A, const FVector3D<long double>& B);

	template FVector3D<float> Cross(const FVector3D<float>& A, const FVector3D<float>& B);
	template FVector3D<double> Cross(const FVector3D<double>& A, const FVector3D<double>& B);
	template FVector3D<long double> Cross(const FVector3D<long double>& A, const FVector3D<long double>& B);

	template float Distance(const FVector3D<float>& A, const FVector3D<float>& B);
	template double Distance(const FVector3D<double>& A, const FVector3D<double>& B);
	template long double Distance(const FVector3D<long double>& A, const FVector3D<long double>& B);

	template float DistanceSquared(const FVector3D<float>& A, const FVector3D<float>& B);
	template double DistanceSquared(const FVector3D<double>& A, const FVector3D<double>& B);
	template long double DistanceSquared(const FVector3D<long double>& A, const FVector3D<long double>& B);

	template FVector3D<float> Project(const FVector3D<float>& A, const FVector3D<float>& B);
	template FVector3D<double> Project(const FVector3D<double>& A, const FVector3D<double>& B);
	template FVector3D<long double> Project(const FVector3D<long double>& A, const FVector3D<long double>& B);

	template FVector3D<float> Reject(const FVector3D<float>& A, const FVector3D<float>& B);
	template FVector3D<double> Reject(const FVector3D<double>& A, const FVector3D<double>& B);
	template FVector3D<long double> Reject(const FVector3D<long double>& A, const FVector3D<long double>& B);
}

