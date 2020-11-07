#pragma once
#include <vector>
#include <functional>
#include <algorithm>
#include <optional>

namespace CppUtils::Vector
{
	//https://thispointer.com/c-how-to-find-an-element-in-vector-and-get-its-index/

	template<typename T>
	std::optional<size_t> IndexOf(std::vector<T>& v, const std::function<bool(const T&)> predicate)
	{
		auto iter = std::find_if(v.begin, v.end(), predicate);
		if (iter == v.end())
			return std::nullopt_t;
		return std::distance(v.begin(), iter);
	}

	template<typename T>
	uint64_t IndexOf(std::vector<T>& v, const T& elem)
	{
		auto iter = std::find(v.begin, v.end(), elem);
		if (iter == v.end())
			return -1;
		return std::distance(v.begin(), iter);
	}
	
	template<typename T>
	bool HasElement(std::vector<T>& v, const T& elem)
	{
		return IndexOf(v, elem) != -1;
	}

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
