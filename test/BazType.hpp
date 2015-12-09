/*
 * BarType.hpp
 *
 *  Created on: 21 июля 2015 г.
 *      Author: Dmitriy Khaustov aka Dиmon (khaustov.dm@gmail.com)
 */

#if !defined BAZTYPE_HPP_ || defined ENUM_HELPER_CPP_MODE

#ifndef BAZTYPE_HPP_1
#define BAZTYPE_HPP_1
#include "../src/enum_helper_begin_hpp.h"
#endif // BAZTYPE_HPP_1

BEGIN(Baz, uint8_t)
MEMBER(Baz, ITEM1, "item-of-baz-#1")
MEMBER(Baz, ITEM2, "item-of-baz-#2")
MEMBER(Baz, ITEM3, "item-of-baz-#3")
END(Baz)

#ifndef BAZTYPE_HPP_2
#define BAZTYPE_HPP_2
#include "../src/enum_helper_end.h"
#endif // BAZTYPE_HPP_2

#endif /* !defined BAZTYPE_HPP_ || defined ENUM_HELPER_CPP_MODE */
