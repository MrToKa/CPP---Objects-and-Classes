#include <iomanip>
#include <iostream>
#include <cmath>

class Point
{
	double x, y;

public:

	Point(double x_ = 0, double y_ = 0)
	{
		this->x = x_;
		this->y = y_;
	}

	Point(std::istream& in)
	{
		in >> this->x >> this->y;
	}

	double getEucledianDistance(const Point& other) const
	{
		double dx = this->x - other.x;
		double dy = this->y - other.y;

		return sqrt(dx * dx + dy * dy);
	}
};

int main()
{
	Point p1, p2;

	p1 = Point(std::cin);
	p2 = Point(std::cin);

	std::cout << std::fixed << std::setprecision(3) << p1.getEucledianDistance(p2) << std::endl;
}
