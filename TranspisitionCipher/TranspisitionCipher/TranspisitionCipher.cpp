#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::string Encryption(std::string plaintext, size_t key)
{
	std::string cyphertext = "";
	std::vector<std::vector<char>> table;

	int numrows = std::ceil(plaintext.size() / (double)key);


	for (size_t row = 0; row < numrows; row++)
	{
		table.push_back(std::vector<char>());
		for (size_t col = 0; col < key; col++)
		{
			table[row].push_back('*');
		}
	}

	int count{};
	for (size_t j = 0; j < numrows; j++)
	{
		for (size_t i = 0; i < key; i++)
		{
			if (count < plaintext.size())
			{
				table[j][i] = plaintext[count];
			}
			count++;
		}
	}

	for (size_t a = 0; a < key; a++)
	{
		for (size_t b = 0; b < numrows; b++)
		{
			auto ch = table[b][a];
			if (ch != '*')
			{
				cyphertext += ch;
			}
		}
	}
	return cyphertext;
}

//[row][column]

//std::string Decryption(std::string ciphertext, size_t key)
//{
//	std::string plaintext = "";
//	int numrows = std::ceil(ciphertext.size() / (double)key);
//	std::vector<std::vector<char>> table;
//
//	for (size_t row = 0; row < numrows; row++)
//	{
//		table.push_back(std::vector<char>());
//		for (size_t col = 0; col < key; col++)
//		{
//			table[row].push_back('*');
//		}
//	}
//
//	int count{};
//	for (size_t i = 0; i < key; i++)
//	{
//		for (size_t j = 0; j < numrows; j++)
//		{
//			if (count < ciphertext.size())
//			{
//				table[j][i] = ciphertext[count];
//				count++;
//			}
//		}
//	}
//
//	for (size_t x = 0; x < numrows; x++)
//	{
//		for (size_t y = 0; y < key; y++)
//		{
//			auto ch = table[x][y];
//			if (ch != '*')
//			{
//				plaintext += ch;
//			}
//		}
//	}
//
//	return plaintext;
//}

std::string Decryption(std::string ciphertext, int key)
{
	std::string plaintext;
	const int rows = key;
	const int columns = std::ceil(ciphertext.size() / (double)key);
	int remainder = ciphertext.size() % key;
	std::vector<std::vector<char>> table;

	for (size_t col = 0; col < columns; col++)
	{
		for (size_t row = 0; row < rows; row++)
		{
			table[row].push_back('');
			if ((columns - 1) == col && row < (rows - remainder))
			{

			}
		}
	}

	return plaintext;
}

int main()
{
	//std::vector<std::vector<char>> table;
	auto encrypted = Encryption("Common sense is not so common.", 8);
	std::cout << encrypted << "\n";
	std::cout << Decryption(encrypted, 8);
	//table.
}