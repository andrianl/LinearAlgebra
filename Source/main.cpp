#include <iostream>
#include "Vector.h"
#include "Vector2D.h"
#include "Vector4D.h"

int main()
{
	Vector2D Location2{};
	Vector3D Location3{};
	Vector4D Location4{};


	Vector3D LocationX{ 4, 8, 12 };
	Vector3D LocationY{ 5 , 8 , 19 };

	std::cout << "Double precision " << sizeof(Vector3D) * 8 << std::endl;

	auto X = Distance(LocationX, LocationY);
	return 0;
}