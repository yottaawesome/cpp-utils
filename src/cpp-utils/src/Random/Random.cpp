#include "pch.hpp"
#include <random>
#include "include/CppUtils.hpp"

namespace CppUtils::Random
{
	int GeneratePseudorandomInt(const int lower, const int upper)
	{
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(2000, 6000);
		return dist6(rng);
	}
}