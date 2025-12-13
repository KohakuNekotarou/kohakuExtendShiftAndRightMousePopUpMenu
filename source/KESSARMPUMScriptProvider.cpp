#include "VCPlugInHeaders.h"

// Interface includes:
#include "IApplication.h"
#include "IActionManager.h"
#include "IMenuManager.h"
#include "IScript.h"
#include "IScriptRequestData.h"
#include "IWorkspace.h"

// General includes:
#include "CAlert.h" // CAlert::InformationAlert(Msg);
#include "CScriptProvider.h"

// Project includes:
#include "KESSARMPUMScriptingDefs.h"
#include "KESSARMPUMID.h"
#include "KESSARMPUMDynamicMenu.h"
#include "KESSARMPUMScriptProvider.h"



#include "KESSARMPUMMenuFilter.h"

// CREATE_PMINTERFACE
CREATE_PMINTERFACE(KESSARMPUMScriptProvider, kKESSARMPUMScriptProviderImpl)

// Constructor
KESSARMPUMScriptProvider::KESSARMPUMScriptProvider(IPMUnknown* boss) : CScriptProvider(boss)
{
}

ErrorCode KESSARMPUMScriptProvider::HandleMethod(
	ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent)
{
	ErrorCode status = kFailure;

	switch (scriptID.Get())
	{
		case e_KESSARMPUMSetShiftRtMouseMenuItem:
			status = this->SetShiftRtMouseMenuItem(
				scriptID, iScriptRequestData, iScript_parent);
			break;

		case e_KESSARMPUMSetShiftRtMouseSubMenu:
			status = this->SetShiftRtMouseButtonPopUpSubMenu(
				scriptID, iScriptRequestData, iScript_parent);
			break;

		case e_KESSARMPUMInstall:
			status = this->InstallShiftRightMouseButtonPopUpMenu();
			break;

		case e_KESSARMPUMRemove:
			status = this->RemoveShiftRightMouseButtonPopUpMenu();
			break;

		default:
			status = CScriptProvider::HandleMethod(scriptID, iScriptRequestData, iScript_parent);
	}

    return status;
}

ErrorCode KESSARMPUMScriptProvider::AccessProperty(
	ScriptID scriptID_prop, IScriptRequestData* iScriptRequestData, IScript* iScript_parent)
{
	ErrorCode status = kFailure;

	switch (scriptID_prop.Get())
	{
		case p_KESSARMPUMIs:
			status = this->IsShiftRightMouseButtonPopUpMenu(scriptID_prop, iScriptRequestData, iScript_parent);
			break;

		default:
			status = CScriptProvider::AccessProperty(scriptID_prop, iScriptRequestData, iScript_parent);
	}

	return status;
}

ErrorCode KESSARMPUMScriptProvider::SetShiftRtMouseMenuItem(
	ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent)
{
	ErrorCode status = kFailure;

	do
	{
		// ---------------------------------------------------------------------------------------
		// Query target menu string
		ScriptData scriptData;
		PMString pMString_TargetMenu;
		if (iScriptRequestData->ExtractRequestData(p_KESSARMPUMTargetMenuString, scriptData) == kFailure) break;

		if (scriptData.GetPMString(pMString_TargetMenu) == kFailure) break;

		if (pMString_TargetMenu != "RtMouseDefault"
			&& pMString_TargetMenu != "RtMouseLayout"
			) break;

		// ---------------------------------------------------------------------------------------
		// Query actionID
		ScriptObject scriptObject = iScript_parent->GetScriptObject(iScriptRequestData->GetRequestContext());

		scriptData = scriptObject.specifierData;

		int32 int32_menuItemActionID;
		scriptData.GetInt32(&int32_menuItemActionID);
		ActionID actionID(int32_menuItemActionID);








		// ---------------------------------------------------------------------------------------
		// Set actionID
		auto result = std::find( // Is existing
			KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenuItemActionID.begin(),
			KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenuItemActionID.end(),
			actionID
		);

		if (result == KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenuItemActionID.end()) // Not found
		{
			// push_back
			KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenuItemActionID.push_back(actionID);
		}








		status = kSuccess;
	} while (false);

	return status;
}

ErrorCode KESSARMPUMScriptProvider::SetShiftRtMouseButtonPopUpSubMenu(
	ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent)
{
	ErrorCode status = kFailure;

	do
	{
		// ---------------------------------------------------------------------------------------
		// Query target menu string
		ScriptData scriptData;
		PMString pMString_TargetMenu;
		if (iScriptRequestData->ExtractRequestData(p_KESSARMPUMTargetMenuString, scriptData) == kFailure) break;

		if (scriptData.GetPMString(pMString_TargetMenu) == kFailure) break;

		if (pMString_TargetMenu != "RtMouseDefault") break;

		// ---------------------------------------------------------------------------------------
		// Query name
		ScriptObject scriptObject = iScript_parent->GetScriptObject(iScriptRequestData->GetRequestContext());

		scriptData = scriptObject.specifierData;

		PMString pMString_name;
		scriptData.GetPMString(pMString_name);





		// ‚±‚±‚©‚ç–¢ŽÀ‘•




		// Display Performance
		// ---------------------------------------------------------------------------------------
		// Set menuPath
		PMString subMenuPath;
		auto result = std::find( // Is existing
			KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseDefaultSubMenuPath.begin(),
			KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseDefaultSubMenuPath.end(),
			subMenuPath
		);

		if (result == KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseDefaultSubMenuPath.end()) // Not found
		{
			// push_back
			KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseDefaultSubMenuPath.push_back(subMenuPath);
		}

		status = kSuccess;

	} while (false);

	return status;
}

ErrorCode KESSARMPUMScriptProvider::InstallShiftRightMouseButtonPopUpMenu()
{
	ErrorCode status = kFailure;

	do
	{
		// ---------------------------------------------------------------------------------------
		// Query Manager
		InterfacePtr<IApplication> iApplication(GetExecutionContextSession()->QueryApplication());
		if (iApplication == nil) break;

		InterfacePtr<IActionManager> iActionManager(iApplication->QueryActionManager());
		if (iActionManager == nil) break;

		InterfacePtr<IMenuManager> iMenuManager(iActionManager, UseDefaultIID());
		if (iMenuManager == nil) break;

		// ---------------------------------------------------------------------------------------
		// Add DynMnuPlaceholder
		this->RemoveActionAndMenu(
			iActionManager, iMenuManager, kKESSARMPUMRtMouseDefaultDynMnuPlaceholderActionID, "RtMouseDefault");
		this->AddActionAndMenu(
			iActionManager, iMenuManager, kKESSARMPUMRtMouseDefaultDynMnuPlaceholderActionID, "RtMouseDefault");

		this->RemoveActionAndMenu(
			iActionManager, iMenuManager, kKESSARMPUMRtMouseLayoutDynMnuPlaceholderActionID, "RtMouseLayout");
		this->AddActionAndMenu(
			iActionManager, iMenuManager, kKESSARMPUMRtMouseLayoutDynMnuPlaceholderActionID, "RtMouseLayout");

		this->RemoveActionAndMenu(
			iActionManager, iMenuManager, kKESSARMPUMRtMouseTextDynMnuPlaceholderActionID, "RtMouseText");
		this->AddActionAndMenu(
			iActionManager, iMenuManager, kKESSARMPUMRtMouseTextDynMnuPlaceholderActionID, "RtMouseText");

		status = kSuccess;
	} while (false);

	return status;
}

ErrorCode KESSARMPUMScriptProvider::RemoveShiftRightMouseButtonPopUpMenu()
{
	ErrorCode status = kFailure;

	do
	{
		// ---------------------------------------------------------------------------------------
		// Clear
		KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenuItemActionID.clear();
		KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseDefaultSubMenuPath.clear();

		KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseLayoutMenuItemActionID.clear();
		KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseLayoutSubMenuPath.clear();

		KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseTextMenuItemActionID.clear();
		KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseTextSubMenuPath.clear();

		// ---------------------------------------------------------------------------------------
		// Query Manager
		InterfacePtr<IApplication> iApplication(GetExecutionContextSession()->QueryApplication());
		if (iApplication == nil) break;

		InterfacePtr<IActionManager> iActionManager(iApplication->QueryActionManager());
		if (iActionManager == nil) break;

		InterfacePtr<IMenuManager> iMenuManager(iActionManager, UseDefaultIID());
		if (iMenuManager == nil) break;

		




		// ‚±‚±‚©‚ç








		// ---------------------------------------------------------------------------------------
		// Remove DynMnuPlaceholder
		this->RemoveActionAndMenu(
			iActionManager, iMenuManager, kKESSARMPUMRtMouseDefaultDynMnuPlaceholderActionID, "RtMouseDefault");

		this->RemoveActionAndMenu(
			iActionManager, iMenuManager, kKESSARMPUMRtMouseLayoutDynMnuPlaceholderActionID, "RtMouseLayout");

		this->RemoveActionAndMenu(
			iActionManager, iMenuManager, kKESSARMPUMRtMouseTextDynMnuPlaceholderActionID, "RtMouseText");

		status = kSuccess;
	} while (false);

	return status;
}

ErrorCode KESSARMPUMScriptProvider::IsShiftRightMouseButtonPopUpMenu(
	ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent)
{
	ErrorCode status = kFailure;







	/*
	PMString result, num;
	for (ActionID actionID : KESSARMPUMMenuFilter::vector_ActionID_actionID)
	{
		num.AsNumber(actionID.Get());
		result.Append(num);
		result.Append(",\n");
	}

	CAlert::InformationAlert(result);

	result = "";

	for (PMString pMString : KESSARMPUMMenuFilter::vector_PMString_menuPath)
	{
		result.Append(pMString);
		result.Append(",\n");
	}

	CAlert::InformationAlert(result);
	*/
	














	do
	{
		if (iScriptRequestData->IsPropertyGet())
		{
			// ---------------------------------------------------------------------------------------
			// Query Manager
			InterfacePtr<IApplication> iApplication(GetExecutionContextSession()->QueryApplication());
			if (iApplication == nil) break;

			InterfacePtr<IActionManager> iActionManager(iApplication->QueryActionManager());
			if (iActionManager == nil) break;
			
			// ---------------------------------------------------------------------------------------
			// Append return data
			int32 int32_isValidAction;
			if (iActionManager->IsValidAction(kKESSARMPUMRtMouseDefaultDynMnuPlaceholderActionID))
				int32_isValidAction = 1;
			else int32_isValidAction = 0;

			iScriptRequestData->AppendReturnData(iScript_parent, scriptID, ScriptData(int32_isValidAction));

			status = kSuccess;
		}
	} while (false);

	return status;
}

void KESSARMPUMScriptProvider::AddActionAndMenu(
	IActionManager* iActionManager, IMenuManager* iMenuManager, ActionID actionID, PMString menuPath)
{
	iActionManager->AddAction(
		kKESSARMPUMActionComponentBoss, // ptr to IActionComponent to field menu hit
		actionID, // Action ID
		"KESSARMPUMDynMnuPlaceholder", // Sub-menu string
		kOtherActionArea, // Action area
		kNormalAction, // Action type
		kCustomEnabling, // Enabling type
		kInvalidInterfaceID, // Selection InterfaceID this action cares about or kInvalidInterfaceID.
		kFalse // User editability
	);

	iMenuManager->AddMenuItem(
		actionID, // Action ID
		menuPath, // Menu path
		0, // Menu position
		kTrue // IsDynamicMenu
	);
}

void KESSARMPUMScriptProvider::RemoveActionAndMenu(
	IActionManager* iActionManager, IMenuManager* iMenuManager, ActionID actionID, PMString menuPath)
{
	iActionManager->RemoveAction(actionID);

	iMenuManager->RemoveMenuItem(menuPath, actionID);
}