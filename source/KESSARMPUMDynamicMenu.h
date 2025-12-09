#pragma once

// Interface includes:
#include "IDynamicMenu.h"

// General includes:
#include "CScriptProvider.h"

// Project includes:
#include "KESSARMPUMID.h"

class KESSARMPUMDynamicMenu : public CPMUnknown<IDynamicMenu>
{
public:
	KESSARMPUMDynamicMenu(IPMUnknown* boss);

	void RebuildMenu(ActionID dynamicActionID, IPMUnknown* widget);

	static void SetMenuCustomizationData(
		std::vector<ActionID>& vector_actionID,
		std::vector<PMString>& vector_menuPath,
		std::vector<ActionID>& vector_existingActionID,
		std::vector<PMString>& vector_existingmenuPath,
		IMenuCustomizationData* iMenuCustomizationData,
		bool16 showHideFlg
	);

	// RtMouseDefaultMenuItemActionID
	static std::vector<ActionID> vector_ActionID_RtMouseDefaultMenuItemActionID;

	// RtMouseDefaultSubMenuPath
	static std::vector<PMString> vector_PMString_RtMouseDefaultSubMenuPath;
};