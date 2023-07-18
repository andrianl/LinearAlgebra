#include "Vector.h"
#include <iostream>

int main()
{
	Vector2D Location2{};
	Vector3D Location3{};
	Vector4D Location4{};


	Vector3D LocationX{ 4, 8, 12 };
	Vector3D LocationY{ 5 , 8 , 19 };

	//std::cout << "Double precision " << sizeof(Vector3D) * 8 << std::endl;

	auto DistanceXY = Distance(LocationX, LocationY);

	auto MagnitudeX = Magnitude(LocationX);
	auto MagnitudeFromX = LocationX.Magnitude();

	Vector3D NormalizedVector = LocationY.Normalize();

	std::cout << "Distance From X to Y: " << DistanceXY << std::endl;
	std::cout << "Magnitude of X " << MagnitudeX << std::endl;
	std::cout << "Magnitude from X: " << MagnitudeFromX << std::endl;
	std::cout << "Normalized Vector Y: " << NormalizedVector.GetX() << ' ' << NormalizedVector.GetY() << ' ' << NormalizedVector.GetZ() << ' ' << std::endl;

	return 0;
}