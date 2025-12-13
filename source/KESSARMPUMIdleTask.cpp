#include "VCPlugInHeaders.h"

// Interface includes.
#include "ICommand.h"
#include "IMenuCustomizationData.h"

// General includes.
#include "CAlert.h" // CAlert::InformationAlert(Msg);
#include "CIdleTask.h"
#include "CmdUtils.h"

// Project includes.
#include "KESSARMPUMID.h"
#include "KESSARMPUMDynamicMenu.h"

class KESSARMPUMIdleTask : public CIdleTask
{
public:

	KESSARMPUMIdleTask(IPMUnknown* boss);

	virtual uint32 RunTask(uint32 appFlags, IdleTimer* timeCheck);

};

CREATE_PMINTERFACE(KESSARMPUMIdleTask, kKESSARMPUMIdleTaskImpl)

KESSARMPUMIdleTask::KESSARMPUMIdleTask(IPMUnknown *boss)
	:CIdleTask(boss)
{
}

uint32 KESSARMPUMIdleTask::RunTask(uint32 appFlags, IdleTimer* timeCheck)
{
	// Show existing menu
	do {
		InterfacePtr<ICommand> iCommand(CmdUtils::CreateCommand(kSetMenuCustomizationPrefsCmdBoss));
		if (iCommand == nil) break;

		InterfacePtr<IMenuCustomizationData> iMenuCustomizationData(iCommand, UseDefaultIID());
		if (iMenuCustomizationData == nil) break;

		bool16 bool16_show = kTrue;
		switch (KESSARMPUMDynamicMenu::enum_PopUpMenuName)
		{
			case KESSARMPUMDynamicMenu::kKESSARMPUMRtMouseDefault: // RtMouseDefault
			{
				KESSARMPUMDynamicMenu::SetMenuCustomizationData(
					KESSARMPUMDynamicMenu::vector_ActionID_RtMouseDefaultMenuItemActionID,
					KESSARMPUMDynamicMenu::vector_PMString_RtMouseDefaultSubMenuPath,
					KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseDefaultMenuItemActionID,
					KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseDefaultSubMenuPath,
					iMenuCustomizationData,
					bool16_show
				);
				break;
			}
			case KESSARMPUMDynamicMenu::kKESSARMPUMRtMouseLayout: // RtMouseLayout
			{
				KESSARMPUMDynamicMenu::SetMenuCustomizationData(
					KESSARMPUMDynamicMenu::vector_ActionID_RtMouseLayoutMenuItemActionID,
					KESSARMPUMDynamicMenu::vector_PMString_RtMouseLayoutSubMenuPath,
					KESSARMPUMDynamicMenu::vector_ActionID_ShiftRtMouseLayoutMenuItemActionID,
					KESSARMPUMDynamicMenu::vector_PMString_ShiftRtMouseLayoutSubMenuPath,
					iMenuCustomizationData,
					bool16_show
				);
				break;
			}
		}

		CmdUtils::ProcessCommand(iCommand);

	} while (false);

	// Removes the task from its queues.
	return IIdleTask::kEndOfTime;
}