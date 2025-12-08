//========================================================================================
//  
//  $File$
//  
//  Owner: Adobe Developer Technologies
//  
//  $Author$
//  
//  $DateTime$
//  
//  $Revision$
//  
//  $Change$
//  
//  Copyright 1997-2010 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//========================================================================================

#include "VCPlugInHeaders.h"

// Interface includes:



// Includes:
#include "KeyStates.h" // for IsShiftKeyPressed
#include "DebugClassUtils.h"
#include "IApplication.h"
#include "IActionManager.h"

#include "IMenuFilter.h"

// General includes:
#include "CAlert.h" // CAlert::InformationAlert(Msg);

// Project includes:
#include "TestMenuFilter.h"
#include "DynMnuID.h"

/* CREATE_PMINTERFACE
 Binds the C++ implementation class onto its
 ImplementationID making the C++ code callable by the
 application.
*/
CREATE_PMINTERFACE(TestMenuFilter, kTestMenuFilterImpl)

PMString TestMenuFilter::pMString_info = "";
std::vector<ActionID> TestMenuFilter::vector_ActionID_actionID = {};
std::vector<PMString> TestMenuFilter::vector_PMString_menuPath = {};
std::vector<PMReal> TestMenuFilter::vector_PMReal_menuPos = {};

TestMenuFilter::TestMenuFilter(IPMUnknown* boss)
	: CPMUnknown<IMenuFilter>(boss) 
{
	// does nothing. 
}

void TestMenuFilter::FilterMenuItem(
	ActionID* actionID, PMString* menuPath, PMReal* menuPos, bool16 isDynamic, bool16 isOwnerDraw)
{
	//if (::IsShiftKeyPressed())
	if (menuPath->Contains("RtMouseDefault"))
	{
		if (actionID->Get() != kDynMnuPlaceholderActionID)
		{
			// 2d‚É‚È‚ç‚È‚¢‚æ‚¤‚É
			auto it = std::find(
				TestMenuFilter::vector_ActionID_actionID.begin(),
				TestMenuFilter::vector_ActionID_actionID.end(),
				*actionID
			);

			if (it == TestMenuFilter::vector_ActionID_actionID.end() && actionID->Get() != 0)
			{
				if (actionID->Get() != kDynMnuStaticMenuActionID)
				{
					TestMenuFilter::vector_ActionID_actionID.push_back(*actionID);
					TestMenuFilter::vector_PMString_menuPath.push_back(*menuPath);
					TestMenuFilter::vector_PMReal_menuPos.push_back(*menuPos);
				}
			}
			else if (actionID->Get() == 0)
			{
				auto it2 = std::find(
					TestMenuFilter::vector_PMString_menuPath.begin(),
					TestMenuFilter::vector_PMString_menuPath.end(),
					*menuPath
				);

				if (it2 == TestMenuFilter::vector_PMString_menuPath.end())
				{
					TestMenuFilter::vector_ActionID_actionID.push_back(*actionID);
					TestMenuFilter::vector_PMString_menuPath.push_back(*menuPath);
					TestMenuFilter::vector_PMReal_menuPos.push_back(*menuPos);
				}
			}
		}
	}

	/*
	PMString result = "\n", num;
	result.Append("ID:");
	num.AsNumber(actionID->Get());
	result.Append(num);
	result.Append(" Path:");
	result.Append(*menuPath);
	InterfacePtr<IApplication> iApplication(::GetExecutionContextSession()->QueryApplication());
	InterfacePtr<IActionManager> iActionMgr(iApplication->QueryActionManager());
	PMString name = iActionMgr->GetActionName(*actionID);
	result.Append(" Name:");
	result.Append(name);
	if(isDynamic == kTrue) result.Append(" isDynamic");
	KESSDScriptProvider::pMString_info.Append(result);
	*/
}

// End, CstAFltActionFilter.cpp.
