#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include "Enum.h"
#include <Windows.h>

template <typename T>
static inline void SAFE_DELETE(T*& p)
{
	if (p)
	{
		delete p;
		p = nullptr;
	}
};