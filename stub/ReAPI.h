#pragma once

extern IRehldsApi* g_ReAPI_Api;
extern const RehldsFuncs_t* g_ReAPI_Funcs;
extern IRehldsServerData* g_ReAPI_ServerData;
extern IRehldsHookchains* g_ReAPI_Hookchains;
extern IRehldsServerStatic* g_ReAPI_ServerStatic;

extern void ReAPI_Init();
extern void ReAPI_Stop();
