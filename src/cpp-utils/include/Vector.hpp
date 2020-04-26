#pragma once
#include <vector>
#include <functional>

namespace CppUtils::Vector
{
	template<typename T>
	void FindIn(std::vector<T>& results, const std::vector<T>& search, const std::function<bool(const T&)>& predicate)
	{
		auto iter = search.begin();
		while (iter != search.end())
		{
			iter = std::find_if(iter, search.end(), predicate);
			if (iter != search.end())
			{
				results.push_back(*iter);
				iter++;
			}
		}
	}
}
