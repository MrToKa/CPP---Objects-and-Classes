#ifndef COMPANYMEMORYUTILS_H
#define COMPANYMEMORYUTILS_H

std::vector<Company> readCompaniesFromMemory(const unsigned char* memory, int numCompanies)
{
	std::vector<Company> companies;

	int currentByte = 0;
	for (int i = 0; i < numCompanies; i++)
	{

		int id = memory[currentByte];
		currentByte++;

		/*int nameLength = memory[currentByte];
		currentByte++;*/

		std::string name = "";
		while (memory[currentByte] != 0)
		{
			name += memory[currentByte];
			currentByte++;
		}
		currentByte++;

		int numEmployees = memory[currentByte];
		currentByte++;

		std::vector<std::pair<char, char> > employees;
		for (int j = 0; j < numEmployees; j++)
		{
			char firstInitial = memory[currentByte];
			currentByte++;

			char secondInitial = memory[currentByte];
			currentByte++;

			employees.push_back(std::make_pair(firstInitial, secondInitial));
		}

		companies.push_back(Company(id, name, employees));
	}

	return companies;
}

#endif
