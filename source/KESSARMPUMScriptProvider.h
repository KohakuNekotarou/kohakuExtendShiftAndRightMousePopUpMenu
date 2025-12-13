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

	ErrorCode SetShiftRtMouseMenuItem(
		ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent);

	ErrorCode SetShiftRtMouseButtonPopUpSubMenu(
		ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent);

	ErrorCode InstallShiftRightMouseButtonPopUpMenu();

	ErrorCode RemoveShiftRightMouseButtonPopUpMenu();

	ErrorCode IsShiftRightMouseButtonPopUpMenu(
		ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent);

	void AddActionAndMenu(
		IActionManager* iActionManager, IMenuManager* iMenuManager, ActionID actionID, PMString menuPath);

	void RemoveActionAndMenu(
		IActionManager* iActionManager, IMenuManager* iMenuManager, ActionID actionID, PMString menuPath);
};