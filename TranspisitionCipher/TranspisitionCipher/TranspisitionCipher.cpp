#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::string Encryption(std::string plaintext, size_t length)
{
	std::string cyphertext = "";
	std::vector<std::vector<char>> table;

	int numrows = std::ceil(plaintext.size() / (double)length);


	for (size_t row = 0; row < numrows; row++)
	{
		table.push_back(std::vector<char>());
		for (size_t col = 0; col < length; col++)
		{
			table[row].push_back('*');
		}
	}

	int count{};
	for (size_t j = 0; j < numrows; j++)
	{
		for (size_t i = 0; i < length; i++)
		{
			if (count <= plaintext.size())
			{
				table[j][i] = plaintext[count];
			}
			count++;
		}
	}
	return cyphertext;
}

int main()
{
	//std::vector<std::vector<char>> table;
	std::cout << Encryption("Common sense is not so common.", 8);
	//table.
}