// This file is part of nbind, copyright (C) 2014-2016 BusFaster Ltd.
// Released under the MIT license, see LICENSE.

#pragma once

#include "nbind/export.h"

namespace nbind {

std::forward_list<BindClassBase *>& nbind_api getClassList(void);
nbind_api std::forward_list<MethodDef>& getFunctionList(void);
const nbind_api void** getPrimitiveList(void);
nbind_api const void** getNamedTypeList(void);

void nbind_api registerClass(BindClassBase &bindClass);
void nbind_api registerFunction(
	const char *name,
	funcPtr ptr,
	unsigned int num,
	BaseSignature *signature,
	TypeFlags flags
);

} // namespace
