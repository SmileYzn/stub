#pragma once

extern IReGameApi* g_ReGameAPI_Api;
extern const ReGameFuncs_t* g_ReGameAPI_Funcs;
extern IReGameHookchains* g_ReGameAPI_Hookchains;
extern CGameRules* g_ReGameAPI_Rules;

extern void ReGameAPI_Init();
extern void ReGameAPI_Stop();

extern CGameRules* ReGameAPI_InstallGameRules(IReGameHook_InstallGameRules* chain);
