// This file is part of nbind, copyright (C) 2014-2015 BusFaster Ltd.
// Released under the MIT license, see LICENSE.

#pragma once

#ifdef BUILDING_NODE_EXTENSION

#include "Binding.h"

// Support overloading macros by number of arguments.
// See http://stackoverflow.com/a/16683147/16509

// _1, _2... are dummy parameters to discard original macro arguments.
#define VA_SIZE_HELPER(_3, _2, _1, ARGC, ...) ARGC
#define VA_SIZE(...) VA_SIZE_HELPER(__VA_ARGS__, 3, 2, 1)

#define VA_CONCAT(A, B) A ## B

#define VA_SELECT_HELPER(NAME, ARGC) VA_CONCAT(NAME ## _, ARGC)
#define VA_SELECT(NAME, ...) VA_SELECT_HELPER(NAME, VA_SIZE(__VA_ARGS__))(__VA_ARGS__)

// Define bindings for a C++ class using a syntax that looks like a function definition.

#define NBIND_CLASS(Name) \
	template<class Bound> struct BindInvoker##Name { \
		BindInvoker##Name(); \
		nbind::BindClass<Name> linkage; \
		nbind::BindDefiner<Name> definer; \
	}; \
	static struct BindInvoker##Name<Name> bindInvoker##Name; \
	template<class Bound> BindInvoker##Name<Bound>::BindInvoker##Name():definer(#Name)

// Define a method passing its name, and optionally the original C++ method name
// if the name visible to JavaScript should be different.

#define method_1(name) definer.function(#name, &Bound::name)
#define method_2(name, boundName) definer.function(#name, &Bound::boundName)
#define method(...) VA_SELECT(method, __VA_ARGS__)

// Define a constructor.
// Constructor argument types must be appended as template arguments like:
// construct<int, int>()

#define construct definer.constructor

#define field(name) definer.field(#name, &Bound::name)
#define getter(name) definer.property(#name, &Bound::name)
// TODO: varargs macro also supporting this:
//#define getter(name, get) definer.property(#name, &Bound::get)
#define getset(getName, setName) definer.property(#getName, &Bound::getName, &Bound::setName)
// TODO: varargs macro also supporting this:
// #define getset(name, get, set) definer.property(#name, &Bound::get, &Bound::set)

#define NBIND_INIT(moduleName) NODE_MODULE(moduleName, nbind::Bindings::initModule)

#endif
