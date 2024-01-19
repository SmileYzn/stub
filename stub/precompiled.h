#pragma once

// Disable security function warnings (MSVC)
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

// If is not MSVC build
#ifndef _WIN32
#define _GLIBCXX_USE_CXX11_ABI		0
#define _stricmp					strcasecmp
#define _strnicmp					strncasecmp
#define _strdup						strdup
#define _unlink						unlink
#define _vsnprintf					vsnprintf
#define _write						write
#define _close						close
#define _acces						access
#define _vsnwprintf					vswprintf
#endif

// Standard library
#include <string>
#include <vector>
#include <map>
#include <array>

// System Includes
#ifndef _WIN32
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#else
#include <direct.h>
#endif

// CSSDK (ReHLDS SDK)
#include <extdll.h>
#include <eiface.h>

// MetaMod SDK
#include <meta_api.h> 

// ReHLDS Api
#include <rehlds_api.h>
#include <rehlds_interfaces.h>

// ReGameDLL Api
#include <regamedll_api.h>
#include <regamedll_const.h>

// Plugin Includes
#include "MetaMod.h"
#include "MetaDLL.h"
#include "MetaEngine.h"

// ReAPI & ReGameAPI
#include "ReAPI.h"
#include "ReGameAPI.h"

// Stub
#include "stub.h"