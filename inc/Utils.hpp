#pragma once

namespace bnk::utils
{
	struct Point
	{
		float x;
		float y;
	};

	struct Vector
	{
		float x;
		float y;
	};

	float Distance(Point point1, Point point2);

}