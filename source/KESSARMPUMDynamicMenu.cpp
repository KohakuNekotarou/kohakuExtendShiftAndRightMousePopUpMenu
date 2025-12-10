#include "VCPlugInHeaders.h"

// Interface includes:
#include "ICommand.h"
#include "IDynamicMenu.h"

#include "IEventWatcher.h"


#include "IIdleTask.h"
#include "IIdleTaskMgr.h"











#include "IMenuCustomizationData.h"

// General includes:
#include "CAlert.h" // CAlert::InformationAlert(Msg);
#include "CmdUtils.h"
#include "KeyStates.h" // for IsShiftKeyPressed

// Project includes:
#include "KESSARMPUMID.h"
#include "KESSARMPUMMenuFilter.h"
#include "KESSARMPUMDynamicMenu.h"

// CREATE_PMINTERFACE
CREATE_PMINTERFACE(KESSARMPUMDynamicMenu, kKESSARMPUMDynamicMenuImpl)

// Class variable
std::vector<ActionID> KESSARMPUMDynamicMenu::vector_ActionID_RtMouseDefaultMenuItemActionID = {
	78350,
	78349,
	78348,
	78351,
	78352,
	78346,
	78345,
	78344,
	78341,
	44293,
	49922,
	49923,
	50191,
	50192,
	50178,
	50179,
	24325,
	24342,
	24327,
	24329,
	24343,
	24326,
	24347,
	24328,
	24349,
	24330,
	13313,
	118785,
	118786,
	118791,
	118789,
	118872,
	118850,
	11289,
	11287,
	11288,
	11290,
	273,
	271
};
std::vector<PMString> KESSARMPUMDynamicMenu::vector_PMString_RtMouseDefaultSubMenuPath = {
	"RtMouseDefault:Display Performance:",
	"RtMouseDefault:Writing Direction:",
	"RtMouseDefault:Grids && Guides:",
	"RtMouseDefault:SelectObjectMenu:"
};

// Constructor
KESSARMPUMDynamicMenu::KESSARMPUMDynamicMenu(IPMUnknown *boss) :
	CPMUnknown<IDynamicMenu>(boss) 
{
}

void KESSARMPUMDynamicMenu::RebuildMenu(ActionID dynamicActionID, IPMUnknown* widget)
{
	KESSARMPUMMenuFilter::bool16_dynamicMenuExperience = kTrue; // dynamicMenuExperience

	if (IsShiftKeyPressed() == kTrue)
	{
		do {
			// ---------------------------------------------------------------------------------------
			// Add task
			// Insert an idle task before opening modal dialog to prevent the program from stopping.
			InterfacePtr<IIdleTask> iIdleTask(GetExecutionContextSession(), IID_IKESSARMPUMIDLETASK);
			if (iIdleTask == nil) break;

			InterfacePtr<IIdleTaskMgr> idleTaskMgr(GetExecutionContextSession(), ::UseDefaultIID());
			if (idleTaskMgr == nil) break;

			idleTaskMgr->RemoveTask(iIdleTask); // RemoveTask
			idleTaskMgr->AddTask(iIdleTask, 0); // AddTask

			// ---------------------------------------------------------------------------------------
			// MenuCustomization
			InterfacePtr<ICommand> iCommand(CmdUtils::CreateCommand(kSetMenuCustomizationPrefsCmdBoss));
			if (iCommand == nil) break;

			InterfacePtr<IMenuCustomizationData> iMenuCustomizationData(iCommand, UseDefaultIID());
			if (iMenuCustomizationData == nil) break;

			// Hide existing menu
			bool16 bool16_hide = kFalse;
			this->SetMenuCustomizationData(
				KESSARMPUMDynamicMenu::vector_ActionID_RtMouseDefaultMenuItemActionID,
				KESSARMPUMDynamicMenu::vector_PMString_RtMouseDefaultSubMenuPath,
				KESSARMPUMMenuFilter::vector_ActionID_ShiftAndRtMousePopUpMenuItemActionID,
				KESSARMPUMMenuFilter::vector_PMString_ShiftAndRtMousePopUpMenuSubMenuPath,
				iMenuCustomizationData,
				bool16_hide
			);

			// Show my menu
			bool16 bool16_show = kTrue;
			this->SetMenuCustomizationData(
				KESSARMPUMMenuFilter::vector_ActionID_ShiftAndRtMousePopUpMenuItemActionID,
				KESSARMPUMMenuFilter::vector_PMString_ShiftAndRtMousePopUpMenuSubMenuPath,
				KESSARMPUMDynamicMenu::vector_ActionID_RtMouseDefaultMenuItemActionID,
				KESSARMPUMDynamicMenu::vector_PMString_RtMouseDefaultSubMenuPath,
				iMenuCustomizationData,
				bool16_show
			);

			// ProcessCommand
			CmdUtils::ProcessCommand(iCommand);

		} while (false);
	}
	else // if (IsShiftKeyPressed() == kFalse)
	{
		do {
			InterfacePtr<ICommand> iCommand(CmdUtils::CreateCommand(kSetMenuCustomizationPrefsCmdBoss));
			if (iCommand == nil) break;

			InterfacePtr<IMenuCustomizationData> iMenuCustomizationData(iCommand, UseDefaultIID());
			if (iMenuCustomizationData == nil) break;

			// Hide my menu
			bool16 bool16_hide = kFalse;
			this->SetMenuCustomizationData(
				KESSARMPUMMenuFilter::vector_ActionID_ShiftAndRtMousePopUpMenuItemActionID,
				KESSARMPUMMenuFilter::vector_PMString_ShiftAndRtMousePopUpMenuSubMenuPath,
				KESSARMPUMDynamicMenu::vector_ActionID_RtMouseDefaultMenuItemActionID,
				KESSARMPUMDynamicMenu::vector_PMString_RtMouseDefaultSubMenuPath,
				iMenuCustomizationData,
				bool16_hide
			);

			CmdUtils::ProcessCommand(iCommand);

		} while (false);
	}
}

void KESSARMPUMDynamicMenu::SetMenuCustomizationData(
	std::vector<ActionID>& vector_actionID,
	std::vector<PMString>& vector_menuPath,
	std::vector<ActionID>& vector_existingActionID,
	std::vector<PMString>& vector_existingmenuPath,
	IMenuCustomizationData* iMenuCustomizationData,
	bool16 showHideFlg)
{
	// MenuItem
	for (std::vector<ActionID>::iterator it = vector_actionID.begin(); it != vector_actionID.end(); ++it)
	{
		if (showHideFlg == kTrue) iMenuCustomizationData->ShowMenuAction(*it);
		else
		{
			// Is it included in existingActionID?
			auto result = std::find(vector_existingActionID.begin(), vector_existingActionID.end(), *it);

			if (result == vector_existingActionID.end()) { // Not found
				iMenuCustomizationData->HideMenuAction(*it);
			}
		}
	}

	// SubMenu
	for (std::vector<PMString>::iterator it = vector_menuPath.begin(); it != vector_menuPath.end(); ++it)
	{
		// Remove ":"
		PMString pMString_menuPath = *it;

		int32 int32_count = pMString_menuPath.CharCount();

		pMString_menuPath.Remove(int32_count - 1, 1);

		if (showHideFlg == kTrue) iMenuCustomizationData->ShowSubMenu(pMString_menuPath);
		else
		{
			// Is it included in existingmenuPath?
			auto result = std::find(vector_existingmenuPath.begin(), vector_existingmenuPath.end(), *it);

			if (result == vector_existingmenuPath.end()) { // Not found
				iMenuCustomizationData->HideSubMenu(pMString_menuPath);
			}
		}
	}
}