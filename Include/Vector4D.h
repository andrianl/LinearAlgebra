#pragma once

#include <concepts>

#include "Math.h"

/**
 * @brief Concept to check if a type is a floating-point type.
 *
 * @tparam T The type to check.
 */
template <typename T>
concept FloatingPoint = std::is_floating_point_v<T>;

/**
 * @brief 4D Vector class template.
 *
 * @tparam T The floating-point type to use for vector components.
 */
template <FloatingPoint T>
class FVector4D
{
public:
    /**
     * @brief Default constructor. Initializes all components to zero.
     */
    FVector4D() = default;

    /**
     * @brief Constructor that initializes vector components with given values.
     *
     * @param InX The X component value.
     * @param InY The Y component value.
     * @param InZ The Z component value.
     * @param InW The W component value.
     */
    FVector4D(const T& InX, const T& InY, const T& InZ, const T& InW) : X(InX), Y(InY), Z(InZ), W(InW) {}

    /**
     * @brief Copy constructor.
     *
     * @param Other The vector to copy.
     */
    FVector4D(const FVector4D& Other) = default;

    /**
     * @brief Move constructor.
     *
     * @param Other The vector to move.
     */
    FVector4D(FVector4D&& Other) noexcept = default;

    /**
     * @brief Equality operator.
     *
     * @param other The vector to compare.
     * @return true if the vectors are equal, false otherwise.
     */
    bool operator==(const FVector4D& other) const = default;

    /**
     * @brief Access individual components of the vector by index.
     *
     * @param i The index of the component.
     * @return Reference to the component at the specified index.
     */
    T& operator[](const int8 i) { return (&X)[i]; }

    /**
     * @brief Access individual components of the vector by index (const version).
     *
     * @param i The index of the component.
     * @return Const reference to the component at the specified index.
     */
    const T& operator[](const int8 i) const { return (&X)[i]; }

    /**
     * @brief Get the X component value.
     *
     * @return The X component value.
     */
    T GetX() const { return X; }

    /**
     * @brief Get the Y component value.
     *
     * @return The Y component value.
     */
    T GetY() const { return Y; }

    /**
     * @brief Get the Z component value.
     *
     * @return The Z component value.
     */
    T GetZ() const { return Z; }

    /**
     * @brief Get the W component value.
     *
     * @return The W component value.
     */
    T GetW() const { return W; }

    /**
     * @brief Set the X component value.
     *
     * @param InX The new X component value.
     */
    void SetX(const T& InX) { X = InX; }

    /**
     * @brief Set the Y component value.
     *
     * @param InY The new Y component value.
     */
    void SetY(const T& InY) { Y = InY; }

    /**
     * @brief Set the Z component value.
     *
     * @param InZ The new Z component value.
     */
    void SetZ(const T& InZ) { Z = InZ; }

    /**
     * @brief Set the W component value.
     *
     * @param InW The new W component value.
     */
    void SetW(const T& InW) { W = InW; }

    /**
     * @brief Calculate the magnitude (length) of the vector.
     *
     * @return The magnitude of the vector.
     */
    T Magnitude() const { return Sqrt(X * X + Y * Y + Z * Z + W * W); }

    /**
     * @brief Normalize the vector to have a magnitude of 1.
     *
     * @return Reference to the normalized vector.
     */
    FVector4D& Normalize()
    {
        const T magnitude = Magnitude();
        *this /= magnitude;
        return *this;
    }

    /**
    * @brief Calculate the distance between this vector and another vector.
    *
    * @param Other The other vector.
    * @return The distance between this vector and the other vector.
    */
    T DistanceTo(const FVector4D& Other) const
    {
        return Magnitude(*this - Other);
    }

    /**
     * @brief Compound assignment operator for vector addition.
     *
     * @param Other The vector to add.
     * @return Reference to the modified vector.
     */
    FVector4D& operator+=(const FVector4D& Other)
    {
        X += Other.X;
        Y += Other.Y;
        Z += Other.Z;
        W += Other.W;
        return *this;
    }

    /**
     * @brief Compound assignment operator for vector subtraction.
     *
     * @param Other The vector to subtract.
     * @return Reference to the modified vector.
     */
    FVector4D& operator-=(const FVector4D& Other)
    {
        X -= Other.X;
        Y -= Other.Y;
        Z -= Other.Z;
        W -= Other.W;
        return *this;
    }

    /**
     * @brief Compound assignment operator for scalar multiplication.
     *
     * @param Scalar The scalar value to multiply by.
     * @return Reference to the modified vector.
     */
    FVector4D& operator*=(const T& Scalar)
    {
        X *= Scalar;
        Y *= Scalar;
        Z *= Scalar;
        W *= Scalar;
        return *this;
    }

    /**
     * @brief Compound assignment operator for scalar division.
     *
     * @param Scalar The scalar value to divide by.
     * @return Reference to the modified vector.
     */
    FVector4D& operator/=(const T& Scalar)
    {
        const T Delimeter = static_cast<T>(1) / Scalar;
        X *= Delimeter;
        Y *= Delimeter;
        Z *= Delimeter;
        W *= Delimeter;
        return *this;
    }

private:
    T X, Y, Z, W; // Components of the vector
};

/**
 * @brief Binary operator for vector-scalar multiplication.
 *
 * @param LHS The vector to multiply.
 * @param Scalar The scalar value to multiply by.
 * @return The result of the multiplication.
 */
template <FloatingPoint T>
inline FVector4D<T> operator*(const FVector4D<T>& LHS, const T& Scalar)
{
    return { LHS.GetX() * Scalar, LHS.GetY() * Scalar, LHS.GetZ() * Scalar, LHS.GetW() * Scalar };
}

/**
 * @brief Binary operator for vector-scalar division.
 *
 * @param LHS The vector to divide.
 * @param Scalar The scalar value to divide by.
 * @return The result of the division.
 */
template <FloatingPoint T>
inline FVector4D<T> operator/(const FVector4D<T>& LHS, const T& Scalar)
{
    const T Delimeter = static_cast<T>(1) / Scalar;
    return { LHS.GetX() * Delimeter, LHS.GetY() * Delimeter, LHS.GetZ() * Delimeter, LHS.GetW() * Delimeter };
}

/**
 * @brief Binary operator for vector addition.
 *
 * @param A The first vector.
 * @param B The second vector.
 * @return The result of the addition.
 */
template <FloatingPoint T>
inline FVector4D<T> operator+(const FVector4D<T>& A, const FVector4D<T>& B)
{
    return { A.GetX() + B.GetX(), A.GetY() + B.GetY(), A.GetZ() + B.GetZ(), A.GetW() + B.GetW() };
}

/**
 * @brief Binary operator for vector subtraction.
 *
 * @param A The vector to subtract from.
 * @param B The vector to subtract.
 * @return The result of the subtraction.
 */
template <FloatingPoint T>
inline FVector4D<T> operator-(const FVector4D<T>& A, const FVector4D<T>& B)
{
    return { A.GetX() - B.GetX(), A.GetY() - B.GetY(), A.GetZ() - B.GetZ(), A.GetW() - B.GetW() };
}

/**
 * @brief Unary negation operator for a vector.
 *
 * @param Vector The vector to negate.
 * @return The negated vector.
 */
template <FloatingPoint T>
inline FVector4D<T> operator-(const FVector4D<T>& Vector)
{
    return { -Vector.GetX(), -Vector.GetY(), -Vector.GetZ(), -Vector.GetW() };
}

/**
 * @brief Calculate the magnitude (length) of a vector.
 *
 * @param Vector The vector to calculate the magnitude of.
 * @return The magnitude of the vector.
 */
template <FloatingPoint T>
inline T Magnitude(const FVector4D<T>& Vector)
{
    return Vector.Magnitude();
}

/**
 * @brief Get a normalized (unit) vector from a given vector.
 *
 * @param Vector The vector to normalize.
 * @return The normalized vector.
 */
template <FloatingPoint T>
inline FVector4D<T> GetNormalized(const FVector4D<T>& Vector)
{
    const T magnitude = Magnitude(Vector);
    FVector4D<T> NormalizedVector = Vector / magnitude;

    return NormalizedVector;
}

/**
 * @brief Calculate the dot product of two vectors.
 *
 * @param A The first vector.
 * @param B The second vector.
 * @return The dot product of the two vectors.
 */
template <FloatingPoint T>
inline T Dot(const FVector4D<T>& A, const FVector4D<T>& B)
{
    return A.GetX() * B.GetX() + A.GetY() * B.GetY() + A.GetZ() * B.GetZ() + A.GetW() * B.GetW();
}

/**
 * @brief Calculate the distance between two vectors.
 *
 * @param A The first vector.
 * @param B The second vector.
 * @return The distance between the two vectors.
 */
template <FloatingPoint T>
inline T Distance(const FVector4D<T>& A, const FVector4D<T>& B)
{
    return Magnitude(A - B);
}

/**
 * @brief Calculate the squared distance between two vectors.
 *
 * @param A The first vector.
 * @param B The second vector.
 * @return The squared distance between the two vectors.
 */
template <FloatingPoint T>
inline T DistanceSquared(const FVector4D<T>& A, const FVector4D<T>& B)
{
    const FVector4D<T> Difference = A - B;
    return Dot(Difference, Difference);
}

#ifdef DOUBLE_PRECISION
using Vector4D = FVector4D<double>;
#elif
using Vector4D = FVector4D<float>;
#endif