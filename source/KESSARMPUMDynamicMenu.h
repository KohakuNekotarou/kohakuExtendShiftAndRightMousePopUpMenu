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
	typedef enum {
		kKESSARMPUMNill = 0,
		kKESSARMPUMRtMouseDefault = 1,
		kKESSARMPUMRtMouseLayout = 2,
		kKESSARMPUMRtMouseText = 3

	} KESSARMPUMPopUpMenuName;

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

	// PopUpMenuName
	static KESSARMPUMDynamicMenu::KESSARMPUMPopUpMenuName enum_PopUpMenuName;

	// RtMouseDefault
	static std::vector<ActionID> vector_ActionID_RtMouseDefaultMenuItemActionID;
	static std::vector<PMString> vector_PMString_RtMouseDefaultSubMenuPath;

	// RtMouseLayout
	static std::vector<ActionID> vector_ActionID_RtMouseLayoutMenuItemActionID;
	static std::vector<PMString> vector_PMString_RtMouseLayoutSubMenuPath;

	// ShiftRtMouseDefault
	static std::vector<ActionID> vector_ActionID_ShiftRtMouseDefaultMenuItemActionID;
	static std::vector<PMString> vector_PMString_ShiftRtMouseDefaultSubMenuPath;

	// ShiftRtMouseLayout
	static std::vector<ActionID> vector_ActionID_ShiftRtMouseLayoutMenuItemActionID;
	static std::vector<PMString> vector_PMString_ShiftRtMouseLayoutSubMenuPath;

	// ShiftRtMouseText
	static std::vector<ActionID> vector_ActionID_ShiftRtMouseTextMenuItemActionID;
	static std::vector<PMString> vector_PMString_ShiftRtMouseTextSubMenuPath;
};