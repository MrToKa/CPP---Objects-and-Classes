#include <iostream>
#include <vector>

class Student
{
	std::string name;
	std::string surname;
	double average;

public:
	Student(std::string name, std::string surname, double average)
	{
		this->name = name;
		this->surname = surname;
		this->average = average;
	}

	std::string getName()
	{
		return name;
	}

	std::string getSurname()
	{
		return surname;
	}

	double getAverage() const
	{
		return average;
	}

	void print() const
	{
		std::cout << name << " " << surname << " " << average << std::endl;
	}

};

int main()
{
	std::vector<Student> students;

	int totalStudents;
	std::cin >> totalStudents;

	if (totalStudents <= 0)
	{
		std::cout << "Invalid input" << std::endl;
		return 0;
	}

	while (totalStudents)
	{
		std::string name;
		std::string surname;
		double average;

		std::cin >> name >> surname >> average;

		students.emplace_back(name, surname, average);		

		totalStudents--;
	}

	double totalAverage = 0;

	for (const auto& student : students)
	{
		student.print();
		totalAverage += student.getAverage();
	}

	std::cout << totalAverage / students.size() << std::endl;


	return 0;
}
