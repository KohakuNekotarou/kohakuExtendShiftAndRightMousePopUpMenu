#ifndef __CstAFltActionFilter__
#define __CstAFltActionFilter__

#include "KESSARMPUMID.h"
#include "IMenuFilter.h"

class KESSARMPUMMenuFilter : public CPMUnknown<IMenuFilter>
{
public:

	KESSARMPUMMenuFilter(IPMUnknown* boss);

	virtual void FilterMenuItem(
		ActionID* actionID, PMString* menuPath, PMReal* menuPos, bool16 isDynamic, bool16 isOwnerDraw);

	static bool16 bool16_dynamicMenuExperience;
	static std::vector<ActionID> vector_ActionID_actionID;
	static std::vector<PMString> vector_PMString_menuPath;
	static std::vector<PMReal> vector_PMReal_menuPos;
	static std::vector<bool16> vector_bool16_isDynamic;
	static std::vector<ActionID> vector_ActionID_ShiftAndRtMousePopUpMenuItemActionID;
	static std::vector<PMString> vector_PMString_ShiftAndRtMousePopUpMenuSubMenuPath;
};
#endif // __CstAFltActionFilter__
