#pragma once

// Interface includes:
#include "IScript.h"
#include "IScriptRequestData.h"

// General includes:
#include "CScriptProvider.h"

// Project includes:
#include "KESSARMPUMID.h"

class KESSARMPUMScriptProvider : public CScriptProvider
{
public:

	KESSARMPUMScriptProvider(IPMUnknown* boss);

	virtual ErrorCode HandleMethod(
		ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent);

	virtual ErrorCode AccessProperty(
		ScriptID scriptID_prop, IScriptRequestData* iScriptRequestData, IScript* iScript_parent);

private:

	virtual ErrorCode SetShiftRightMouseButtonPopUpMenuItem(
		ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent);

	virtual ErrorCode InstallShiftRightMouseButtonPopUpMenu();

	virtual ErrorCode RemoveShiftRightMouseButtonPopUpMenu();

	virtual ErrorCode IsShiftRightMouseButtonPopUpMenu(
		ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent);
};