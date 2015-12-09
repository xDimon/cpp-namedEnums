/*
 * EnumString.cpp
 *
 *  Created on: 19 июня 2015 г.
 *      Author: Dmitriy Khaustov aka Dиmon (khaustov.dm@gmail.com)
 */

#include "EnumString.hpp"

#include <stdlib.h>
#include <sys/types.h>

template <typename T>
EnumString<T>::EnumString()
{
	memset(_num2str, 0, sizeof(_num2str));
	memset(_freq, 0, sizeof(_freq));
}

template <typename T>
EnumString<T>::EnumString(std::initializer_list<std::pair<uint64_t, const char *>> list)
: EnumString()
{
	for (auto item : list)
	{
		if (item.first >= static_cast<T>(-1)+1)
		{
			throw "Overflow by enum";
		}
		if (_num2str[item.first])
		{
			throw "Duplicate by enum";
		}
		if (_str2num.find(item.second) != _str2num.end())
		{
			throw "Duplicate by string";
		}

		_num2str[item.first] = strdup(item.second);
		_str2num.insert(std::make_pair(_num2str[item.first], item.first));
	}

	uint8_t num = 0;
	do
	{
		if (!_num2str[num]) break;
	}
	while (++num);

	_lastNum = num;

	do
	{
		if (_num2str[num])
		{
			throw "Recognized passed element";
		}
	}
	while (++num);
}

template <typename T>
EnumString<T>::~EnumString()
{
	for (uint64_t num = 0; num <= _lastNum; num++)
	{
		free(_num2str[num]);
	}
}

template <typename T>
T EnumString<T>::numByString(const char *str, size_t len, bool addIfNotExists = true)
{
	uint64_t num;
	if (str == nullptr || *str == 0)
	{
		return 0;
	}

	char *str2 = len ? strndup(str, len) : nullptr;

	auto i = _str2num.find(str2?str2:str);
	if (i != _str2num.end())
	{
		num = i->second;

		_freq[num]++;

		if (len) free(str2);
		return num;
	}

	if (!addIfNotExists)
	{
		free(str2);
		return 0;
	}

	num = _lastNum;

	do
	{
		if (num >= static_cast<T>(-1))
		{
			free(str2);
			throw "Too many string identifier";
			return 0;
		}

		if (!_num2str[num]) break;
	}
	while (num++);

	_lastNum = num;

	_num2str[num] = str2 ? str2 : strdup(str);

	_str2num.insert(std::make_pair(_num2str[num], num));

	return num;
}

template <typename T>
const char *EnumString<T>::stringByNum(T num)
{
	return (num > _lastNum || !_num2str[num]) ? "_undefined" : _num2str[num];
}

template class EnumString<uint8_t>;
template class EnumString<uint16_t>;
