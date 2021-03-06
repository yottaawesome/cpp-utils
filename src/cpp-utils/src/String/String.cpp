#include "pch.hpp"
#include <string>
#include "include/CppUtils.hpp"

namespace CppUtils::String
{
	// Adapted from https://stackoverflow.com/a/29752943/7448661
	std::wstring Replace(std::wstring source, const std::wstring& from, const std::wstring& to)
    {
        std::wstring newString;
        newString.reserve(source.length());

        std::wstring::size_type lastPos = 0;
        std::wstring::size_type findPos;

        while (std::wstring::npos != (findPos = source.find(from, lastPos)))
        {
            newString.append(source, lastPos, findPos - lastPos);
            newString += to;
            lastPos = findPos + from.length();
        }

        newString += source.substr(lastPos);

        return newString;
    }

    // trim from start (in place)
    void LeftTrim(std::wstring& s)
    {
        s.erase(
            s.begin(),
            std::find_if(
                s.begin(),
                s.end(),
                [](int ch) { return !std::isspace(ch); }
            )
        );
    }

    // trim from end (in place)
    void RightTrim(std::wstring& s)
    {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
            return !std::isspace(ch);
            }).base(), s.end());
    }

    // trim from both ends (in place)
    void Trim(std::wstring& s)
    {
        LeftTrim(s);
        RightTrim(s);
    }

    // trim from start (copying)
    std::wstring LeftTrimCopy(std::wstring s)
    {
        LeftTrim(s);
        return s;
    }

    // trim from end (copying)
    std::wstring RightTrimCopy(std::wstring s)
    {
        RightTrim(s);
        return s;
    }

    // trim from both ends (copying)
    std::wstring TrimCopy(std::wstring s)
    {
        Trim(s);
        return s;
    }

    std::vector<std::wstring> TokeniseString(const std::wstring& stringToTokenise, const std::wstring& delimiter)
    {
        std::vector<std::wstring> results;
        size_t position = 0;
        std::wstring intermediateString = stringToTokenise;

        // If we don't find it at all, add the whole string
        if (stringToTokenise.find(delimiter, position) == std::string::npos)
        {
            results.push_back(stringToTokenise);
        }
        else
        {
            while ((position = intermediateString.find(delimiter, position)) != std::string::npos)
            {
                // split and add to the results
                std::wstring split = stringToTokenise.substr(0, position);
                results.push_back(split);

                // move up our position
                position += delimiter.length();
                intermediateString = stringToTokenise.substr(position);

                // On the last iteration, enter the remainder
                if (intermediateString.find(delimiter, position) == std::string::npos)
                    results.push_back(intermediateString);
            }
        }

        return results;
    }
}
