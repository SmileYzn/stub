#include "precompiled.h"
#include "interface.cpp"

CReAPI gReAPI;

bool CReAPI::Init()
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

				this->m_API = (IRehldsApi*)ifaceFactory(VREHLDS_HLDS_API_VERSION, &retCode);

				if (this->m_API)
				{
					if (this->m_API->GetMajorVersion() == REHLDS_API_VERSION_MAJOR)
					{
						if (this->m_API->GetMinorVersion() >= REHLDS_API_VERSION_MINOR)
						{
							this->m_Funcs = this->m_API->GetFuncs();
							
							this->m_Data = this->m_API->GetServerData();
							
							this->m_Hookchains = this->m_API->GetHookchains();
							
							this->m_Server_Static = this->m_API->GetServerStatic();

							return true;
						}
					}
				}
			}
		}
	}

	gpMetaUtilFuncs->pfnLogConsole(&Plugin_info, "[%s] ReHLDS API failed to load.", Plugin_info.logtag);
	gpMetaUtilFuncs->pfnLogConsole(&Plugin_info, "[%s] ReHLDS API version required: %d.%d", Plugin_info.logtag, REHLDS_API_VERSION_MAJOR, REHLDS_API_VERSION_MINOR);
	
	return false;
}

bool CReAPI::Stop()
{
	return false;
}

