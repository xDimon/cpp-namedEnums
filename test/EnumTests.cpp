/*
 * EnumTests.cpp
 *
 *  Created on: 21 июля 2015 г.
 *      Author: Dmitriy Khaustov aka Dиmon (khaustov.dm@gmail.com)
 */

#include <iostream>

#include "../src/EnumString.hpp"
#include "BarType.hpp"
#include "BazType.hpp"
#include "FooType.hpp"

int main()
{
	for (auto i = -1; i < 5; i++)
	{
		std::cout << "FooStrings.get(" << i << "):\t" << FooStrings.get(i) << std::endl;
	}
	std::cout << std::endl;
	BazStrings.add("item-of-baz-additional-#1");

	std::cout << "BarStrings.get(BarType::NONE):   " << BarStrings.get(BarType::NONE) << std::endl;
	std::cout << "BarStrings.get(BarType::ITEM1):  " << BarStrings.get(BarType::ITEM1) << std::endl;
	std::cout << "BarStrings.get(BarType::ITEM2):  " << BarStrings.get(BarType::ITEM2) << std::endl;
	std::cout << "BarStrings.get(BarType::ITEM3):  " << BarStrings.get(BarType::ITEM3) << std::endl;
	std::cout << "BarStrings.get(BarType::__LAST): " << BarStrings.get(BarType::__LAST) << std::endl;
	std::cout << "BarStrings.get(BarType::___AUX): " << BarStrings.get(BarType::___AUX) << std::endl;
	std::cout << std::endl;

	BazStrings.add("item-of-baz-additional-#1");
	BazStrings.add("item-of-baz-additional-#2");
	BazStrings.add("item-of-baz-additional-#3");
	for (auto i = 0; i < 8; i++)
	{
		std::cout << "BazStrings.get(" << i << "):\t" << BazStrings.get(i) << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
