#include <iostream>
#include "../Include/Math.h"

#include "../Include/Vector.h"

int main()
{
	Vector3D Location{};
	Vector3D Location2{};
	std::cout << "Double precision " << sizeof(Vector3D) * 8 << std::endl;

	auto X = Distance(Location, Location2);
	return 0;
}