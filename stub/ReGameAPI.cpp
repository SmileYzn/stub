#include "precompiled.h"

IReGameApi* g_ReGameAPI_Api;
const ReGameFuncs_t* g_ReGameAPI_Funcs;
IReGameHookchains* g_ReGameAPI_Hookchains;
CGameRules* g_ReGameAPI_Rules;

void ReGameAPI_Init()
{
	auto szGameDLLModule = gpMetaUtilFuncs->pfnGetGameInfo(&Plugin_info, GINFO_DLL_FULLPATH);

	if (szGameDLLModule)
	{
		auto GameModule = Sys_LoadModule(szGameDLLModule);

		if (GameModule)
		{
			auto ifaceFactory = Sys_GetFactory(GameModule);

			if (ifaceFactory)
			{
				auto retCode = 0;

				g_ReGameAPI_Api = (IReGameApi*)ifaceFactory(VRE_GAMEDLL_API_VERSION, &retCode);

				if (g_ReGameAPI_Api)
				{
					if (g_ReGameAPI_Api->GetMajorVersion() == REGAMEDLL_API_VERSION_MAJOR)
					{
						if (g_ReGameAPI_Api->GetMinorVersion() >= REGAMEDLL_API_VERSION_MINOR)
						{
							if (g_ReGameAPI_Api->BGetICSEntity(CSENTITY_API_INTERFACE_VERSION))
							{
								if (g_ReGameAPI_Api->BGetIGameRules(GAMERULES_API_INTERFACE_VERSION))
								{
									g_ReGameAPI_Funcs = g_ReGameAPI_Api->GetFuncs();

									g_ReGameAPI_Hookchains = g_ReGameAPI_Api->GetHookchains();

									if (g_ReGameAPI_Hookchains)
									{
										g_ReGameAPI_Hookchains->InstallGameRules()->registerHook(ReGameAPI_InstallGameRules);
									}
								}

								return;
							}
						}
					}
				}
			}
		}
	}

	gpMetaUtilFuncs->pfnLogConsole(&Plugin_info, "[%s] ReGameDLL_CS API failed to load.", Plugin_info.logtag);
	gpMetaUtilFuncs->pfnLogConsole(&Plugin_info, "[%s] ReGameDLL_CS API version required: %d.%d", Plugin_info.logtag, REGAMEDLL_API_VERSION_MAJOR, REGAMEDLL_API_VERSION_MINOR);
}

void ReGameAPI_Stop()
{
	if (g_ReGameAPI_Hookchains)
	{
		g_ReGameAPI_Hookchains->InstallGameRules()->unregisterHook(ReGameAPI_InstallGameRules);
	}
}

CGameRules* ReGameAPI_InstallGameRules(IReGameHook_InstallGameRules* chain)
{
	g_ReGameAPI_Rules = chain->callNext();

	return g_ReGameAPI_Rules;
}