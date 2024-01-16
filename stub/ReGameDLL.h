#pragma once

class CReGameDLL
{
public:
	bool Init();
	bool Stop();

	static CGameRules* InstallGameRules(IReGameHook_InstallGameRules* chain);

	IReGameApi* m_API;
	const ReGameFuncs_t* m_Funcs;
	IReGameHookchains* m_Hookchains;
	CGameRules* m_Rules;
};

extern CReGameDLL gReGameDLL;