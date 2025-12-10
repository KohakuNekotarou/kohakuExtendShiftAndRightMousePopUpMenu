#pragma once

// Interface includes:
#include "IDynamicMenu.h"
#include "IMenuCustomizationData.h"

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

	static std::vector<ActionID> vector_ActionID_RtMouseDefaultMenuItemActionID;
	static std::vector<PMString> vector_PMString_RtMouseDefaultSubMenuPath;
	static std::vector<ActionID> vector_ActionID_ShiftRtMouseDefaultMenuItemActionID;
	static std::vector<PMString> vector_PMString_ShiftRtMouseDefaultSubMenuPath;
};