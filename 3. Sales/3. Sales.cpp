#include <iomanip>
#include <iostream>
#include <map>
#include <vector>

class Sale
{
	std::string town;
	std::string product;
	double price;
	double quantity;

public:
	Sale(std::string town, std::string product, double price, double quantity)
	{
		this->town = town;
		this->product = product;
		this->price = price;
		this->quantity = quantity;
	}

	std::string getTown()
	{
		return this->town;
	}

	std::string getProduct()
	{
		return this->product;
	}

	double getPrice()
	{
		return this->price;
	}

	double getQuantity()
	{
		return this->quantity;
	}

	Sale(std::istream& in)
	{
		in >> this->town >> this->product >> this->price >> this->quantity;
	}
};

int main()
{
	std::map<std::string, double> salesByTown;

	int salesCount;
	std::cin >> salesCount;
	while (salesCount)
	{
		Sale sale(std::cin);
		salesByTown[sale.getTown()] += sale.getPrice() * sale.getQuantity();
		salesCount--;
	}

	//print sales by town
	for (auto sale : salesByTown)
	{
		std::cout << sale.first << " -> " << std::fixed << std::setprecision(2) << sale.second << std::endl;
	}

	return 0;
}
