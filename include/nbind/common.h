// This file is part of nbind, copyright (C) 2014-2016 BusFaster Ltd.
// Released under the MIT license, see LICENSE.

#pragma once

#include "export.h"

namespace nbind {

std::forward_list<BindClassBase *> & nbind_api getClassList(void);
std::forward_list<MethodDef> & nbind_api getFunctionList(void);
const void ** nbind_api getPrimitiveList(void);
const void ** nbind_api getNamedTypeList(void);

void nbind_api registerClass(BindClassBase &bindClass);
void nbind_api registerFunction(
	const char *name,
	funcPtr ptr,
	unsigned int num,
	BaseSignature *signature,
	TypeFlags flags
);

} // namespace
