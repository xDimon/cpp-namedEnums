/*
 * BarType.hpp
 *
 *  Created on: 21 июля 2015 г.
 *      Author: Dmitriy Khaustov aka Dиmon (khaustov.dm@gmail.com)
 */

#if !defined BARTYPE_HPP_ || defined ENUM_HELPER_CPP_MODE

#ifndef BARTYPE_HPP_1
#define BARTYPE_HPP_1
#include "../src/enum_helper_begin_hpp.h"
#endif // BARTYPE_HPP_1

BEGIN(Bar, uint16_t)
MEMBER(Bar, ITEM1, "item-of-bar-#1")
MEMBER(Bar, ITEM2, "item-of-bar-#2")
MEMBER(Bar, ITEM3, "item-of-bar-#3")
END(Bar)

#ifndef BARTYPE_HPP_2
#define BARTYPE_HPP_2
#include "../src/enum_helper_end.h"
#endif // BARTYPE_HPP_2

#endif /* !defined BARTYPE_HPP_ || defined ENUM_HELPER_CPP_MODE */
