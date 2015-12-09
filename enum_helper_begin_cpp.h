/*
 * enum_helper_cpp_begin.h
 *
 *  Created on: 21 июля 2015 г.
 *      Author: Dmitriy Khaustov aka Dиmon (khaustov.dm@gmail.com)
 */

#include <utility>

#define ENUM_HELPER_CPP_MODE

#define BEGIN(TYPE,BASETYPE) EnumString<BASETYPE> TYPE##Strings({
#define MEMBER(TYPE,NAME,STR) std::make_pair(static_cast<uint64_t>(TYPE##Type::NAME), STR),
#define END(TYPE) std::make_pair(static_cast<uint64_t>(TYPE##Type::NONE), "none")});
