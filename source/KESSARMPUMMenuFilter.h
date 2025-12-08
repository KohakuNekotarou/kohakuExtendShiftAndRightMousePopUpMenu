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

#ifndef __CstAFltActionFilter__
#define __CstAFltActionFilter__

#include "DynMnuID.h"
#include "IMenuFilter.h"

/** Filters actions in a configurable way, with the	help of ActionFilterHelper.
 * 
 * 	@ingroup customactionfilter
 * 	@author Ken Sadahiro
*/
class TestMenuFilter : public CPMUnknown<IMenuFilter>
{
public:
	/** Constructor.
		@param boss interface ptr from boss object on which this interface is aggregated.
	*/
	TestMenuFilter(IPMUnknown* boss);

	/** FilterAction
		@see IActionFilter
	*/
	virtual void FilterMenuItem(
		ActionID* actionID, PMString* menuPath, PMReal* menuPos, bool16 isDynamic, bool16 isOwnerDraw);


	static PMString pMString_info;


	static std::vector<ActionID> vector_ActionID_actionID;
	static std::vector<PMString> vector_PMString_menuPath;
	static std::vector<PMReal> vector_PMReal_menuPos;
};
#endif // __CstAFltActionFilter__
