#include "Vector.h"

int main()
{
	Vector3D LocationX{ 3,4,5 }, LocationY{ 5,6,7 };

	auto X = Distance(LocationX, LocationY);

	auto Y = Cross(LocationX, LocationY);
	auto Z = Dot(LocationX, LocationY);

	return 0;
}