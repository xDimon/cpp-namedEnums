/*
 * EnumString.hpp
 *
 *  Created on: 19 июня 2015 г.
 *      Author: Dmitriy Khaustov aka Dиmon (khaustov.dm@gmail.com)
 */

#ifndef XDIMON_TYPES_ENUM_ENUMSTRING_HPP_
#define XDIMON_TYPES_ENUM_ENUMSTRING_HPP_

#include <stddef.h>
#include <cstdint>
#include <cstring>
#include <map>
#include <utility>

template <typename T>
class EnumString
{
	static_assert(std::is_same<T, uint8_t>::value || std::is_same<T, uint16_t>::value, "Bad type for EnumString base type");

private:
	struct cmpr
	{
		bool operator()(const char * x, const char * y) const
		{
			return strcasecmp(x, y) < 0;
		}
	};

	char *_num2str[static_cast<T>(-1)+1];
	std::map<const char *, T, cmpr> _str2num;
	T _lastNum = 0;
	uint16_t _freq[static_cast<T>(-1)+1];

	const char *stringByNum(T num);
	T numByString(const char *str, size_t len, bool addIfNotExists);

public:
	typedef T keyType;

	EnumString();
	EnumString(std::initializer_list<std::pair<uint64_t, const char *>>);
	virtual ~EnumString();

	inline T add(const char *str, size_t len)
	{
		return numByString(str, len, true);
	}
	inline T add(const char *str)
	{
		return numByString(str, 0, true);
	}
	inline T get(const char *str, size_t len)
	{
		return numByString(str, len, false);
	}
	inline T get(const char *str)
	{
		return numByString(str, 0, false);
	}
	inline T get(char *str)
	{
		return numByString(str, 0, false);
	}
	template <typename t>
	inline const char *get(t num)
	{
		return stringByNum(static_cast<T>(num));
	}
};

#endif // XDIMON_TYPES_ENUM_ENUMSTRING_HPP_
