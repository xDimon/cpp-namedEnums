/*
 * enum_helper_hpp_begin.h
 *
 *  Created on: 21 июля 2015 г.
 *      Author: Dmitriy Khaustov aka Dиmon (khaustov.dm@gmail.com)
 */

#ifndef ENUM_HELPER_CPP_MODE

#include "EnumString.hpp"

#define BEGIN(TYPE, BASETYPE) extern EnumString<BASETYPE> TYPE##Strings; enum class TYPE##Type : BASETYPE { NONE = 0,
#define MEMBER(TYPE, NAME, STR) NAME,
#define END(TYPE) ___AUX, __LAST = ___AUX-1};

#endif /* ENUM_HELPER_CPP_MODE */
