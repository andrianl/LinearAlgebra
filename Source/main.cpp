#include "Vector.h"
#include <iostream>

int main()
{
	Vector3D LocationX{3, 4, 5}, LocationY{5, 6, 7};

	auto X = Distance(LocationX, LocationY);
	auto Y = Cross(LocationX, LocationY);
	auto Z = Dot(LocationX, LocationY);

	Vector2D Location2X{3, 4}, Location2Y{4, 5};

	auto X2 = Distance(Location2X, Location2Y);
	// auto Y2 = Cross(Location2X, Location2Y);
	auto Z2 = Dot(Location2X, Location2Y);

	Vector4D Location4X{3, 4, 5, 6}, Location4Y{5, 6, 7, 8};

	auto X4 = Distance(Location4X, Location4Y);

	auto Z4 = Dot(Location4X, Location4Y);

	return 0;
}