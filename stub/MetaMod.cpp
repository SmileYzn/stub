#include "precompiled.h"

#pragma region METAMOD
plugin_info_t Plugin_info =
{
	META_INTERFACE_VERSION,
	"Stub Plugin",
	"0.0.1",
	__DATE__,
	"SmileY",
	"https://github.com/SmileYzn/stub",
	"STUB",
	PT_STARTUP,
	PT_ANYTIME,
};

enginefuncs_t g_engfuncs;
globalvars_t *gpGlobals;
meta_globals_t *gpMetaGlobals;
gamedll_funcs_t *gpGamedllFuncs;
mutil_funcs_t *gpMetaUtilFuncs;
META_FUNCTIONS gMetaFunctionTable;

C_DLLEXPORT void WINAPI GiveFnptrsToDll(enginefuncs_t *pengfuncsFromEngine, globalvars_t *pGlobals)
{
	memcpy(&g_engfuncs, pengfuncsFromEngine, sizeof(enginefuncs_t));
	
	gpGlobals = pGlobals;
}

C_DLLEXPORT int Meta_Attach(PLUG_LOADTIME now, META_FUNCTIONS *pFunctionTable, meta_globals_t *pMGlobals, gamedll_funcs_t *pGamedllFuncs)
{
	gpMetaGlobals = pMGlobals;

	gpGamedllFuncs = pGamedllFuncs;

	memset(&gMetaFunctionTable, 0, sizeof(META_FUNCTIONS));

	gMetaFunctionTable.pfnGetEntityAPI2 = GetEntityAPI2;

	gMetaFunctionTable.pfnGetEntityAPI2_Post = GetEntityAPI2_Post;

	gMetaFunctionTable.pfnGetEngineFunctions = GetEngineFunctions;

	gMetaFunctionTable.pfnGetEngineFunctions_Post = GetEngineFunctions_Post;

	gMetaFunctionTable.pfnGetNewDLLFunctions = GetNewDLLFunctions;

	gMetaFunctionTable.pfnGetNewDLLFunctions_Post = GetNewDLLFunctions_Post;

	memcpy(pFunctionTable, &gMetaFunctionTable, sizeof(META_FUNCTIONS));

	ReAPI_Init();

	ReGameDLL_Init();

	return TRUE;
}

C_DLLEXPORT int Meta_Detach(PLUG_LOADTIME now, PL_UNLOAD_REASON reason)
{
	ReAPI_Stop();

	ReGameDLL_Stop();

	return TRUE;
}

C_DLLEXPORT int Meta_Query(char *interfaceVersion, plugin_info_t **pPlugInfo, mutil_funcs_t *pMetaUtilFuncs)
{
	*pPlugInfo = PLID;

	gpMetaUtilFuncs = pMetaUtilFuncs;

	return TRUE;
}
#pragma endregion

#pragma region META_DLL_PRE
DLL_FUNCTIONS g_DLL_FunctionTable_Pre;

C_DLLEXPORT int GetEntityAPI2(DLL_FUNCTIONS *pFunctionTable, int *interfaceVersion)
{
	memset(&g_DLL_FunctionTable_Pre, 0, sizeof(DLL_FUNCTIONS));

	// Funtion hooks here

	memcpy(pFunctionTable, &g_DLL_FunctionTable_Pre, sizeof(DLL_FUNCTIONS));

	return 1;
}
#pragma endregion

#pragma region META_DLL_POST
DLL_FUNCTIONS g_DLL_FunctionTable_Post;

C_DLLEXPORT int GetEntityAPI2_Post(DLL_FUNCTIONS *pFunctionTable, int *interfaceVersion)
{
	memset(&g_DLL_FunctionTable_Post, 0, sizeof(DLL_FUNCTIONS));

	// Funtion hooks here

	memcpy(pFunctionTable, &g_DLL_FunctionTable_Post, sizeof(DLL_FUNCTIONS));

	return 1;
}
#pragma endregion

#pragma region NEW_DLL_PRE
NEW_DLL_FUNCTIONS g_DLL_NewFunctionTable_Pre;

C_DLLEXPORT int GetNewDLLFunctions(NEW_DLL_FUNCTIONS *pNewFunctionTable, int *interfaceVersion)
{
	memset(&g_DLL_NewFunctionTable_Pre, 0, sizeof(NEW_DLL_FUNCTIONS));

	// Funtion hooks here

	memcpy(pNewFunctionTable, &g_DLL_NewFunctionTable_Pre, sizeof(NEW_DLL_FUNCTIONS));

	return 1;
}
#pragma endregion

#pragma region NEW_DLL_POST
NEW_DLL_FUNCTIONS g_DLL_NewFunctionTable_Post;

C_DLLEXPORT int GetNewDLLFunctions_Post(NEW_DLL_FUNCTIONS *pNewFunctionTable, int *interfaceVersion)
{
	memset(&g_DLL_NewFunctionTable_Post, 0, sizeof(NEW_DLL_FUNCTIONS));

	// Funtion hooks here

	memcpy(pNewFunctionTable, &g_DLL_NewFunctionTable_Post, sizeof(NEW_DLL_FUNCTIONS));

	return 1;
}
#pragma endregion

#pragma region ENGINE_PRE
enginefuncs_t g_ENGINE_FunctionTable_Pre;

C_DLLEXPORT int GetEngineFunctions(enginefuncs_t *pengfuncsFromEngine, int *interfaceVersion)
{
	memset(&g_ENGINE_FunctionTable_Pre, 0, sizeof(enginefuncs_t));

	// Funtion hooks here

	memcpy(pengfuncsFromEngine, &g_ENGINE_FunctionTable_Pre, sizeof(enginefuncs_t));

	return 1;
}
#pragma endregion

#pragma region ENGINE_POST
enginefuncs_t g_ENGINE_FunctionTable_Post;

C_DLLEXPORT int GetEngineFunctions_Post(enginefuncs_t *pengfuncsFromEngine, int *interfaceVersion)
{
	memset(&g_ENGINE_FunctionTable_Post, 0, sizeof(enginefuncs_t));

	// Funtion hooks here

	memcpy(pengfuncsFromEngine, &g_ENGINE_FunctionTable_Post, sizeof(enginefuncs_t));

	return 1;
}
#pragma endregion
