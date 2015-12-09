/*
 * FooType.hpp
 *
 *  Created on: 21 июля 2015 г.
 *      Author: Dmitriy Khaustov aka Dиmon (khaustov.dm@gmail.com)
 */

#if !defined FOOTYPE_HPP_ || defined ENUM_HELPER_CPP_MODE

#ifndef FOOTYPE_HPP_1
#define FOOTYPE_HPP_1
#include "../src/enum_helper_begin_hpp.h"
#endif // FOOTYPE_HPP_1

BEGIN(Foo, uint8_t)
MEMBER(Foo, ITEM1, "item-of-foo-#1")
MEMBER(Foo, ITEM2, "item-of-foo-#2")
MEMBER(Foo, ITEM3, "item-of-foo-#3")
END(Foo)

#ifndef FOOTYPE_HPP_2
#define FOOTYPE_HPP_2
#include "../src/enum_helper_end.h"
#endif // FOOTYPE_HPP_2

#endif // !defined FOOTYPE_HPP_ || defined ENUM_HELPER_CPP_MODE
