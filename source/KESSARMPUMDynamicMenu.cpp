#include "VCPlugInHeaders.h"

// Interface includes:
#include "ICommand.h"
#include "IDynamicMenu.h"
#include "IIdleTask.h"
#include "IIdleTaskMgr.h"
#include "IMenuCustomizationData.h"

// General includes:
#include "CAlert.h" // CAlert::InformationAlert(Msg);
#include "CmdUtils.h"
#include "KeyStates.h" // for IsShiftKeyPressed

// Project includes:
#include "KESSARMPUMID.h"
#include "KESSARMPUMDynamicMenu.h"

// CREATE_PMINTERFACE
CREATE_PMINTERFACE(KESSARMPUMDynamicMenu, kKESSARMPUMDynamicMenuImpl)

// Class variable
// PopUpMenuName
KESSARMPUMDynamicMenu::KESSARMPUMPopUpMenuName KESSARMPUMDynamicMenu::enum_PopUpMenuName = 
	KESSARMPUMDynamicMenu::kKESSARMPUMNill;

// RtMouseDefault
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

// RtMouseLayout
std::vector<ActionID> KESSARMPUMDynamicMenu::vector_ActionID_RtMouseLayoutMenuItemActionID = {
	78691,
	78845,
	78612,
	78815,
	78636,
	78350,
	78349,
	78348,
	78351,
	78346,
	78345,
	78344,
	78341,
	44289,
	44293,
	36612,
	108293,
	37889,
	13571,
	13575,
	6179,
	6167,
	132646,
	132628,
	132657,
	132620,
	132645,
	132659,
	132642,
	132644,
	132651,
	132655,
	79362,
	79370,
	79367,
	79377,
	95490,
	84234,
	83458,
	83460,
	83464,
	83463,
	83461,
	83465,
	83462,
	83628,
	102152,
	102154,
	102149,
	102150,
	102151,
	102155,
	104988,
	105171,
	67895,
	67868,
	67869,
	67870,
	67871,
	67872,
	67873,
	67874,
	67876,
	67875,
	11026,
	36609,
	134194,
	32259,
	34818,
	151614,
	151615,
	50177,
	50184,
	50185,
	50187,
	50188,
	50195,
	50189,
	119681,
	119793,
	118785,
	118786,
	118791,
	118789,
	118790,
	118799,
	118800,
	118801,
	118802,
	118812,
	118813,
	118811,
	118814,
	118846,
	118851,
	118805,
	118842,
	118837,
	118843,
	11283,
	11284,
	11285,
	11286,
	11289,
	11287,
	11288,
	11290,
	11351,
	11352,
	11355,
	11356,
	11304,
	118856,
	118857,
	11302,
	11292,
	11291,
	11294,
	11399,
	11293,
	11347,
	11398,
	11350,
	11295,
	11296,
	11297,
	11400,
	11402,
	11403,
	11401,
	118844,
	118845,
	273,
	274,
	269,
	270,
	271,
	149006
};

std::vector<PMString> KESSARMPUMDynamicMenu::vector_PMString_RtMouseLayoutSubMenuPath = {
	"RtMouseLayout:TagFramePopup:",
	"RtMouseLayout:Display Performance:",
	"RtMouseLayout:Anchored Object Menu:",
	"RtMouseLayout:#EditWithApp:",
	"RtMouseLayout:#CaptionSubmenu:",
	"RtMouseLayout:Hyperlinks:",
	"RtMouseLayout:InteractiveContextMenu:",
	"RtMouseLayout:kInCopyMenu:",
	"RtMouseLayout:kInCopyMenu:Add to Assignment:",
	"RtMouseLayout:ObjectEffects:",
	"RtMouseLayout:kCollaborationMenu:",
	"RtMouseLayout:kCollaborationMenu:kAssignTo:",
	"RtMouseLayout:Frame Type:",
	"RtMouseLayout:Zoom:",
	"RtMouseLayout:Tran&sform:",
	"RtMouseLayout:&Transform Again:",
	"RtMouseLayout:&Arrange:",
	"RtMouseLayout:SelectObjectMenu:",
	"RtMouseLayout:Stroke Weight:",
	"RtMouseLayout:Fitting:",
	"RtMouseLayout:&Content:",
	"RtMouseLayout:CaptureFromSelection:"
};

// ShiftRtMouseDefault
std::vector<ActionID> KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenuItemActionID = {};
std::vector<PMString> KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseDefaultSubMenuPath = {};

// ShiftRtMouseLayout
std::vector<ActionID> KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseLayoutMenuItemActionID = {};
std::vector<PMString> KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseLayoutSubMenuPath = {};

// ShiftRtMouseText
std::vector<ActionID> KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseTextMenuItemActionID = {};
std::vector<PMString> KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseTextSubMenuPath = {};

// Constructor
KESSARMPUMDynamicMenu::KESSARMPUMDynamicMenu(IPMUnknown *boss) :
	CPMUnknown<IDynamicMenu>(boss) 
{
}

void KESSARMPUMDynamicMenu::RebuildMenu(ActionID dynamicActionID, IPMUnknown* widget)
{
	do {
		// ---------------------------------------------------------------------------------------
		// Query IMenuCustomizationData
		InterfacePtr<ICommand> iCommand(CmdUtils::CreateCommand(kSetMenuCustomizationPrefsCmdBoss));
		if (iCommand == nil) break;

		InterfacePtr<IMenuCustomizationData> iMenuCustomizationData(iCommand, UseDefaultIID());
		if (iMenuCustomizationData == nil) break;

		// ---------------------------------------------------------------------------------------
		// IsShiftKeyPressed
		bool16 bool16_show = kTrue;
		bool16 bool16_hide = kFalse;
		if (IsShiftKeyPressed() == kTrue)
		{
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
			switch (dynamicActionID.Get())
			{
				case kKESSARMPUMRtMouseDefaultDynMnuPlaceholderActionID: // RtMouseDefault
				{
					KESSARMPUMDynamicMenu::enum_PopUpMenuName = KESSARMPUMDynamicMenu::kKESSARMPUMRtMouseDefault;

					// Hide
					this->SetMenuCustomizationData(
						KESSARMPUMDynamicMenu::vector_ActionID_RtMouseDefaultMenuItemActionID,
						KESSARMPUMDynamicMenu::vector_PMString_RtMouseDefaultSubMenuPath,
						KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenuItemActionID,
						KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseDefaultSubMenuPath,
						iMenuCustomizationData,
						bool16_hide
					);

					// Show
					this->SetMenuCustomizationData(
						KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenuItemActionID,
						KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseDefaultSubMenuPath,
						KESSARMPUMDynamicMenu::vector_ActionID_RtMouseDefaultMenuItemActionID,
						KESSARMPUMDynamicMenu::vector_PMString_RtMouseDefaultSubMenuPath,
						iMenuCustomizationData,
						bool16_show
					);

					break;
				}
				case kKESSARMPUMRtMouseLayoutDynMnuPlaceholderActionID: // RtMouseLayout
				{
					KESSARMPUMDynamicMenu::enum_PopUpMenuName = KESSARMPUMDynamicMenu::kKESSARMPUMRtMouseLayout;

					// Hide
					this->SetMenuCustomizationData(
						KESSARMPUMDynamicMenu::vector_ActionID_RtMouseLayoutMenuItemActionID,
						KESSARMPUMDynamicMenu::vector_PMString_RtMouseLayoutSubMenuPath,
						KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseLayoutMenuItemActionID,
						KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseLayoutSubMenuPath,
						iMenuCustomizationData,
						bool16_hide
					);

					// Show
					this->SetMenuCustomizationData(
						KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseLayoutMenuItemActionID,
						KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseLayoutSubMenuPath,
						KESSARMPUMDynamicMenu::vector_ActionID_RtMouseLayoutMenuItemActionID,
						KESSARMPUMDynamicMenu::vector_PMString_RtMouseLayoutSubMenuPath,
						iMenuCustomizationData,
						bool16_show
					);

					break;
				}
			}



			/*
			
			else if (dynamicActionID.Get() == kKESSARMPUMRtMouseTextDynMnuPlaceholderActionID) // RtMouseText
			{
				KESSARMPUMDynamicMenu::enum_PopUpMenuName = KESSARMPUMDynamicMenu::kKESSARMPUMRtMouseText;
			}
			*/
		}
		else // if (IsShiftKeyPressed() == kFalse)
		{
			KESSARMPUMDynamicMenu::enum_PopUpMenuName = KESSARMPUMDynamicMenu::kKESSARMPUMNill;

			switch (dynamicActionID.Get())
			{
				case kKESSARMPUMRtMouseDefaultDynMnuPlaceholderActionID: // RtMouseDefault
				{
					// Hide
					this->SetMenuCustomizationData(
						KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenuItemActionID,
						KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseDefaultSubMenuPath,
						KESSARMPUMDynamicMenu::vector_ActionID_RtMouseDefaultMenuItemActionID,
						KESSARMPUMDynamicMenu::vector_PMString_RtMouseDefaultSubMenuPath,
						iMenuCustomizationData,
						bool16_hide
					);

					break;
				}
				case kKESSARMPUMRtMouseLayoutDynMnuPlaceholderActionID: // RtMouseLayout
				{
					// Hide
					this->SetMenuCustomizationData(
						KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseLayoutMenuItemActionID,
						KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseLayoutSubMenuPath,
						KESSARMPUMDynamicMenu::vector_ActionID_RtMouseLayoutMenuItemActionID,
						KESSARMPUMDynamicMenu::vector_PMString_RtMouseLayoutSubMenuPath,
						iMenuCustomizationData,
						bool16_hide
					);

					break;
				}
			}
		}

		// ProcessCommand
		CmdUtils::ProcessCommand(iCommand);

	} while (false);
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
		// Is existing
		auto result = std::find(vector_existingActionID.begin(), vector_existingActionID.end(), *it);
		if (result == vector_existingActionID.end()) // Not found
		{
			if (showHideFlg == kTrue) iMenuCustomizationData->ShowMenuAction(*it);
			else iMenuCustomizationData->HideMenuAction(*it);
		}
	}

	// SubMenu
	for (std::vector<PMString>::iterator it = vector_menuPath.begin(); it != vector_menuPath.end(); ++it)
	{
		// Is existing
		auto result = std::find(vector_existingmenuPath.begin(), vector_existingmenuPath.end(), *it);
		if (result == vector_existingmenuPath.end()) // Not found
		{
			// Remove ":"
			PMString pMString_menuPath = *it;

			int32 int32_count = pMString_menuPath.CharCount();

			pMString_menuPath.Remove(int32_count - 1, 1);

			if (showHideFlg == kTrue) iMenuCustomizationData->ShowSubMenu(pMString_menuPath);
			else iMenuCustomizationData->HideSubMenu(pMString_menuPath);
		}
	}
}