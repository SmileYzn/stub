#pragma once

#ifndef _WIN32
#define _GLIBCXX_USE_CXX11_ABI 0
#define _stricmp strcasecmp
#define _strnicmp strncasecmp
#define _strdup strdup
#define _unlink unlink
#define _vsnprintf vsnprintf
#define _write write
#define _close close
#define _acces access
#define _vsnwprintf vswprintf
#endif

#ifdef _WIN32
#pragma warning(disable: 4100)
#pragma warning(disable: 4996)
#endif

// System
#include <osconfig.h>

// C++
#include <map>
#include <vector>
#include <string>
#include <array>

// CSSDK
#include <extdll.h>
#include <eiface.h>

// MetaMod SDK
#include <meta_api.h>

// ReHLDS Api
#include <rehlds_api.h>

// ReGameDLL Api
#include <regamedll_api.h>

// Metamod Includes
#include "MetaMod.h"

// ReAPI & ReGameDLL
#include "ReAPI.h"
#include "ReGameDLL.h"

// Stub
#include "Stub.h"