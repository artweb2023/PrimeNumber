#include <iostream>
#include <set>
#include <vector>


constexpr int firstPrimeNum = 2;

std::set<int> GeneratePrimeNumbersSet(int lowerBound, int upperBound)
{
	std::set<int> primeNumbers;
	if (upperBound < 2)
	{
		return primeNumbers;
	}
	if (lowerBound < 2)
	{
		primeNumbers.insert(2);
		lowerBound = 3;
	}
	std::vector<bool> sieve(upperBound + 1, true);
	if (lowerBound % 2 == 0)
	{
		lowerBound++;
	}
	for (auto i = lowerBound; i <= upperBound; i += 2)
	{
		if (sieve[i])
		{
			primeNumbers.insert(i);
			if (i <= std::sqrt(upperBound))
			{
				for (auto j = i * i; j <= upperBound; j += i)
				{
					sieve[j] = false;
				}
			}
		}
	}
	return primeNumbers;
}

void PrintPrimeNumber(const std::set<int>& primeNumbersSet)
{
	if (primeNumbersSet.empty())
	{
		std::cout << "No prime numbers!" << std::endl;
	}
	for (auto primeNumber : primeNumbersSet)
	{
		std::cout << primeNumber << " ";
	}
	std::cout << '\n';
}

int main()
{
	int lowerBound;
	int upperBound;
	std::cin >> lowerBound;
	std::cin >> upperBound;
	PrintPrimeNumber(GeneratePrimeNumbersSet(lowerBound, upperBound));
	return 0;
}

