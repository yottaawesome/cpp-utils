#pragma once
#include <string>
#include <vector>

namespace CppUtils::String
{
	std::wstring Replace(std::wstring source, const std::wstring& from, const std::wstring& to);
	void LeftTrim(std::wstring& s);
	void RightTrim(std::wstring& s);
	void Trim(std::wstring& s);
	std::wstring LeftTrimCopy(std::wstring s);
	std::wstring RightTrimCopy(std::wstring s);
	std::wstring TrimCopy(std::wstring s);
	std::vector<std::wstring> TokeniseString(const std::wstring& stringToTokenise, const std::wstring& delimiter);
}
