#include "VCPlugInHeaders.h"

// Interface includes:
#include "IApplication.h"
#include "IActionManager.h"
#include "IMenuFilter.h"
#include "IMenuManager.h"

// General includes:
#include "CAlert.h" // CAlert::InformationAlert(Msg);

// Project includes:
#include "KESSARMPUMID.h"
#include "KESSARMPUMMenuFilter.h"

// CREATE_PMINTERFACE
CREATE_PMINTERFACE(KESSARMPUMMenuFilter, kKESSARMPUMMenuFilterImpl)

// Class variable
bool16 KESSARMPUMMenuFilter::bool16_dynamicMenuExperience = kFalse;
std::vector<ActionID> KESSARMPUMMenuFilter::vector_ActionID_actionID = {};
std::vector<PMString> KESSARMPUMMenuFilter::vector_PMString_menuPath = {};
std::vector<ActionID> KESSARMPUMMenuFilter::vector_ActionID_ShiftAndRtMousePopUpMenuItemActionID = {};
std::vector<PMString> KESSARMPUMMenuFilter::vector_PMString_ShiftAndRtMousePopUpMenuSubMenuPath = {};

// Constructor
KESSARMPUMMenuFilter::KESSARMPUMMenuFilter(IPMUnknown* boss)
	: CPMUnknown<IMenuFilter>(boss) 
{
	do // Remove DynMnuPlaceholderMenu
	{
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

	} while (false);
}

void KESSARMPUMMenuFilter::FilterMenuItem(
	ActionID* actionID, PMString* menuPath, PMReal* menuPos, bool16 isDynamic, bool16 isOwnerDraw)
{
	/*
	// Query menu
	// Plug-IN first only
	if (menuPath->Contains("RtMouseDefault"))
	{
		// Not DynamicMenuActionID
		PMString pMString_contains = *menuPath;
		if (actionID->Get() != kKESSARMPUMRtMouseDefaultDynMnuPlaceholderActionID
			&& pMString_contains.Contains("-") == kFalse)
		{
			if (actionID->Get() == kInvalidActionID) // Sub menu
			{
				KESSARMPUMMenuFilter::vector_PMString_menuPath.push_back(*menuPath);
			}
			else KESSARMPUMMenuFilter::vector_ActionID_actionID.push_back(*actionID); // Menu item
		}
	}
	*/
}