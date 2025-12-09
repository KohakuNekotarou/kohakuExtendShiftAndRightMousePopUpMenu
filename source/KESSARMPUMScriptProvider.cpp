#include "VCPlugInHeaders.h"

// Interface includes:
#include "IApplication.h"
#include "IActionManager.h"


#include "iEventWatcher.h"

#include "IMenuManager.h"
#include "IScript.h"
#include "IScriptRequestData.h"
#include "IWorkspace.h"

// General includes:
#include "CAlert.h" // CAlert::InformationAlert(Msg);
#include "CScriptProvider.h"

#include "LocaleSetting.h"
#include "PMLocaleId.h"

// Project includes:
#include "KESSARMPUMScriptingDefs.h"
#include "KESSARMPUMID.h"
#include "KESSARMPUMMenuFilter.h"
#include "KESSARMPUMScriptProvider.h"

// CREATE_PMINTERFACE
CREATE_PMINTERFACE(KESSARMPUMScriptProvider, kKESSARMPUMScriptProviderImpl)

ErrorCode KESSARMPUMScriptProvider::HandleMethod(
	ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent)
{
	ErrorCode status = kFailure;

	switch (scriptID.Get())
	{
	case e_Speak:
		status = this->Test(scriptID, iScriptRequestData, iScript_parent);
		break;

	default:
		status = CScriptProvider::HandleMethod(scriptID, iScriptRequestData, iScript_parent);
	}

    return status;
}

ErrorCode KESSARMPUMScriptProvider::Test(ScriptID scriptID, IScriptRequestData* iScriptRequestData, IScript* iScript_parent)
{
	ErrorCode status = kFailure;

	/*
	// Query ActionID & Menu path
	// Plug-In first Onry
	PMString pMString_actionID;
	for (int32 i = 0; i < KESSARMPUMMenuFilter::vector_ActionID_actionID.size(); i++)
	{
		PMString pMString_num;
		pMString_num.AsNumber(KESSARMPUMMenuFilter::vector_ActionID_actionID[i].Get());
		pMString_actionID.Append(pMString_num);
		pMString_actionID.Append("\n");
	}
	CAlert::InformationAlert(pMString_actionID);

	PMString pMString_menuPath;
	for (int32 i = 0; i < KESSARMPUMMenuFilter::vector_PMString_menuPath.size(); i++)
	{
		pMString_menuPath.Append(KESSARMPUMMenuFilter::vector_PMString_menuPath[i]);
		pMString_menuPath.Append("\n");
	}
	CAlert::InformationAlert(pMString_menuPath);
	*/

	do
	{
		// ---------------------------------------------------------------------------------------
		// Add DynMnuPlaceholderMenu
		InterfacePtr<IApplication> iApplication(GetExecutionContextSession()->QueryApplication());
		if (iApplication == nil) break;

		InterfacePtr<IActionManager> iActionManager(iApplication->QueryActionManager());
		if (iActionManager == nil) break;

		InterfacePtr<IMenuManager> iMenuManager(iActionManager, UseDefaultIID());
		if (iMenuManager == nil) break;

		iMenuManager->RemoveMenuItem(
			"RtMouseDefault", // Menu path
			kKESSARMPUMRtMouseDefaultDynMnuPlaceholderActionID // ActionID
		);

		iMenuManager->AddMenuItem(
			kKESSARMPUMRtMouseDefaultDynMnuPlaceholderActionID, // Action ID
			"RtMouseDefault", // Menu path
			0, // Menu position
			kTrue // IsDynamicMenu
		);







		KESSARMPUMMenuFilter::vector_ActionID_ShiftAndRtMousePopUpMenuItemActionID.clear();
		KESSARMPUMMenuFilter::vector_ActionID_ShiftAndRtMousePopUpMenuItemActionID.push_back(271);
		KESSARMPUMMenuFilter::vector_ActionID_ShiftAndRtMousePopUpMenuItemActionID.push_back(-16777147);

		KESSARMPUMMenuFilter::vector_PMString_ShiftAndRtMousePopUpMenuSubMenuPath.clear();
		//KESSARMPUMMenuFilter::vector_PMString_ShiftAndRtMousePopUpMenuSubMenuPath.push_back("RtMouseDefault");
		//KESSARMPUMMenuFilter::vector_PMString_ShiftAndRtMousePopUpMenuSubMenuPath.push_back("RtMouseDefault");


		

		status = kSuccess;
	} while (false);

	return status;
}