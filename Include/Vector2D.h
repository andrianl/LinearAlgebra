#pragma once

// internal includes
#include "Platform.h"
#include "Types.h"

namespace Ratchet
{

    /**
     * @brief 2D Vector class template.
     *
     * @tparam T The floating-point type to use for vector components.
     */
    template <FloatingPoint T>
    class FVector2D
    {
    public:
        /**
         * @brief Default constructor. Initializes all components to zero.
         */
        FVector2D();

        /**
         * @brief Constructor that initializes vector components with given values.
         *
         * @param InX The X component value.
         * @param InY The Y component value.
         */
        FVector2D(const T InX, const T InY);

        /**
         * @brief Copy constructor.
         *
         * @param Other The vector to copy.
         */
        FVector2D(const FVector2D &Other);

        /**
         * @brief Equality operator.
         *
         * @param other The vector to compare.
         * @return true if the vectors are equal, false otherwise.
         */
        bool operator==(const FVector2D &other) const;

        /**
         * @brief Access individual components of the vector by index.
         *
         * @param i The index of the component.
         * @return Reference to the component at the specified index.
         */
        T &operator[](const int8 i);

        /**
         * @brief Access individual components of the vector by index (const version).
         *
         * @param i The index of the component.
         * @return Const reference to the component at the specified index.
         */
        const T &operator[](const int8 i) const;

        /**
         * @brief Get the X component value.
         *
         * @return The X component value.
         */
        T GetX() const;

        /**
         * @brief Get the Y component value.
         *
         * @return The Y component value.
         */
        T GetY() const;

        /**
         * @brief Set the X component value.
         *
         * @param InX The new X component value.
         */
        void SetX(const T InX);

        /**
         * @brief Set the Y component value.
         *
         * @param InY The new Y component value.
         */
        void SetY(const T InY);

        /**
         * @brief Calculate the magnitude (length) of the vector.
         *
         * @return The magnitude of the vector.
         */
        T Magnitude() const;

        /**
         * @brief Normalize the vector to have a magnitude of 1.
         *
         * @return Reference to the normalized vector.
         */
        FVector2D &Normalize();

        /**
         * @brief Calculate the distance between this vector and another vector.
         *
         * @param Other The other vector.
         * @return The distance between this vector and the other vector.
         */
        T DistanceTo(const FVector2D &Other) const;

        /**
         * @brief Compound assignment operator for vector addition.
         *
         * @param Other The vector to add.
         * @return Reference to the modified vector.
         */
        FVector2D &operator+=(const FVector2D &Other);

        /**
         * @brief Compound assignment operator for vector subtraction.
         *
         * @param Other The vector to subtract.
         * @return Reference to the modified vector.
         */
        FVector2D &operator-=(const FVector2D &Other);

        /**
         * @brief Compound assignment operator for scalar multiplication.
         *
         * @param Scalar The scalar value to multiply by.
         * @return Reference to the modified vector.
         */
        FVector2D &operator*=(const T Scalar);

        /**
         * @brief Compound assignment operator for scalar division.
         *
         * @param Scalar The scalar value to divide by.
         * @return Reference to the modified vector.
         */
        FVector2D &operator/=(const T Scalar);

    private:
        T X, Y; // Components of the vector
    };

    /**
     * @brief Binary operator for vector-scalar multiplication.
     *
     * @param LHS The vector to multiply.
     * @param Scalar The scalar value to multiply by.
     * @return The result of the multiplication.
     */
    template <FloatingPoint T>
    FVector2D<T> operator*(const FVector2D<T> &LHS, const T Scalar);

    /**
     * @brief Binary operator for vector-scalar division.
     *
     * @param LHS The vector to divide.
     * @param Scalar The scalar value to divide by.
     * @return The result of the division.
     */
    template <FloatingPoint T>
    FVector2D<T> operator/(const FVector2D<T> &LHS, const T Scalar);

    /**
     * @brief Binary operator for vector addition.
     *
     * @param A The first vector.
     * @param B The second vector.
     * @return The result of the addition.
     */
    template <FloatingPoint T>
    FVector2D<T> operator+(const FVector2D<T> &A, const FVector2D<T> &B);

    /**
     * @brief Binary operator for vector subtraction.
     *
     * @param A The vector to subtract from.
     * @param B The vector to subtract.
     * @return The result of the subtraction.
     */
    template <FloatingPoint T>
    FVector2D<T> operator-(const FVector2D<T> &A, const FVector2D<T> &B);

    /**
     * @brief Unary negation operator for a vector.
     *
     * @param Vector The vector to negate.
     * @return The negated vector.
     */
    template <FloatingPoint T>
    FVector2D<T> operator-(const FVector2D<T> &Vector);

    /**
     * @brief Calculate the magnitude (length) of a vector.
     *
     * @param Vector The vector to calculate the magnitude of.
     * @return The magnitude of the vector.
     */
    template <FloatingPoint T>
    T Magnitude(const FVector2D<T> &Vector);

    /**
     * @brief Get a normalized (unit) vector from a given vector.
     *
     * @param Vector The vector to normalize.
     * @return The normalized vector.
     */
    template <FloatingPoint T>
    FVector2D<T> GetNormalized(const FVector2D<T> &Vector);

    /**
     * @brief Calculate the dot product of two vectors.
     *
     * @param A The first vector.
     * @param B The second vector.
     * @return The dot product of the two vectors.
     */
    template <FloatingPoint T>
    T Dot(const FVector2D<T> &A, const FVector2D<T> &B);

    /**
     * @brief Calculate the distance between two vectors.
     *
     * @param A The first vector.
     * @param B The second vector.
     * @return The distance between the two vectors.
     */
    template <FloatingPoint T>
    T Distance(const FVector2D<T> &A, const FVector2D<T> &B);

    /**
     * @brief Calculate the squared distance between two vectors.
     *
     * @param A The first vector.
     * @param B The second vector.
     * @return The squared distance between the two vectors.
     */
    template <FloatingPoint T>
    T DistanceSquared(const FVector2D<T> &A, const FVector2D<T> &B);

}