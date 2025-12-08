#include "VCPlugInHeaders.h"

// Interface includes:
#include "IActionManager.h"
#include "IApplication.h"
#include "IDynamicMenu.h"
#include "IMenuManager.h"

// General includes:
#include "CAlert.h" // CAlert::InformationAlert(Msg);
#include "KeyStates.h" // for IsShiftKeyPressed

// Project includes:
#include "KESSARMPUMID.h"
#include "KESSARMPUMMenuFilter.h"

class KESSARMPUMDynamicMenu : public CPMUnknown<IDynamicMenu>
{
	public:
		KESSARMPUMDynamicMenu(IPMUnknown *boss);

		void RebuildMenu(ActionID dynamicActionID, IPMUnknown* widget);

		static bool16 SiftAfterFlg;
};

// CREATE_PMINTERFACE
CREATE_PMINTERFACE(KESSARMPUMDynamicMenu, kKESSARMPUMDynamicMenuImpl)

// Class variable
bool16 KESSARMPUMDynamicMenu::SiftAfterFlg = kFalse;

// Constructor
KESSARMPUMDynamicMenu::KESSARMPUMDynamicMenu(IPMUnknown *boss) :
	CPMUnknown<IDynamicMenu>(boss) 
{
}

void KESSARMPUMDynamicMenu::RebuildMenu(ActionID dynamicActionID, IPMUnknown* widget)
{
	do {
		// ---------------------------------------------------------------------------------------
		// Query IMenuManager
		InterfacePtr<IApplication> iApplication(GetExecutionContextSession()->QueryApplication());
		if (iApplication == nil) break;

		InterfacePtr<IActionManager> iActionManager(iApplication->QueryActionManager());
		if (iActionManager == nil) break;

		InterfacePtr<IMenuManager> iMenuManager(iActionManager, UseDefaultIID());
		if (iMenuManager == nil) break;
	
		// ---------------------------------------------------------------------------------------
		// Edit PopUp Menu
		if (IsShiftKeyPressed() == kTrue)
		{
			// After regular menu appears?
			if (KESSARMPUMDynamicMenu::SiftAfterFlg == kFalse)
			{
				// Delete existing menu
				for (int32 i = 0; i < KESSARMPUMMenuFilter::vector_ActionID_actionID.size(); i++)
				{
					iMenuManager->RemoveMenuItem(
						KESSARMPUMMenuFilter::vector_PMString_menuPath[i], // Menu path
						KESSARMPUMMenuFilter::vector_ActionID_actionID[i] // ActionID
					);
				}

				// Add to Menu
				iMenuManager->AddMenuItem(
					271,
					"RtMouseDefault",
					0,
					kFalse
				);

				// SiftAfterFlg
				KESSARMPUMDynamicMenu::SiftAfterFlg = kTrue;
			}
		}
		else
		{
			// After shift menu appears?
			if (KESSARMPUMDynamicMenu::SiftAfterFlg == kTrue)
			{
				// Delete menu
				iMenuManager->RemoveMenuItem(
					"RtMouseDefault", // Menu path
					271 // ActionID
				);

				// Add existing menu
				for (int32 i = 0; i < KESSARMPUMMenuFilter::vector_ActionID_actionID.size(); i++)
				{
					iMenuManager->AddMenuItem(
						KESSARMPUMMenuFilter::vector_ActionID_actionID[i], // Action ID
						KESSARMPUMMenuFilter::vector_PMString_menuPath[i], // Menu path
						KESSARMPUMMenuFilter::vector_PMReal_menuPos[i], // Menu position
						KESSARMPUMMenuFilter::vector_bool16_isDynamic[i] // IsDynamicMenu
					);
				}

				// SiftAfterFlg
				KESSARMPUMDynamicMenu::SiftAfterFlg = kFalse;
			}
		}
	} while (false);
}