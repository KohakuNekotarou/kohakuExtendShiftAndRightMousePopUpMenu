#include "VCPlugInHeaders.h"

// Interface includes:
#include "IMenuFilter.h"

// General includes:
#include "CAlert.h" // CAlert::InformationAlert(Msg);

// Project includes:
#include "KESSARMPUMID.h"
#include "KESSARMPUMMenuFilter.h"

// CREATE_PMINTERFACE
CREATE_PMINTERFACE(KESSARMPUMMenuFilter, kKESSARMPUMMenuFilterImpl)

// Class variable
std::vector<ActionID> KESSARMPUMMenuFilter::vector_ActionID_actionID = {};
std::vector<PMString> KESSARMPUMMenuFilter::vector_PMString_menuPath = {};
std::vector<PMReal> KESSARMPUMMenuFilter::vector_PMReal_menuPos = {};
std::vector<bool16> KESSARMPUMMenuFilter::vector_bool16_isDynamic = {};

// Constructor
KESSARMPUMMenuFilter::KESSARMPUMMenuFilter(IPMUnknown* boss)
	: CPMUnknown<IMenuFilter>(boss) 
{
	// does nothing. 
}

void KESSARMPUMMenuFilter::FilterMenuItem(
	ActionID* actionID, PMString* menuPath, PMReal* menuPos, bool16 isDynamic, bool16 isOwnerDraw)
{
	if (menuPath->Contains("RtMouseDefault"))
	{
		
		// Not DynamicMenuActionID
		if (actionID->Get() != kKESSARMPUMRtMouseDefaultDynMnuPlaceholderActionID)
		{
			// ---------------------------------------------------------------------------------------
			// Do not duplicate
			auto result_actionID = std::find(
				KESSARMPUMMenuFilter::vector_ActionID_actionID.begin(),
				KESSARMPUMMenuFilter::vector_ActionID_actionID.end(),
				*actionID
			);

			// not duplicated && actionID->Get() != 0
			if (result_actionID == KESSARMPUMMenuFilter::vector_ActionID_actionID.end() && actionID->Get() != 0)
			{
				// Added menu?
				//if (actionID->Get() != kDynMnuStaticMenuActionID)
				//{
					KESSARMPUMMenuFilter::vector_ActionID_actionID.push_back(*actionID);
					KESSARMPUMMenuFilter::vector_PMString_menuPath.push_back(*menuPath);
					KESSARMPUMMenuFilter::vector_PMReal_menuPos.push_back(*menuPos);
					KESSARMPUMMenuFilter::vector_bool16_isDynamic.push_back(isDynamic);
					//}
			}
			else if (actionID->Get() == 0)
			{
				// ---------------------------------------------------------------------------------------
				// Do not duplicate
				auto result_menuPath = std::find(
					KESSARMPUMMenuFilter::vector_PMString_menuPath.begin(),
					KESSARMPUMMenuFilter::vector_PMString_menuPath.end(),
					*menuPath
				);

				// not duplicated
				if (result_menuPath == KESSARMPUMMenuFilter::vector_PMString_menuPath.end())
				{
					KESSARMPUMMenuFilter::vector_ActionID_actionID.push_back(*actionID);
					KESSARMPUMMenuFilter::vector_PMString_menuPath.push_back(*menuPath);
					KESSARMPUMMenuFilter::vector_PMReal_menuPos.push_back(*menuPos);
					KESSARMPUMMenuFilter::vector_bool16_isDynamic.push_back(isDynamic);
				}
			}
		}
		
	}
}