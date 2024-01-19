#include "precompiled.h"
#include "interface.cpp"

IRehldsApi* g_ReAPI_Api;
const RehldsFuncs_t* g_ReAPI_Funcs;
IRehldsServerData* g_ReAPI_ServerData;
IRehldsHookchains* g_ReAPI_Hookchains;
IRehldsServerStatic* g_ReAPI_ServerStatic;

void ReAPI_Init()
{
	if (g_engfuncs.pfnIsDedicatedServer())
	{
		CSysModule* engineModule = nullptr;

#ifdef WIN32
		const std::vector<std::string> dllNames = { "swds.dll", "hw.dll", "sw.dll" };

		for (auto const & dll : dllNames)
		{
			if (engineModule = Sys_GetModuleHandle(dll.c_str()))
			{
				break;
			}
		}
#else
		engineModule = Sys_LoadModule("engine_i486.so");
#endif

		if (engineModule)
		{
			auto ifaceFactory = Sys_GetFactory(engineModule);

			if (ifaceFactory)
			{
				int retCode = 0;

				g_ReAPI_Api = (IRehldsApi*)ifaceFactory(VREHLDS_HLDS_API_VERSION, &retCode);

				if (g_ReAPI_Api)
				{
					if (g_ReAPI_Api->GetMajorVersion() == REHLDS_API_VERSION_MAJOR)
					{
						if (g_ReAPI_Api->GetMinorVersion() >= REHLDS_API_VERSION_MINOR)
						{
							g_ReAPI_Funcs = g_ReAPI_Api->GetFuncs();
							
							g_ReAPI_ServerData = g_ReAPI_Api->GetServerData();
							
							g_ReAPI_Hookchains = g_ReAPI_Api->GetHookchains();
							
							g_ReAPI_ServerStatic = g_ReAPI_Api->GetServerStatic();

							if (g_ReAPI_Hookchains)
							{
								// Register hooks here
							}

							return;
						}
					}
				}
			}
		}
	}

	gpMetaUtilFuncs->pfnLogConsole(&Plugin_info, "[%s] ReHLDS API failed to load.", Plugin_info.logtag);
	gpMetaUtilFuncs->pfnLogConsole(&Plugin_info, "[%s] ReHLDS API version required: %d.%d", Plugin_info.logtag, REHLDS_API_VERSION_MAJOR, REHLDS_API_VERSION_MINOR);
}

void ReAPI_Stop()
{
	if (g_ReAPI_Hookchains)
	{
		// Unregister hooks here
	}
}

